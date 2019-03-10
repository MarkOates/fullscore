#pragma once



#include <vector>

#include <fullscore/models/Note.h>



class NoteSet
{
public:
   std::vector<Note> notes;

   NoteSet(std::vector<Note> notes);

   bool operator==(const NoteSet &other) const;
};



