



#include <fullscore/transforms/descend_transform.h>




Transform::Descend::Descend()
   : Base("descend")
{
}




Transform::Descend::~Descend()
{
}




std::vector<Note> Transform::Descend::transform(std::vector<Note> n)
{
   if (n.empty()) return {};

   int initial_scale_degree = n[0].pitch.scale_degree;

   for (unsigned i=0; i<n.size(); i++)
      n[i].pitch = Pitch(initial_scale_degree - i, 0);

   return n;
}




