


#include <gtest/gtest.h>

#include <fullscore/components/keyboard_command_mapper.h>



TEST(KeyboardCommandMapperTest, can_get_and_set_mappings)
{
   KeyboardCommandMapper mapper;

   std::string command_identifier_1 = "this_is_the_command";

   EXPECT_TRUE(mapper.set_mapping(14 /*ALLEGRO_KEY_N*/, true, false, true, command_identifier_1));
   EXPECT_EQ(command_identifier_1, mapper.get_mapping(14 /*ALLEGRO_KEY_N*/, true, false, true));
}



TEST(KeyboardCommandMapperTest, can_get_and_set_all_valid_allegro_keycodes)
{
   KeyboardCommandMapper mapper;

   for (unsigned k=0 /*ALLEGRO_KEY_A*/; k<215/*ALLEGRO_KEY_MODIFIERS*/; k++)
   {
      std::string identifier = "this is a test identifier";

      EXPECT_TRUE(          mapper.set_mapping(k, true, true, true, identifier));
      EXPECT_EQ(identifier, mapper.get_mapping(k, true, true, true));

      EXPECT_TRUE(          mapper.set_mapping(k, true, false, true, identifier));
      EXPECT_EQ(identifier, mapper.get_mapping(k, true, false, true));

      EXPECT_TRUE(          mapper.set_mapping(k, true, true, false, identifier));
      EXPECT_EQ(identifier, mapper.get_mapping(k, true, true, false));
   }
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}


