


#include <fullscore/transforms/ClearMeasureTransform.h>

#include <fullscore/Transform.h>



Transform::ClearMeasure::ClearMeasure()
   : Base(Transform::CLEAR_MEASURE_TRANSFORM_IDENTIFIER)
{}



Transform::ClearMeasure::~ClearMeasure()
{}



std::vector<Note> Transform::ClearMeasure::transform(std::vector<Note> source)
{
   return std::vector<Note>();
}



