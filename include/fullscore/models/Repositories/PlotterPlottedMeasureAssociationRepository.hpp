#pragma once


#include <fullscore/models/measures/Plotted.hpp>
#include <fullscore/models/plotters/Base.hpp>
#include <vector>


namespace fullscore
{
   namespace models
   {
      class PlotterPlottedMeasureAssociationRepository
      {
      private:
         Plotter::Base* plotter;
         std::vector<Measure::Plotted*> measures;

      public:
         PlotterPlottedMeasureAssociationRepository(Plotter::Base* plotter=nullptr, std::vector<Measure::Plotted*> measures={});
         ~PlotterPlottedMeasureAssociationRepository();


         Plotter::Base* get_plotter();
         std::vector<Measure::Plotted*> get_measures();
      };
   }
}



