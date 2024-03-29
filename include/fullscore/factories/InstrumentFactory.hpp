#pragma once



#include <fullscore/models/staves/Instrument.hpp>


class InstrumentFactory
{
public:
   Staff::Instrument *create_flute();
   Staff::Instrument *create_clarinet();
   Staff::Instrument *create_oboe();
   Staff::Instrument *create_bassoon();

   Staff::Instrument *create_trumpet();
   Staff::Instrument *create_french_horn();
   Staff::Instrument *create_trombone();
   Staff::Instrument *create_bass_trombone();
   Staff::Instrument *create_euphonium();
   Staff::Instrument *create_tuba();

   Staff::Instrument *create_violin();
   Staff::Instrument *create_viola();
   Staff::Instrument *create_cello();
   Staff::Instrument *create_bass();
};



