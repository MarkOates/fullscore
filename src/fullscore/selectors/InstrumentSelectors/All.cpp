

#include <fullscore/selectors/InstrumentSelectors/All.hpp>


namespace InstrumentSelectors
{


All::All(std::vector<Staff::Base *> &pool)
   : Base("all", pool)
{
}


All::~All()
{
}


std::vector<Staff::Base *> All::select()
{
   return pool;
}


};


