



#include <fullscore/transforms/HalfDurationTransform.h>

#include <fullscore/helpers/DurationHelper.h>
#include <algorithm>




Transform::HalfDuration::HalfDuration()
   : Base("half_duration")
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
      note.duration.set_denominator(DurationHelper::half_duration(note.duration.get_denominator()));
   return result;
}





