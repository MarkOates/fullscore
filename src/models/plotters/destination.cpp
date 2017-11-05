


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
   throw std::runtime_error("Plotter::Destination has been disabled");

   return true;
}



