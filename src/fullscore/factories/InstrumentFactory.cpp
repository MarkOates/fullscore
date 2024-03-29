


#include <fullscore/factories/InstrumentFactory.hpp>

#include <fullscore/converters/ScientificPitchNotationToPitchConverter.hpp>
#include <fullscore/InstrumentAttributeNames.hpp>



Staff::Instrument *InstrumentFactory::create_flute()
{
   Staff::Instrument *instrument = new Staff::Instrument("Flute");

   // lineage
   instrument->attributes.set(InstrumentAttributeNames::FAMILY, InstrumentAttributeNames::Family::WOODWIND);

   // roles
   instrument->attributes.set(InstrumentAttributeNames::VOICE_ROLE, InstrumentAttributeNames::VoiceRole::SOPRANO);

   // transposition & clef
   instrument->attributes.set(InstrumentAttributeNames::DEFAULT_CLEF, InstrumentAttributeNames::TREBLE_CLEF);
   instrument->attributes.set(InstrumentAttributeNames::TRANSPOSITION_CONCERT_TO_WRITTEN_PITCH, 0);

   return instrument;
}



Staff::Instrument *InstrumentFactory::create_clarinet()
{
   Staff::Instrument *instrument = new Staff::Instrument("Clarinet");

   // lineage
   instrument->attributes.set(InstrumentAttributeNames::FAMILY, InstrumentAttributeNames::Family::WOODWIND);

   // roles
   instrument->attributes.set(InstrumentAttributeNames::VOICE_ROLE, InstrumentAttributeNames::VoiceRole::ALTO);

   // transposition & clef
   instrument->attributes.set(InstrumentAttributeNames::DEFAULT_CLEF, InstrumentAttributeNames::TREBLE_CLEF);
   instrument->attributes.set(InstrumentAttributeNames::TRANSPOSITION_CONCERT_TO_WRITTEN_PITCH, 2);

   return instrument;
}



Staff::Instrument *InstrumentFactory::create_oboe()
{
   Staff::Instrument *instrument = new Staff::Instrument("Oboe");

   // lineage
   instrument->attributes.set(InstrumentAttributeNames::FAMILY, InstrumentAttributeNames::Family::WOODWIND);

   // roles
   instrument->attributes.set(InstrumentAttributeNames::VOICE_ROLE, InstrumentAttributeNames::VoiceRole::SOPRANO);

   // transposition & clef
   instrument->attributes.set(InstrumentAttributeNames::DEFAULT_CLEF, InstrumentAttributeNames::TREBLE_CLEF);
   instrument->attributes.set(InstrumentAttributeNames::TRANSPOSITION_CONCERT_TO_WRITTEN_PITCH, 0);

   return instrument;
}



Staff::Instrument *InstrumentFactory::create_bassoon()
{
   Staff::Instrument *instrument = new Staff::Instrument("Bassoon");

   // lineage
   instrument->attributes.set(InstrumentAttributeNames::FAMILY, InstrumentAttributeNames::Family::WOODWIND);

   // roles
   instrument->attributes.set(InstrumentAttributeNames::VOICE_ROLE, InstrumentAttributeNames::VoiceRole::TENOR);

   // transposition & clef
   instrument->attributes.set(InstrumentAttributeNames::DEFAULT_CLEF, InstrumentAttributeNames::BASS_CLEF);
   instrument->attributes.set(InstrumentAttributeNames::TRANSPOSITION_CONCERT_TO_WRITTEN_PITCH, 0);

   return instrument;
}



Staff::Instrument *InstrumentFactory::create_trumpet()
{
   Staff::Instrument *instrument = new Staff::Instrument("Trumpet");

   // lineage
   instrument->attributes.set(InstrumentAttributeNames::FAMILY, InstrumentAttributeNames::Family::BRASS);

   // roles
   instrument->attributes.set(InstrumentAttributeNames::VOICE_ROLE, InstrumentAttributeNames::VoiceRole::SOPRANO);

   // transposition & clef
   instrument->attributes.set(InstrumentAttributeNames::DEFAULT_CLEF, InstrumentAttributeNames::TREBLE_CLEF);
   instrument->attributes.set(InstrumentAttributeNames::TRANSPOSITION_CONCERT_TO_WRITTEN_PITCH, 2);

   return instrument;
}



Staff::Instrument *InstrumentFactory::create_french_horn()
{
   Staff::Instrument *instrument = new Staff::Instrument("French Horn");

   // lineage
   instrument->attributes.set(InstrumentAttributeNames::FAMILY, InstrumentAttributeNames::Family::BRASS);

   // roles
   instrument->attributes.set(InstrumentAttributeNames::VOICE_ROLE, InstrumentAttributeNames::VoiceRole::ALTO);

   // transposition & clef
   instrument->attributes.set(InstrumentAttributeNames::DEFAULT_CLEF, InstrumentAttributeNames::TREBLE_CLEF);
   instrument->attributes.set(InstrumentAttributeNames::TRANSPOSITION_CONCERT_TO_WRITTEN_PITCH, 7);

   return instrument;
}



Staff::Instrument *InstrumentFactory::create_trombone()
{
   Staff::Instrument *instrument = new Staff::Instrument("Trombone");

   // lineage
   instrument->attributes.set(InstrumentAttributeNames::FAMILY, InstrumentAttributeNames::Family::BRASS);

   // roles
   instrument->attributes.set(InstrumentAttributeNames::VOICE_ROLE, InstrumentAttributeNames::VoiceRole::TENOR);

   // transposition & clef
   instrument->attributes.set(InstrumentAttributeNames::DEFAULT_CLEF, InstrumentAttributeNames::BASS_CLEF);
   instrument->attributes.set(InstrumentAttributeNames::TRANSPOSITION_CONCERT_TO_WRITTEN_PITCH, 0);

   // range
   instrument->attributes.set(InstrumentAttributeNames::COMFORTABLE_RANGE_MIN, SPNToPitchConverter('F', 2).convert());
   instrument->attributes.set(InstrumentAttributeNames::COMFORTABLE_RANGE_MAX, SPNToPitchConverter('F', 4).convert());
   instrument->attributes.set(InstrumentAttributeNames::EXTENDED_RANGE_MIN, SPNToPitchConverter('G', 1).convert());
   instrument->attributes.set(InstrumentAttributeNames::EXTENDED_RANGE_MAX, SPNToPitchConverter('B', 4, -1).convert());
   instrument->attributes.set(InstrumentAttributeNames::HYPER_EXTENDED_RANGE_MIN, SPNToPitchConverter('F', 1).convert());
   instrument->attributes.set(InstrumentAttributeNames::HYPER_EXTENDED_RANGE_MAX, SPNToPitchConverter('D', 5).convert());

   // SmartMusic ranges
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_BASIC_RANGE_MIN, SPNToPitchConverter('G', 2, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_BASIC_RANGE_MAX, SPNToPitchConverter('D', 4, 0).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_INTERMEDIATE_RANGE_MIN, SPNToPitchConverter('E', 2, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_INTERMEDIATE_RANGE_MAX, SPNToPitchConverter('F', 4, 0).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_ADVANCED_RANGE_MIN, SPNToPitchConverter('E', 2, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_ADVANCED_RANGE_MAX, SPNToPitchConverter('B', 4, -1).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_EXTENDED_RANGE_MIN, SPNToPitchConverter('G', 1, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_EXTENDED_RANGE_MAX, SPNToPitchConverter('F', 5, 0).convert());

   return instrument;
}



Staff::Instrument *InstrumentFactory::create_bass_trombone()
{
   Staff::Instrument *instrument = new Staff::Instrument("Bass Trombone");

   // lineage
   instrument->attributes.set(InstrumentAttributeNames::FAMILY, InstrumentAttributeNames::Family::BRASS);

   // roles
   instrument->attributes.set(InstrumentAttributeNames::VOICE_ROLE, InstrumentAttributeNames::VoiceRole::BASS);

   // transposition & clef
   instrument->attributes.set(InstrumentAttributeNames::DEFAULT_CLEF, InstrumentAttributeNames::BASS_CLEF);
   instrument->attributes.set(InstrumentAttributeNames::TRANSPOSITION_CONCERT_TO_WRITTEN_PITCH, 0);

   // SmartMusic ranges
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_BASIC_RANGE_MIN, SPNToPitchConverter('G', 2, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_BASIC_RANGE_MAX, SPNToPitchConverter('D', 4, 0).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_INTERMEDIATE_RANGE_MIN, SPNToPitchConverter('C', 2, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_INTERMEDIATE_RANGE_MAX, SPNToPitchConverter('F', 4, 0).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_ADVANCED_RANGE_MIN, SPNToPitchConverter('B', 1, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_ADVANCED_RANGE_MAX, SPNToPitchConverter('B', 4, -1).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_EXTENDED_RANGE_MIN, SPNToPitchConverter('G', 1, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_EXTENDED_RANGE_MAX, SPNToPitchConverter('F', 5, 0).convert());

   return instrument;
}



Staff::Instrument *InstrumentFactory::create_euphonium()
{
   Staff::Instrument *instrument = new Staff::Instrument("Euphonium");

   // lineage
   instrument->attributes.set(InstrumentAttributeNames::FAMILY, InstrumentAttributeNames::Family::BRASS);

   // roles
   instrument->attributes.set(InstrumentAttributeNames::VOICE_ROLE, InstrumentAttributeNames::VoiceRole::TENOR);

   // transposition & clef
   instrument->attributes.set(InstrumentAttributeNames::DEFAULT_CLEF, InstrumentAttributeNames::BASS_CLEF);
   instrument->attributes.set(InstrumentAttributeNames::TRANSPOSITION_CONCERT_TO_WRITTEN_PITCH, 0);

   // range
   instrument->attributes.set(InstrumentAttributeNames::COMFORTABLE_RANGE_MIN, SPNToPitchConverter('G', 2).convert());
   instrument->attributes.set(InstrumentAttributeNames::COMFORTABLE_RANGE_MAX, SPNToPitchConverter('F', 4).convert());
   instrument->attributes.set(InstrumentAttributeNames::EXTENDED_RANGE_MIN, SPNToPitchConverter('E', 2, -1).convert());
   instrument->attributes.set(InstrumentAttributeNames::EXTENDED_RANGE_MAX, SPNToPitchConverter('A', 4, -1).convert());
   instrument->attributes.set(InstrumentAttributeNames::HYPER_EXTENDED_RANGE_MIN, SPNToPitchConverter('G', 1, -1).convert());
   instrument->attributes.set(InstrumentAttributeNames::HYPER_EXTENDED_RANGE_MAX, SPNToPitchConverter('C', 5).convert());

   // SmartMusic ranges
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_BASIC_RANGE_MIN, SPNToPitchConverter('G', 2, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_BASIC_RANGE_MAX, SPNToPitchConverter('D', 4, 0).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_INTERMEDIATE_RANGE_MIN, SPNToPitchConverter('E', 2, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_INTERMEDIATE_RANGE_MAX, SPNToPitchConverter('F', 4, 0).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_ADVANCED_RANGE_MIN, SPNToPitchConverter('E', 2, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_ADVANCED_RANGE_MAX, SPNToPitchConverter('B', 4, -1).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_EXTENDED_RANGE_MIN, SPNToPitchConverter('B', 1, -1).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_EXTENDED_RANGE_MAX, SPNToPitchConverter('F', 5, 0).convert());

   return instrument;
}



Staff::Instrument *InstrumentFactory::create_tuba()
{
   Staff::Instrument *instrument = new Staff::Instrument("Tuba");

   // lineage
   instrument->attributes.set(InstrumentAttributeNames::FAMILY, InstrumentAttributeNames::Family::BRASS);

   // roles
   instrument->attributes.set(InstrumentAttributeNames::VOICE_ROLE, InstrumentAttributeNames::VoiceRole::BASS);

   // transposition & clef
   instrument->attributes.set(InstrumentAttributeNames::DEFAULT_CLEF, InstrumentAttributeNames::BASS_CLEF);
   instrument->attributes.set(InstrumentAttributeNames::TRANSPOSITION_CONCERT_TO_WRITTEN_PITCH, 0);

   // SmartMusic ranges
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_BASIC_RANGE_MIN, SPNToPitchConverter('G', 1, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_BASIC_RANGE_MAX, SPNToPitchConverter('D', 3, 0).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_INTERMEDIATE_RANGE_MIN, SPNToPitchConverter('E', 1, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_INTERMEDIATE_RANGE_MAX, SPNToPitchConverter('F', 3, 0).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_ADVANCED_RANGE_MIN, SPNToPitchConverter('E', 1, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_ADVANCED_RANGE_MAX, SPNToPitchConverter('B', 3, -1).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_EXTENDED_RANGE_MIN, SPNToPitchConverter('C', 1, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_EXTENDED_RANGE_MAX, SPNToPitchConverter('F', 4, 0).convert());

   return instrument;
}



Staff::Instrument *InstrumentFactory::create_violin()
{
   Staff::Instrument *instrument = new Staff::Instrument("Violin");

   // lineage
   instrument->attributes.set(InstrumentAttributeNames::FAMILY, InstrumentAttributeNames::Family::STRING);

   // roles
   instrument->attributes.set(InstrumentAttributeNames::VOICE_ROLE, InstrumentAttributeNames::VoiceRole::SOPRANO);

   // transposition & clef
   instrument->attributes.set(InstrumentAttributeNames::DEFAULT_CLEF, InstrumentAttributeNames::TREBLE_CLEF);
   instrument->attributes.set(InstrumentAttributeNames::TRANSPOSITION_CONCERT_TO_WRITTEN_PITCH, 0);

   // SmartMusic ranges
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_BASIC_RANGE_MIN, SPNToPitchConverter('G', 3, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_BASIC_RANGE_MAX, SPNToPitchConverter('B', 5, 0).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_INTERMEDIATE_RANGE_MIN, SPNToPitchConverter('G', 3, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_INTERMEDIATE_RANGE_MAX, SPNToPitchConverter('D', 6, 0).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_ADVANCED_RANGE_MIN, SPNToPitchConverter('G', 3, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_ADVANCED_RANGE_MAX, SPNToPitchConverter('E', 7, 0).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_EXTENDED_RANGE_MIN, SPNToPitchConverter('G', 3, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_EXTENDED_RANGE_MAX, SPNToPitchConverter('E', 7, 0).convert());

   return instrument;
}



Staff::Instrument *InstrumentFactory::create_viola()
{
   Staff::Instrument *instrument = new Staff::Instrument("Viola");

   // lineage
   instrument->attributes.set(InstrumentAttributeNames::FAMILY, InstrumentAttributeNames::Family::STRING);

   // roles
   instrument->attributes.set(InstrumentAttributeNames::VOICE_ROLE, InstrumentAttributeNames::VoiceRole::ALTO);

   // transposition & clef
   instrument->attributes.set(InstrumentAttributeNames::DEFAULT_CLEF, InstrumentAttributeNames::ALTO_CLEF);
   instrument->attributes.set(InstrumentAttributeNames::TRANSPOSITION_CONCERT_TO_WRITTEN_PITCH, 0);

   // SmartMusic ranges
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_BASIC_RANGE_MIN, SPNToPitchConverter('C', 3, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_BASIC_RANGE_MAX, SPNToPitchConverter('E', 5, 0).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_INTERMEDIATE_RANGE_MIN, SPNToPitchConverter('C', 3, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_INTERMEDIATE_RANGE_MAX, SPNToPitchConverter('G', 5, 0).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_ADVANCED_RANGE_MIN, SPNToPitchConverter('C', 3, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_ADVANCED_RANGE_MAX, SPNToPitchConverter('B', 5, 0).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_EXTENDED_RANGE_MIN, SPNToPitchConverter('C', 3, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_EXTENDED_RANGE_MAX, SPNToPitchConverter('F', 6, 0).convert());

   return instrument;
}



Staff::Instrument *InstrumentFactory::create_cello()
{
   Staff::Instrument *instrument = new Staff::Instrument("Cello");

   // lineage
   instrument->attributes.set(InstrumentAttributeNames::FAMILY, InstrumentAttributeNames::Family::STRING);

   // roles
   instrument->attributes.set(InstrumentAttributeNames::VOICE_ROLE, InstrumentAttributeNames::VoiceRole::BARITONE);

   // transposition & clef
   instrument->attributes.set(InstrumentAttributeNames::DEFAULT_CLEF, InstrumentAttributeNames::BASS_CLEF);
   instrument->attributes.set(InstrumentAttributeNames::TRANSPOSITION_CONCERT_TO_WRITTEN_PITCH, 0);

   // SmartMusic ranges
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_BASIC_RANGE_MIN, SPNToPitchConverter('C', 2, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_BASIC_RANGE_MAX, SPNToPitchConverter('D', 4, 0).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_INTERMEDIATE_RANGE_MIN, SPNToPitchConverter('C', 2, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_INTERMEDIATE_RANGE_MAX, SPNToPitchConverter('G', 4, 0).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_ADVANCED_RANGE_MIN, SPNToPitchConverter('C', 2, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_ADVANCED_RANGE_MAX, SPNToPitchConverter('G', 5, 0).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_EXTENDED_RANGE_MIN, SPNToPitchConverter('C', 2, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_EXTENDED_RANGE_MAX, SPNToPitchConverter('G', 5, 0).convert());

   return instrument;
}



Staff::Instrument *InstrumentFactory::create_bass()
{
   Staff::Instrument *instrument = new Staff::Instrument("Contrabass");

   // lineage
   instrument->attributes.set(InstrumentAttributeNames::FAMILY, InstrumentAttributeNames::Family::STRING);

   // roles
   instrument->attributes.set(InstrumentAttributeNames::VOICE_ROLE, InstrumentAttributeNames::VoiceRole::BASS);

   // transposition & clef
   instrument->attributes.set(InstrumentAttributeNames::DEFAULT_CLEF, InstrumentAttributeNames::BASS_CLEF);
   instrument->attributes.set(InstrumentAttributeNames::TRANSPOSITION_CONCERT_TO_WRITTEN_PITCH, 12);

   // SmartMusic ranges
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_BASIC_RANGE_MIN, SPNToPitchConverter('E', 2, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_BASIC_RANGE_MAX, SPNToPitchConverter('C', 4, 0).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_INTERMEDIATE_RANGE_MIN, SPNToPitchConverter('E', 2, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_INTERMEDIATE_RANGE_MAX, SPNToPitchConverter('F', 4, 0).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_ADVANCED_RANGE_MIN, SPNToPitchConverter('E', 2, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_ADVANCED_RANGE_MAX, SPNToPitchConverter('D', 5, 0).convert());

   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_EXTENDED_RANGE_MIN, SPNToPitchConverter('E', 2, 0).convert());
   instrument->attributes.set(InstrumentAttributeNames::SMARTMUSIC_EXTENDED_RANGE_MAX, SPNToPitchConverter('D', 5, 0).convert());

   return instrument;
}



