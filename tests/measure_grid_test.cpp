


#include <gtest/gtest.h>

#include <fullscore/models/measure_grid.h>
#include <fullscore/models/note.h>



TEST(MeasureGridTest, creates_successfully)
{
   MeasureGrid measure_grid(1, 1);
}



TEST(MeasureGridTest, returns_the_number_of_staves)
{
   MeasureGrid measure_grid(17, 13);

   EXPECT_EQ(13, measure_grid.get_num_staves());
}



TEST(MeasureGridTest, returns_the_number_of_measures)
{
   MeasureGrid measure_grid(17, 3);

   EXPECT_EQ(17, measure_grid.get_num_measures());
}



TEST(MeasureGridTest, sets_and_gets_the_name_of_a_row)
{
   MeasureGrid measure_grid(1, 3);

   EXPECT_EQ(true, measure_grid.set_voice_name(0, "Trombone"));
   EXPECT_EQ("Trombone", measure_grid.get_voice_name(0));

   EXPECT_EQ(true, measure_grid.set_voice_name(2, "Euphonium"));
   EXPECT_EQ("Euphonium", measure_grid.get_voice_name(2));

   EXPECT_EQ(true, measure_grid.set_voice_name(2, "Tuba"));
   EXPECT_EQ("Tuba", measure_grid.get_voice_name(2));
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



