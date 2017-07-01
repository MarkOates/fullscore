


PROJECT_NAME_SNAKE_CASE=fullscore



# here are the directories of the projects
# LIBS_ROOT=E:
LIBS_ROOT=/Users/markoates/Repos
ALLEGRO_DIR=$(LIBS_ROOT)/allegro5/build
ALLEGRO_FLARE_DIR=$(LIBS_ROOT)/allegro_flare
PROJECT_DIR=$(LIBS_ROOT)/$(PROJECT_NAME_SNAKE_CASE)
GOOGLE_TEST_DIR=$(LIBS_ROOT)/googletest
GOOGLE_TEST_LIB_DIR=$(GOOGLE_TEST_DIR)/build/googlemock/gtest
GOOGLE_TEST_INCLUDE_DIR=$(GOOGLE_TEST_DIR)/googletest/include



# these are the names of the libs you are linking
ALLEGRO_FLARE_LIB=allegro_flare-0.8.9wip
ALLEGRO_LIBS=-lallegro_color -lallegro_font -lallegro_ttf -lallegro_dialog -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro_image -lallegro_main -lallegro
ALLEGRO_LIBS_FOR_TESTS=-lallegro_color -lallegro_font -lallegro_ttf -lallegro_dialog -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro_image -lallegro
OPENGL_LIB=-framework OpenGL
# OPENGL_LIB=-lopengl32
# OPENGL_LIB=-lGL
GOOGLE_TEST_LIBS=-lgtest


.PHONY: all clean main



SOURCES := $(shell find src -name '*.cpp')
OBJECTS := $(SOURCES:src/%.cpp=obj/%.o)

TEST_SOURCES := $(shell find tests -name '*.cpp')
TESTS := $(TEST_SOURCES:tests/%.cpp=bin/tests/%)



bin/$(PROJECT_NAME_SNAKE_CASE): programs/$(PROJECT_NAME_SNAKE_CASE).cpp $(OBJECTS)
	@printf "compiling program \e[1m\e[36m$<\033[0m..."
	g++ -std=gnu++11 $(OBJECTS) $< -o $@ -l$(ALLEGRO_FLARE_LIB) $(ALLEGRO_LIBS) -L$(ALLEGRO_FLARE_DIR)/lib -L$(ALLEGRO_DIR)/lib $(OPENGL_LIB) -I$(ALLEGRO_FLARE_DIR)/include -I$(ALLEGRO_DIR)/include -I./include
	@echo "done. Executable at \033[1m\033[32m$@\033[0m"



obj/%.o: src/%.cpp
	@mkdir -p $(@D)
	@printf "compiling object for \e[1m\e[34m$<\033[0m..."
	@g++ -c -std=gnu++11 $< -o $@ -I$(ALLEGRO_FLARE_DIR)/include -I$(ALLEGRO_DIR)/include -I./include
	@echo "done."



tests: $(TESTS)



bin/tests/%: tests/%.cpp $(OBJECTS)
	@printf "compiling test \e[1m\e[36m$<\033[0m..."
	@g++ -std=gnu++11 $(OBJECTS) $< -o $@ -l$(ALLEGRO_FLARE_LIB) $(ALLEGRO_LIBS_FOR_TESTS) $(GOOGLE_TEST_LIBS) -L$(ALLEGRO_FLARE_DIR)/lib -L$(ALLEGRO_DIR)/lib $(OPENGL_LIB) -I$(ALLEGRO_FLARE_DIR)/include -I$(ALLEGRO_DIR)/include -I./include -I$(GOOGLE_TEST_INCLUDE_DIR) -L$(GOOGLE_TEST_LIB_DIR)
	@echo "done. Executable at \033[1m\033[32m$@\033[0m"



clean:
	-rm -rdf obj/
	-rm bin/$(PROJECT_NAME_SNAKE_CASE)



