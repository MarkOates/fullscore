



#include <fullscore/transforms/add_dot.h>




Transform::AddDot::AddDot()
{
}




Transform::AddDot::~AddDot()
{
}




std::vector<Note> Transform::AddDot::transform(std::vector<Note> n)
{
   for (auto &note : n)
      note.dots = std::min(2, note.dots+1);

   return n;
}




