#pragma once



#include <fullscore/models/measures/base.h>



namespace Measure
{
   class Static : public Base
   {
   public:
      Static();

      virtual std::vector<Note> get_notes_copy() override;
      virtual bool set_notes(std::vector<Note>) override;
      virtual std::vector<Note> *get_notes_pointer() override;
   };
};



