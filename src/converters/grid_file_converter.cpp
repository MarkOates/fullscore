



#include <fullscore/converters/grid_file_converter.h>

#include <fullscore/models/measures/base.h>
#include <fullscore/models/staves/instrument.h>
#include <fullscore/converters/note_string_converter.h>
#include <fullscore/converters/time_signature_string_converter.h>
#include <fullscore/models/grid.h>
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




