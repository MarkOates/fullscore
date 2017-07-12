


#include <fullscore/models/measure.h>

#include <fullscore/models/note.h>
#include <allegro_flare/useful.h>



Measure::Measure()
   : genesis(nullptr)
   , extension(12)
{}



bool Measure::refresh()
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
         std::cout << "Measure genesis failed" << std::endl;
         return false;
      }
   }
   return false;
}



bool Measure::references_source()
{
   return genesis && genesis->includes_reference();
}



bool Measure::set_notes(std::vector<Note> notes)
{
   this->notes = notes;
}



std::vector<Note> Measure::get_notes()
{
   return notes;
}



