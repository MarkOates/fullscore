

#include <fullscore/UI/PlotterEditor/Actions/SayHello.hpp>

#include <fullscore/UI/PlotterEditor/Actions.hpp>
#include <iostream>


namespace UI::PlotterEditor::Actions
{


SayHello::SayHello()
   : ::Action::Base(SAY_HELLO_ACTION_IDENTIFIER)
{}


SayHello::~SayHello()
{}


bool SayHello::execute()
{
   std::cout << "Hello! PlotterEditor" << std::endl;

   return false;
}


} // namespace UI::PlotterEditor::Actions


