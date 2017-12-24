


#include <fullscore/transforms/SplitNoteTransform.h>

#include <fullscore/transforms/HalfDurationTransform.h>



Transform::SplitNote::SplitNote()
   : Base("split_note")
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



