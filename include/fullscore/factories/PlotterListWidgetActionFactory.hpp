#pragma once


#include <string>


class PlotterListWidget;
namespace Action { class Base; }


class PlotterListWidgetActionFactory
{
public:
   static Action::Base *create_action(PlotterListWidget *plotter_list_widget, std::string action_name);
};



