#pragma once


#include <allegro_flare/gui/widget.h>
#include <fullscore/ui/MeasureEditor/KeyboardCommands.hpp>
#include <fullscore/services/MusicEngraver.h>
#include <fullscore/models/Note.h>
#include <fullscore/models/measures/Base.h>


namespace Measures { class Base; }


namespace UI::MeasureEditor
{
   class Widget : public UIWidget
   {
   private:
      Measure::Base *measure;

   public:
      NoteModeKeyboardCommands note_mode_keyboard_commands;
      MeasureModeKeyboardCommands measure_mode_keyboard_commands;

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

      int note_cursor_x;
      edit_mode_target_t edit_mode_target;
      mode_t mode;
      MusicEngraver music_engraver;

      float STAFF_HEIGHT;
      float FULL_MEASURE_WIDTH;

      Note *get_note_at_cursor();
      int move_note_cursor_x(int delta);
      void toggle_edit_mode_target();
      bool is_measure_target_mode();
      bool is_note_target_mode();

      Measure::Base *get_measure();

      Widget(UIWidget *parent, Measure::Basic *measure);

      std::vector<std::string> get_keyboard_action_mapping(int al_keycode, bool shift, bool ctrl, bool alt);

      void on_draw() override;
   };
}


