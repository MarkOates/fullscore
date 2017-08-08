



#include <fullscore/transforms/ascend_transform.h>




Transform::Ascend::Ascend()
   : Base("ascend")
{
}




Transform::Ascend::~Ascend()
{
}




std::vector<Note> Transform::Ascend::transform(std::vector<Note> n)
{
   if (n.empty()) return {};

   int initial_scale_degree = n[0].pitch.scale_degree;

   for (unsigned i=0; i<n.size(); i++)
      n[i].pitch = Pitch(initial_scale_degree + i, 0);

   return n;
}



