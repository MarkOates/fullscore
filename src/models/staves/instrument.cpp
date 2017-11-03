


#include <fullscore/models/staves/instrument.h>

#include <fullscore/models/measures/base.h>
#include <fullscore/models/measure.h>
#include <fullscore/models/staff.h>
#include <algorithm>



Staff::Instrument::Instrument()
   : Base(Staff::TYPE_IDENTIFIER_INSTRUMENT)
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



