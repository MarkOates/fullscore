#pragma once



#include <fullscore/actions/Base.h>



namespace Action
{
   class DeleteFloatingMeasure : public Base
   {
   private:
      int floating_measure_id;

   public:
      DeleteFloatingMeasure(int floating_measure_id);
      ~DeleteFloatingMeasure();

      bool execute() override;
   };
};



