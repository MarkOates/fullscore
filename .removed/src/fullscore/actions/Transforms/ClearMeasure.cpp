


#include <fullscore/actions/Transforms/ClearMeasure.hpp>

#include <fullscore/Transforms/ClearMeasureTransform.hpp>
#include <fullscore/models/Note.hpp>



Action::Transforms::ClearMeasure::ClearMeasure(std::vector<Note> *notes)
   : Base("clear_measure")
   , notes(notes)
{}



Action::Transforms::ClearMeasure::~ClearMeasure()
{}



bool Action::Transforms::ClearMeasure::execute()
{
   if (!notes) throw std::runtime_error("Cannot clear_measure on a nullptr notes");

   ::Transforms::ClearMeasure clear_measure_transform;
   *notes = clear_measure_transform.transform(*notes);

   return true;
}



