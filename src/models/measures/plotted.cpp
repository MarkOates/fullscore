


#include <fullscore/models/measures/plotted.h>

#include <fullscore/models/plotters/destination.h>
#include <fullscore/models/measure.h>
#include <fullscore/models/Note.h>
#include <allegro_flare/useful.h>



Measure::Plotted::Plotted(Plotter::Base *plotter)
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
   // TODO figure out how to place notes into a plotted staff
   return { Note(0), Note(3), Note(4), Note(5) };
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



