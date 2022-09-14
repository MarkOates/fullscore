



#include <fullscore/converters/GridFileConverter.hpp>

#include <fullscore/models/measures/Base.hpp>
#include <fullscore/models/staves/Instrument.hpp>
#include <fullscore/models/Grid.hpp>




GridFileConverter::GridFileConverter(Grid *grid, std::string filename)
   : grid(grid)
   , filename(filename)
{}




bool GridFileConverter::save()
{
   throw std::runtime_error("GridFileConverter::save() has been disabled");
}




bool GridFileConverter::load()
{
   throw std::runtime_error("GridFileConverter::load() has been disabled");
}




