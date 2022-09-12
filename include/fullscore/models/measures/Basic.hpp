#pragma once



#include <vector>

#include <fullscore/models/measures/Base.hpp>



class Note;



namespace Measure
{
   class Basic : public Measure::Base
   {
   private:
      std::vector<Note> notes;

   public:
      Basic(std::vector<Note> notes = {});

      int extension;

      virtual int get_num_notes() override;
      virtual bool set_notes(std::vector<Note> notes={}) override;
      virtual std::vector<Note> get_notes_copy() override;
      virtual std::vector<Note> *get_notes_pointer() override;
   };
};



