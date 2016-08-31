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
   int note_cursor_x;
   bool input_mode;

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
   void on_mouse_enter() override;
   void on_mouse_leave() override;

   float get_measure_cursor_real_x();
   float get_measure_cursor_real_y();

   void toggle_input_mode();
   bool is_measure_mode();
   bool is_note_mode();
};




#endif

