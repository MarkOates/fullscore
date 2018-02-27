

#include <fullscore/selectors/InstrumentSelector.hpp>

#include <fullscore/InstrumentAttributes.h>


InstrumentSelector::InstrumentSelector(std::vector<Staff::Base *> &pool)
   : pool(pool)
{
}


InstrumentSelector::~InstrumentSelector()
{
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


std::vector<Staff::Instrument *> InstrumentSelector::bass_voices()
{
   return matches(InstrumentAttribute::VOICE_ROLE, InstrumentAttribute::VoiceRole::BASS);
}


std::vector<int> InstrumentSelector::ids(std::vector<Staff::Instrument *> &instruments)
{
   std::vector<int> result_staff_ids;
   for (auto &instrument : instruments) result_staff_ids.push_back(instrument->get_id());
   return result_staff_ids;
}


