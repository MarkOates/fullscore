

#include <fullscore/models/PlotterPlottedMeasureAssociation.hpp>




namespace fullscore
{
namespace models
{


PlotterPlottedMeasureAssociation::PlotterPlottedMeasureAssociation(Plotter::Base* plotter, std::vector<Measure::Plotted*> measures)
   : plotter(plotter)
   , measures(measures)
{
}


PlotterPlottedMeasureAssociation::~PlotterPlottedMeasureAssociation()
{
}


Plotter::Base* PlotterPlottedMeasureAssociation::get_plotter()
{
   return plotter;
}


std::vector<Measure::Plotted*> PlotterPlottedMeasureAssociation::get_measures()
{
   return measures;
}


} // namespace models
} // namespace fullscore


