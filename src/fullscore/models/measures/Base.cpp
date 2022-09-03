


#include <fullscore/models/measures/Base.hpp>

#include <fullscore/models/Repositories/MeasureRepository.hpp>



Measure::Base::Base(std::string type)
   : type(type)
   , id(Measure::next_id++)
{
   Measure::push_back(this);
}



Measure::Base::~Base()
{
   Measure::remove(id);
}



std::string Measure::Base::get_type()
{
   return type;
}



bool Measure::Base::is_type(std::string measure_type)
{
   return type == measure_type;
}



int Measure::Base::get_id()
{
   return id;
}



std::vector<Note> *Measure::Base::get_notes_pointer()
{
   return nullptr;
}



