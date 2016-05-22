#ifndef __FULLSCORE_GUI_SCORE_EDITOR_HEADER
#define __FULLSCORE_GUI_SCORE_EDITOR_HEADER




#include <allegro_flare/placement2d.h>
#include <allegro_flare/display.h>

#include <allegro_flare/gui/widget.h>

#include <fullscore/measure_grid.h>
#include <fullscore/playback_control.h>
#include <fullscore/music_engraver.h>



class GUIScoreEditor : public UIWidget
{
public:
	MeasureGrid measure_grid;
	PlaybackControl playback_control;

	int measure_cursor_x; // should be renamed to grid_cursor_x, grid_cursor_y
	int measure_cursor_y;
	float cursor_x;
	float cursor_y;

	placement2d camera;

	MusicEngraver music_engraver;

	bool showing_debug_data;

	float STAFF_HEIGHT;
	float MEASURE_WIDTH;

	GUIScoreEditor(UIWidget *parent, Display *display, PlaybackDeviceInterface *playback_device);
	void on_draw() override;
	void on_timer() override;
	Measure *get_hovered_measure();
	Note *get_hovered_note();
	int get_hovered_measure_index();
	int get_hovered_staff_index();
	void on_click() override;
	void on_mouse_move(float x, float y, float dx, float dy) override;
	void on_key_down() override;
};




#endif

