


#include <fullscore/transforms/stack_transform.h>



Transform::Stack::Stack(std::vector<Transform::Base *> transformations)
   : Base("stack")
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



bool Transform::Stack::includes_reference()
{
   for(auto &transform : transformations)
      if (transform->get_identifier() == "reference") return true;
   return false;
}



