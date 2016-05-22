#ifndef __FULLSCORE_CELL_HEADER
#define __FULLSCORE_CELL_HEADER



#include <fullscore/note.h>

class Cell
{
private:
   std::vector<Note> notes;

public:
   Cell();
   void insert_note(int pos, const Note &note);
   bool remove_note(int pos);
};




#endif
