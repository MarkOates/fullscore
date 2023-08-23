#pragma once



#include <fullscore/models/Duration.hpp>

#include <fullscore/models/Pitch.hpp>



class Note
{
private:
   Pitch pitch;
   Duration duration;
   bool rest;

public:
   Note(int _scale_degree=0, Duration duration=Duration(), bool rest=false);
   ~Note();

   bool set_pitch(Pitch pitch);
   bool set_duration(Duration duration);
   bool set_rest(bool rest);

   Pitch get_pitch() const;
   Duration get_duration() const;
   bool get_rest() const;

   bool operator==(const Note &other) const;
};



