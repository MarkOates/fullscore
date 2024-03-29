



#include <gtest/gtest.h>

#include <fullscore/services/PitchProjector.hpp>




TEST(PitchProjectorTest, projects_an_index_set_through_a_projection_set__TEST_1)
{
   ProjectionSet projection_set({0, 2, 4, 6, 7, 9, 11}, 12);
   IndexSet index_set({0, 1, 2, 3});

   PitchProjector projector(projection_set, index_set);
   IndexSet result = projector.get_projection();

   IndexSet expected_result = IndexSet({0, 2, 4, 6});
   EXPECT_EQ(expected_result, result);
}




TEST(PitchProjectorTest, projects_an_index_set_through_a_projection_set__TEST_2)
{
   PitchProjector projector(ProjectionSet({0, 2, 3, 5, 6, 8, 9, 11}, 12), IndexSet({0, 1, 2, 3}));
   IndexSet result = projector.get_projection();

   IndexSet expected_result = IndexSet({0, 2, 3, 5});
   EXPECT_EQ(expected_result, result);
}




TEST(PitchProjectorTest, extends_a_projection)
{
   PitchProjector projector(ProjectionSet({0}, 3), IndexSet({0, 1, 2, 3}));
   IndexSet result = projector.get_projection();
   IndexSet expected_result = IndexSet({0, 3, 6, 9});

   EXPECT_EQ(expected_result, result);
}




TEST(PitchProjectorTest, extends_a_projection_into_negative_numbers_TEST_1)
{
   PitchProjector projector(ProjectionSet({0}, 4), IndexSet({0, -1, -2, -3}));
   IndexSet result = projector.get_projection();
   IndexSet expected_result = IndexSet({0, -4, -8, -12});

   EXPECT_EQ(expected_result, result);
}




TEST(PitchProjectorTest, extends_a_projection_into_negative_numbers_TEST_2)
{
   PitchProjector projector(ProjectionSet({0, 1}, 12), IndexSet({0, -1, -2, -3}));
   IndexSet result = projector.get_projection();
   IndexSet expected_result = IndexSet({0, -11, -12, -23});

   EXPECT_EQ(expected_result, result);
}




TEST(PitchProjectorTest, with_an_extension_of_0_will_wrap_on_outside_index_values)
{
   PitchProjector projector(ProjectionSet({0, 2}, 0), IndexSet({0, -1, -2, -3}));
   IndexSet result = projector.get_projection();
   IndexSet expected_result = IndexSet({0, 2, 0, 2});

   EXPECT_EQ(expected_result, result);
}




TEST(PitchProjectorTest, with_an_empty_projection_set_will_return_an_empty_result)
{
   PitchProjector projector(ProjectionSet({}, 0), IndexSet({0, -1, -2, -3}));
   IndexSet result = projector.get_projection();
   IndexSet expected_result = IndexSet({});

   EXPECT_EQ(expected_result, result);
}




TEST(PitchProjectorTest, with_an_empty_index_set_will_return_an_empty_result)
{
   PitchProjector projector(ProjectionSet({1, 2, 3, 4}, 5), IndexSet({}));
   IndexSet result = projector.get_projection();
   IndexSet expected_result = IndexSet({});

   EXPECT_EQ(expected_result, result);
}



TEST(PitchProjectorTest, does_not_explode_like_in_the_projection_calculator_program)
{
   PitchProjector projector(ProjectionSet({0, 1, 2, 3, 4}, 12), IndexSet({0, -1, 2, 3, 4}));
   IndexSet result = projector.get_projection();
   IndexSet expected_result = IndexSet({0, -8, 2, 3, 4});

   EXPECT_EQ(expected_result, result);
}




