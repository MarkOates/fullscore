#pragma once



#include <fullscore/actions/Base.h>



class AppController;
class UIGridEditor;

namespace UI::GridEditor::Actions
{
   class SetCurrentUIGridEditor : public Base
   {
   private:
      AppController *app_controller;
      UIGridEditor *grid_editor;

   public:
      SetCurrentUIGridEditor(AppController *app_controller, UIGridEditor *grid_editor);
      ~SetCurrentUIGridEditor();

      bool execute() override;
   };
};



