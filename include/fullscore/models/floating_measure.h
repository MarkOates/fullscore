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
   enum find_option_t
   {
      FIND_OPTION_NONE = 0,
      FIND_OPTION_INCLUDE_NOT_FOUND,
      FIND_OPTION_RAISE_NOT_FOUND,
   };

   static int get_next_id();
   static FloatingMeasure *find(int id, find_option_t find_option=FIND_OPTION_NONE);
   static std::vector<FloatingMeasure *> find_at_staff_and_barline(int staff_id, int barline_num);
   static std::vector<FloatingMeasure *> find_in_staff_after_barline(int staff_id, int barline_num, bool sort=true);
   static FloatingMeasure *find_first_in_staff_after_barline(int staff_id, int barline_num);
   static std::vector<FloatingMeasure *> in_staff(int staff_id, bool sort=true);
   static std::vector<FloatingMeasure *> get_pool_elements();
   static bool destroy(int floating_measure_id);
   static bool destroy_all();
   static int get_num_pool_elements();
};



