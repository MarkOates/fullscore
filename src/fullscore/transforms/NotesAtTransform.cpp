


#include <fullscore/transforms/NotesAtTransform.h>

#include <fullscore/Transform.h>



Transform::NotesAt::NotesAt(std::vector<int> indexes)
   : Base(Transform::NOTES_AT_TRANSFORM_IDENTIFIER)
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



