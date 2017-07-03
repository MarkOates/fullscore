



#include <fullscore/transforms/remove_dot.h>




Transform::RemoveDot::RemoveDot()
{
}




Transform::RemoveDot::~RemoveDot()
{
}




std::vector<Note> Transform::RemoveDot::transform(std::vector<Note> n)
{
   for (auto &note : n)
      note.dots = std::max(0, note.dots-1);

   return n;
}




