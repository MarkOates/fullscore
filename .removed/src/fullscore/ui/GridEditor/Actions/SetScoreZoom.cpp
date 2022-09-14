



#include <fullscore/UI/GridEditor/Actions/SetScoreZoom.hpp>

//#include <fullscore/widgets/GridEditor.h>
#include <fullscore/UI/GridEditor/Widget.hpp>
#include <allegro_flare/motion.h>


namespace UI::GridEditor::Actions
{


SetScoreZoom::SetScoreZoom(UI::GridEditor::Widget *grid_editor, Motion *motion, float destination, float duration)
   : ::Action::Base("set_score_zoom")
   , grid_editor(grid_editor)
   , motion(motion)
   , destination(destination)
   , duration(duration)
{}




SetScoreZoom::~SetScoreZoom()
{}




bool SetScoreZoom::execute()
{
   if (!grid_editor || !motion) return false;

   motion->cmove_to(&grid_editor->place.scale.x, destination, duration);
   motion->cmove_to(&grid_editor->place.scale.y, destination, duration);

   return true;
}


} // namespace UI::GridEditor::Actions


