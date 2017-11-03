


#include <fullscore/models/plotters/destination.h>

#include <fullscore/models/measures/plotted.h>
#include <fullscore/models/grid.h>
#include <fullscore/models/plotter.h>
#include <allegro_flare/useful.h>
#include <algorithm>



Plotter::Destination::Destination()
   : Base(Plotter::TYPE_IDENTIFIER_DESTINATION)
   , destinations()
{}



Plotter::Destination::~Destination()
{}



bool Plotter::Destination::add_destination(GridCoordinate destination)
{
   if (has_destination(destination)) return false;
   destinations.push_back(destination);
   return true;
}



bool Plotter::Destination::has_destination(GridCoordinate destination)
{
   return std::find(destinations.begin(), destinations.end(), destination) != destinations.end();
}



bool Plotter::Destination::remove_destination(GridCoordinate destination)
{
   std::vector<GridCoordinate>::iterator it = std::find(destinations.begin(), destinations.end(), destination);
   if (it == destinations.end()) return false;

   destinations.erase(it);
   return true;
}



int Plotter::Destination::num_destinations()
{
   return destinations.size();
}



std::vector<GridCoordinate> Plotter::Destination::get_destinations()
{
   return destinations;
}



std::vector<Note> Plotter::Destination::get_notes_for(GridCoordinate destination)
{
   // TODO: replace temp code below
   return { Note(-7), Note(0), Note(2), Note(4) };
}



bool Plotter::Destination::plot()
{
   for (auto &destination : destinations)
   {
      Grid *destination_grid = destination.get_grid();
      int staff_id = destination.get_staff_id();

      if (!destination_grid) throw std::runtime_error("Plotter::Destination cannot plot to a nullptr destination_grid");

      Staff::Base *destination_staff = destination_grid->get_staff(staff_id);
      if (!destination_staff) throw std::runtime_error("Plotter::Destination cannot plot to a nullptr destination_staff");
      if (!destination_staff->is_type("instrument"))
      {
         std::stringstream error_message;
         error_message << "Plotter::Destination cannot plot to a \"" << destination_staff->get_type() << "\" staff type";
         throw std::runtime_error(error_message.str());
      }

      throw std::runtime_error("Plotter::Destination can not plot to measures because set_measure has been disabled");
   }

   return true;
}



