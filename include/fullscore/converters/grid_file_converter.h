#ifndef __FULLSCORE_MEASURE_GRID_FILE_CONVERTER_HEADER
#define __FULLSCORE_MEASURE_GRID_FILE_CONVERTER_HEADER




#include <string>



class MeasureGrid;

class MeasureGridFileConverter
{
private:
   MeasureGrid *grid;
   std::string filename;

public:
   MeasureGridFileConverter(MeasureGrid *grid, std::string filename);

   bool save();
   bool load();
};




#endif
