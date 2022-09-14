


#include <fullscore/Transforms/ClearMeasureTransform.hpp>

#include <fullscore/TransformNames.hpp>



Transforms::ClearMeasure::ClearMeasure()
   : Base(TransformNames::CLEAR_MEASURE_TRANSFORM_IDENTIFIER)
{}



Transforms::ClearMeasure::~ClearMeasure()
{}



std::vector<Note> Transforms::ClearMeasure::transform(std::vector<Note> source)
{
   return std::vector<Note>();
}



