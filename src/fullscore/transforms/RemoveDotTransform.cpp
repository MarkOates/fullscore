



#include <fullscore/transforms/RemoveDotTransform.hpp>

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
   {
      Duration duration = note.get_duration();
      duration.set_dots(std::max(0, duration.get_dots()-1));
      note.set_duration(duration);
   }

   return n;
}




