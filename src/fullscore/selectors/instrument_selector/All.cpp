

#include <fullscore/selectors/instrument_selector/All.hpp>


namespace InstrumentSelector
{


All::All(std::vector<Staff::Base *> &pool)
   : Interface("all", pool)
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


