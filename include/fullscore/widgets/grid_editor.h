#pragma once



#include <allegro_flare/gui/widget.h>
#include <allegro_flare/placement2d.h>
#include <fullscore/models/grid.h>
#include <fullscore/models/playback_control.h>
#include <fullscore/services/music_engraver.h>



class ReferenceCursor;



class UIGridEditor : public UIWidget
{
public:
   class RenderingDependencies
   {
   public:
      RenderingDependencies(ReferenceCursor *reference_cursor);

      ReferenceCursor *reference_cursor;
      void set_reference_cursor(ReferenceCursor *reference_cursor);
   };

   enum edit_mode_target_t
   {
      NONE_TARGET=0,
      NOTE_TARGET,
      MEASURE_TARGET,
   };

   enum mode_t
   {
      NONE=0,
      NORMAL_MODE, // navigation, manipulation, etc
      INSERT_MODE,   // inserting new content
      COMMAND_MODE   // editing on the command windows
   };

   enum state_t
   {
      STATE_NONE=0,
      STATE_ACTIVE,
      STATE_INACTIVE
   };

   Grid grid;
   PlaybackControl playback_control;

   RenderingDependencies rendering_dependencies;

   int measure_cursor_x; // should be renamed to grid_cursor_x, grid_cursor_y
   int measure_cursor_y;
   int note_cursor_x;
   edit_mode_target_t edit_mode_target;
   mode_t mode;
   state_t state;

   MusicEngraver music_engraver;

   bool showing_debug_data;

   float STAFF_HEIGHT;
   float FULL_MEASURE_WIDTH;

   UIGridEditor(UIWidget *parent, ReferenceCursor *reference_cursor);
   void on_draw() override;
   void on_timer() override;
   Measure::Base *get_measure_at_cursor();
   Note *get_note_at_cursor();

   int move_measure_cursor_x(int delta);
   int move_measure_cursor_y(int delta);
   int move_note_cursor_x(int delta);
   void set_reference_cursor(ReferenceCursor *reference_cursor);

   float get_measure_cursor_real_x();
   float get_measure_cursor_real_y();
   float get_measure_length_to_note(Measure::Base *measure, int note_index);
   float get_measure_width(Measure::Base *m);

   void toggle_edit_mode_target();
   bool is_measure_target_mode();
   bool is_note_target_mode();

   void set_state(state_t new_state);
};



