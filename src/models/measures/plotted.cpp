


#include <fullscore/models/measures/plotted.h>

#include <fullscore/models/measure.h>
#include <fullscore/models/Note.h>
#include <fullscore/models/plotters/base.h>
#include <allegro_flare/useful.h>



Measure::Plotted::Plotted(Plotter *plotter)
   : Base(Measure::TYPE_IDENTIFIER_PLOTTED)
   , plotter(plotter)
{}



std::vector<Note> Measure::Plotted::get_plotted_notes()
{
   if (!plotter)
   {
      Note returned_note = Note(0, Duration::WHOLE);
      returned_note.is_rest = true;
      return { returned_note };
   }

   // some placeholder code
   if (plotter->num_destinations() == 0) throw std::runtime_error("Plotted measure cannot exist without destinations.");

   std::vector<GridCoordinate> plotter_destinations = plotter->get_destinations();
   std::vector<Note> dummy_plotted_notes = plotter->get_notes_for(random_element(plotter_destinations));

   return dummy_plotted_notes;
}



bool Measure::Plotted::set_notes(std::vector<Note> notes)
{
   return false;
}



int Measure::Plotted::get_num_notes()
{
   return get_plotted_notes().size();
}



std::vector<Note> Measure::Plotted::get_notes_copy()
{
   return get_plotted_notes();
}



std::vector<Note> *Measure::Plotted::get_notes_pointer()
{
   return nullptr;
}



