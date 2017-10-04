#pragma once



#include <fullscore/models/measures/base.h>



namespace Plotter { class Base; }



namespace Measure
{
   class Plotted : public Base
   {
   private:
      Plotter::Base *plotter;
      std::vector<Note> get_plotted_notes();

   public:
      Plotted(Plotter::Base *plotter);

      virtual int get_num_notes() override;
      virtual std::vector<Note> get_notes_copy() override;
      virtual bool set_notes(std::vector<Note>) override;
      virtual std::vector<Note> *get_notes_pointer() override;
   };
};



