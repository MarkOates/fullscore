



#include <fullscore/transforms/InvertTransform.hpp>

#include <fullscore/TransformNames.hpp>



Transform::Invert::Invert(int axis)
   : Base(TransformNames::INVERT_TRANSFORM_IDENTIFIER)
   , axis(axis)
{
}




Transform::Invert::~Invert()
{
}




std::vector<Note> Transform::Invert::transform(std::vector<Note> source)
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





