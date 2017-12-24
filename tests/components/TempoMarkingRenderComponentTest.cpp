


#include <gtest/gtest.h>

#include <fullscore/components/TempoMarkingRenderComponent.hpp>



TEST(TempoMarkingRenderComponentTest, can_be_created)
{
   // TODO
}



TEST(TempoMarkingRenderComponentTest, with_an_invalid_font_argument_raises_an_exception)
{
   TempoMarking tempo_marking(Duration(Duration::QUARTER, 3), 128);

   try
   {
      TempoMarkingRenderComponent tempo_marking_render_component(nullptr, 0, 0, tempo_marking);
   }
   catch (std::invalid_argument const &e)
   {
      EXPECT_EQ(e.what(), std::string("Cannot create a TempoMarkingRenderComponent with a nullptr font"));
   }
   catch (...)
   {
      FAIL() << "Expected std::invalid_argument";
   }
}



