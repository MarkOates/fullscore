



#include <fullscore/Transforms/RemoveDotTransform.hpp>

#include <fullscore/TransformNames.hpp>




Transforms::RemoveDot::RemoveDot()
   : Base(TransformNames::REMOVE_DOT_TRANSFORM_IDENTIFIER)
{
}




Transforms::RemoveDot::~RemoveDot()
{
}




std::vector<Note> Transforms::RemoveDot::transform(std::vector<Note> n)
{
   for (auto &note : n)
   {
      Duration duration = note.get_duration();
      duration.set_dots(std::max(0, duration.get_dots()-1));
      note.set_duration(duration);
   }

   return n;
}




