#pragma once



#include <fullscore/actions/Base.h>
#include <fullscore/models/GridCoordinate.h>



namespace UI::GridEditor::Actions
{
   class CreateFloatingMeasure : public Action::Base
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



