


#include <gtest/gtest.h>

#include <fullscore/converters/note_string_converter.h>

#include <fullscore/models/Duration.h>
#include <fullscore/models/note.h>



TEST(NoteStringConverterTest, converts_a_note_to_a_string)
{
   Note note(5, Duration(Duration::SIXTEENTH, 3));
   note.pitch.accidental = -2;
   note.duration.dots = 3;
   note.is_rest = true;
   NoteStringConverter converter(&note);

   EXPECT_EQ("5 -2 16 3 1", converter.write());
}



TEST(NoteStringConverterTest, converts_a_string_to_a_note)
{
   Note source_note;

   NoteStringConverter converter(&source_note);

   Note expected_note(5, Duration(Duration::SIXTEENTH, 3));
   expected_note.pitch.accidental = -2;
   expected_note.duration.dots = 3;
   expected_note.is_rest = true;

   EXPECT_EQ(true, converter.read("5 -2 16 3 1"));
   EXPECT_EQ(expected_note, source_note);
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



