


#include <gtest/gtest.h>

#include <fullscore/transforms/reference.h>

#include <fullscore/models/measure_grid.h>



TEST(ReferenceTransformTest, can_be_created)
{
   MeasureGrid measure_grid(1, 1);
   Transform::Reference reference_transform(&measure_grid, 0, 0);
}



TEST(ReferenceTransformTest, copies_a_set_of_notes_from_a_measure_grid_and_coordinates)
{
   std::vector<Note> source_notes = {};

   MeasureGrid measure_grid(1, 1);
   Measure::Basic *measure = measure_grid.get_measure(0, 0);
   measure->set_notes({ Note(2), Note(0), Note(1) });

   Transform::Reference reference_transform(&measure_grid, 0, 0);

   std::vector<Note> expected_notes = { Note(2), Note(0), Note(1) };
   std::vector<Note> returned_notes = reference_transform.transform(source_notes);

   EXPECT_EQ(expected_notes, returned_notes);
}



TEST(ReferenceTransformTest, when_referencing_a_measure_grid_that_does_not_exist__raises_an_exception)
{
   Transform::Reference reference_transform(nullptr, 0, 0);

   ASSERT_THROW(reference_transform.transform({}), std::runtime_error);
}



TEST(ReferenceTransformTest, transform__with_coordinates_that_are_outside_the_grid__raises_an_exception)
{
   MeasureGrid measure_grid(1, 1);
   Transform::Reference reference_transform(&measure_grid, 9999, 9999);

   ASSERT_THROW(reference_transform.transform({}), std::runtime_error);
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



