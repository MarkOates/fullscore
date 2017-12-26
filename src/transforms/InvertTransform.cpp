



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
      note.pitch.set_scale_degree((note.pitch.get_scale_degree() - axis) * -1 + axis);
   return notes;
}





