



#include <fullscore/transforms/invert.h>




Transform::Invert::Invert(int axis)
   : axis(axis)
{
}




Transform::Invert::~Invert()
{
}




std::vector<Note> Transform::Invert::transform(std::vector<Note> source)
{
   std::vector<Note> notes = source;
   for (auto &note : notes)
      note.pitch.scale_degree = (note.pitch.scale_degree - axis) * -1 + axis;
   return notes;
}





