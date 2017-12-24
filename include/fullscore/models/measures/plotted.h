#pragma once



#include <fullscore/models/measures/Base.h>



namespace Measure
{
   class Plotted : public Base
   {
   private:
      std::vector<Note> notes;

   public:
      Plotted(std::vector<Note> notes = {});
      ~Plotted();

      virtual int get_num_notes() override;
      virtual std::vector<Note> get_notes_copy() override;
      virtual bool set_notes(std::vector<Note>) override;
      virtual std::vector<Note> *get_notes_pointer() override;
   };
};



