


#include <gtest/gtest.h>

#include <fullscore/converters/ScientificPitchNotationToPitchConverter.h>



TEST(NoteStringConverterTest, can_be_created)
{
   ScientificPitchNotationToPitchConverter converter('C', 0);
}



TEST(NoteStringConverterTest, with_no_accidental_assumes_0)
{
   ASSERT_EQ(0, ScientificPitchNotationToPitchConverter('C', 4).convert());
}



TEST(NoteStringConverterTest, converts_from_note_names_a_pitch_with_the_expected_values)
{
   ASSERT_EQ(0,  ScientificPitchNotationToPitchConverter('C', 4, 0).convert());
   ASSERT_EQ(2,  ScientificPitchNotationToPitchConverter('D', 4, 0).convert());
   ASSERT_EQ(4,  ScientificPitchNotationToPitchConverter('E', 4, 0).convert());
   ASSERT_EQ(5,  ScientificPitchNotationToPitchConverter('F', 4, 0).convert());
   ASSERT_EQ(7,  ScientificPitchNotationToPitchConverter('G', 4, 0).convert());
   ASSERT_EQ(9,  ScientificPitchNotationToPitchConverter('A', 4, 0).convert());
   ASSERT_EQ(11, ScientificPitchNotationToPitchConverter('B', 4, 0).convert());
}



TEST(NoteStringConverterTest, converts_octaves_with_the_expected_values)
{
   for (int octave=-5; octave<=5; octave++)
   {
      int octave_pitch_offset = octave * 12;
      ASSERT_EQ(0+octave_pitch_offset,  ScientificPitchNotationToPitchConverter('C', 4+octave, 0).convert());
      ASSERT_EQ(2+octave_pitch_offset,  ScientificPitchNotationToPitchConverter('D', 4+octave, 0).convert());
      ASSERT_EQ(4+octave_pitch_offset,  ScientificPitchNotationToPitchConverter('E', 4+octave, 0).convert());
      ASSERT_EQ(5+octave_pitch_offset,  ScientificPitchNotationToPitchConverter('F', 4+octave, 0).convert());
      ASSERT_EQ(7+octave_pitch_offset,  ScientificPitchNotationToPitchConverter('G', 4+octave, 0).convert());
      ASSERT_EQ(9+octave_pitch_offset,  ScientificPitchNotationToPitchConverter('A', 4+octave, 0).convert());
      ASSERT_EQ(11+octave_pitch_offset, ScientificPitchNotationToPitchConverter('B', 4+octave, 0).convert());
   }
}



TEST(NoteStringConverterTest, converts_accidentals_with_the_expected_values)
{
   for (int accidental=-5; accidental<=5; accidental++)
   {
      for (int octave=-5; octave<=5; octave++)
      {
         int octave_pitch_offset = octave * 12;
         ASSERT_EQ(0+octave_pitch_offset+accidental,  ScientificPitchNotationToPitchConverter('C', 4+octave, accidental).convert());
         ASSERT_EQ(2+octave_pitch_offset+accidental,  ScientificPitchNotationToPitchConverter('D', 4+octave, accidental).convert());
         ASSERT_EQ(4+octave_pitch_offset+accidental,  ScientificPitchNotationToPitchConverter('E', 4+octave, accidental).convert());
         ASSERT_EQ(5+octave_pitch_offset+accidental,  ScientificPitchNotationToPitchConverter('F', 4+octave, accidental).convert());
         ASSERT_EQ(7+octave_pitch_offset+accidental,  ScientificPitchNotationToPitchConverter('G', 4+octave, accidental).convert());
         ASSERT_EQ(9+octave_pitch_offset+accidental,  ScientificPitchNotationToPitchConverter('A', 4+octave, accidental).convert());
         ASSERT_EQ(11+octave_pitch_offset+accidental, ScientificPitchNotationToPitchConverter('B', 4+octave, accidental).convert());
      }
   }
}



TEST(NoteStringConverterTest, with_an_invalid_note_name_throws_an_exception)
{
   ASSERT_THROW(ScientificPitchNotationToPitchConverter('X', 4).convert(), std::runtime_error);
}



