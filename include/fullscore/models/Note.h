#pragma once



#include <fullscore/models/Duration.h>

#include <fullscore/models/Pitch.h>



class Note
{
private:
   Pitch pitch;
   Duration duration;
   int is_rest;

public:
   Note(int _scale_degree=0, Duration duration=Duration());
   ~Note();

   bool set_pitch(Pitch pitch);
   bool set_duration(Duration duration);
   bool set_rest(bool rest);

   Pitch get_pitch();
   Duration get_duration();
   bool get_rest();

   bool operator==(const Note &other) const;
};



