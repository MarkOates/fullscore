#pragma once



#include <vector>
#include <fullscore/models/note.h>



namespace Measure
{
   class Base
   {
   private:
      std::string type;

   public:
      Base(std::string type);
      ~Base();
      std::string get_type();
      bool is_type(std::string measure_type);

      virtual std::vector<Note> get_notes_copy() = 0;
      virtual bool set_notes(std::vector<Note>) = 0;
      virtual std::vector<Note> *get_notes_pointer();
   };
};



