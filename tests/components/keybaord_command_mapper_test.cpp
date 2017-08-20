


#include <gtest/gtest.h>

#include <fullscore/components/keyboard_command_mapper.h>



TEST(KeyboardCommandMapperTest, can_get_and_set_mappings)
{
   KeyboardCommandMapper mapper;

   std::string command_identifier_1 = "this_is_the_command";

   EXPECT_TRUE(mapper.set_mapping(14 /*ALLEGRO_KEY_N*/, true, false, true, command_identifier_1));
   EXPECT_EQ(command_identifier_1, mapper.get_mapping(14 /*ALLEGRO_KEY_N*/, true, false, true));
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



