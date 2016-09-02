
#
# Makefile for Fullscore
#


BASE_DIR=/Users/markoates/Repos
ALLEGRO_DIR=$(BASE_DIR)/allegro5
ALLEGROFLARE_DIR=$(BASE_DIR)/allegro_flare
ALLEGROFLARE_LIB_NAME=allegro_flare-0.8.8wip




ALLEGRO_LIB_DIR=$(ALLEGRO_DIR)/build/lib
ALLEGRO_INCLUDE_DIR=$(ALLEGRO_DIR)/include
ALLEGROFLARE_LIB_DIR=$(ALLEGROFLARE_DIR)/lib
ALLEGROFLARE_INCLUDE_DIR=$(ALLEGROFLARE_DIR)/include

OBJS=command_bar fullscore_project_controller gui_score_editor main measure measure_grid mixer music_engraver note playback_control playback_device_interface run_script transform

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



#
# Build Targets
#


bin/fullscore$(EXE_EXTENSION): $(OBJ_FILES)
	g++ $(OBJ_FILES) -o $@ -L$(ALLEGRO_LIB_DIR) -L$(ALLEGROFLARE_LIB_DIR) $(ALLEGRO_LIBS) $(ALLEGROFLARE_LIBS)


$(OBJ_FILES): obj/%.o : src/%.cpp
	g++ -std=gnu++11 -c -o obj/$(notdir $@) $< -I./include -I$(ALLEGRO_INCLUDE_DIR) -I$(ALLEGROFLARE_INCLUDE_DIR)
	


#
# Make Clean
#

clean:
	rm ./obj/*.o
	rm ./bin/fullscore
