#pragma once



#include <fullscore/transforms/base.h>



namespace Transform
{
   class NotesAt : public Base
   {
   private:
      std::vector<int> indexes;

   public:
      NotesAt(std::vector<int> indexes);
      ~NotesAt();

      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
}



