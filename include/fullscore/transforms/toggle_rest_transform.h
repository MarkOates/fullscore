#ifndef __FULLSCORE_TOGGLE_REST_TRANSFORM_HEADER
#define __FULLSCORE_TOGGLE_REST_TRANSFORM_HEADER




#include <fullscore/transforms/transform_base.h>




namespace Transform
{
   class ToggleRest : public Transform::Base
   {
   public:
      ToggleRest();
      ~ToggleRest();
      virtual std::vector<Note> transform(std::vector<Note> notes) override;
   };
};




#endif
