



#include <fullscore/transforms/erase_note_transform.h>

#include <algorithm>
#include <fullscore/constants.h>




Transform::EraseNote::EraseNote(int index_num)
   : index_num(index_num)
{
}




Transform::EraseNote::~EraseNote()
{
}




std::vector<Note> Transform::EraseNote::transform(std::vector<Note> notes)
{
   if (index_num < 0 || notes.size() >= index_num) return notes;
   notes.erase(notes.begin() + index_num);
   return notes;
}





