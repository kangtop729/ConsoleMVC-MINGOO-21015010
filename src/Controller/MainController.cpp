#include "MainController.h"

namespace
{
    constexpr int ExitChoice = 0;
    constexpr int StartChoice = 1;
}

MainController::MainController(AppState& state, IView& view)
    : state(state)
    , view(view)
{
}

void MainController::HandleInput()
{
    const int choice = view.ReadMenuChoice();

    if (choice == ExitChoice)
    {
        state.Stop();
        view.ShowMessage("Exiting ConsoleMVC PoC");
    }
    else if (choice == StartChoice)
    {
        view.ShowMessage("Start selected");
    }
    else
    {
        view.ShowMessage("Invalid choice");
    }
}
