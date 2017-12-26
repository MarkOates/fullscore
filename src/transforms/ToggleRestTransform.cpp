



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
   for (auto &note : notes) note.set_rest(!note.get_rest());
   return notes;
}




