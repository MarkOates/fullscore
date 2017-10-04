#pragma once



class GridHorizontalCoordinate
{
private:
   int measure_num;
   int beat_num;

public:
   GridHorizontalCoordinate(int measure_num = 0, int beat_num = 0);

   void set_measure_num(int measure_num);
   void set_beat_num(int beat_num);
   int get_measure_num();
   int get_beat_num();
};



