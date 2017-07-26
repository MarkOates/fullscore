



#include <fullscore/transforms/erase_note_transform.h>

#include <algorithm>




Transform::EraseNote::EraseNote(int index_num)
   : Base("erase_note")
   , index_num(index_num)
{
}




Transform::EraseNote::~EraseNote()
{
}




std::vector<Note> Transform::EraseNote::transform(std::vector<Note> notes)
{
   if (index_num < 0 || index_num >= notes.size()) return notes;
   notes.erase(notes.begin() + index_num);
   return notes;
}





