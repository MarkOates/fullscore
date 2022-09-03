#pragma once


#include <fullscore/models/plotters/Base.hpp>
#include <vector>


namespace InstrumentSelector { class Interface; }
class Note;


namespace Plotter
{
   class Selector : public Base
   {
   private:
      InstrumentSelector::Interface *instrument_selector;
      std::vector<Note> notes;

   public:
      Selector(InstrumentSelector::Interface *instrument_selector=nullptr, std::vector<Note> notes={});
      virtual ~Selector();

      void set_notes(std::vector<Note> notes={});
      void set_instrument_selector(InstrumentSelector::Interface *instrument_selector);

      std::vector<Note> get_notes();
      InstrumentSelector::Interface *get_instrument_selector();

      bool plot() override;
   };
}


