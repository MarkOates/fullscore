



#include <fullscore/converters/GridFileConverter.h>

#include <fullscore/models/measures/Base.h>
#include <fullscore/models/staves/Instrument.h>
#include <fullscore/models/Grid.h>
#include <allegro_flare/attributes.h>
#include <allegro_flare/useful_php.h>




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




