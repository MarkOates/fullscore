


#include <fullscore/transforms/ClearMeasureTransform.hpp>

#include <fullscore/Transform.hpp>



Transform::ClearMeasure::ClearMeasure()
   : Base(Transform::CLEAR_MEASURE_TRANSFORM_IDENTIFIER)
{}



Transform::ClearMeasure::~ClearMeasure()
{}



std::vector<Note> Transform::ClearMeasure::transform(std::vector<Note> source)
{
   return std::vector<Note>();
}



