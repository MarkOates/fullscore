#pragma once


#include <fullscore/models/Staff.h>
#include <fullscore/models/staves/Instrument.h>


class InstrumentSelector
{
private:
   std::vector<Staff::Base *> &pool;

public:
   InstrumentSelector(std::vector<Staff::Base *> &pool=Staff::pool);
   ~InstrumentSelector();

   std::vector<Staff::Instrument *> instruments();
   std::vector<Staff::Instrument *> matches(std::string attribute, std::string property);

   std::vector<Staff::Instrument *> soprano_voices();
   std::vector<Staff::Instrument *> alto_voices();
   std::vector<Staff::Instrument *> tenor_voices();
   std::vector<Staff::Instrument *> baritone_voices();
   std::vector<Staff::Instrument *> bass_voices();

   std::vector<Staff::Instrument *> woodwinds();
   std::vector<Staff::Instrument *> brass();
   std::vector<Staff::Instrument *> strings();

   std::vector<Staff::Instrument *> join(std::vector<std::vector<Staff::Instrument *>> instruments);

   std::vector<int> ids(std::vector<Staff::Instrument *> &instruments);
};


