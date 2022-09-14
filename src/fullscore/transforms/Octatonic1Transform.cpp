


#include <fullscore/Transforms/Octatonic1Transform.hpp>

#include <fullscore/TransformNames.hpp>



Transforms::Octatonic1::Octatonic1()
   : Base(TransformNames::OCTATONIC_1_TRANSFORM_IDENTIFIER)
{}



Transforms::Octatonic1::~Octatonic1()
{}



std::vector<Note> Transforms::Octatonic1::transform(std::vector<Note> source)
{
   std::vector<Note> notes = {0, 2, 3, 5, 6, 8, 9, 11};
   return notes;
}



