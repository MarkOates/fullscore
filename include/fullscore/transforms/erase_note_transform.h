#ifndef __FULLSCORE_ERASE_NOTE_TRANSFORM_HEADER
#define __FULLSCORE_ERASE_NOTE_TRANSFORM_HEADER




#include <fullscore/transforms/transform_base.h>




namespace Transform
{
   class EraseNote : public Base
   {
   public:
      int index_num;

      EraseNote(int index_num);
      ~EraseNote();
      virtual std::vector<Note> transform(std::vector<Note> n) override;
   };
}




#endif

