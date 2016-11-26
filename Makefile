
#
# Makefile for Fullscore
#


BASE_DIR=/Users/markoates/Repos
ALLEGRO_DIR=$(BASE_DIR)/allegro5
ALLEGROFLARE_DIR=$(BASE_DIR)/allegro_flare
ALLEGROFLARE_LIB_NAME=allegro_flare-0.8.8wip
GOOGLE_TEST_DIR=$(BASE_DIR)/googletest




ALLEGRO_LIB_DIR=$(ALLEGRO_DIR)/build/lib
ALLEGRO_INCLUDE_DIR=$(ALLEGRO_DIR)/include
ALLEGROFLARE_LIB_DIR=$(ALLEGROFLARE_DIR)/lib
ALLEGROFLARE_INCLUDE_DIR=$(ALLEGROFLARE_DIR)/include
GOOGLE_TEST_LIB_DIR=$(GOOGLE_TEST_DIR)/build/googlemock/gtest
GOOGLE_TEST_INCLUDE_DIR=$(GOOGLE_TEST_DIR)/googletest/include

OBJS=command_bar fullscore_application_controller follow_camera gui_score_editor main mixer music_engraver playback_control playback_device_interface run_script
OBJS+=$(addprefix actions/,$(basename $(notdir $(wildcard source/actions/*.cpp))))
OBJS+=$(addprefix actions/transforms/,$(basename $(notdir $(wildcard source/actions/transforms/*.cpp))))
OBJS+=$(addprefix helpers/,$(basename $(notdir $(wildcard source/helpers/*.cpp))))
OBJS+=components/time_signature_render_component components/measure_grid_render_component
OBJS+=converters/measure_grid_file_converter converters/note_string_converter converters/time_signature_string_converter
OBJS+=models/index_set models/measure models/measure_grid models/note models/playback_note models/projection_pitch models/projection_set models/time_signature
OBJS+=transforms/add_dot_transform transforms/double_duration_transform transforms/erase_note_transform transforms/half_duration_transform transforms/remove_dot_transform transforms/retrograde_transform transforms/insert_note_transform transforms/invert_transform transforms/toggle_rest_transform transforms/transform_base transforms/transpose_transform

ifeq ($(OS), Windows_NT)
	EXE_EXTENSION=.exe
	OBJS += playback_device_win_midi
else
	EXE_EXTENSION=
	OBJS += playback_device_generic
endif


OBJ_FILES=$(OBJS:%=obj/%.o)

ALLEGRO_LIBS=-lallegro_color -lallegro_font -lallegro_ttf -lallegro_dialog -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro_image -lallegro_main -lallegro
ALLEGROFLARE_LIBS=-l$(ALLEGROFLARE_LIB_NAME)
GOOGLE_TEST_LIBS=-lgtest



#
# Build Targets
#


bin/fullscore$(EXE_EXTENSION): $(OBJ_FILES)
	g++ $(OBJ_FILES) -o $@ -L$(ALLEGRO_LIB_DIR) -L$(ALLEGROFLARE_LIB_DIR) $(ALLEGRO_LIBS) $(ALLEGROFLARE_LIBS)

$(OBJ_FILES): obj/%.o : source/%.cpp
	g++ -std=gnu++11 -c -o $@ $< -I./include -I$(ALLEGRO_INCLUDE_DIR) -I$(ALLEGROFLARE_INCLUDE_DIR)



#
# Tools
#


.PHONY: tools

tools: bin/generate$(EXE_EXTENSION)

bin/generate$(EXE_EXTENSION): source/tools/generate.cpp
	g++ -std=gnu++11 -o bin/generate$(EXE_EXTENSION) source/tools/generate.cpp -I$(ALLEGRO_INCLUDE_DIR) -L$(ALLEGRO_LIB_DIR) $(ALLEGRO_LIBS)




#
# Tests
#

.PHONY: tests

TEST_OBJS=$(addprefix tests/,$(basename $(notdir $(wildcard tests/*.cpp))))
TEST_OBJ_FILES=$(OBJS:%=bin/tests/%)

tests: bin/tests/test_test$(EXE_EXTENSION) bin/tests/duration_helper_test$(EXE_EXTENSION) bin/tests/measure_grid_helper_test$(EXE_EXTENSION)

bin/tests/test_test: tests/test_test.cpp
	g++ -o bin/tests/test_test tests/test_test.cpp -I./include -I$(GOOGLE_TEST_INCLUDE_DIR) -I$(ALLEGRO_INCLUDE_DIR) -I$(ALLEGROFLARE_DIR) -L$(GOOGLE_TEST_LIB_DIR) $(GOOGLE_TEST_LIBS)

bin/tests/duration_helper_test$(EXE_EXTENSION): tests/duration_helper_test.cpp obj/helpers/duration_helper.o obj/models/time_signature.o
	g++ obj/models/time_signature.o obj/helpers/duration_helper.o -o bin/tests/duration_helper_test tests/duration_helper_test.cpp -I./include -I$(GOOGLE_TEST_INCLUDE_DIR) -I$(ALLEGRO_INCLUDE_DIR) -I$(ALLEGROFLARE_DIR) -L$(GOOGLE_TEST_LIB_DIR) $(GOOGLE_TEST_LIBS)

bin/tests/measure_grid_helper_test$(EXE_EXTENSION): tests/measure_grid_helper_test.cpp obj/helpers/measure_grid_helper.o obj/models/measure_grid.o obj/models/time_signature.o obj/models/note.o obj/helpers/duration_helper.o
	g++ obj/models/measure_grid.o obj/helpers/duration_helper.o obj/models/note.o obj/models/time_signature.o obj/helpers/measure_grid_helper.o -o bin/tests/measure_grid_helper_test tests/measure_grid_helper_test.cpp -I./include -I$(GOOGLE_TEST_INCLUDE_DIR) -I$(ALLEGRO_INCLUDE_DIR) -I$(ALLEGROFLARE_DIR) -L$(GOOGLE_TEST_LIB_DIR) $(GOOGLE_TEST_LIBS)




#
# Make Clean
#

clean:
	-rm ./obj/*.o
	-rm ./obj/*/*.o
	-rm ./obj/*/*/*.o
	-rm ./bin/fullscore
