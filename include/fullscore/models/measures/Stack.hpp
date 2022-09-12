#pragma once



#include <vector>

#include <fullscore/Transforms/StackTransform.hpp>
#include <fullscore/models/measures/Base.hpp>



class Note;



namespace Measure
{
   class Stack : public Measure::Base
   {
   public:
      Transforms::Stack transformations;
      bool refresh();

      Stack();

      virtual int get_num_notes() override;
      virtual bool set_notes(std::vector<Note> notes) override;
      virtual std::vector<Note> get_notes_copy() override;
      virtual std::vector<Note> *get_notes_pointer() override;
   };
};



