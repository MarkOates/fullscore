#pragma once


class PlotterListRepository;


class PlotterListPlotter
{
private:
   PlotterListRepository *plotter_list;

public:
   PlotterListPlotter(PlotterListRepository *plotter_list);
   ~PlotterListPlotter();

   void plot();
};


