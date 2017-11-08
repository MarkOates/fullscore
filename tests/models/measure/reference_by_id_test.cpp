


#include <gtest/gtest.h>

#include <fullscore/models/measures/basic.h>
#include <fullscore/models/measures/reference_by_id.h>



TEST(MeasureReferenceByIDTest, can_be_created)
{
   Measure::ReferenceByID measure(0);
}



TEST(MeasureReferenceByIDTest, can_get_notes_from_a_referenced_measure)
{
   std::vector<Note> notes = { Note(2, Duration::HALF), Note(-1, Duration::EIGHTH), Note(14, Duration::QUARTER) };

   Measure::Basic source_measure(notes);

   Measure::ReferenceByID reference_by_id_measure(source_measure.get_id());

   std::vector<Note> returned_notes = reference_by_id_measure.get_notes_copy();

   ASSERT_EQ(notes, returned_notes);
}



TEST(MeasureReferenceByIDTest, can_get_its_number_of_notes)
{
   Measure::Basic measure1({ Note(0), Note(0), Note(0) });
   Measure::ReferenceByID reference_by_id_measure1(measure1.get_id());
   ASSERT_EQ(3, reference_by_id_measure1.get_num_notes());

   Measure::Basic measure2({ Note(0), Note(0), Note(0), Note(0), Note(0), Note(0), Note(0) });
   Measure::ReferenceByID reference_by_id_measure2(measure2.get_id());
   ASSERT_EQ(7, reference_by_id_measure2.get_num_notes());
}



