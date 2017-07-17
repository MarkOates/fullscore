#pragma once



#include <vector>

#include <fullscore/transforms/stack.h>
#include <fullscore/models/measures/base.h>



class Note;



namespace Measure
{
   class Stack : public Measure::Base
   {
   public:
      Transform::Stack transformations;
      bool refresh();

      Stack();

      virtual int get_num_notes() override;
      virtual bool set_notes(std::vector<Note> notes) override;
      virtual std::vector<Note> get_notes_copy() override;
      virtual std::vector<Note> *get_notes_pointer() override;
   };
};



