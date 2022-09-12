


#include <gtest/gtest.h>

#include <fullscore/models/measures/Stack.hpp>

#include <fullscore/transforms/DoubleDurationTransform.hpp>
#include <fullscore/transforms/EraseNoteTransform.hpp>
#include <fullscore/transforms/RetrogradeTransform.hpp>
#include <fullscore/transforms/Octatonic1Transform.hpp>



TEST(MeasureStackTest, can_be_created)
{
   Measure::Stack measure;
}



TEST(MeasureStackTest, returns_a_nullptr_when_asked_for_a_ponter_to_its_notes)
{
   Measure::Stack measure;

   measure.transformations.add_transform(new Transform::Octatonic1());
   measure.transformations.add_transform(new Transform::EraseNote(0));
   measure.transformations.add_transform(new Transform::EraseNote(2));

   ASSERT_EQ(nullptr, measure.get_notes_pointer());
}



TEST(MeasureStackTest, with_transformations_returns_the_number_of_notes)
{
   Measure::Stack measure;

   measure.transformations.add_transform(new Transform::Octatonic1());
   measure.transformations.add_transform(new Transform::EraseNote(0));
   measure.transformations.add_transform(new Transform::EraseNote(2));

   int num_returned_notes = measure.get_num_notes();

   ASSERT_EQ(6, num_returned_notes);
}



TEST(MeasureStackTest, with_a_transformation_populates_its_notes)
{
   Measure::Stack measure;

   measure.transformations.add_transform(new Transform::Octatonic1());
   measure.transformations.add_transform(new Transform::EraseNote(0));
   measure.transformations.add_transform(new Transform::EraseNote(2));
   measure.transformations.add_transform(new Transform::DoubleDuration());
   measure.transformations.add_transform(new Transform::Retrograde());

   std::vector<Note> expected_notes = {
      Note(11, Duration::HALF),
      Note(9, Duration::HALF),
      Note(8, Duration::HALF),
      Note(6, Duration::HALF),
      Note(3, Duration::HALF),
      Note(2, Duration::HALF),
   };
   std::vector<Note> measure_notes = measure.get_notes_copy();

   ASSERT_EQ(expected_notes, measure_notes);
}



