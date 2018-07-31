

#include <fullscore/selectors/instrument_selector/Interface.hpp>


namespace InstrumentSelector
{


Interface::Interface(std::string name, std::vector<Staff::Base *> &pool)
   : name(name)
   , pool(pool)
{
}


Interface::~Interface()
{
}


}


