


#include <fullscore/models/grid.h>

#include <fullscore/models/measures/base.h>
#include <fullscore/models/staves/instrument.h>
#include <fullscore/models/note.h>
#include <iostream>



Grid::Grid(int num_x_measures, int num_y_staves)
   : voices()
   , time_signatures()
{
   for (unsigned i=0; i<num_y_staves; i++) voices.push_back(new Staff::Instrument(num_x_measures));
   time_signatures.resize(num_x_measures, TimeSignature(4, Duration()));
}



Grid::~Grid()
{
   // these should likely be destructed here or handled in some way other than being left dangling,
   // but a measure grid is frequently created elsewhere and returned in a function
   //for (int i=voices.size(); i>=0; i--) if (voices[i]) delete voices[i];
}



Measure::Base *Grid::get_measure(int x_measure, int y_staff)
{
   // bounds check
   if (!in_grid_range(x_measure, y_staff)) return nullptr;

   Staff::Base *staff = voices[y_staff];
   if (!staff) return nullptr;

   return staff->get_measure(x_measure);
}



bool Grid::set_measure(int x_measure, int y_staff, Measure::Base *measure)
{
   // bounds check
   if (!in_grid_range(x_measure, y_staff)) return false;

   // WARNING
   // this implementation directly assigns a measure to the voice, assuming
   // that a voice has measures, and the voice's measures are of Measure::Base type
   // this should likely be handled by a method on the Row, like
   // voices[i]->set_measure(x_measure, measure);
   voices[y_staff]->set_column(x_measure, measure);
   return true;
}



bool Grid::delete_measure(int x_measure, int y_staff)
{
   return set_measure(x_measure, y_staff, nullptr);
}



bool Grid::in_grid_range(int x_measure, int y_staff)
{
   if (x_measure < 0 || x_measure >= this->get_num_measures() || this->get_num_measures() == 0) return false;
   if (y_staff < 0 || y_staff >= this->get_num_staves() || this->get_num_staves() == 0) return false;

   return true;
}



int Grid::get_num_measures() const
{
   if (voices.empty()) return 0;
   return voices[0]->get_num_columns();
}



int Grid::get_num_staves() const
{
   return voices.size();
}



bool Grid::insert_staff(Staff::Base *staff, int index)
{
   if (!staff) return false;

   if (index < 0) index = 0;

   if (index >= (int)voices.size()) return append_staff(staff);
   else voices.insert(voices.begin() + index, staff);

   return true;
}



bool Grid::delete_staff(int index)
{
   if (index < 0 || index >= (int)voices.size()) return false;
   // TODO: Thinking a delete voice[index] should happen here
   voices.erase(voices.begin() + index);
   return true;
}



bool Grid::append_staff(Staff::Base *staff)
{
   if (!staff) return false;
   voices.push_back(staff);
   return true;
}



void Grid::insert_column(int index)
{
   int num_measures = get_num_measures();
   if (index < 0) index = 0;

   if (index >= num_measures)
   {
      append_measure();
   }
   else
   {
      // insert a time signature
      time_signatures.insert(time_signatures.begin() + index, TimeSignature(4, Duration()));

      // insert a measure into each row
      for (unsigned i=0; i<voices.size(); i++)
      {
         // WARNING: this assumes all staves have the same
         // number of measures (they likely may not once there are different "staff" types)
         // TODO: this method is "constructing" the voice.  Probably should not
         // be doing this here
         voices[i]->insert_column(index, nullptr);
      }
   }
}



bool Grid::delete_column(int index)
{
   int num_measures = get_num_measures();

   if (index < 0 || index >= num_measures) return false;

   // remove the time signature
   time_signatures.erase(time_signatures.begin() + index);

   // remove the measure from each row
   // WARNING: this assumes voices have "measures" to remove, also
   // is assuming the role of being responsible for deleting contents
   // inside another class
   // This should likely be replaced with a voice[i]->delete_measure(int) function
   for (unsigned i=0; i<voices.size(); i++)
      voices[i]->erase_column(index);

   return true;
}



void Grid::append_measure()
{
   // append time signature
   time_signatures.push_back(TimeSignature(4, Duration()));

   // append measure to each row
   for (unsigned i=0; i<voices.size(); i++)
   {
      // warning, this is responsible for constructing the measures
      // that are appended.  This should likely be replaced by a
      // Voice::append_column();
      voices[i]->append_column(nullptr);
   }
}



bool Grid::set_voice_name(int row_number, std::string name)
{
   if (row_number < 0) return "";
   if (row_number >= voices.size()) return "";
   voices[row_number]->set_name(name);
   return true;
}



std::string Grid::get_voice_name(int row_number)
{
   if (row_number < 0) return "";
   if (row_number >= voices.size()) return "";
   return voices[row_number]->get_name();
}



bool Grid::set_time_signature(int index, TimeSignature time_signature)
{
   if (index < 0) return false;
   if (index >= get_num_measures()) return false;

   time_signatures[index] = time_signature;
   return true;
}



float Grid::get_height() const
{
   float height = 0;
   for (int i=0; i<get_num_staves(); i++)
      if (voices[i]) height += voices[i]->get_height();
   return height;
}



Staff::Base *Grid::get_staff(int y_staff)
{
   if (y_staff < 0 || y_staff >= voices.size()) return nullptr;

   Staff::Base *staff = voices[y_staff];
   if (!staff) return nullptr;
   return staff;
}



TimeSignature Grid::get_time_signature(int index)
{
   if (index < 0) return TimeSignature(0, Duration());
   if (index >= get_num_measures()) return TimeSignature(0, Duration());

   return time_signatures[index];
}



TimeSignature *Grid::get_time_signature_ptr(int index)
{
   if (index < 0 || index >= get_num_measures()) return nullptr;

   return &time_signatures[index];
}



