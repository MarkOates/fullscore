



#include <fullscore/models/note_playback_info.h>




NotePlaybackInfo::NotePlaybackInfo()
   : start_time(0)
   , end_time(0)
   , attacked(false)
   , released(false)
   , pitch(0)
   , channel(0)
   , velocity(0)
{
};




NotePlaybackInfo::~NotePlaybackInfo()
{
}




