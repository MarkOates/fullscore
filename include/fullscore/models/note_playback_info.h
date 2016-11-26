#pragma once



class NotePlaybackInfo
{
public:
   float start_time, end_time;
   bool attacked, released;
   int pitch, channel, velocity;

   NotePlaybackInfo();
   ~NotePlaybackInfo();
};



