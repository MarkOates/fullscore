#pragma once



#include <fullscore/transforms/Base.h>



namespace Transform
{
   class EraseNote : public Base
   {
   public:
      int index_num;

      EraseNote(int index_num);
      ~EraseNote();
      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
}



