


#include <fullscore/factories/instrument_factory.h>

#include <fullscore/converters/scientific_pitch_notation_to_pitch_converter.h>
#include <fullscore/instrument_attributes.h>



Staff::Instrument *InstrumentFactory::create_trombone()
{
   Staff::Instrument *instrument = new Staff::Instrument("Trombone");

   // lineage
   instrument->attributes.set(InstrumentAttribute::FAMILY, InstrumentAttribute::Family::BRASS);

   // roles
   instrument->attributes.set(InstrumentAttribute::VOICE_ROLE, InstrumentAttribute::VoiceRole::TENOR);

   // range
   instrument->attributes.set(InstrumentAttribute::COMFORTABLE_RANGE_MIN, SPNToPitchConverter('F', 2).convert());
   instrument->attributes.set(InstrumentAttribute::COMFORTABLE_RANGE_MAX, SPNToPitchConverter('F', 4).convert());
   instrument->attributes.set(InstrumentAttribute::EXTENDED_RANGE_MIN, SPNToPitchConverter('G', 1).convert());
   instrument->attributes.set(InstrumentAttribute::EXTENDED_RANGE_MAX, SPNToPitchConverter('B', 4, -1).convert());
   instrument->attributes.set(InstrumentAttribute::HYPER_EXTENDED_RANGE_MIN, SPNToPitchConverter('F', 1).convert());
   instrument->attributes.set(InstrumentAttribute::HYPER_EXTENDED_RANGE_MAX, SPNToPitchConverter('D', 5).convert());

   return instrument;
}



Staff::Instrument *InstrumentFactory::create_euphonium()
{
   Staff::Instrument *instrument = new Staff::Instrument("Euphonium");

   // lineage
   instrument->attributes.set(InstrumentAttribute::FAMILY, InstrumentAttribute::Family::BRASS);

   // roles
   instrument->attributes.set(InstrumentAttribute::VOICE_ROLE, InstrumentAttribute::VoiceRole::TENOR);

   // range
   instrument->attributes.set(InstrumentAttribute::COMFORTABLE_RANGE_MIN, SPNToPitchConverter('G', 2).convert());
   instrument->attributes.set(InstrumentAttribute::COMFORTABLE_RANGE_MAX, SPNToPitchConverter('F', 4).convert());
   instrument->attributes.set(InstrumentAttribute::EXTENDED_RANGE_MIN, SPNToPitchConverter('E', 2, -1).convert());
   instrument->attributes.set(InstrumentAttribute::EXTENDED_RANGE_MAX, SPNToPitchConverter('A', 4, -1).convert());
   instrument->attributes.set(InstrumentAttribute::HYPER_EXTENDED_RANGE_MIN, SPNToPitchConverter('G', 1, -1).convert());
   instrument->attributes.set(InstrumentAttribute::HYPER_EXTENDED_RANGE_MAX, SPNToPitchConverter('C', 5).convert());

   return instrument;
}



