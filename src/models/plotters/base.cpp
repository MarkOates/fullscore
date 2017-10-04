


#include <fullscore/models/plotters/base.h>

#include <fullscore/models/measures/plotted.h>
#include <fullscore/models/grid.h>
#include <allegro_flare/useful.h>
#include <algorithm>



Plotter::Base::Base()
   : destinations()
{}



Plotter::Base::~Base()
{}



bool Plotter::Base::add_destination(GridCoordinate destination)
{
   if (has_destination(destination)) return false;
   destinations.push_back(destination);
   return true;
}



bool Plotter::Base::has_destination(GridCoordinate destination)
{
   return std::find(destinations.begin(), destinations.end(), destination) != destinations.end();
}



bool Plotter::Base::remove_destination(GridCoordinate destination)
{
   std::vector<GridCoordinate>::iterator it = std::find(destinations.begin(), destinations.end(), destination);
   if (it == destinations.end()) return false;

   destinations.erase(it);
   return true;
}



int Plotter::Base::num_destinations()
{
   return destinations.size();
}



std::vector<GridCoordinate> Plotter::Base::get_destinations()
{
   return destinations;
}



std::vector<Note> Plotter::Base::get_notes_for(GridCoordinate destination)
{
   // TODO: replace temp code below
   return { Note(-7), Note(0), Note(2), Note(4) };
}



bool Plotter::Base::plot()
{
   for (auto &destination : destinations)
   {
      Grid *destination_grid = destination.get_grid();
      int staff_id = destination.get_staff_id();
      int measure_num = destination.get_measure_num();
      //int beat_num = destination.get_grid(); // <- unused until feature is added

      if (!destination_grid) throw std::runtime_error("Plotter::Base cannot plot to a nullptr destination_grid");

      Staff::Base *destination_staff = destination_grid->get_staff(staff_id);
      if (!destination_staff) throw std::runtime_error("Plotter::Base cannot plot to a nullptr destination_staff");
      if (!destination_staff->is_type("instrument"))
      {
         std::stringstream error_message;
         error_message << "Plotter::Base cannot plot to a \"" << destination_staff->get_type() << "\" staff type";
         throw std::runtime_error(error_message.str());
      }

      // create the measure
      Measure::Plotted *plotted_measure = new Measure::Plotted(this);

      if (!destination_grid->set_measure(measure_num, staff_id, plotted_measure))
      {
         delete plotted_measure;
         std::stringstream error_message;
         error_message << "Plotter::Base was not able to set a plotted measure to (measure_num: " << measure_num << ", staff_id: " << staff_id << ")";
         throw std::runtime_error(error_message.str());
      }
   }

   return true;
}



