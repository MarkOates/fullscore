


#include <fullscore/models/plotter.h>

#include <allegro_flare/useful.h>
#include <algorithm>



Plotter::Plotter()
   : destinations()
{}



Plotter::~Plotter()
{}



bool Plotter::add_destination(GridCoordinate destination)
{
   if (has_destination(destination)) return false;
   destinations.push_back(destination);
   return true;
}



bool Plotter::has_destination(GridCoordinate destination)
{
   return std::find(destinations.begin(), destinations.end(), destination) != destinations.end();
}



bool Plotter::remove_destination(GridCoordinate destination)
{
   std::vector<GridCoordinate>::iterator it = std::find(destinations.begin(), destinations.end(), destination);
   if (it == destinations.end()) return false;

   destinations.erase(it);
   return true;
}



int Plotter::num_destinations()
{
   return destinations.size();
}



std::vector<GridCoordinate> Plotter::get_destinations()
{
   return destinations;
}



std::vector<Note> Plotter::get_notes_for(GridCoordinate destination)
{
   // temp code

   std::vector<Note> source_notes = { Note(-7), Note(0), Note(2), Note(4) };

   return { random_element(source_notes), random_element(source_notes) };
}



