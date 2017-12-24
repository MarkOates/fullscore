


#include <gtest/gtest.h>

#include <fullscore/actions/CreateFloatingMeasureAction.h>
#include <fullscore/models/FloatingMeasure.h>
#include <fullscore/Action.h>



TEST(CreateFloatingMeasureActionTest, can_be_created)
{
   Action::CreateFloatingMeasure create_floating_measure_action(GridCoordinate(), 0);
}



TEST(CreateFloatingMeasureActionTest, has_the_expected_action_name)
{
   Action::CreateFloatingMeasure create_floating_measure_action(GridCoordinate(), 0);

   ASSERT_EQ(Action::CREATE_FLOATING_MEASURE_ACTION_IDENTIFIER, create_floating_measure_action.get_action_name());
}



TEST(CreateFloatingMeasureActionTest, creates_a_floating_measure_with_the_expected_values)
{
   GridCoordinate grid_coordinate = GridCoordinate(2, GridHorizontalCoordinate{7, 13});
   int measure_id = 11;
   Action::CreateFloatingMeasure create_floating_measure_action(grid_coordinate, measure_id);

   std::vector<FloatingMeasure *> initial_floating_measure_elements = FloatingMeasure::get_pool_elements();

   ASSERT_EQ(0, initial_floating_measure_elements.size());

   ASSERT_TRUE(create_floating_measure_action.execute());

   std::vector<FloatingMeasure *> floating_measure_elements = FloatingMeasure::get_pool_elements();

   ASSERT_EQ(1, floating_measure_elements.size());
   ASSERT_EQ(grid_coordinate, floating_measure_elements[0]->get_grid_coordinate());
   ASSERT_EQ(measure_id, floating_measure_elements[0]->get_measure_id());
}



TEST(CreateFloatingMeasureActionTest, returns_the_id_of_the_newly_created_floating_measure)
{
   Action::CreateFloatingMeasure create_floating_measure_action({}, 0);
   int expected_next_id = FloatingMeasure::get_next_id();

   ASSERT_TRUE(create_floating_measure_action.execute());

   std::vector<FloatingMeasure *> floating_measure_elements = FloatingMeasure::get_pool_elements();

   ASSERT_EQ(expected_next_id, floating_measure_elements.back()->get_id());
   ASSERT_EQ(expected_next_id, create_floating_measure_action.get_created_floating_measure_id());
}



TEST(CreateFloatingMeasureActionTest, if_a_floating_measure_has_not_been_created_yet_returns_a_floating_measure_id_of_negative_1)
{
   Action::CreateFloatingMeasure create_floating_measure_action({}, 0);
   ASSERT_EQ(-1, create_floating_measure_action.get_created_floating_measure_id());
}



