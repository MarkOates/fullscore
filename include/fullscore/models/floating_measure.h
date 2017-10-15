#pragma once



#include <fullscore/models/measure.h>
#include <fullscore/models/grid_coordinate.h>



class FloatingMeasure
{
private:
   int id;
   GridCoordinate coordinate;
   int measure_id;

public:
   FloatingMeasure(GridCoordinate coordinate, int measure_id);
   ~FloatingMeasure();

   GridCoordinate get_coordinate();
   int get_measure_id();
   int get_id();

private:
   static int next_id;

public:
   static int get_next_id();
};



