#pragma once


#include <allegro_flare/gui/widget.h>
#include <allegro_flare/placement2d.h>
#include <fullscore/models/FloatingMeasureCursor.h>
#include <fullscore/models/Grid.h>
#include <fullscore/models/PlaybackControl.h>
#include <fullscore/services/MusicEngraver.h>
#include <fullscore/UI/GridEditor/KeyboardCommands.hpp>


namespace UI::GridEditor::RenderComponents { class UIGridEditorRenderComponent; }


namespace UI::GridEditor
{
   class Widget : public UIWidget
   {
   public:
      friend class ::UI::GridEditor::RenderComponents::UIGridEditorRenderComponent;

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

      NormalModeKeyboardCommands normal_mode_keyboard_commands;
      NoteModeKeyboardCommands note_mode_keyboard_commands;
      MeasureModeKeyboardCommands measure_mode_keyboard_commands;
      void _set_keyboard_mappings();

      int grid_cursor_x;
      int grid_cursor_y;
      int note_cursor_x;
      FloatingMeasureCursor floating_measure_cursor;
      edit_mode_target_t edit_mode_target;
      mode_t mode;
      state_t state;

      MusicEngraver music_engraver;

      bool showing_debug_data;

      float STAFF_HEIGHT;
      float FULL_MEASURE_WIDTH;

      Widget(UIWidget *parent);
      void on_draw() override;
      void on_timer() override;
      Measure::Base *get_measure_at_cursor();
      Note *get_note_at_cursor();

      int move_grid_cursor_x(int delta);
      int move_grid_cursor_y(int delta);
      int move_note_cursor_x(int delta);

      float get_grid_cursor_real_x();
      float get_grid_cursor_real_y();
      float get_measure_width(Measure::Base *m);

      void toggle_edit_mode_target();
      bool is_measure_target_mode();
      bool is_note_target_mode();

      void set_state(state_t new_state);
   };
}


