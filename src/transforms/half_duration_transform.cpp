



#include <fullscore/transforms/half_duration_transform.h>

#include <algorithm>
#include <fullscore/constants.h>




Transform::HalfDuration::HalfDuration()
   : minimum_duration(DURATION_THIRTYSECOND)
{
}




Transform::HalfDuration::~HalfDuration()
{
}




std::vector<Note> Transform::HalfDuration::transform(std::vector<Note> n)
{
   std::vector<Note> result = n;
   for (auto &note : result)
      note.duration = std::min(minimum_duration, note.duration * 2);
   return result;
}





