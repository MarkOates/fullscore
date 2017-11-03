#pragma once



#include <fullscore/transforms/base.h>



namespace Transform
{
   class Stack : public Transform::Base
   {
   private:
      std::vector<Transform::Base *> transformations;

   public:
      Stack(std::vector<Transform::Base *> transformations = {});

      bool add_transform(Transform::Base *transform);
      bool clear();

      virtual std::vector<Note> transform(std::vector<Note> notes) override;
      std::vector<Transform::Base *> get_transformations();
   };
};



