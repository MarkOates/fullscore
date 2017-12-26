



#include <fullscore/transforms/TransposeTransform.h>




Transform::Transpose::Transpose(int transposition)
   : Base("transpose")
   , transposition(transposition)
{
}




Transform::Transpose::~Transpose()
{
}




std::vector<Note> Transform::Transpose::transform(std::vector<Note> source)
{
   std::vector<Note> notes = source;
   for (auto &note : notes) note.pitch.set_scale_degree(note.pitch.get_scale_degree() + transposition);
   return notes;
}




