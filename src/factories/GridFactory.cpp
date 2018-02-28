


#include <fullscore/factories/GridFactory.h>
#include <fullscore/factories/InstrumentFactory.h>
#include <fullscore/models/measures/Basic.h>
#include <fullscore/models/plotters/Basic.h>
#include <fullscore/models/plotters/Staff.hpp>
#include <fullscore/models/staves/HarmonicAnalysis.h>
#include <fullscore/models/staves/MeasureNumbers.h>
#include <fullscore/models/staves/Instrument.h>
#include <fullscore/models/staves/Spacer.h>
#include <fullscore/models/staves/Tempo.h>
#include <fullscore/models/Note.h>
#include <fullscore/selectors/InstrumentSelector.hpp>
#include <fullscore/transforms/HalfDurationTransform.h>
#include <fullscore/transforms/Octatonic1Transform.h>
#include <fullscore/transforms/RetrogradeTransform.h>
#include <fullscore/transforms/TransposeTransform.h>
#include <fullscore/InstrumentAttributes.h>
#include <allegro_flare/useful.h>
#include <iostream>



std::string const SPACER = "-";
std::string const MEASURE_NUMBERS = "#";
std::string const TEMPO = "!";
std::string const HARMONIC_ANALYSIS = "V";



static int __average_pitch(std::vector<Note> &notes)
{
   int sum = 0;
   for (auto &note : notes) sum = note.get_pitch().get_scale_degree() + note.get_pitch().get_accidental();
   return sum / notes.size();
}



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
   Grid grid(10);


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

   for (unsigned i=0; i<grid.get_num_barlines(); i++)
   {
      Plotter::Basic basic_plotter_1 = Plotter::Basic(&grid, i, notes_to_plot);
      basic_plotter_1.plot();
   }

   auto notes_retrograde = Transform::Retrograde().transform(notes_to_plot);

   Plotter::Basic basic_plotter_2 = Plotter::Basic(&grid, 5, notes_retrograde);
   basic_plotter_2.plot();


   return grid;
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

   Grid grid(12*4);


   InstrumentFactory instrument_factory;


   grid.append_staff(new Staff::MeasureNumbers);
   grid.append_staff(new Staff::Tempo);
   grid.append_staff(instrument_factory.create_flute());
   grid.append_staff(instrument_factory.create_oboe());
   grid.append_staff(instrument_factory.create_clarinet());
   grid.append_staff(instrument_factory.create_bassoon());
   grid.append_staff(new Staff::Spacer());
   grid.append_staff(instrument_factory.create_trumpet());
   grid.append_staff(instrument_factory.create_trumpet());
   grid.append_staff(instrument_factory.create_french_horn());
   grid.append_staff(instrument_factory.create_trombone());
   grid.append_staff(instrument_factory.create_bass_trombone());
   grid.append_staff(instrument_factory.create_tuba());
   grid.append_staff(new Staff::Spacer());
   grid.append_staff(instrument_factory.create_violin());
   grid.append_staff(instrument_factory.create_violin());
   grid.append_staff(instrument_factory.create_viola());
   grid.append_staff(instrument_factory.create_cello());
   grid.append_staff(instrument_factory.create_bass());

   Note rest_note = Note(0, Duration(Duration::QUARTER));
   rest_note.set_rest(true);

   std::vector<Note> notes_to_plot = {
      Note(-1, Duration(Duration::QUARTER)),
      Note(0, Duration(Duration::QUARTER)),
      Note(1, Duration(Duration::EIGHTH)),
      Note(2, Duration(Duration::EIGHTH)),
      rest_note,
   };

   std::vector<Note> octanotes = Transform::Retrograde().transform(Transform::HalfDuration().transform(Transform::Octatonic1().transform({})));
   std::vector<Note> octanotes_1 = Transform::Transpose(12).transform(octanotes);
   std::vector<Note> octanotes_2 = Transform::Transpose(24).transform(octanotes);
   std::vector<Note> octanotes_n1 = Transform::Transpose(-12).transform(octanotes);
   std::vector<Note> octanotes_n2 = Transform::Transpose(-24).transform(octanotes);

   auto notes_retrograde = Transform::Retrograde().transform(notes_to_plot);


   InstrumentSelector instrument_selector;

   std::vector<Staff::Instrument *> soprano_instruments = instrument_selector.soprano_voices();
   std::vector<Staff::Instrument *> alto_instruments = instrument_selector.alto_voices();
   std::vector<Staff::Instrument *> tenor_instruments = instrument_selector.tenor_voices();
   std::vector<Staff::Instrument *> baritone_instruments = instrument_selector.baritone_voices();
   std::vector<Staff::Instrument *> bass_instruments = instrument_selector.bass_voices();
   std::vector<Staff::Instrument *> tenor_and_baritone_instruments = instrument_selector.join({ tenor_instruments, baritone_instruments });

   std::vector<Staff::Instrument *> woodwind_instruments = instrument_selector.woodwinds();
   std::vector<Staff::Instrument *> brass_instruments = instrument_selector.brass();
   std::vector<Staff::Instrument *> string_instruments = instrument_selector.strings();

   std::vector<Staff::Instrument *> all_instruments = instrument_selector.instruments();

   std::vector<int> soprano_staff_ids = instrument_selector.ids(soprano_instruments);
   std::vector<int> alto_staff_ids = instrument_selector.ids(alto_instruments);

   std::vector<int> tenor_and_baritone_staff_ids = instrument_selector.ids(tenor_and_baritone_instruments);
   std::vector<int> bass_staff_ids = instrument_selector.ids(bass_instruments);

   std::vector<int> woodwind_staff_ids = instrument_selector.ids(woodwind_instruments);
   std::vector<int> brass_staff_ids = instrument_selector.ids(brass_instruments);
   std::vector<int> string_staff_ids = instrument_selector.ids(string_instruments);
   std::vector<int> all_instrument_staff_ids = instrument_selector.ids(all_instruments);

   int measure_cursor = 0;
   int interval = 2;

   for (unsigned barline_num=measure_cursor; barline_num<measure_cursor+interval; barline_num++)
   {
      Plotter::Staff staff_plotter = Plotter::Staff(soprano_staff_ids, barline_num, notes_to_plot);
      staff_plotter.plot();
   }

   measure_cursor += interval;

   for (unsigned barline_num=measure_cursor; barline_num<measure_cursor+interval; barline_num++)
   {
      Plotter::Staff staff_plotter = Plotter::Staff(alto_staff_ids, barline_num, notes_retrograde);
      staff_plotter.plot();
   }

   measure_cursor += interval;

   for (unsigned barline_num=measure_cursor; barline_num<measure_cursor+interval; barline_num++)
   {
      Plotter::Staff staff_plotter = Plotter::Staff(tenor_and_baritone_staff_ids, barline_num, notes_to_plot);
      staff_plotter.plot();
   }

   measure_cursor += interval;

   for (unsigned barline_num=measure_cursor; barline_num<measure_cursor+interval; barline_num++)
   {
      Plotter::Staff staff_plotter = Plotter::Staff(bass_staff_ids, barline_num, octanotes);
      staff_plotter.plot();
   }

   measure_cursor += interval;

   // by family

   for (unsigned barline_num=measure_cursor; barline_num<measure_cursor+interval; barline_num++)
   {
      Plotter::Staff staff_plotter = Plotter::Staff(woodwind_staff_ids, barline_num, octanotes);
      staff_plotter.plot();
   }

   measure_cursor += interval;

   for (unsigned barline_num=measure_cursor; barline_num<measure_cursor+interval; barline_num++)
   {
      Plotter::Staff staff_plotter = Plotter::Staff(brass_staff_ids, barline_num, octanotes);
      staff_plotter.plot();
   }

   measure_cursor += interval;

   for (unsigned barline_num=measure_cursor; barline_num<measure_cursor+interval; barline_num++)
   {
      Plotter::Staff staff_plotter = Plotter::Staff(string_staff_ids, barline_num, octanotes);
      staff_plotter.plot();
   }

   measure_cursor += interval;

   for (unsigned barline_num=measure_cursor; barline_num<measure_cursor+interval; barline_num++)
   {
      Plotter::Staff staff_plotter = Plotter::Staff(all_instrument_staff_ids, barline_num, octanotes);
      staff_plotter.plot();
   }

   std::vector<Staff::Instrument *> instruments_in_range;
   std::vector<Note> *notes;

   measure_cursor += interval;
   notes = &octanotes_2;
   for (unsigned barline_num=measure_cursor; barline_num<measure_cursor+interval; barline_num++)
   {
      int average_pitch = __average_pitch(*notes);
      instruments_in_range = instrument_selector.within_basic_range(average_pitch);
      std::vector<int> staff_ids = instrument_selector.ids(instruments_in_range);
      Plotter::Staff staff_plotter = Plotter::Staff(staff_ids, barline_num, *notes);
      staff_plotter.plot();
   }

   measure_cursor += interval;
   notes = &octanotes_1;
   for (unsigned barline_num=measure_cursor; barline_num<measure_cursor+interval; barline_num++)
   {
      int average_pitch = __average_pitch(*notes);
      instruments_in_range = instrument_selector.within_basic_range(average_pitch);
      std::vector<int> staff_ids = instrument_selector.ids(instruments_in_range);
      Plotter::Staff staff_plotter = Plotter::Staff(staff_ids, barline_num, *notes);
      staff_plotter.plot();
   }

   measure_cursor += interval;
   notes = &octanotes;
   for (unsigned barline_num=measure_cursor; barline_num<measure_cursor+interval; barline_num++)
   {
      int average_pitch = __average_pitch(*notes);
      instruments_in_range = instrument_selector.within_basic_range(average_pitch);
      std::vector<int> staff_ids = instrument_selector.ids(instruments_in_range);
      Plotter::Staff staff_plotter = Plotter::Staff(staff_ids, barline_num, *notes);
      staff_plotter.plot();
   }

   measure_cursor += interval;
   notes = &octanotes_n1;
   for (unsigned barline_num=measure_cursor; barline_num<measure_cursor+interval; barline_num++)
   {
      int average_pitch = __average_pitch(*notes);
      instruments_in_range = instrument_selector.within_basic_range(average_pitch);
      std::vector<int> staff_ids = instrument_selector.ids(instruments_in_range);
      Plotter::Staff staff_plotter = Plotter::Staff(staff_ids, barline_num, *notes);
      staff_plotter.plot();
   }

   measure_cursor += interval;
   notes = &octanotes_n2;
   for (unsigned barline_num=measure_cursor; barline_num<measure_cursor+interval; barline_num++)
   {
      int average_pitch = __average_pitch(*notes);
      instruments_in_range = instrument_selector.within_basic_range(average_pitch);
      std::vector<int> staff_ids = instrument_selector.ids(instruments_in_range);
      Plotter::Staff staff_plotter = Plotter::Staff(staff_ids, barline_num, *notes);
      staff_plotter.plot();
   }




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



