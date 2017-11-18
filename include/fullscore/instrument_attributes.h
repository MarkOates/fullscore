#pragma once



namespace InstrumentAttribute
{
   // Families

   std::string const FAMILY = "family";

   namespace Family
   {
      std::string const WOODWIND   = "woodwind";
      std::string const BRASS      = "brass";
      std::string const PERCUSSION = "percussion";
      std::string const STRING     = "string";
   }


   // Roles

   std::string const VOICE_ROLE   = "voice_role";

   namespace VoiceRole
   {
      std::string const SOPRANO  = "soprano";
      std::string const ALTO     = "alto";
      std::string const TENOR    = "tenor";
      std::string const BARITONE = "baritone";
      std::string const BASS     = "bass";
   }


   // Range

   std::string const COMFORTABLE_RANGE_MIN    = "comfortable_range_min";
   std::string const COMFORTABLE_RANGE_MAX    = "comfortable_range_max";
   std::string const EXTENDED_RANGE_MIN       = "extended_range_min";
   std::string const EXTENDED_RANGE_MAX       = "extended_range_max";
   std::string const HYPER_EXTENDED_RANGE_MIN = "hyper_extended_range_min";
   std::string const HYPER_EXTENDED_RANGE_MAX = "hyper_extended_range_max";


   // Range

   std::string const SMARTMUSIC_BASIC_RANGE_MIN        = "smartmusic_basic_range_min";
   std::string const SMARTMUSIC_BASIC_RANGE_MAX        = "smartmusic_basic_range_max";
   std::string const SMARTMUSIC_INTERMEDIATE_RANGE_MIN = "smartmusic_intermediate_range_min";
   std::string const SMARTMUSIC_INTERMEDIATE_RANGE_MAX = "smartmusic_intermediate_range_max";
   std::string const SMARTMUSIC_ADVANCED_RANGE_MIN     = "smartmusic_advanced_range_min";
   std::string const SMARTMUSIC_ADVANCED_RANGE_MAX     = "smartmusic_advanced_range_max";
   std::string const SMARTMUSIC_EXTENDED_RANGE_MIN     = "smartmusic_extended_range_min";
   std::string const SMARTMUSIC_EXTENDED_RANGE_MAX     = "smartmusic_extended_range_max";
}



