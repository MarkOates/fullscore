


#include <fullscore/transforms/octatonic_1.h>



Transform::Octatonic1::Octatonic1()
{}



Transform::Octatonic1::~Octatonic1()
{}



std::vector<Note> Transform::Octatonic1::transform(std::vector<Note> source)
{
   std::vector<Note> notes = {0, 2, 3, 5, 6, 8, 9, 11};
   return notes;
}



