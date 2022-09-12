#pragma once



#include <fullscore/actions/Base.h>



class AppController;
namespace UI::GridEditor { class Widget; }

namespace UI::GridEditor::Actions
{
   class SetCurrentUIGridEditor : public Action::Base
   {
   private:
      AppController *app_controller;
      UI::GridEditor::Widget *grid_editor;

   public:
      SetCurrentUIGridEditor(AppController *app_controller, UI::GridEditor::Widget *grid_editor);
      ~SetCurrentUIGridEditor();

      bool execute() override;
   };
};



