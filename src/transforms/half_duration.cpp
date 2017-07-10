



#include <fullscore/transforms/half_duration.h>

#include <fullscore/models/duration.h>
#include <algorithm>




Transform::HalfDuration::HalfDuration()
   : minimum_duration(Duration::THIRTYSECOND)
{
}




Transform::HalfDuration::~HalfDuration()
{
}




std::vector<Note> Transform::HalfDuration::transform(std::vector<Note> n)
{
   std::vector<Note> result = n;
   for (auto &note : result)
      note.duration.denominator = half_duration(note.duration.denominator);
   return result;
}





