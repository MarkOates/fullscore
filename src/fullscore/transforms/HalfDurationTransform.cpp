



#include <fullscore/transforms/HalfDurationTransform.h>

#include <fullscore/helpers/DurationHelper.hpp>
#include <fullscore/Transform.h>
#include <algorithm>




Transform::HalfDuration::HalfDuration()
   : Base(Transform::HALF_DURATION_TRANSFORM_IDENTIFIER)
   , minimum_duration(Duration::THIRTYSECOND)
{
}




Transform::HalfDuration::~HalfDuration()
{
}




std::vector<Note> Transform::HalfDuration::transform(std::vector<Note> n)
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





