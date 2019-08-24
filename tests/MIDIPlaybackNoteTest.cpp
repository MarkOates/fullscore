
#include <gtest/gtest.h>

#include <MIDIPlaybackNote.hpp>

TEST(MIDIPlaybackNoteTest, run__returns_the_expected_response)
{
   MIDIPlaybackNote program_runner;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, program_runner.run());
}
