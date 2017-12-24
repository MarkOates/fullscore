#pragma once



#include <fullscore/actions/Base.h>



class AppController;
class UIGridEditor;

namespace Action
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


