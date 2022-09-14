#pragma once


#include <fullscore/models/plotters/Base.hpp>
#include <vector>


namespace InstrumentSelectors { class Base; }
class Note;


namespace Plotter
{
   class Selector : public Base
   {
   private:
      InstrumentSelectors::Base *instrument_selector;
      std::vector<Note> notes;

   public:
      Selector(InstrumentSelectors::Base *instrument_selector=nullptr, std::vector<Note> notes={});
      virtual ~Selector();

      void set_notes(std::vector<Note> notes={});
      void set_instrument_selector(InstrumentSelectors::Base *instrument_selector);

      std::vector<Note> get_notes();
      InstrumentSelectors::Base *get_instrument_selector();

      bool plot() override;
   };
}


