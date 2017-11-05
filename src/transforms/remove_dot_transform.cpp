



#include <fullscore/transforms/remove_dot_transform.h>

#include <fullscore/transform.h>




Transform::RemoveDot::RemoveDot()
   : Base(Transform::REMOVE_DOT_TRANSFORM_IDENTIFIER)
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




