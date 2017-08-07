#pragma once



#include <fullscore/models/measures/base.h>



class Grid;



namespace Measure
{
   class Reference : public Base
   {
   private:
      Grid *grid;
      int measure_x;
      int staff_y;

   public:
      Reference(Grid *grid, int measure_x, int staff_y);

      Measure::Base *get_referenced_measure();

      virtual int get_num_notes() override;
      virtual std::vector<Note> get_notes_copy() override;
      virtual bool set_notes(std::vector<Note>) override;
      virtual std::vector<Note> *get_notes_pointer() override;
   };
};



