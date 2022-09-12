



#include <fullscore/transforms/TransposeTransform.hpp>

#include <fullscore/TransformNames.hpp>



Transform::Transpose::Transpose(int transposition)
   : Base(TransformNames::TRANSPOSE_TRANSFORM_IDENTIFIER)
   , transposition(transposition)
{
}




Transform::Transpose::~Transpose()
{
}




std::vector<Note> Transform::Transpose::transform(std::vector<Note> source)
{
   std::vector<Note> notes = source;
   for (auto &note : notes)
   {
      Pitch pitch = note.get_pitch();
      pitch.set_scale_degree(pitch.get_scale_degree() + transposition);
      note.set_pitch(pitch);
   }
   return notes;
}




