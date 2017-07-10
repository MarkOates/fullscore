


#include <fullscore/models/measure.h>

#include <fullscore/models/note.h>
#include <allegro_flare/useful.h>



Measure::Measure()
   : genesis(nullptr)
   , extension(12)
{}



Note *Measure::operator[](int index)
{
   if (index < 0 || notes.empty() || index >= notes.size()) return NULL;
   return &notes[index];
}



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



