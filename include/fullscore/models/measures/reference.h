#pragma once



#include <fullscore/models/measures/base.h>



class MeasureGrid *measure_grid;



namespace Measure
{
   class Reference : public Base
   {
   private:
      MeasureGrid *measure_grid;
      int measure_x;
      int staff_y;

   public:
      Reference(MeasureGrid *measure_grid, int measure_x, int staff_y);

      Measure::Base *get_referenced_measure();

      virtual int get_num_notes() override;
      virtual std::vector<Note> get_notes_copy() override;
      virtual bool set_notes(std::vector<Note>) override;
      virtual std::vector<Note> *get_notes_pointer() override;
   };
};



