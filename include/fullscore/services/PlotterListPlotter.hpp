#pragma once


class PlotterList;


class PlotterListPlotter
{
private:
   PlotterList *plotter_list;

public:
   PlotterListPlotter(PlotterList *plotter_list);
   ~PlotterListPlotter();

   void plot();
};


