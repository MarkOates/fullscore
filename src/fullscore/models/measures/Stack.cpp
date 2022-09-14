


#include <fullscore/models/measures/Stack.hpp>

#include <fullscore/models/Repositories/MeasureRepository.hpp>
#include <fullscore/models/Note.hpp>
#include <iostream>



Measure::Stack::Stack()
   : Base(MeasureRepository::TYPE_IDENTIFIER_STACK)
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



