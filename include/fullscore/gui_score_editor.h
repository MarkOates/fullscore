#ifndef __FULLSCORE_GUI_SCORE_EDITOR_HEADER
#define __FULLSCORE_GUI_SCORE_EDITOR_HEADER




#include <allegro_flare/placement2d.h>
#include <allegro_flare/display.h>

#include <flare_gui/widget_parent.h>

#include <fullscore/measure_grid.h>
#include <fullscore/playback_control.h>
#include <fullscore/music_engraver.h>



class GUIScoreEditor : public FGUIParent
{
public:
	MeasureGrid measure_grid;
	PlaybackControl playback_control;

	int measure_cursor_x;
	int measure_cursor_y;
	float cursor_x;
	float cursor_y;

	placement2d camera;

	MusicEngraver music_engraver;

	bool showing_debug_data;

	float STAFF_HEIGHT;
	float MEASURE_WIDTH;

	GUIScoreEditor(FGUIParent *parent, Display *display, PlaybackDeviceInterface *playback_device);
	void on_draw() override;
	void on_timer() override;
	Measure *get_hovered_measure();
	Note *get_hovered_note();
	void on_click() override;
	void on_mouse_move(float x, float y, float dx, float dy) override;
	void on_key_down() override;
};




#endif