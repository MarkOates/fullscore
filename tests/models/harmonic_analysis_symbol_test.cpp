


#include <gtest/gtest.h>

#include <fullscore/models/harmonic_analysis_symbol.h>



TEST(HarmonicAnalysisSymbolTest, can_be_created)
{
   HarmonicAnalysisSymbol harmonic_analysis_symbol(0, HarmonicAnalysisSymbol::MAJOR, 0, {});
}



TEST(HarmonicAnalysisSymbolTest, returns_major_and_minor_roman_numerals_for_values_0_to_11)
{
   std::vector<std::string> expected_major_values = { "O", "I", "II", "III", "IV", "V", "VI", "VII", "IIX", "IX", "X", "XI" };
   std::vector<std::string> expected_minor_values = { "o", "i", "ii", "iii", "iv", "v", "vi", "vii", "iix", "ix", "x", "xi" };

   for (int i=0; i<expected_major_values.size(); i++)
   {
      ASSERT_EQ(expected_major_values[i], HarmonicAnalysisSymbol::get_roman_numeral_string(i, HarmonicAnalysisSymbol::MAJOR));
      ASSERT_EQ(expected_major_values[i], HarmonicAnalysisSymbol::get_roman_numeral_string(i, HarmonicAnalysisSymbol::AUGMENTED));

      ASSERT_EQ(expected_minor_values[i], HarmonicAnalysisSymbol::get_roman_numeral_string(i, HarmonicAnalysisSymbol::MINOR));
      ASSERT_EQ(expected_minor_values[i], HarmonicAnalysisSymbol::get_roman_numeral_string(i, HarmonicAnalysisSymbol::DIMINISHED));
   }
}



TEST(HarmonicAnalysisSymbolTest, with_a_scale_degree_that_does_not_exist_returns_dashes)
{
   std::string expected_string = "--";

   ASSERT_EQ(expected_string, HarmonicAnalysisSymbol::get_roman_numeral_string(12, HarmonicAnalysisSymbol::MAJOR));
   ASSERT_EQ(expected_string, HarmonicAnalysisSymbol::get_roman_numeral_string(999, HarmonicAnalysisSymbol::MAJOR));
   ASSERT_EQ(expected_string, HarmonicAnalysisSymbol::get_roman_numeral_string(-1, HarmonicAnalysisSymbol::MAJOR));

   ASSERT_EQ(expected_string, HarmonicAnalysisSymbol::get_roman_numeral_string(12, HarmonicAnalysisSymbol::MINOR));
   ASSERT_EQ(expected_string, HarmonicAnalysisSymbol::get_roman_numeral_string(999, HarmonicAnalysisSymbol::MINOR));
   ASSERT_EQ(expected_string, HarmonicAnalysisSymbol::get_roman_numeral_string(-1, HarmonicAnalysisSymbol::MINOR));
}



TEST(HarmonicAnalysisSymbolTest, returns_a_string_from_accidental)
{
   ASSERT_EQ("b", HarmonicAnalysisSymbol::get_accidental_string(-1));
   ASSERT_EQ("bbb", HarmonicAnalysisSymbol::get_accidental_string(-3));

   ASSERT_EQ("", HarmonicAnalysisSymbol::get_accidental_string(0));

   ASSERT_EQ("#", HarmonicAnalysisSymbol::get_accidental_string(1));
   ASSERT_EQ("###", HarmonicAnalysisSymbol::get_accidental_string(3));
}



TEST(HarmonicAnalysisSymbolTest, returns_a_string_for_a_chord_quality_symbol)
{
   ASSERT_EQ("o", HarmonicAnalysisSymbol::get_chord_quality_symbol_string(HarmonicAnalysisSymbol::DIMINISHED));
   ASSERT_EQ("+", HarmonicAnalysisSymbol::get_chord_quality_symbol_string(HarmonicAnalysisSymbol::AUGMENTED));

   ASSERT_EQ("", HarmonicAnalysisSymbol::get_chord_quality_symbol_string(HarmonicAnalysisSymbol::MAJOR));
   ASSERT_EQ("", HarmonicAnalysisSymbol::get_chord_quality_symbol_string(HarmonicAnalysisSymbol::MINOR));
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



