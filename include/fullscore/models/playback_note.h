#pragma once



class PlaybackNote
{
public:
   float start_time, end_time;
   bool attacked, released;
   int pitch, channel, velocity;

   PlaybackNote();
   ~PlaybackNote();
};



