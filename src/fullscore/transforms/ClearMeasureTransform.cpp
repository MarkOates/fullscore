


#include <fullscore/transforms/ClearMeasureTransform.hpp>

#include <fullscore/TransformNames.hpp>



Transform::ClearMeasure::ClearMeasure()
   : Base(TransformNames::CLEAR_MEASURE_TRANSFORM_IDENTIFIER)
{}



Transform::ClearMeasure::~ClearMeasure()
{}



std::vector<Note> Transform::ClearMeasure::transform(std::vector<Note> source)
{
   return std::vector<Note>();
}



