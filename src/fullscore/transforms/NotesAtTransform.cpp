


#include <fullscore/transforms/NotesAtTransform.hpp>

#include <fullscore/Transform.hpp>



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
      int index = indexes[i];
      if (index >= source.size())
      {
         std::stringstream error_message;
         error_message << "Transform::NotesAt::transform() error: cannot have index greater than the number of elements in the set (index: " << index << ", set_size: " << source.size() << ").";
         throw std::runtime_error(error_message.str());
      }
      if (index < 0)
      {
         std::stringstream error_message;
         error_message << "Transform::NotesAt::transform() error: cannot have index less than zero (index: " << index << ", set_size: " << source.size() << ").";
         throw std::runtime_error(error_message.str());
      }
      result.push_back(source[index]);
   }

   return result;
}



