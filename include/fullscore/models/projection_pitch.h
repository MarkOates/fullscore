#pragma once



class ProjectionPitch
{
public:
   int pitch;

   ProjectionPitch(int pitch);

   bool operator==(const ProjectionPitch &other) const;
};



