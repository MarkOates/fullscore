



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
      note.duration.set_dots(std::min(2, note.duration.get_dots()+1));

   return n;
}




