#pragma once

#include <string>

class IView
{
public:
    virtual ~IView() = default;

    virtual void ShowMainMenu() = 0;
    virtual int ReadMenuChoice() = 0;
    virtual void ShowMessage(const std::string& message) = 0;
};
