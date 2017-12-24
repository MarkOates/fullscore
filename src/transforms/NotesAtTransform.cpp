


#include <fullscore/transforms/NotesAtTransform.h>



Transform::NotesAt::NotesAt(std::vector<int> indexes)
   : Base("notes_at")
   , indexes(indexes)
{
}



Transform::NotesAt::~NotesAt()
{
}



std::vector<Note> Transform::NotesAt::transform(std::vector<Note> source)
{
   std::vector<Note> result = {};

   for (unsigned i=0; i<indexes.size(); i++)
   {
      if (i >= source.size()) continue;
      result.push_back(source[i]);
   }

   return result;
}



