

#include <fullscore/models/plotters/Selector.hpp>

#include <fullscore/models/Note.h>
#include <fullscore/models/Plotter.h>
#include <fullscore/selectors/instrument_selector/Interface.hpp>


Plotter::Selector::Selector(InstrumentSelector::Interface *instrument_selector, std::vector<Note> notes)
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


void Plotter::Selector::set_instrument_selector(InstrumentSelector::Interface *instrument_selector)
{
   this->instrument_selector = instrument_selector;
}


std::vector<Note> Plotter::Selector::get_notes()
{
   return notes;
}


InstrumentSelector::Interface *Plotter::Selector::get_instrument_selector()
{
   return instrument_selector;
}


bool Plotter::Selector::plot()
{
   // TODO
   return true;
}


