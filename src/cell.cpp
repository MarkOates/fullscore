


#include <fullscore/cell.h>



Cell::Cell()
   : notes()
{
}



void Cell::insert_note(int pos, const Note &note)
{
   if (pos < 0) notes.insert(notes.begin(), note);
   else if (pos >= notes.size()) notes.push_back(note);
   else notes.insert(notes.begin()+pos, note);
}



bool Cell::remove_note(int pos)
{
   if (pos < 0 || pos >= notes.size()) return false;
   notes.erase(notes.begin()+pos);
   return true;
}



