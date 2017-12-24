


#include <gtest/gtest.h>

#include <fullscore/models/measures/Base.h>



class MeasureBaseTestDerivedClass : public Measure::Base
{
private:
   std::vector<Note> notes;

public:
   MeasureBaseTestDerivedClass()
      : Measure::Base("test_derived_class")
      , notes({ Note(0, Duration::HALF), Note(3, Duration::SIXTEENTH) })
   {}
   virtual int get_num_notes() override
   {
      return notes.size();
   }
   virtual std::vector<Note> get_notes_copy() override
   {
      return notes;
   }
   virtual bool set_notes(std::vector<Note> notes) override
   {
      this->notes = notes;
      return true;
   }
   virtual std::vector<Note> *get_notes_pointer() override
   {
      return &notes;
   }
};



TEST(MeasureBaseTest, can_be_created)
{
   MeasureBaseTestDerivedClass measure_base;
}



TEST(MeasureBaseTest, returns_its_type)
{
   MeasureBaseTestDerivedClass measure_base;
   ASSERT_EQ("test_derived_class", measure_base.get_type());
}



TEST(MeasureBaseTest, returns_true_if_matches_type)
{
   MeasureBaseTestDerivedClass measure_base;
   ASSERT_EQ(true, measure_base.is_type("test_derived_class"));
}



TEST(MeasureBaseTest, returns_false_if_does_not_matche_type)
{
   MeasureBaseTestDerivedClass measure_base;
   ASSERT_EQ(false, measure_base.is_type("definitely_not_this_type"));
}



TEST(MeasureBaseTest, returns_a_copy_of_its_notes)
{
   MeasureBaseTestDerivedClass measure_base;
   std::vector<Note> expected_notes = { Note(0, Duration::HALF), Note(3, Duration::SIXTEENTH) };
   std::vector<Note> returned_notes = measure_base.get_notes_copy();

   ASSERT_EQ(expected_notes, returned_notes);
}



TEST(MeasureBaseTest, returns_a_pointer_to_its_notes)
{
   MeasureBaseTestDerivedClass measure_base;
   std::vector<Note> expected_notes = { Note(0, Duration::HALF), Note(3, Duration::SIXTEENTH) };
   std::vector<Note> *returned_notes = measure_base.get_notes_pointer();

   ASSERT_EQ(2, returned_notes->size());
   ASSERT_EQ(expected_notes.size(), returned_notes->size());

   for (unsigned i=0; i<returned_notes->size(); i++)
      ASSERT_EQ(expected_notes[i], (*returned_notes).at(i));
}



