#pragma once



class ProjectionPitch
{
public:
   int pitch;
   int accidental;

   ProjectionPitch(int pitch, int accidental=0);

   bool operator==(const ProjectionPitch &other) const;
};



