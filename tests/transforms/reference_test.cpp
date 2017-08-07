


#include <gtest/gtest.h>

#include <fullscore/transforms/reference_transform.h>

#include <fullscore/models/measures/basic.h>
#include <fullscore/models/grid.h>



TEST(ReferenceTransformTest, can_be_created)
{
   MeasureGrid grid(1, 1);
   Transform::Reference reference_transform(&grid, 0, 0);
}



TEST(ReferenceTransformTest, copies_a_set_of_notes_from_a_grid_and_coordinates)
{
   std::vector<Note> source_notes = {};

   MeasureGrid grid(1, 1);
   grid.set_measure(0, 0, new Measure::Basic({ Note(2), Note(0), Note(1) }));
   Measure::Base *measure = grid.get_measure(0, 0);
   ASSERT_NE(nullptr, measure);

   Transform::Reference reference_transform(&grid, 0, 0);

   std::vector<Note> expected_notes = { Note(2), Note(0), Note(1) };
   std::vector<Note> returned_notes = reference_transform.transform(source_notes);

   EXPECT_EQ(expected_notes, returned_notes);
}



TEST(ReferenceTransformTest, when_referencing_a_grid_that_does_not_exist__raises_an_exception)
{
   Transform::Reference reference_transform(nullptr, 0, 0);

   ASSERT_THROW(reference_transform.transform({}), std::runtime_error);
}



TEST(ReferenceTransformTest, transform__with_coordinates_that_are_outside_the_grid__raises_an_exception)
{
   MeasureGrid grid(1, 1);
   Transform::Reference reference_transform(&grid, 9999, 9999);

   ASSERT_THROW(reference_transform.transform({}), std::runtime_error);
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



