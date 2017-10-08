


#include <fullscore/factories/grid_factory.h>
#include <fullscore/models/measures/basic.h>
#include <fullscore/models/staves/harmonic_analysis.h>
#include <fullscore/models/staves/measure_numbers.h>
#include <fullscore/models/staves/instrument.h>
#include <fullscore/models/staves/spacer.h>
#include <fullscore/models/staves/tempo.h>
#include <fullscore/models/Note.h>
#include <allegro_flare/useful.h>
#include <iostream>



std::string const SPACER = "-";
std::string const MEASURE_NUMBERS = "#";
std::string const TEMPO = "!";
std::string const HARMONIC_ANALYSIS = "V";



Grid GridFactory::twinkle_twinkle_little_star()
{
   Grid grid(4, 2);

   // twinkle twinkle, little star
   grid.set_measure(0,0, new Measure::Basic({ Note(0), Note(0), Note(4), Note(4) }));
   grid.set_measure(1,0, new Measure::Basic({ Note(5), Note(5), Note(4, Duration::HALF) }));
   grid.set_measure(2,0, new Measure::Basic({ Note(3), Note(3), Note(2), Note(2) }));
   grid.set_measure(3,0, new Measure::Basic({ Note(1), Note(1), Note(0, Duration::HALF) }));

   for (int i=0; i<grid.get_num_staves(); i++)
      grid.set_voice_name(i, tostring("Voice ") + tostring(i));

   return grid;
}



Grid GridFactory::big_score()
{
   Grid grid(60, 12);

   for (int i=0; i<grid.get_num_staves(); i++)
      grid.set_voice_name(i, tostring("Voice ") + tostring(i));

   return grid;
}



Grid GridFactory::string_quartet()
{
   std::vector<std::string> voices = {
      MEASURE_NUMBERS,
      TEMPO,
      "Violin I",
      "Violin II",
      "Viola",
      "Cello",
      HARMONIC_ANALYSIS,
   };

   const int NUM_MEASURES = 20;

   Grid grid(NUM_MEASURES, 0);

   for (int i=0; i<voices.size(); i++)
   {
      if (voices[i] == MEASURE_NUMBERS)
      {
         grid.append_staff(new Staff::MeasureNumbers(NUM_MEASURES));
      }
      else if (voices[i] == SPACER)
      {
         grid.append_staff(new Staff::Spacer(NUM_MEASURES));
      }
      else if (voices[i] == HARMONIC_ANALYSIS)
      {
         Staff::HarmonicAnalysis *staff = new Staff::HarmonicAnalysis(NUM_MEASURES);
         grid.append_staff(staff);

         staff->set_symbol(
            GridHorizontalCoordinate(0, 0),
            HarmonicAnalysisSymbol(Pitch(6, -1), HarmonicAnalysisSymbol::DIMINISHED, 1, {})
         );

         staff->set_symbol(
            GridHorizontalCoordinate(1, 2),
            HarmonicAnalysisSymbol(Pitch(9, 0), HarmonicAnalysisSymbol::MAJOR, 1, {})
         );

         staff->set_symbol(
            GridHorizontalCoordinate(2, 0),
            HarmonicAnalysisSymbol(Pitch(10, 0), HarmonicAnalysisSymbol::MINOR, 1, {})
         );

         staff->set_symbol(
            GridHorizontalCoordinate(3, 2),
            HarmonicAnalysisSymbol(Pitch(4, 0), HarmonicAnalysisSymbol::AUGMENTED, 1, {})
         );

         staff->set_symbol(
            GridHorizontalCoordinate(4, 0),
            HarmonicAnalysisSymbol(Pitch(3, 0), HarmonicAnalysisSymbol::MAJOR, 1, {})
         );
      }
      else if (voices[i] == TEMPO)
      {
         Staff::Tempo *tempo_staff = new Staff::Tempo(NUM_MEASURES);
         grid.append_staff(tempo_staff);
         TempoMarking tempo_marking(Duration(Duration::QUARTER), 128);
         tempo_staff->set_tempo_marking(0, 0, tempo_marking);
      }
      else
      {
         grid.append_staff(new Staff::Instrument(NUM_MEASURES));
         grid.set_voice_name(i, voices[i]);
      }
   }

   return grid;
}



Grid GridFactory::full_score()
{
   std::vector<std::string> voices = {
      MEASURE_NUMBERS,
      "Flute I",
      "Flute II",
      "Flute III",
      SPACER,
      "Oboe",
      "English Horn",
      SPACER,
      "Clarinet I",
      "Clarinet II",
      "Clarinet III",
      SPACER,
      "Bassoon I",
      "Bassoon II",
      SPACER,
      SPACER,
      "Trumpet I",
      "Trumpet II",
      "Trumpet III",
      SPACER,
      "F Horn I",
      "F Horn II",
      "F Horn III",
      "F Horn IV",
      SPACER,
      "Trombone I",
      "Trombone II",
      "Trombone III",
      "Bass Trombone",
      SPACER,
      "Tuba",
      SPACER,
      SPACER,
      "Percussion I",
      "Percussion II",
      "Percussion III",
      SPACER,
      "Piano {Grand Staff}",
      SPACER,
      "Harp {Grand Staff}",
      SPACER,
      SPACER,
      "Violin I",
      "Violin II",
      "Viola",
      "Cello",
      "Bass",
   };

   const int NUM_MEASURES = 20;

   Grid grid(NUM_MEASURES, 0);

   for (int i=0; i<voices.size(); i++)
   {
      if (voices[i] == MEASURE_NUMBERS)
      {
         grid.append_staff(new Staff::MeasureNumbers(NUM_MEASURES));
      }
      else if (voices[i] == SPACER)
      {
         grid.append_staff(new Staff::Spacer(NUM_MEASURES));
      }
      else if (voices[i] == TEMPO)
      {
         grid.append_staff(new Staff::Tempo(NUM_MEASURES));
      }
      else
      {
         grid.append_staff(new Staff::Instrument(NUM_MEASURES));
         grid.set_voice_name(i, voices[i]);
      }
   }

   return grid;
}



Grid GridFactory::create(std::string identifier)
{
   if (identifier == "big_score") return big_score();
   if (identifier == "twinkle_twinkle") return twinkle_twinkle_little_star();
   if (identifier == "full_score") return full_score();
   if (identifier == "string_quartet") return string_quartet();

   std::cout << "Could not find score " << identifier << std::endl;
   return Grid(4, 1);
}



