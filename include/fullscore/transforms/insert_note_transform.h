#ifndef __FULLSCORE_INSERT_NOTE_TRANSFORM_HEADER
#define __FULLSCORE_INSERT_NOTE_TRANSFORM_HEADER




#include <fullscore/transform_base.h>

#include <fullscore/models/note.h>




namespace Transform
{
   class InsertNote : public Base
   {
   public:
      int position;
      Note note;

      InsertNote(int position, Note note);
      ~InsertNote();
      virtual std::vector<Note> transform(std::vector<Note> n) override;
   };
}




#endif
