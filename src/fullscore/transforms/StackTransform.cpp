


#include <fullscore/Transforms/StackTransform.hpp>

#include <fullscore/TransformNames.hpp>



Transforms::Stack::Stack(std::vector<Transforms::Base *> transformations)
   : Base(TransformNames::STACK_TRANSFORM_IDENTIFIER)
   , transformations(transformations)
{}



bool Transforms::Stack::add_transform(Transforms::Base *transform)
{
   transformations.push_back(transform);
   return true;
}



bool Transforms::Stack::clear()
{
   transformations.clear();
   return true;
}



std::vector<Note> Transforms::Stack::transform(std::vector<Note> notes)
{
   for(auto &transform : transformations)
      notes = transform->transform(notes);

   return notes;
}



std::vector<Transforms::Base *> Transforms::Stack::get_transformations()
{
   return transformations;
}



