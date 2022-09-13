



#include <fullscore/Transforms/HalfDurationTransform.hpp>

#include <fullscore/services/DurationHelper.hpp>
#include <fullscore/TransformNames.hpp>
#include <algorithm>




Transforms::HalfDuration::HalfDuration()
   : Base(TransformNames::HALF_DURATION_TRANSFORM_IDENTIFIER)
   , minimum_duration(Duration::THIRTYSECOND)
{
}




Transforms::HalfDuration::~HalfDuration()
{
}




std::vector<Note> Transforms::HalfDuration::transform(std::vector<Note> n)
{
   std::vector<Note> result = n;
   for (auto &note : result)
   {
      Duration duration = note.get_duration();
      duration.set_denominator(DurationHelper::half_duration(note.get_duration().get_denominator()));
      note.set_duration(duration);
   }
   return result;
}





