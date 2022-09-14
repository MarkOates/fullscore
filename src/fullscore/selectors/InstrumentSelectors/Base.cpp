

#include <fullscore/selectors/InstrumentSelectors/Base.hpp>


namespace InstrumentSelectors
{


Base::Base(std::string name, std::vector<Staff::Base *> &pool)
   : name(name)
   , pool(pool)
{
}


Base::~Base()
{
}


}


