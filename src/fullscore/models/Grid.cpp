


#include <fullscore/models/Grid.h>

#include <fullscore/models/measures/Base.h>
#include <fullscore/models/staves/Instrument.h>
#include <fullscore/models/Note.h>
#include <iostream>



Grid::Grid(int num_barlines)
   : voices()
   , time_signatures()
{
   time_signatures.resize(num_barlines, TimeSignature(4, Duration()));
}



Grid::~Grid()
{
   // these should likely be destructed here or handled in some way other than being left dangling,
   // but a measure grid is frequently created elsewhere and returned in a function
   //for (int i=voices.size(); i>=0; i--) if (voices[i]) delete voices[i];
}



int Grid::get_num_barlines() const
{
   return time_signatures.size();
}



int Grid::get_num_staves() const
{
   return voices.size();
}



int Grid::get_num_plotters() const
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



Plotter::Base *Grid::get_plotter(int index)
{
   if (index < 0 || index >= voices.size()) return nullptr;

   Plotter::Base *plotter = plotters[index];
   if (!plotter) return nullptr;
   return plotter;
}



std::vector<Plotter::Base *> Grid::get_plotters()
{
   return plotters;
}



bool Grid::insert_plotter(Plotter::Base *plotter, int index)
{
   if (!plotter) return false;

   if (index < 0) index = 0;

   if (index >= (int)plotters.size()) return append_plotter(plotter);
   else plotters.insert(plotters.begin() + index, plotter);

   return true;
}



bool Grid::delete_plotter(int index)
{
   if (index < 0 || index >= (int)plotters.size()) return false;
   // TODO: Thinking a delete voice[index] should happen here
   plotters.erase(plotters.begin() + index);
   return true;
}



bool Grid::append_plotter(Plotter::Base *plotter)
{
   if (!plotter) return false;
   plotters.push_back(plotter);
   return true;
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
   if (index < 0) throw std::runtime_error("cannot set_time_signature at index < 0");
   if (index >= time_signatures.size())
   {
      std::stringstream error_message;
      error_message
         << "cannot set_time_signature at "
         << index
         << " because it is >= "
         << time_signatures.size()
         << " (the number of time_signatures in the grid)";
      throw std::runtime_error(error_message.str());
   }

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



std::vector<Staff::Base *> Grid::get_staves()
{
   return voices;
}



TimeSignature Grid::get_time_signature(int index)
{
   if (index < 0) throw std::runtime_error("cannot get_time_signature at index < 0");
   if (index >= time_signatures.size())
   {
      std::stringstream error_message;
      error_message
         << "cannot get_time_signature at "
         << index
         << " because it is >= "
         << time_signatures.size()
         << " (the number of time_signatures in the grid)";
      throw std::runtime_error(error_message.str());
   }

   return time_signatures[index];
}



TimeSignature *Grid::get_time_signature_ptr(int index)
{
   if (index < 0) throw std::runtime_error("cannot get_time_signature_ptr at index < 0");
   if (index >= time_signatures.size())
   {
      std::stringstream error_message;
      error_message
         << "cannot get_time_signature_ptr at "
         << index
         << " because it is >= "
         << time_signatures.size()
         << " (the number of time_signatures in the grid)";
      throw std::runtime_error(error_message.str());
   }

   return &time_signatures[index];
}



