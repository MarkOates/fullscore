



#include <fullscore/transforms/retrograde.h>




Transform::Retrograde::Retrograde()
   : Base("retrograde")
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




