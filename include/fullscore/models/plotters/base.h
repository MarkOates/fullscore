#pragma once



#include <fullscore/models/staves/instrument.h>
#include <fullscore/models/grid_coordinate.h>
#include <fullscore/models/Note.h>



namespace Plotter
{
   class Base
   {
   private:
      std::vector<GridCoordinate> destinations;

   public:
      Base();
      virtual ~Base();

      bool add_destination(GridCoordinate destination);
      bool has_destination(GridCoordinate destination);
      bool remove_destination(GridCoordinate destination);
      int num_destinations();

      std::vector<GridCoordinate> get_destinations();

      std::vector<Note> get_notes_for(GridCoordinate destination);

      bool plot();
   };
}



