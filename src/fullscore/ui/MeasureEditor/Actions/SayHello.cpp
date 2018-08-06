

#include <fullscore/UI/MeasureEditor/Actions/SayHello.hpp>

#include <fullscore/UI/MeasureEditor/Actions.hpp>
#include <iostream>


namespace UI::MeasureEditor::Actions
{


SayHello::SayHello()
   : ::Action::Base(SAY_HELLO_ACTION_IDENTIFIER)
{}


SayHello::~SayHello()
{}


bool SayHello::execute()
{
   std::cout << "Hello! MeasureEditor" << std::endl;

   return false;
}


} // namespace UI::MeasureEditor::Actions


