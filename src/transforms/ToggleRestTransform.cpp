



#include <fullscore/transforms/ToggleRestTransform.h>




Transform::ToggleRest::ToggleRest()
   : Base("toggle_rest")
{
}




Transform::ToggleRest::~ToggleRest()
{
}




std::vector<Note> Transform::ToggleRest::transform(std::vector<Note> source)
{
   std::vector<Note> notes = source;
   for (auto &note : notes) note.is_rest = !note.is_rest;
   return notes;
}




