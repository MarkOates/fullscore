


#include <fullscore/models/measure.h>

#include <fullscore/models/note.h>
#include <allegro_flare/useful.h>



BasicMeasure::BasicMeasure()
   : Measure::Base("measure")
   , genesis(nullptr)
   , extension(12)
{}



bool BasicMeasure::refresh()
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
         std::cout << "BasicMeasure genesis failed" << std::endl;
         return false;
      }
   }
   return false;
}



bool BasicMeasure::references_source()
{
   return genesis && genesis->includes_reference();
}



bool BasicMeasure::set_notes(std::vector<Note> notes)
{
   this->notes = notes;
   return true;
}



std::vector<Note> BasicMeasure::get_notes_copy()
{
   return notes;
}



std::vector<Note> *BasicMeasure::get_notes_pointer()
{
   return &notes;
}



