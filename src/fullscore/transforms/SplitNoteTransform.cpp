


#include <fullscore/transforms/SplitNoteTransform.hpp>

#include <fullscore/transforms/HalfDurationTransform.hpp>
#include <fullscore/Transform.hpp>



Transform::SplitNote::SplitNote()
   : Base(Transform::SPLIT_NOTE_TRANSFORM_IDENTIFIER)
{
}



Transform::SplitNote::~SplitNote()
{
}



std::vector<Note> Transform::SplitNote::transform(std::vector<Note> n)
{
   std::vector<Note> results = {};

   for (auto &note : n)
   {
      results.push_back(note);
      results.push_back(note);
   }

   results = ::Transform::HalfDuration().transform(results);

   return  results;
}



