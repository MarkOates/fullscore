

#include <fullscore/UI/MeasureEditor/ActionFactory.hpp>

#include <fullscore/UI/MeasureEditor/Actions.hpp>
#include <fullscore/UI/MeasureEditor/Widget.hpp>
#include <fullscore/actions/QueueAction.h>

#include <fullscore/actions/transforms/AddDotToNote.h>
#include <fullscore/actions/transforms/AppendNote.h>
#include <fullscore/actions/transforms/Ascend.h>
#include <fullscore/actions/transforms/ClearMeasure.h>
#include <fullscore/actions/transforms/Descend.h>
#include <fullscore/actions/transforms/DoubleDuration.h>
#include <fullscore/actions/transforms/EraseNote.h>
#include <fullscore/actions/transforms/HalfDuration.h>
#include <fullscore/actions/transforms/InsertNote.h>
#include <fullscore/actions/transforms/InsertNoteAfter.h>
#include <fullscore/actions/transforms/Invert.h>
#include <fullscore/actions/transforms/Octatonic1.h>
#include <fullscore/actions/transforms/RemoveDot.h>
#include <fullscore/actions/transforms/Retrograde.h>
#include <fullscore/actions/transforms/SplitNote.h>
#include <fullscore/actions/transforms/ToggleRest.h>
#include <fullscore/actions/transforms/TransposeUp.h>
#include <fullscore/actions/transforms/TransposeDown.h>

#include <fullscore/UI/MeasureEditor/Actions/ToggleEditMode.hpp>
#include <fullscore/UI/MeasureEditor/Actions/MoveCursorLeft.hpp>
#include <fullscore/UI/MeasureEditor/Actions/MoveCursorRight.hpp>
#include <fullscore/UI/MeasureEditor/Actions/SayHello.hpp>


namespace UI::MeasureEditor
{


Action::Base *ActionFactory::create_action(Widget *widget, std::string action_name)
{
   Action::Base *action = nullptr;
   std::vector<Note> *notes = nullptr;
   Note *single_note = nullptr;
   Measure::Base *focused_measure = widget->get_measure();

   if (widget->is_note_target_mode())
   {
      single_note = widget->get_note_at_cursor();
      if (focused_measure && focused_measure->get_notes_pointer()) notes = focused_measure->get_notes_pointer();
   }
   if (widget->is_measure_target_mode())
   {
      if (focused_measure && focused_measure->get_notes_pointer()) notes = focused_measure->get_notes_pointer();
   }

   if (action_name == Actions::TRANSPOSE_UP_ACTION_IDENTIFIER)
   {
      if (widget->is_note_target_mode())
      {
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (unsigned i=0; i<(Framework::key_shift ? 7 : 1); i++)
            action_queue->add_action(new Action::Transform::TransposeUp(single_note));
         return action_queue;
      }
      else
      {
         if (!notes) { std::cout << "cannot transpose_up on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (auto &note : *notes)
            for (unsigned i=0; i<(Framework::key_shift ? 7 : 1); i++)
               action_queue->add_action(new Action::Transform::TransposeUp(&note));
         return action_queue;
      }
   }
   else if (action_name == Actions::TRANSPOSE_DOWN_ACTION_IDENTIFIER)
   {
      if (widget->is_note_target_mode())
      {
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (unsigned i=0; i<(Framework::key_shift ? 7 : 1); i++)
            action_queue->add_action(new Action::Transform::TransposeDown(single_note));
         return action_queue;
      }
      else
      {
         if (!notes) { std::cout << "cannot transpose_down on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (auto &note : *notes)
            for (unsigned i=0; i<(Framework::key_shift ? 7 : 1); i++)
               action_queue->add_action(new Action::Transform::TransposeDown(&note));
         return action_queue;
      }
   }
   else if (action_name == Actions::HALF_DURATION_ACTION_IDENTIFIER)
   {
      if (widget->is_note_target_mode()) action = new Action::Transform::HalfDuration(single_note);
      else
      {
         if (!notes) { std::cout << "cannot half_duration on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (auto &note : *notes) action_queue->add_action(new Action::Transform::HalfDuration(&note));
         return action_queue;
      }
   }
   else if (action_name == Actions::DOUBLE_DURATION_ACTION_IDENTIFIER)
   {
      if (widget->is_note_target_mode()) action = new Action::Transform::DoubleDuration(single_note);
      else
      {
         if (!notes) { std::cout << "cannot double_duration on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (auto &note : *notes) action_queue->add_action(new Action::Transform::DoubleDuration(&note));
         return action_queue;
      }
   }
   else if (action_name == Actions::TOGGLE_REST_ACTION_IDENTIFIER)
   {
      if (widget->is_note_target_mode()) action = new Action::Transform::ToggleRest(single_note);
      else
      {
         if (!notes) { std::cout << "cannot toggle_rest on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (auto &note : *notes) action_queue->add_action(new Action::Transform::ToggleRest(&note));
         return action_queue;
      }
   }
   else if (action_name == Actions::INVERT_ACTION_IDENTIFIER)
   {
      if (widget->is_note_target_mode()) action = new Action::Transform::Invert(single_note);
      else
      {
         if (!notes) { std::cout << "cannot invert_note on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (auto &note : *notes) action_queue->add_action(new Action::Transform::Invert(&note));
         return action_queue;
      }
   }
   else if (action_name == Actions::ERASE_NOTE_ACTION_IDENTIFIER)
      action = new Action::Transform::EraseNote(notes, widget->note_cursor_x);
   else if (action_name == Actions::ASCEND_ACTION_IDENTIFIER)
      action = new Action::Transform::Ascend(notes);
   else if (action_name == Actions::DESCEND_ACTION_IDENTIFIER)
      action = new Action::Transform::Descend(notes);
   else if (action_name == Actions::ADD_DOT_TO_NOTE_ACTION_IDENTIFIER)
      action = new Action::Transform::AddDotToNote(single_note);
   else if (action_name == Actions::REMOVE_DOT_ACTION_IDENTIFIER)
      action = new Action::Transform::RemoveDot(single_note);
   else if (action_name == Actions::SPLIT_NOTE_ACTION_IDENTIFIER)
      action = new Action::Transform::SplitNote(notes);
   else if (action_name == Actions::RETROGRADE_ACTION_IDENTIFIER)
      action = new Action::Transform::Retrograde(notes);
   else if (action_name == Actions::OCTATONIC_1_ACTION_IDENTIFIER)
      action = new Action::Transform::Octatonic1(notes);
   else if (action_name == Actions::INSERT_NOTE_ACTION_IDENTIFIER)
      action = new Action::Transform::InsertNote(notes, widget->note_cursor_x, Note());
   else if (action_name == Actions::INSERT_NOTE_AFTER_TRANSFORM_IDENTIFIER)
      action = new Action::Transform::InsertNoteAfter(notes, widget->note_cursor_x, Note());
   else if (action_name == Actions::TOGGLE_EDIT_MODE_ACTION_IDENTIFIER)
      action = new Actions::ToggleEditMode(widget);
   else if (action_name == Actions::MOVE_CURSOR_LEFT_ACTION_IDENTIFIER)
      action = new Actions::MoveCursorLeft(widget);
   else if (action_name == Actions::MOVE_CURSOR_RIGHT_ACTION_IDENTIFIER)
      action = new Actions::MoveCursorRight(widget);
   else if (action_name == Actions::SAY_HELLO_ACTION_IDENTIFIER)
      action = new Actions::SayHello();

   return action;
}


} // namespace UI::MeasureEditor


