


#include <fullscore/factories/grid_factory.h>
#include <fullscore/models/measures/basic.h>
#include <fullscore/models/plotters/basic.h>
#include <fullscore/models/staves/harmonic_analysis.h>
#include <fullscore/models/staves/measure_numbers.h>
#include <fullscore/models/staves/instrument.h>
#include <fullscore/models/staves/spacer.h>
#include <fullscore/models/staves/tempo.h>
#include <fullscore/models/Note.h>
#include <fullscore/transforms/retrograde_transform.h>
#include <allegro_flare/useful.h>
#include <iostream>



std::string const SPACER = "-";
std::string const MEASURE_NUMBERS = "#";
std::string const TEMPO = "!";
std::string const HARMONIC_ANALYSIS = "V";



Grid GridFactory::twinkle_twinkle_little_star()
{
   throw std::runtime_error("GridFactory::twinkle_twinkle_little_star() has been disabled");
}



Grid GridFactory::big_score()
{
   throw std::runtime_error("GridFactory::big_score() has been disabled");
}



Grid GridFactory::string_quartet()
{
   throw std::runtime_error("GridFactory::string_quartet() has been disabled");
}



Grid GridFactory::full_score()
{
   throw std::runtime_error("GridFactory::full_score() has been disabled");
}



Grid GridFactory::development()
{
   /*
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
   */



   /*
   Grid grid = create("full_score");


   std::vector<Note> notes_to_plot = {
      Note(-1, Duration(Duration::QUARTER, 1)),
      Note(0, Duration(Duration::QUARTER, 1)),
      Note(1, Duration(Duration::EIGHTH)),
      Note(2, Duration(Duration::EIGHTH)),
   };

   Plotter::Basic basic_plotter_1 = Plotter::Basic(&grid, 3, notes_to_plot);
   basic_plotter_1.plot();

   auto notes_retrograde = Transform::Retrograde().transform(notes_to_plot);

   Plotter::Basic basic_plotter_2 = Plotter::Basic(&grid, 5, notes_retrograde);
   basic_plotter_2.plot();
   */


/*
   Measure::Basic *basic_measure = new Measure::Basic({ Note(1), Note(-5), Note(3) });
   Staff::Base *staff_to_put_measure = Staff::find_first_of_type(Staff::TYPE_IDENTIFIER_INSTRUMENT);
   FloatingMeasure *floating_measure = new FloatingMeasure(GridCoordinate(&current_grid_editor->grid, staff_to_put_measure->get_id(), 2), basic_measure->get_id());
*/

   Grid grid;


   grid.append_staff(new Staff::MeasureNumbers);
   grid.append_staff(new Staff::Tempo);
   grid.append_staff(new Staff::Instrument("Flute I"));
   grid.append_staff(new Staff::Instrument("Flute II"));
   grid.append_staff(new Staff::Instrument("Oboe"));
   grid.append_staff(new Staff::Instrument("Bassoon"));
   grid.append_staff(new Staff::Instrument("Clarinet I"));
   grid.append_staff(new Staff::Instrument("Clarinet II"));
   grid.append_staff(new Staff::Spacer());
   grid.append_staff(new Staff::Instrument("Trumpet I"));
   grid.append_staff(new Staff::Instrument("Trumpet II"));
   grid.append_staff(new Staff::Instrument("F Horn I"));
   grid.append_staff(new Staff::Instrument("F Horn II"));
   grid.append_staff(new Staff::Instrument("Trombone I"));
   grid.append_staff(new Staff::Instrument("Trombone II"));
   grid.append_staff(new Staff::Instrument("Tuba"));
   grid.append_staff(new Staff::Spacer());
   grid.append_staff(new Staff::Instrument("Violin I"));
   grid.append_staff(new Staff::Instrument("Violin II"));
   grid.append_staff(new Staff::Instrument("Viola"));
   grid.append_staff(new Staff::Instrument("Cello"));
   grid.append_staff(new Staff::Instrument("Bass"));


   std::vector<Note> notes_to_plot = {
      Note(-1, Duration(Duration::QUARTER, 1)),
      Note(0, Duration(Duration::QUARTER, 1)),
      Note(1, Duration(Duration::EIGHTH)),
      Note(2, Duration(Duration::EIGHTH)),
   };

   Plotter::Basic basic_plotter_1 = Plotter::Basic(&grid, 3, notes_to_plot);
   basic_plotter_1.plot();

   auto notes_retrograde = Transform::Retrograde().transform(notes_to_plot);

   Plotter::Basic basic_plotter_2 = Plotter::Basic(&grid, 5, notes_retrograde);
   basic_plotter_2.plot();


   return grid;
}



Grid GridFactory::create(std::string identifier)
{
   if (identifier == "big_score") return big_score();
   if (identifier == "twinkle_twinkle") return twinkle_twinkle_little_star();
   if (identifier == "full_score") return full_score();
   if (identifier == "string_quartet") return string_quartet();
   if (identifier == "development") return development();

   std::cout << "Could not find score " << identifier << std::endl;
   return Grid();
}



