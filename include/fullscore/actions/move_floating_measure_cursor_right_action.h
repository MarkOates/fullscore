#pragma once



#include <fullscore/actions/base.h>



namespace Action
{
   class MoveFloatingMeasureCursorRight : public Base
   {
   public:
      MoveFloatingMeasureCursorRight();
      ~MoveFloatingMeasureCursorRight();

      bool execute() override;
   };
};



