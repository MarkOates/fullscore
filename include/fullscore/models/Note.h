#pragma once



#include <fullscore/models/Duration.h>
#include <fullscore/models/pitch.h>
#include <allegro_flare/attributes.h>



class Note : public Attributes
{
public:
   Pitch pitch;
   Duration duration;
   int is_rest;

   Note(int _scale_degree=0, Duration duration = Duration());
   ~Note();

   bool operator==(const Note &other) const;
};



