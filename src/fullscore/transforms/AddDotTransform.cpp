



#include <fullscore/transforms/AddDotTransform.hpp>

#include <fullscore/Transform.hpp>




Transform::AddDot::AddDot()
   : Base(Transform::ADD_DOT_TRANSFORM_IDENTIFIER)
{
}




Transform::AddDot::~AddDot()
{
}




std::vector<Note> Transform::AddDot::transform(std::vector<Note> n)
{
   for (auto &note : n)
   {
      Duration duration = note.get_duration();
      duration.set_dots(std::min(2, duration.get_dots()+1));
      note.set_duration(duration);
   }

   return n;
}




