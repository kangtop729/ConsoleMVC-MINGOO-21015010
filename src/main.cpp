#ifdef _DEBUG
#include <gtest/gtest.h>
#else
#include "Model/AppState.h"
#include "View/ConsoleView.h"
#include "Controller/MainController.h"
#endif

int main(int argc, char** argv)
{
#ifdef _DEBUG
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#else
    AppState state;
    ConsoleView view;
    MainController controller(state, view);

    view.ShowMainMenu();
    while (state.IsRunning())
    {
        controller.HandleInput();
        if (state.IsRunning())
        {
            view.ShowMainMenu();
        }
    }

    return 0;
#endif
}
