



#include <fullscore/converters/measure_grid_file_converter.h>

#include <fullscore/models/measure_grid.h>




MeasureGridFileConverter::MeasureGridFileConverter(MeasureGrid *measure_grid, std::string filename)
   : measure_grid(measure_grid)
   , filename(filename)
{}




bool MeasureGridFileConverter::save()
{
   if (!measure_grid) return false;
   if (filename.empty()) return false;

   // unimplemented
   return false;
}




bool MeasureGridFileConverter::load()
{
   if (!measure_grid) return false;
   if (filename.empty()) return false;

   // unimplemented
   return false;
}




