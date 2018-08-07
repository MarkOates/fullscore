


#include <fullscore/models/plotters/Destination.h>

#include <fullscore/models/FloatingMeasure.h>
#include <fullscore/models/measures/Plotted.h>
#include <fullscore/models/Grid.h>
#include <fullscore/models/Plotter.h>
#include <allegro_flare/useful.h>
#include <algorithm>



Plotter::Destination::Destination(std::vector<GridCoordinate> destinations, std::vector<Note> notes)
   : Base(Plotter::TYPE_IDENTIFIER_DESTINATION)
   , destinations(destinations)
   , notes(notes)
{}



Plotter::Destination::~Destination()
{}



void Plotter::Destination::set_notes(std::vector<Note> notes)
{
   this->notes = notes;
}



void Plotter::Destination::set_destinations(std::vector<GridCoordinate> destinations)
{
   this->destinations = destinations;
}



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
   return notes;
}



bool Plotter::Destination::plot()
{
   //throw std::runtime_error("Plotter::Destination has been disabled");

   // 1) destroy any measures that exist on this plotter
   // 2) create measures from this plotter

   Measure::Base *m = new Measure::Plotted(notes);

   for (auto &destination : destinations)
   {
      new FloatingMeasure(destination, m->get_id());
   }

   return true;
}



