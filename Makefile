

OBJS=gui_score_editor main measure measure_grid music_engraver note playback_control playback_device_interface playback_device_win_midi run_script


OBJ_FILES=$(OBJS:%=obj/%.o)
INCLUDE_FLAGS=-IE:/allegro-5.1.11-mingw-edgar/include -IE:/allegro_flare/include -IE:/fullscore/include -IE:/flare_gui/include
LIBRARY_LINKS=-lflare_gui-0.6.6-mingw-4.8.1 -lallegro_flare-0.8.6-mingw-4.8.1 -lallegro_monolith-debug.dll -lwinmm -LE:/allegro-5.1.11-mingw-edgar/lib -LE:/allegro_flare/lib -LE:/flare_gui/lib


bin/fullscore.exe: $(OBJ_FILES) E:/flare_gui/lib/libflare_gui-0.6.6-mingw-4.8.1.a
	g++ $(OBJ_FILES) -o $@ $(LIBRARY_LINKS)


$(OBJ_FILES): obj/%.o : src/%.cpp
	g++ -std=gnu++11 -c -o obj/$(notdir $@) $< $(INCLUDE_FLAGS)
	


