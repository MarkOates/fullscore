#pragma once



#include <fullscore/actions/base.h>
#include <fullscore/models/grid_coordinate.h>



namespace Action
{
   class CreateFloatingMeasure : public Base
   {
   private:
      GridCoordinate grid_coordinate;
      int measure_id;
      int created_floating_measure_id;

   public:
      CreateFloatingMeasure(GridCoordinate grid_coordinate, int measure_id);
      ~CreateFloatingMeasure();

      bool execute() override;
      int get_created_floating_measure_id();
   };
};



