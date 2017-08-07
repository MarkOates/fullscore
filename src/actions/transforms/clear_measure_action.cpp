


#include <fullscore/actions/transforms/clear_measure_action.h>

#include <fullscore/transforms/clear_measure_transform.h>
#include <fullscore/models/note.h>



Action::Transform::ClearMeasure::ClearMeasure(std::vector<Note> *notes)
   : Base("clear_measure")
   , notes(notes)
{}



Action::Transform::ClearMeasure::~ClearMeasure()
{}



bool Action::Transform::ClearMeasure::execute()
{
   if (!notes) return false;

   ::Transform::ClearMeasure clear_measure_transform;
   *notes = clear_measure_transform.transform(*notes);

   return true;
}



