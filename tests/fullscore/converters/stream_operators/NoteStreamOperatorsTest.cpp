


#include <gtest/gtest.h>

#include <fullscore/converters/stream_operators/NoteStreamOperators.hpp>
#include <fullscore/models/Note.hpp>



TEST(NoteStreamOperatorsTest, outputs_to_a_stream_operator)
{
   Note note(7, Duration(Duration::SIXTEENTH, 3));
   note.set_pitch(Pitch(note.get_pitch().get_scale_degree(), -5));
   note.set_rest(true);

   std::stringstream ss;

   ss << note;

   ASSERT_EQ("7 -5 16 3 1", ss.str());
}



TEST(NoteStreamOperatorsTest, inputs_from_a_stream_operator)
{
   Note note(7, Duration(Duration::SIXTEENTH, 3));
   note.set_pitch(Pitch(note.get_pitch().get_scale_degree(), -5));
   note.set_rest(true);

   std::stringstream ss;

   ss << "7 -5 16 3 1";
   ss >> note;

   ASSERT_EQ(Pitch(7, -5), note.get_pitch());
   ASSERT_EQ(Duration(Duration::SIXTEENTH, 3), note.get_duration());
   ASSERT_EQ(true, note.get_rest());
}



TEST(NoteStreamOperatorsTest, stream_operators_are_symmetrical)
{
   Note note(7, Duration(Duration::SIXTEENTH, 3));
   note.set_pitch(Pitch(note.get_pitch().get_scale_degree(), -5));
   note.set_rest(true);

   std::string expected_string = "7 -5 16 3 1";

   std::stringstream ss;

   ss << note;
   ss >> note;
   ss << note;

   ASSERT_EQ(expected_string, ss.str());
}



