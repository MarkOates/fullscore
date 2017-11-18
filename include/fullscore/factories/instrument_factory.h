#pragma once



#include <fullscore/models/staves/instrument.h>



class InstrumentFactory
{
public:
   Staff::Instrument *create_trombone();
   Staff::Instrument *create_bass_trombone();
   Staff::Instrument *create_euphonium();
   Staff::Instrument *create_tuba();

   Staff::Instrument *create_violin();
   Staff::Instrument *create_viola();
   Staff::Instrument *create_cello();
   Staff::Instrument *create_bass();
};



