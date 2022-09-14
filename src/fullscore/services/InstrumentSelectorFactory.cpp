

#include <fullscore/services/InstrumentSelectorFactory.hpp>

#include <fullscore/InstrumentAttributeNames.hpp>
#include <sstream>


InstrumentSelectorFactory::InstrumentSelectorFactory(std::vector<Staff::Base *> &pool)
   : pool(pool)
{
}


InstrumentSelectorFactory::~InstrumentSelectorFactory()
{
}


std::vector<Staff::Instrument *> InstrumentSelectorFactory::instruments()
{
   std::vector<Staff::Instrument *> results;

   for (auto &element : pool)
      if (element->is_type(StaffRepository::TYPE_IDENTIFIER_INSTRUMENT))
         results.push_back(static_cast<Staff::Instrument *>(element));

   return results;
}


std::vector<Staff::Instrument *> InstrumentSelectorFactory::matches(std::string attribute, std::string property)
{
   std::vector<Staff::Instrument *> results;

   for (auto &element : pool)
   {
      if (element->is_type(StaffRepository::TYPE_IDENTIFIER_INSTRUMENT) && static_cast<Staff::Instrument *>(element)->attributes.exists(attribute, property))
         results.push_back(static_cast<Staff::Instrument *>(element));
   }

   return results;
}


std::vector<Staff::Instrument *> InstrumentSelectorFactory::soprano_voices()
{
   return matches(InstrumentAttributeNames::VOICE_ROLE, InstrumentAttributeNames::VoiceRole::SOPRANO);
}


std::vector<Staff::Instrument *> InstrumentSelectorFactory::alto_voices()
{
   return matches(InstrumentAttributeNames::VOICE_ROLE, InstrumentAttributeNames::VoiceRole::ALTO);
}


std::vector<Staff::Instrument *> InstrumentSelectorFactory::tenor_voices()
{
   return matches(InstrumentAttributeNames::VOICE_ROLE, InstrumentAttributeNames::VoiceRole::TENOR);
}


std::vector<Staff::Instrument *> InstrumentSelectorFactory::baritone_voices()
{
   return matches(InstrumentAttributeNames::VOICE_ROLE, InstrumentAttributeNames::VoiceRole::BARITONE);
}


std::vector<Staff::Instrument *> InstrumentSelectorFactory::bass_voices()
{
   return matches(InstrumentAttributeNames::VOICE_ROLE, InstrumentAttributeNames::VoiceRole::BASS);
}


std::vector<Staff::Instrument *> InstrumentSelectorFactory::woodwinds()
{
   return matches(InstrumentAttributeNames::FAMILY, InstrumentAttributeNames::Family::WOODWIND);
}


std::vector<Staff::Instrument *> InstrumentSelectorFactory::brass()
{
   return matches(InstrumentAttributeNames::FAMILY, InstrumentAttributeNames::Family::BRASS);
}


std::vector<Staff::Instrument *> InstrumentSelectorFactory::strings()
{
   return matches(InstrumentAttributeNames::FAMILY, InstrumentAttributeNames::Family::STRING);
}


std::vector<Staff::Instrument *> InstrumentSelectorFactory::within_basic_range(int pitch)
{
   std::vector<Staff::Instrument *> results;
   std::vector<std::string> warnings;

   for (auto &element : pool)
      if (element->is_type(StaffRepository::TYPE_IDENTIFIER_INSTRUMENT))
      {
         Staff::Instrument *instrument = static_cast<Staff::Instrument *>(element);
         if (instrument->attributes.exists(InstrumentAttributeNames::SMARTMUSIC_BASIC_RANGE_MIN) && instrument->attributes.exists(InstrumentAttributeNames::SMARTMUSIC_BASIC_RANGE_MIN))
         {
            int range_min = instrument->attributes.get_as_int(InstrumentAttributeNames::SMARTMUSIC_BASIC_RANGE_MIN);
            int range_max = instrument->attributes.get_as_int(InstrumentAttributeNames::SMARTMUSIC_BASIC_RANGE_MAX);

            if (pitch >= range_min && pitch <= range_max) results.push_back(instrument);
         }
         else
         {
            std::stringstream warning_message;
            warning_message << "Instrument does not have expected range data: " << instrument->get_id();
            warnings.push_back(warning_message.str());
         }
      }

   return results;
}


std::vector<Staff::Instrument *> InstrumentSelectorFactory::join(std::vector<std::vector<Staff::Instrument *>> instruments)
{
   std::vector<Staff::Instrument *> results;
   for (auto &instrs : instruments)
      for (auto &instrument : instrs)
      {
         results.push_back(instrument);
      }

   return std::vector<Staff::Instrument *>(results);
}


std::vector<int> InstrumentSelectorFactory::ids(std::vector<Staff::Instrument *> &instruments)
{
   std::vector<int> result_staff_ids;
   for (auto &instrument : instruments) result_staff_ids.push_back(instrument->get_id());
   return result_staff_ids;
}


