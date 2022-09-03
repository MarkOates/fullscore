

#include <fullscore/models/Repositories/PlotterPlottedMeasureAssociationRepository.hpp>




namespace fullscore
{
namespace models
{


PlotterPlottedMeasureAssociationRepository::PlotterPlottedMeasureAssociationRepository(Plotter::Base* plotter, std::vector<Measure::Plotted*> measures)
   : plotter(plotter)
   , measures(measures)
{
}


PlotterPlottedMeasureAssociationRepository::~PlotterPlottedMeasureAssociationRepository()
{
}


Plotter::Base* PlotterPlottedMeasureAssociationRepository::get_plotter()
{
   return plotter;
}


std::vector<Measure::Plotted*> PlotterPlottedMeasureAssociationRepository::get_measures()
{
   return measures;
}


} // namespace models
} // namespace fullscore


