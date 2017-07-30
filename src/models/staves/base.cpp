


#include <fullscore/models/measures/base.h>
#include <fullscore/models/staves/base.h>
#include <fullscore/models/staff.h>



Staff::Base::Base(std::string type, int num_measures)
   : type(type)
   , id(Staff::next_id++)
   , name()
   , measures()
{
   for (unsigned i=0; i<num_measures; i++) measures.push_back(nullptr);
}



Staff::Base::~Base()
{}



std::string Staff::Base::get_type()
{
   return type;
}



bool Staff::Base::is_type(std::string type)
{
   return type == type;
}



int Staff::Base::get_id()
{
   return id;
}



/////



//Staff::Base(int num_measures) : measures()
//{
   //for (unsigned i=0; i<num_measures; i++) measures.push_back(nullptr);
//}



Measure::Base *Staff::Base::get_measure(int x_measure)
{
   if (x_measure < 0 || x_measure >= get_num_columns()) return nullptr;
   return measures[x_measure];
}



void Staff::Base::set_name(std::string name)
{
   this->name = name;
}



std::string Staff::Base::get_name()
{
   return name;
}



int Staff::Base::get_num_columns()
{
   return measures.size();
}



bool Staff::Base::set_column(int measure_x, Measure::Base *measure)
{
   // TODO move the bounds check to be handled in here
   // TODO if there is already a measure present, the deletion should be moved to here as well
   measures[measure_x] = measure;
   return true;
}



bool Staff::Base::insert_column(int at_index, Measure::Base *measure)
{
   // TODO move the bounds check to here
   // behavior that < 0 inserts are corrected to 0 and
   // >= size measures default to append() should probably be handled
   // at the MeasureGrid layer, since it would need to be implement in
   // all of the derived classes, and is expected behavior of the MeasureGrid
   measures.insert(measures.begin() + at_index, measure);
   return true;
}



bool Staff::Base::erase_column(int at_index)
{
   // TODO move the bounds check to here
   // behavior that < 0 inserts are corrected to 0 and

   // >= size measures default to append() should probably be handled
   // at the MeasureGrid layer, since it would need to be implement in
   // all of the derived classes, and is expected behavior of the MeasureGrid
   if (at_index < 0) std::runtime_error("Cannot erase measure < 0");
   if (at_index >= measures.size()) std::runtime_error("Cannot erase measure >= size()");

   if (measures[at_index]) delete measures[at_index];

   measures.erase(measures.begin() + at_index);

   return true;
}



bool Staff::Base::append_column(Measure::Base *measure)
{
   measures.push_back(measure);
   return true;
}



