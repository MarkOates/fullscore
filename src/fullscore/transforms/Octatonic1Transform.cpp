


#include <fullscore/transforms/Octatonic1Transform.hpp>

#include <fullscore/Transform.hpp>



Transform::Octatonic1::Octatonic1()
   : Base(Transform::OCTATONIC_1_TRANSFORM_IDENTIFIER)
{}



Transform::Octatonic1::~Octatonic1()
{}



std::vector<Note> Transform::Octatonic1::transform(std::vector<Note> source)
{
   std::vector<Note> notes = {0, 2, 3, 5, 6, 8, 9, 11};
   return notes;
}



