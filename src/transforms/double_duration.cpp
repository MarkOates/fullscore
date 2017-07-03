



#include <fullscore/transforms/double_duration.h>

#include <fullscore/models/duration.h>
#include <algorithm>




Transform::DoubleDuration::DoubleDuration()
   : maximum_duration(Duration::WHOLE)
{
}




Transform::DoubleDuration::~DoubleDuration()
{
}




std::vector<Note> Transform::DoubleDuration::transform(std::vector<Note> n)
{
   std::vector<Note> result = n;
   for (auto &note : result)
      note.duration.denominator = std::max(maximum_duration, note.duration.denominator / 2);
   return result;
}




