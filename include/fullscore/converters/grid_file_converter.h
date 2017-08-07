#ifndef __FULLSCORE_MEASURE_GRID_FILE_CONVERTER_HEADER
#define __FULLSCORE_MEASURE_GRID_FILE_CONVERTER_HEADER




#include <string>



class Grid;

class GridFileConverter
{
private:
   Grid *grid;
   std::string filename;

public:
   GridFileConverter(Grid *grid, std::string filename);

   bool save();
   bool load();
};




#endif
