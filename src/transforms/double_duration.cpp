



#include <fullscore/transforms/double_duration.h>

#include <algorithm>
#include <fullscore/constants.h>




Transform::DoubleDuration::DoubleDuration()
   : maximum_duration(DURATION_WHOLE)
{
}




Transform::DoubleDuration::~DoubleDuration()
{
}




std::vector<Note> Transform::DoubleDuration::transform(std::vector<Note> n)
{
   std::vector<Note> result = n;
   for (auto &note : result)
      note.duration = std::max(maximum_duration, note.duration / 2);
   return result;
}




