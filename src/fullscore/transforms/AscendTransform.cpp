



#include <fullscore/transforms/AscendTransform.hpp>

#include <fullscore/Transform.h>




Transform::Ascend::Ascend()
   : Base(Transform::ASCEND_TRANSFORM_IDENTIFIER)
{
}




Transform::Ascend::~Ascend()
{
}




std::vector<Note> Transform::Ascend::transform(std::vector<Note> n)
{
   if (n.empty()) return {};

   int initial_scale_degree = n[0].get_pitch().get_scale_degree();

   for (unsigned i=0; i<n.size(); i++)
   {
      Pitch pitch = n[i].get_pitch();
      pitch = Pitch(initial_scale_degree + i, 0);
      n[i].set_pitch(pitch);
   }

   return n;
}




