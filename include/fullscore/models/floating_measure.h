#pragma once



#include <fullscore/models/measure.h>
#include <fullscore/models/grid_coordinate.h>



class FloatingMeasure
{
private:
   int id;
   GridCoordinate grid_coordinate;
   int measure_id;

public:
   FloatingMeasure(GridCoordinate grid_coordinate, int measure_id);
   ~FloatingMeasure();

   GridCoordinate get_grid_coordinate();
   int get_measure_id();
   int get_id();

private:
   static int next_id;
   static std::vector<FloatingMeasure *> pool_elements;

public:
   static int get_next_id();
   static std::vector<FloatingMeasure *> find_at_staff_and_barline(int staff_id, int barline_num);
   static std::vector<FloatingMeasure *> get_pool_elements();
   static bool destroy_all();
   static int get_num_pool_elements();
};



