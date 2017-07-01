



#include <fullscore/playback_device_win_midi.h>
#include <allegro_flare/midi_win.h>




PlaybackDeviceWinMIDI::PlaybackDeviceWinMIDI()
{
   /*
   init_midi();

   if (midi_out_device.empty()) return;

   open_midi_device(midi_out_device[0]);
   */
}




PlaybackDeviceWinMIDI::~PlaybackDeviceWinMIDI()
{
   /*
   uninstall_midi();
   */
}




void PlaybackDeviceWinMIDI::note_on(int channel, int pitch, int velocity)
{
   /*
   midi_note_on(channel, pitch, velocity);
   */
}




void PlaybackDeviceWinMIDI::note_off(int channel, int pitch)
{
   /*
   midi_note_off(channel, pitch);
   */
}




void PlaybackDeviceWinMIDI::patch_change(int channel, int patch_num)
{
   /*
   midi_patch_change(channel, patch_num);
   */
}




void PlaybackDeviceWinMIDI::all_notes_off()
{
   /*
   midi_all_notes_off();
   */
}




