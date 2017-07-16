


#include <fullscore/models/measures/basic.h>

#include <fullscore/models/note.h>
#include <allegro_flare/useful.h>



Measure::Basic::Basic()
   : Base("basic")
   , genesis(nullptr)
   , extension(12)
{}



Measure::Basic::Basic(std::vector<Note> notes)
   : Base("basic")
   , genesis(nullptr)
   , extension(12)
   , notes()
{
   set_notes(notes);
}



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



int Measure::Basic::get_num_notes()
{
   return notes.size();
}



std::vector<Note> Measure::Basic::get_notes_copy()
{
   return notes;
}



std::vector<Note> *Measure::Basic::get_notes_pointer()
{
   return &notes;
}



