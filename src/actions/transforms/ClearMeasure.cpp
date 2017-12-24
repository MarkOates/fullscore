


#include <fullscore/actions/transforms/ClearMeasure.h>

#include <fullscore/transforms/ClearMeasureTransform.h>
#include <fullscore/models/Note.h>



Action::Transform::ClearMeasure::ClearMeasure(std::vector<Note> *notes)
   : Base("clear_measure")
   , notes(notes)
{}



Action::Transform::ClearMeasure::~ClearMeasure()
{}



bool Action::Transform::ClearMeasure::execute()
{
   if (!notes) throw std::runtime_error("Cannot clear_measure on a nullptr notes");

   ::Transform::ClearMeasure clear_measure_transform;
   *notes = clear_measure_transform.transform(*notes);

   return true;
}



