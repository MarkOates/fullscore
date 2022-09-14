



#include <fullscore/Transforms/AddDotTransform.hpp>

#include <fullscore/TransformNames.hpp>




Transforms::AddDot::AddDot()
   : Base(TransformNames::ADD_DOT_TRANSFORM_IDENTIFIER)
{
}




Transforms::AddDot::~AddDot()
{
}




std::vector<Note> Transforms::AddDot::transform(std::vector<Note> n)
{
   for (auto &note : n)
   {
      Duration duration = note.get_duration();
      duration.set_dots(std::min(2, duration.get_dots()+1));
      note.set_duration(duration);
   }

   return n;
}




