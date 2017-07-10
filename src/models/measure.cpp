


#include <fullscore/models/measure.h>

#include <fullscore/models/note.h>
#include <allegro_flare/useful.h>



Measure::Measure()
   : genesis(nullptr)
{}



Note *Measure::operator[](int index)
{
   if (index < 0 || notes.empty() || index >= notes.size()) return NULL;
   return &notes[index];
}



void Measure::end_of_the_line()
{
   if (genesis) notes = genesis->transform({});
}



