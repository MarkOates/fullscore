#pragma once



class Grid;



class GridCoordinate
{
private:
   Grid *grid;
   int staff_id;
   int barline_num;
   int beat_num;

public:
   GridCoordinate(Grid *grid=nullptr, int staff_id=0, int barline_num=0, int beat_num=0);

   void set_grid(Grid *grid);
   void set_staff_id(int staff_id);
   void set_barline_num(int barline_num);
   void set_beat_num(int beat_num);

   Grid *get_grid();
   int get_staff_id();
   int get_barline_num();
   int get_beat_num();

   bool operator==(const GridCoordinate &other) const;
   bool operator!=(const GridCoordinate &other) const;
};



