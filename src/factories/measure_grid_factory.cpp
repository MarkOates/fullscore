


#include <fullscore/factories/measure_grid_factory.h>
#include <fullscore/models/measures/basic.h>
#include <fullscore/models/staves/measure_numbers.h>
#include <fullscore/models/staves/instrument.h>
#include <fullscore/models/staves/spacer.h>
#include <fullscore/models/note.h>
#include <allegro_flare/useful.h>
#include <iostream>



std::string const SPACER = "-";
std::string const MEASURE_NUMBERS = "#";



MeasureGrid MeasureGridFactory::twinkle_twinkle_little_star()
{
   MeasureGrid measure_grid(4, 2);

   // twinkle twinkle, little star
   measure_grid.set_measure(0,0, new Measure::Basic({ Note(0), Note(0), Note(4), Note(4) }));
   measure_grid.set_measure(1,0, new Measure::Basic({ Note(5), Note(5), Note(4, Duration::HALF) }));
   measure_grid.set_measure(2,0, new Measure::Basic({ Note(3), Note(3), Note(2), Note(2) }));
   measure_grid.set_measure(3,0, new Measure::Basic({ Note(1), Note(1), Note(0, Duration::HALF) }));

   for (int i=0; i<measure_grid.get_num_staves(); i++)
      measure_grid.set_voice_name(i, tostring("Voice ") + tostring(i));

   return measure_grid;
}



MeasureGrid MeasureGridFactory::big_score()
{
   MeasureGrid measure_grid(60, 12);

   for (int i=0; i<measure_grid.get_num_staves(); i++)
      measure_grid.set_voice_name(i, tostring("Voice ") + tostring(i));

   return measure_grid;
}



MeasureGrid MeasureGridFactory::full_score()
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

   MeasureGrid measure_grid(NUM_MEASURES, 0);

   for (int i=0; i<voices.size(); i++)
   {
      if (voices[i] == MEASURE_NUMBERS)
      {
         measure_grid.append_staff(new Staff::MeasureNumbers(NUM_MEASURES));
      }
      if (voices[i] == SPACER)
      {
         measure_grid.append_staff(new Staff::Spacer(NUM_MEASURES));
      }
      else
      {
         measure_grid.append_staff(new Staff::Instrument(NUM_MEASURES));
         measure_grid.set_voice_name(i, voices[i]);
      }
   }

   return measure_grid;
}



MeasureGrid MeasureGridFactory::create(std::string identifier)
{
   if (identifier == "big_score") return big_score();
   if (identifier == "twinkle_twinkle") return twinkle_twinkle_little_star();
   if (identifier == "full_score") return full_score();

   std::cout << "Could not find score " << identifier << std::endl;
   return MeasureGrid(4, 1);
}



