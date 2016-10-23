



#include <fullscore/actions/toggle_playback_action.h>

#include <fullscore/gui_score_editor.h>
#include <fullscore/mixer.h>




Action::TogglePlayback::TogglePlayback(GUIScoreEditor *score_editor, UIMixer *ui_mixer)
   : Base("toggle_playback")
   , score_editor(score_editor)
   , ui_mixer(ui_mixer)
{
}




Action::TogglePlayback::~TogglePlayback()
{
}




bool Action::TogglePlayback::execute()
{
   if (!score_editor || !ui_mixer) return false;

   // send the patches before play
   PlaybackDeviceInterface *device = score_editor->playback_control.playback_device;
   for (unsigned i=0; i<score_editor->measure_grid.get_num_staves(); i++)
   {
      device->patch_change(i, ui_mixer->get_patch_num(i));
   }

   // toggle playback
   score_editor->playback_control.toggle_playback();

   return true;
}




