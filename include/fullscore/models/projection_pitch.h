#pragma once



class ProjectionPitch
{
public:
   int pitch;
   int extension;
   int accidental;

   ProjectionPitch(int pitch, int extension=0, int accidental=0);

   bool operator==(const ProjectionPitch &other) const;
};



