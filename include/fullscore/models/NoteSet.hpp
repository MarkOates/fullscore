#pragma once



#include <vector>

#include <fullscore/models/Note.h>



class NoteSet
{
public:
   std::vector<Note> notes;

   NoteSet(std::vector<Note> notes);

   std::vector<Note> NoteSet::get_notes();
   std::vector<Note> &NoteSet::get_notes_ref();

   bool operator==(const NoteSet &other) const;
};



