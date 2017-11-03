


#include <fullscore/models/staves/spacer.h>

#include <fullscore/models/measures/base.h>



Staff::Spacer::Spacer()
   : Base("spacer")
{}



Staff::Spacer::~Spacer()
{}



float Staff::Spacer::get_height()
{
   return 0.5;
}



