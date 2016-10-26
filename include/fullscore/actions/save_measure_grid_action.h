#pragma once




#include <string>
#include <fullscore/actions/action_base.h>




class MeasureGrid;

class SaveMeasureGridAction : public Action::Base
{
private:
   MeasureGrid *measure_grid;
   std::string filename;

public:
   SaveMeasureGridAction(MeasureGrid *measure_grid, std::string filename);
   ~SaveMeasureGridAction();

   bool execute();
};




