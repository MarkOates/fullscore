



#include <fullscore/transforms/double_duration_transform.h>

#include <fullscore/models/duration.h>
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
      note.duration.denominator = double_duration(note.duration.denominator);
   return result;
}




