#pragma once



class NotePlaybackInfo
{
public:
   float start_time, end_time;
   bool attacked, released;

   NotePlaybackInfo();
   ~NotePlaybackInfo();
};



