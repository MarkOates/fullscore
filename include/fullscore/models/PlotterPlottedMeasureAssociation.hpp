#pragma once


#include <fullscore/models/measures/Plotted.h>
#include <fullscore/models/plotters/Base.h>
#include <vector>


namespace fullscore
{
   namespace models
   {
      class PlotterPlottedMeasureAssociation
      {
      private:
         Plotter::Base* plotter;
         std::vector<Measure::Plotted*> measures;

      public:
         PlotterPlottedMeasureAssociation(Plotter::Base* plotter=nullptr, std::vector<Measure::Plotted*> measures={});
         ~PlotterPlottedMeasureAssociation();


         Plotter::Base* get_plotter();
         std::vector<Measure::Plotted*> get_measures();
      };
   }
}



