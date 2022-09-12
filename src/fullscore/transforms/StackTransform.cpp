


#include <fullscore/transforms/StackTransform.hpp>

#include <fullscore/TransformNames.hpp>



Transform::Stack::Stack(std::vector<Transform::Base *> transformations)
   : Base(TransformNames::STACK_TRANSFORM_IDENTIFIER)
   , transformations(transformations)
{}



bool Transform::Stack::add_transform(Transform::Base *transform)
{
   transformations.push_back(transform);
   return true;
}



bool Transform::Stack::clear()
{
   transformations.clear();
   return true;
}



std::vector<Note> Transform::Stack::transform(std::vector<Note> notes)
{
   for(auto &transform : transformations)
      notes = transform->transform(notes);

   return notes;
}



std::vector<Transform::Base *> Transform::Stack::get_transformations()
{
   return transformations;
}



