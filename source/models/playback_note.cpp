



#include <fullscore/models/playback_note.h>




PlaybackNote::PlaybackNote()
   : start_time(0)
   , end_time(0)
   , attacked(false)
   , released(false)
   , pitch(0)
   , channel(0)
   , velocity(0)
{
};




PlaybackNote::~PlaybackNote()
{
}




