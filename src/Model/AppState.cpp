#include "AppState.h"

AppState::AppState()
    : currentMenu(MenuState::Main)
    , running(true)
{
}

MenuState AppState::GetCurrentMenu() const
{
    return currentMenu;
}

void AppState::SetCurrentMenu(MenuState menu)
{
    currentMenu = menu;
}

bool AppState::IsRunning() const
{
    return running;
}

void AppState::Stop()
{
    running = false;
}
