



#include <fullscore/Transforms/InvertTransform.hpp>

#include <fullscore/TransformNames.hpp>



Transforms::Invert::Invert(int axis)
   : Base(TransformNames::INVERT_TRANSFORM_IDENTIFIER)
   , axis(axis)
{
}




Transforms::Invert::~Invert()
{
}




std::vector<Note> Transforms::Invert::transform(std::vector<Note> source)
{
   std::vector<Note> notes = source;
   for (auto &note : notes)
   {
      Pitch pitch = note.get_pitch();
      pitch.set_scale_degree((pitch.get_scale_degree() - axis) * -1 + axis);
      note.set_pitch(pitch);
   }
   return notes;
}





