#ifndef __FULLSCORE_MEASURE_GRID_FILE_CONVERTER_HEADER
#define __FULLSCORE_MEASURE_GRID_FILE_CONVERTER_HEADER




#include <string>



class MeasureGrid;

class MeasureGridFileConverter
{
private:
   std::string filename;
   MeasureGrid *measure_grid;

public:
   MeasureGridFileConverter(MeasureGrid *measure_grid, std::string filename);

   bool save();
   bool load();
};




#endif