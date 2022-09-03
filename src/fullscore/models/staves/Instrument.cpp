


#include <fullscore/models/staves/Instrument.hpp>

#include <fullscore/models/measures/Base.hpp>
#include <fullscore/models/Measure.hpp>
#include <fullscore/models/Staff.hpp>
#include <algorithm>



Staff::Instrument::Instrument(std::string name)
   : Base(Staff::TYPE_IDENTIFIER_INSTRUMENT, name)
   , attributes()
{
}



Staff::Instrument::~Instrument()
{
   // This instrument may contain measure_ids that are no longer in use, they should be destroyed
}



float Staff::Instrument::get_height()
{
   return 1.0;
}



