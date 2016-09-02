



#include <fullscore/transforms/double_duration_transform.h>




Transform::DoubleDuration::DoubleDuration()
{
}




Transform::DoubleDuration::~DoubleDuration()
{
}




std::vector<Note> Transform::DoubleDuration::transform(std::vector<Note> n)
{
   std::vector<Note> result = n;
   for (auto &note : result) note.duration /= 2;
   return result;
}




