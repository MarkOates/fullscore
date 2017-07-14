


#include <fullscore/models/measure/base.h>



Measure::Base::Base(std::string type)
   : type(type)
{}



Measure::Base::~Base()
{}



std::string Measure::Base::get_type()
{
   return type;
}



bool Measure::Base::is_type(std::string measure_type)
{
   return type == measure_type;
}



std::vector<Note> *Measure::Base::get_notes_pointer()
{
   return nullptr;
}



