



#include <fullscore/transforms/DescendTransform.h>




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

   int initial_scale_degree = n[0].get_pitch().get_scale_degree();

   for (unsigned i=0; i<n.size(); i++)
   {
      Pitch pitch = n[i].get_pitch();
      pitch = Pitch(initial_scale_degree - i, 0);
      n[i].set_pitch(pitch);
   }

   return n;
}




