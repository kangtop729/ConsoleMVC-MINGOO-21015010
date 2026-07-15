#pragma once

#include "Model/AppState.h"
#include "View/IView.h"

class MainController
{
public:
    MainController(AppState& state, IView& view);

    void HandleInput();

private:
    AppState& state;
    IView& view;
};
