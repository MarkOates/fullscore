

#include <fullscore/SimpleNothing.hpp>
#include <iostream>
#include <iostream>
#include <fullscore/models/Note.h>
#include <fullscore/converters/stream_operators/NoteStreamOperators.h>
#include <fullscore/converters/stream_operators/PitchStreamOperators.h>
#include <fullscore/converters/stream_operators/DurationStreamOperators.h>
#include <fullscore/converters/stream_operators/StaffStreamOperators.h>
#include <fullscore/Cursor.hpp>


namespace fullscore
{


SimpleNothing::SimpleNothing()
   : cursor()
{
}


SimpleNothing::~SimpleNothing()
{
}


void SimpleNothing::set_cursor(fullscore::Cursor cursor)
{
   this->cursor = cursor;
}


fullscore::Cursor SimpleNothing::get_cursor()
{
   return cursor;
}


void SimpleNothing::output_message()
{
Note note;
note.set_duration(Duration(Duration::QUARTER, 2));
note.set_pitch(Pitch(2, 0));
std::cout << note << std::endl;

}
} // namespace fullscore


