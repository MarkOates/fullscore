



#include <fullscore/transforms/DoubleDurationTransform.h>

#include <fullscore/models/Duration.h>
#include <algorithm>




Transform::DoubleDuration::DoubleDuration()
   : Base("double_duration")
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
      note.duration.set_denominator(double_duration(note.duration.get_denominator()));
   return result;
}




