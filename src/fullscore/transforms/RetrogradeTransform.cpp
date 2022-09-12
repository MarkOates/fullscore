



#include <fullscore/transforms/RetrogradeTransform.hpp>

#include <fullscore/Transform.hpp>




Transform::Retrograde::Retrograde()
   : Base(Transform::RETROGRADE_TRANSFORM_IDENTIFIER)
{
}




Transform::Retrograde::~Retrograde()
{
}




std::vector<Note> Transform::Retrograde::transform(std::vector<Note> source)
{
   std::reverse(source.begin(), source.end());
   return source;
}




