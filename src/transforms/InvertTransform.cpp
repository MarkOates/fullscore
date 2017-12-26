



#include <fullscore/transforms/InvertTransform.h>




Transform::Invert::Invert(int axis)
   : Base("invert")
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





