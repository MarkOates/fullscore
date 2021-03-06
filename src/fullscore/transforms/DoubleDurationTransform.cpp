



#include <fullscore/transforms/DoubleDurationTransform.h>

#include <fullscore/helpers/DurationHelper.h>
#include <fullscore/Transform.h>
#include <algorithm>




Transform::DoubleDuration::DoubleDuration()
   : Base(Transform::DOUBLE_DURATION_TRANSFORM_IDENTIFIER)
   , maximum_duration(Duration::WHOLE)
{
}




Transform::DoubleDuration::~DoubleDuration()
{
}




std::vector<Note> Transform::DoubleDuration::transform(std::vector<Note> n)
{
   std::vector<Note> result = n;
   for (auto &note : result)
   {
      Duration duration = note.get_duration();
      duration.set_denominator(DurationHelper::double_duration(duration.get_denominator()));
      note.set_duration(duration);
   }
   return result;
}




