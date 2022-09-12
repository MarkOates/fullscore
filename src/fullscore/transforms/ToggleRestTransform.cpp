



#include <fullscore/transforms/ToggleRestTransform.hpp>

#include <fullscore/Transform.h>



Transform::ToggleRest::ToggleRest()
   : Base(Transform::TOGGLE_REST_TRANSFORM_IDENTIFIER)
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




