


#include <fullscore/models/measures/basic.h>

#include <fullscore/models/note.h>
#include <allegro_flare/useful.h>



Measure::Basic::Basic()
   : Base("basic")
   , genesis(nullptr)
   , extension(12)
{}



bool Measure::Basic::refresh()
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
         std::cout << "Measure::Basic genesis failed" << std::endl;
         return false;
      }
   }
   return false;
}



bool Measure::Basic::references_source()
{
   return genesis && genesis->includes_reference();
}



bool Measure::Basic::set_notes(std::vector<Note> notes)
{
   this->notes = notes;
   return true;
}



std::vector<Note> Measure::Basic::get_notes_copy()
{
   return notes;
}



std::vector<Note> *Measure::Basic::get_notes_pointer()
{
   return &notes;
}



