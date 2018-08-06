#pragma once



#include <fullscore/models/plotters/Base.h>
#include <fullscore/models/staves/Instrument.h>
#include <fullscore/models/GridCoordinate.h>
#include <fullscore/models/Note.h>
#include <vector>



namespace Plotter
{
   class Destination : public Base
   {
   private:
      std::vector<GridCoordinate> destinations;
      std::vector<Note> notes;

   public:
      Destination(std::vector<GridCoordinate> destinations={}, std::vector<Note> notes={});
      virtual ~Destination();

      bool add_destination(GridCoordinate destination);
      bool has_destination(GridCoordinate destination);
      bool remove_destination(GridCoordinate destination);
      int num_destinations();

      std::vector<GridCoordinate> get_destinations();

      std::vector<Note> get_notes_for(GridCoordinate destination);

      bool plot() override;
   };
}



