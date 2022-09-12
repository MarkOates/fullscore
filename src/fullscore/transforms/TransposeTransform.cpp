



#include <fullscore/Transforms/TransposeTransform.hpp>

#include <fullscore/TransformNames.hpp>



Transforms::Transpose::Transpose(int transposition)
   : Base(TransformNames::TRANSPOSE_TRANSFORM_IDENTIFIER)
   , transposition(transposition)
{
}




Transforms::Transpose::~Transpose()
{
}




std::vector<Note> Transforms::Transpose::transform(std::vector<Note> source)
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




