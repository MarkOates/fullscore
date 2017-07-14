#pragma once



#include <vector>

#include <fullscore/transforms/stack.h>
#include <fullscore/models/measures/base.h>



class Note;



namespace Measure
{
   class BasicMeasure : public Measure::Base
   {
   private:
      std::vector<Note> notes;

   public:
      Transform::Stack *genesis;
      bool refresh();
      bool references_source();

      BasicMeasure();

      int extension;

      virtual bool set_notes(std::vector<Note> notes) override;
      virtual std::vector<Note> get_notes_copy() override;
      virtual std::vector<Note> *get_notes_pointer() override;
   };
};



