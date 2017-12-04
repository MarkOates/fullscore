#pragma once



class FloatingMeasureCursor
{
private:
   int floating_measure_id;

public:
   FloatingMeasureCursor();
   ~FloatingMeasureCursor();

   bool set_floating_measure_id(int floating_measure_id);
   void clear_floating_measure_id();
   int get_floating_measure_id();
};



