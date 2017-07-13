#pragma once



#include <vector>

#include <fullscore/transforms/stack.h>



class Note;



class Measure
{
private:
   friend class MeasureGridFileConverter;
   friend class MeasureGridFactory;
   friend class FullscoreApplicationController;
   friend class GUIScoreEditor;

   std::vector<Note> notes;

public:
   Transform::Stack *genesis;
   bool refresh();
   bool references_source();

   Measure();

   int extension;

   bool set_notes(std::vector<Note> notes);
   std::vector<Note> get_notes_copy();
};



