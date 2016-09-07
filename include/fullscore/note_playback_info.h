#ifndef __FULLSCORE_NOTE_PLAYBACK_INFO_HEADER
#define __FULLSCORE_NOTE_PLAYBACK_INFO_HEADER




class NotePlaybackInfo
{
public:
   bool attacked, released;
   float start_time, end_time;

   NotePlaybackInfo();
   ~NotePlaybackInfo();
};




#endif
