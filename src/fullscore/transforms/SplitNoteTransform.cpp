


#include <fullscore/Transforms/SplitNoteTransform.hpp>

#include <fullscore/Transforms/HalfDurationTransform.hpp>
#include <fullscore/TransformNames.hpp>



Transforms::SplitNote::SplitNote()
   : Base(TransformNames::SPLIT_NOTE_TRANSFORM_IDENTIFIER)
{
}



Transforms::SplitNote::~SplitNote()
{
}



std::vector<Note> Transforms::SplitNote::transform(std::vector<Note> n)
{
   std::vector<Note> results = {};

   for (auto &note : n)
   {
      results.push_back(note);
      results.push_back(note);
   }

   results = ::Transforms::HalfDuration().transform(results);

   return  results;
}



