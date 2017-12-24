


#include <fullscore/models/staves/Spacer.h>

#include <fullscore/models/measures/Base.h>



Staff::Spacer::Spacer()
   : Base("spacer")
{}



Staff::Spacer::~Spacer()
{}



float Staff::Spacer::get_height()
{
   return 0.5;
}



