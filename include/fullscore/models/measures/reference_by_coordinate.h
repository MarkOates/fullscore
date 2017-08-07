#pragma once



#include <fullscore/models/measures/base.h>



class Grid;



namespace Measure
{
   class ReferenceByCoordinate : public Base
   {
   private:
      Grid *referenced_grid;
      int referenced_measure_x;
      int referenced_staff_y;

   public:
      ReferenceByCoordinate(Grid *referenced_grid, int referenced_measure_x, int referenced_staff_y);

      Measure::Base *get_referenced_measure();

      virtual int get_num_notes() override;
      virtual std::vector<Note> get_notes_copy() override;
      virtual bool set_notes(std::vector<Note>) override;
      virtual std::vector<Note> *get_notes_pointer() override;
   };
};



