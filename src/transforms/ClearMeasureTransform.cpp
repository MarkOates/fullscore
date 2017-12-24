


#include <fullscore/transforms/ClearMeasureTransform.h>



Transform::ClearMeasure::ClearMeasure()
   : Base("clear_measure")
{}



Transform::ClearMeasure::~ClearMeasure()
{}



std::vector<Note> Transform::ClearMeasure::transform(std::vector<Note> source)
{
   return std::vector<Note>();
}


