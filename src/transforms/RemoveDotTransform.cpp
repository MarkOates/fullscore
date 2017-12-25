



#include <fullscore/transforms/RemoveDotTransform.h>

#include <fullscore/Transform.h>




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
      note.duration.set_dots(std::max(0, note.duration.get_dots()-1));

   return n;
}




