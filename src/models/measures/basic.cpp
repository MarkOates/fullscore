


#include <fullscore/models/measures/basic.h>

#include <fullscore/models/note.h>
#include <allegro_flare/useful.h>



Measure::BasicMeasure::BasicMeasure()
   : Measure::Base("measure")
   , genesis(nullptr)
   , extension(12)
{}



bool Measure::BasicMeasure::refresh()
{
   if (genesis)
   {
      try
      {
         notes = genesis->transform({});
         return true;
      }
      catch (...)
      {
         std::cout << "Measure::BasicMeasure genesis failed" << std::endl;
         return false;
      }
   }
   return false;
}



bool Measure::BasicMeasure::references_source()
{
   return genesis && genesis->includes_reference();
}



bool Measure::BasicMeasure::set_notes(std::vector<Note> notes)
{
   this->notes = notes;
   return true;
}



std::vector<Note> Measure::BasicMeasure::get_notes_copy()
{
   return notes;
}



std::vector<Note> *Measure::BasicMeasure::get_notes_pointer()
{
   return &notes;
}



