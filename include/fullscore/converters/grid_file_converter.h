#pragma once



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



