


#include <fullscore/models/measures/Stack.h>

#include <fullscore/models/Measure.h>
#include <fullscore/models/Note.h>
#include <allegro_flare/useful.h>



Measure::Stack::Stack()
   : Base(Measure::TYPE_IDENTIFIER_STACK)
   , transformations()
{}



bool Measure::Stack::set_notes(std::vector<Note> notes)
{
   return false;
}



int Measure::Stack::get_num_notes()
{
   return get_notes_copy().size();
}



std::vector<Note> Measure::Stack::get_notes_copy()
{
   try
   {
      return transformations.transform({});
   }
   catch (...)
   {
      std::cout << "Measure::Stack transformations failed" << std::endl;
      return {};
   }
}



std::vector<Note> *Measure::Stack::get_notes_pointer()
{
   return nullptr;
}



