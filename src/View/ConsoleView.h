#pragma once

#include <iostream>
#include "IView.h"

class ConsoleView : public IView
{
public:
    ConsoleView(std::istream& in = std::cin, std::ostream& out = std::cout);

    void ShowMainMenu() override;
    int ReadMenuChoice() override;
    void ShowMessage(const std::string& message) override;

private:
    std::istream& input;
    std::ostream& output;
};
