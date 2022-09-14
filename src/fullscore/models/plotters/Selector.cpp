

#include <fullscore/models/plotters/Selector.hpp>

#include <fullscore/models/Note.hpp>
#include <fullscore/models/Plotter.hpp>
#include <fullscore/selectors/InstrumentSelectors/Base.hpp>


Plotter::Selector::Selector(InstrumentSelectors::Base *instrument_selector, std::vector<Note> notes)
   : Base(Plotter::TYPE_IDENTIFIER_SELECTOR)
   , instrument_selector(instrument_selector)
   , notes(notes)
{}


Plotter::Selector::~Selector()
{}


void Plotter::Selector::set_notes(std::vector<Note> notes)
{
   this->notes = notes;
}


void Plotter::Selector::set_instrument_selector(InstrumentSelectors::Base *instrument_selector)
{
   this->instrument_selector = instrument_selector;
}


std::vector<Note> Plotter::Selector::get_notes()
{
   return notes;
}


InstrumentSelectors::Base *Plotter::Selector::get_instrument_selector()
{
   return instrument_selector;
}


bool Plotter::Selector::plot()
{
   // TODO
   return true;
}


