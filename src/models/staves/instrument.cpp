


#include <fullscore/models/staves/Instrument.h>

#include <fullscore/models/measures/Base.h>
#include <fullscore/models/Measure.h>
#include <fullscore/models/Staff.h>
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



