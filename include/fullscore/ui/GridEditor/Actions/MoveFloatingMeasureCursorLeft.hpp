#pragma once



#include <fullscore/actions/Base.h>
#include <fullscore/models/FloatingMeasureCursor.h>



namespace UI::GridEditor::Actions
{
   class MoveFloatingMeasureCursorLeft : public Action::Base
   {
   private:
      FloatingMeasureCursor *floating_measure_cursor;

   public:
      MoveFloatingMeasureCursorLeft(FloatingMeasureCursor *floating_measure_cursor);
      ~MoveFloatingMeasureCursorLeft();

      bool execute() override;
   };
};



