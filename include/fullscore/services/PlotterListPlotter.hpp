#pragma once


#include <fullscore/models/Repositories/PlotterRepository.hpp>
//class PlotterListRepository;


class PlotterListPlotter
{
private:
   PlotterRepository *plotter_list;

public:
   PlotterListPlotter(PlotterRepository *plotter_list);
   ~PlotterListPlotter();

   void plot();
};


