



#include <fullscore/transforms/remove_dot.h>




Transform::RemoveDot::RemoveDot()
   : Base("remove_dot")
{
}




Transform::RemoveDot::~RemoveDot()
{
}




std::vector<Note> Transform::RemoveDot::transform(std::vector<Note> n)
{
   for (auto &note : n)
      note.duration.dots = std::max(0, note.duration.dots-1);

   return n;
}




