#ifndef __FULLSCORE_GUI_SCORE_EDITOR_HEADER
#define __FULLSCORE_GUI_SCORE_EDITOR_HEADER




#include <allegro_flare/gui/widget.h>
#include <allegro_flare/display.h>
#include <allegro_flare/placement2d.h>
#include <fullscore/models/measure_grid.h>
#include <fullscore/music_engraver.h>
#include <fullscore/playback_control.h>




class GUIScoreEditor : public UIWidget
{
public:
   enum edit_mode_target_t
   {
      NOTE_TARGET=0,
      MEASURE_TARGET
   };

   enum mode_t
   {
      NORMAL_MODE=0, // navigation, manipulation, etc
      INSERT_MODE,   // inserting new content
      COMMAND_MODE   // editing on the command windows
   };

   MeasureGrid measure_grid;
   PlaybackControl playback_control;

   int measure_cursor_x; // should be renamed to grid_cursor_x, grid_cursor_y
   int measure_cursor_y;
   int note_cursor_x;
   edit_mode_target_t edit_mode_target;
   mode_t mode;

   MusicEngraver music_engraver;

   bool showing_debug_data;

   float STAFF_HEIGHT;
   float FULL_MEASURE_WIDTH;

   GUIScoreEditor(UIWidget *parent, Display *display, PlaybackDeviceInterface *playback_device);
   void on_draw() override;
   void on_timer() override;
   Measure *get_measure_at_cursor();
   Note *get_note_at_cursor();

   int move_measure_cursor_x(int delta);
   int move_measure_cursor_y(int delta);
   int move_note_cursor_x(int delta);

   float get_measure_cursor_real_x();
   float get_measure_cursor_real_y();
   float get_measure_length_to_note(Measure &measure, int note_index);
   float get_measure_width(Measure &m);

   void toggle_edit_mode_target();
   bool is_measure_target_mode();
   bool is_note_target_mode();
};




#endif
