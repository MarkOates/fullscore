



#include <fullscore/Transforms/EraseNoteTransform.hpp>

#include <fullscore/TransformNames.hpp>
#include <algorithm>




Transforms::EraseNote::EraseNote(int index_num)
   : Base(TransformNames::ERASE_NOTE_TRANSFORM_IDENTIFIER)
   , index_num(index_num)
{
}




Transforms::EraseNote::~EraseNote()
{
}




std::vector<Note> Transforms::EraseNote::transform(std::vector<Note> notes)
{
   if (index_num < 0 || index_num >= notes.size()) return notes;
   notes.erase(notes.begin() + index_num);
   return notes;
}





