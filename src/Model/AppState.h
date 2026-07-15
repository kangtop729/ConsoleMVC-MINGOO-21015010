#pragma once

enum class MenuState
{
    Main,
    SubMenuA,
};

class AppState
{
public:
    AppState();

    MenuState GetCurrentMenu() const;
    void SetCurrentMenu(MenuState menu);

    bool IsRunning() const;
    void Stop();

private:
    MenuState currentMenu;
    bool running;
};
