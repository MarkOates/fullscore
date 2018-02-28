

#include <fullscore/selectors/InstrumentSelector.hpp>

#include <fullscore/InstrumentAttributes.h>


InstrumentSelector::InstrumentSelector(std::vector<Staff::Base *> &pool)
   : pool(pool)
{
}


InstrumentSelector::~InstrumentSelector()
{
}


std::vector<Staff::Instrument *> InstrumentSelector::instruments()
{
   std::vector<Staff::Instrument *> results;

   for (auto &element : pool)
      if (element->is_type(Staff::TYPE_IDENTIFIER_INSTRUMENT))
         results.push_back(static_cast<Staff::Instrument *>(element));

   return results;
}


std::vector<Staff::Instrument *> InstrumentSelector::matches(std::string attribute, std::string property)
{
   std::vector<Staff::Instrument *> results;

   for (auto &element : pool)
   {
      if (element->is_type(Staff::TYPE_IDENTIFIER_INSTRUMENT) && static_cast<Staff::Instrument *>(element)->attributes.exists(attribute, property))
         results.push_back(static_cast<Staff::Instrument *>(element));
   }

   return results;
}


std::vector<Staff::Instrument *> InstrumentSelector::soprano_voices()
{
   return matches(InstrumentAttribute::VOICE_ROLE, InstrumentAttribute::VoiceRole::SOPRANO);
}


std::vector<Staff::Instrument *> InstrumentSelector::alto_voices()
{
   return matches(InstrumentAttribute::VOICE_ROLE, InstrumentAttribute::VoiceRole::ALTO);
}


std::vector<Staff::Instrument *> InstrumentSelector::tenor_voices()
{
   return matches(InstrumentAttribute::VOICE_ROLE, InstrumentAttribute::VoiceRole::TENOR);
}


std::vector<Staff::Instrument *> InstrumentSelector::baritone_voices()
{
   return matches(InstrumentAttribute::VOICE_ROLE, InstrumentAttribute::VoiceRole::BARITONE);
}


std::vector<Staff::Instrument *> InstrumentSelector::bass_voices()
{
   return matches(InstrumentAttribute::VOICE_ROLE, InstrumentAttribute::VoiceRole::BASS);
}


std::vector<Staff::Instrument *> InstrumentSelector::woodwinds()
{
   return matches(InstrumentAttribute::FAMILY, InstrumentAttribute::Family::WOODWIND);
}


std::vector<Staff::Instrument *> InstrumentSelector::brass()
{
   return matches(InstrumentAttribute::FAMILY, InstrumentAttribute::Family::BRASS);
}


std::vector<Staff::Instrument *> InstrumentSelector::strings()
{
   return matches(InstrumentAttribute::FAMILY, InstrumentAttribute::Family::STRING);
}


std::vector<Staff::Instrument *> InstrumentSelector::join(std::vector<std::vector<Staff::Instrument *>> instruments)
{
   std::vector<Staff::Instrument *> results;
   for (auto &instrs : instruments)
      for (auto &instrument : instrs)
      {
         results.push_back(instrument);
      }

   return std::vector<Staff::Instrument *>(results);
}


std::vector<int> InstrumentSelector::ids(std::vector<Staff::Instrument *> &instruments)
{
   std::vector<int> result_staff_ids;
   for (auto &instrument : instruments) result_staff_ids.push_back(instrument->get_id());
   return result_staff_ids;
}


