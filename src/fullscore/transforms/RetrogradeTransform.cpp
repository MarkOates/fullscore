



#include <fullscore/Transforms/RetrogradeTransform.hpp>

#include <fullscore/TransformNames.hpp>




Transforms::Retrograde::Retrograde()
   : Base(TransformNames::RETROGRADE_TRANSFORM_IDENTIFIER)
{
}




Transforms::Retrograde::~Retrograde()
{
}




std::vector<Note> Transforms::Retrograde::transform(std::vector<Note> source)
{
   std::reverse(source.begin(), source.end());
   return source;
}




