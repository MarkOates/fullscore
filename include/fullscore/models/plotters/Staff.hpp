#pragma once



#include <fullscore/models/plotters/Base.hpp>
#include <fullscore/models/Note.hpp>
#include <vector>



namespace Plotter
{
   class Staff : public Base
   {
   private:
      std::vector<int> staff_ids;
      int barline_num;
      std::vector<Note> notes;

   public:
      Staff(std::vector<int> staff_ids, int barline_num, std::vector<Note> notes);
      ~Staff();

      bool plot() override;
   };
}



