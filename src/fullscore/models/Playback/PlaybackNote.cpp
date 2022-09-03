


#include <fullscore/models/Playback/PlaybackNote.hpp>



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



