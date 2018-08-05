#pragma once



#include <fullscore/actions/Base.h>
#include <fullscore/models/FloatingMeasureCursor.h>



namespace UI::GridEditor::Actions
{
   class MoveFloatingMeasureCursorRight : public Action::Base
   {
   private:
      FloatingMeasureCursor *floating_measure_cursor;

   public:
      MoveFloatingMeasureCursorRight(FloatingMeasureCursor *floating_measure_cursor);
      ~MoveFloatingMeasureCursorRight();

      bool execute() override;
   };
};



