


#include <fullscore/models/staves/Spacer.hpp>

#include <fullscore/models/measures/Base.hpp>



Staff::Spacer::Spacer()
   : Base("spacer")
{}



Staff::Spacer::~Spacer()
{}



float Staff::Spacer::get_height()
{
   return 0.5;
}



