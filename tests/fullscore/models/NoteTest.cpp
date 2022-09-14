


#include <gtest/gtest.h>

#include <fullscore/models/Note.hpp>



TEST(NoteTest, can_be_created)
{
   Note note;
}



TEST(NoteTest, when_initialized_without_arguments_pitch_is_set_to_default_pitch_values)
{
   Note note;
   EXPECT_EQ(Pitch(0), note.get_pitch());
}



TEST(NoteTest, when_initialized_without_arguments_duration_is_set_to_default_duration_values)
{
   Note note;
   EXPECT_EQ(Duration(), note.get_duration());
}



TEST(NoteTest, when_initialized_without_arguments_rest_is_set_to_false)
{
   Note note;
   EXPECT_EQ(false, note.get_rest());
}



TEST(NoteTest, can_get_and_set_pitch)
{
   Note note;

   Pitch pitch_1(-123, 7);
   EXPECT_EQ(true, note.set_pitch(pitch_1));
   EXPECT_EQ(pitch_1, note.get_pitch());

   Pitch pitch_2(999, -2);
   EXPECT_EQ(true, note.set_pitch(pitch_2));
   EXPECT_EQ(pitch_2, note.get_pitch());

   Pitch pitch_3(0, 0);
   EXPECT_EQ(true, note.set_pitch(pitch_3));
   EXPECT_EQ(pitch_3, note.get_pitch());
}



TEST(NoteTest, can_get_and_set_duration)
{
   Note note;

   Duration duration_1(Duration::SIXTEENTH, 7);
   EXPECT_EQ(true, note.set_duration(duration_1));
   EXPECT_EQ(duration_1, note.get_duration());

   Duration duration_2(Duration::HALF, -2);
   EXPECT_EQ(true, note.set_duration(duration_2));
   EXPECT_EQ(duration_2, note.get_duration());

   Duration duration_3(Duration::QUARTER, 0);
   EXPECT_EQ(true, note.set_duration(duration_3));
   EXPECT_EQ(duration_3, note.get_duration());
}



TEST(NoteTest, can_get_and_set_rest)
{
   Note note;

   EXPECT_EQ(true, note.set_rest(false));
   EXPECT_EQ(false, note.get_rest());

   EXPECT_EQ(true, note.set_rest(true));
   EXPECT_EQ(true, note.get_rest());
}



TEST(NoteTest, equality_operator_returns_true_on_equal_note)
{
   EXPECT_EQ(true, Note(0, Duration(Duration::QUARTER, 2)).operator==(Note(0, Duration(Duration::QUARTER, 2))));
   EXPECT_EQ(true, Note(14, Duration(Duration::EIGHTH, 0)).operator==(Note(14, Duration(Duration::EIGHTH, 0))));
   EXPECT_EQ(true, Note(-9, Duration(Duration::SIXTEENTH, 8)).operator==(Note(-9, Duration(Duration::SIXTEENTH, 8))));
}



TEST(NoteTest, equality_operator_returns_false_on_unequal_note)
{
   EXPECT_EQ(false, Note(0, Duration(Duration::QUARTER, 0)).operator==(Note(1, Duration(Duration::QUARTER, 0))));
   EXPECT_EQ(false, Note(0, Duration(Duration::QUARTER, 0)).operator==(Note(0, Duration(Duration::THIRTYSECOND, 0))));
   EXPECT_EQ(false, Note(0, Duration(Duration::QUARTER, 0)).operator==(Note(0, Duration(Duration::QUARTER, 1))));
}



