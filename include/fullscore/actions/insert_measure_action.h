#pragma once




#include <fullscore/actions/action_base.h>




namespace Action
{
   class InsertMeasure : public Base
   {
   public:
      InsertMeasure();
      ~InsertMeasure();

      bool execute() override;
   };
};




