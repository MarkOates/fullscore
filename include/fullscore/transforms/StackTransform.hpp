#pragma once



#include <fullscore/Transforms/Base.hpp>



namespace Transforms
{
   class Stack : public Transforms::Base
   {
   private:
      std::vector<Transforms::Base *> transformations;

   public:
      Stack(std::vector<Transforms::Base *> transformations = {});

      bool add_transform(Transforms::Base *transform);
      bool clear();

      virtual std::vector<Note> transform(std::vector<Note> notes) override;
      std::vector<Transforms::Base *> get_transformations();
   };
};



