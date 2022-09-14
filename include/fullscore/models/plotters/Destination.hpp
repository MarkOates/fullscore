#pragma once



#include <fullscore/models/plotters/Base.hpp>
#include <fullscore/models/staves/Instrument.hpp>
#include <fullscore/models/GridCoordinate.hpp>
#include <fullscore/models/Note.hpp>
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

      void set_notes(std::vector<Note> notes={});
      void set_destinations(std::vector<GridCoordinate> destinations={});

      bool add_destination(GridCoordinate destination);
      bool has_destination(GridCoordinate destination);
      bool remove_destination(GridCoordinate destination);
      int num_destinations();

      std::vector<GridCoordinate> get_destinations();

      std::vector<Note> get_notes();
      std::vector<Note> get_notes_for(GridCoordinate destination);

      bool plot() override;
   };
}



