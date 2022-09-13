



#include <fullscore/Transforms/DoubleDurationTransform.hpp>

#include <fullscore/services/DurationHelper.hpp>
#include <fullscore/TransformNames.hpp>
#include <algorithm>




Transforms::DoubleDuration::DoubleDuration()
   : Base(TransformNames::DOUBLE_DURATION_TRANSFORM_IDENTIFIER)
   , maximum_duration(Duration::WHOLE)
{
}




Transforms::DoubleDuration::~DoubleDuration()
{
}




std::vector<Note> Transforms::DoubleDuration::transform(std::vector<Note> n)
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




