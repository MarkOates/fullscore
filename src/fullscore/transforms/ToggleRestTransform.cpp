



#include <fullscore/Transforms/ToggleRestTransform.hpp>

#include <fullscore/TransformNames.hpp>



Transforms::ToggleRest::ToggleRest()
   : Base(TransformNames::TOGGLE_REST_TRANSFORM_IDENTIFIER)
{
}




Transforms::ToggleRest::~ToggleRest()
{
}




std::vector<Note> Transforms::ToggleRest::transform(std::vector<Note> source)
{
   std::vector<Note> notes = source;
   for (auto &note : notes) note.set_rest(!note.get_rest());
   return notes;
}




