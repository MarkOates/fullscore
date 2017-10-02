#pragma once



#include <fullscore/models/measures/base.h>



class Plotter;



namespace Measure
{
   class Plotted : public Base
   {
   private:
      Plotter *plotter;
      std::vector<Note> get_plotted_notes();

   public:
      Plotted(Plotter *plotter);

      virtual int get_num_notes() override;
      virtual std::vector<Note> get_notes_copy() override;
      virtual bool set_notes(std::vector<Note>) override;
      virtual std::vector<Note> *get_notes_pointer() override;
   };
};



