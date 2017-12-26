



#include <fullscore/transforms/AddDotTransform.h>




Transform::AddDot::AddDot()
   : Base("add_dot")
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




