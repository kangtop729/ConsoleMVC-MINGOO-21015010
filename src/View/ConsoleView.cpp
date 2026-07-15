#include "ConsoleView.h"

ConsoleView::ConsoleView(std::istream& in, std::ostream& out)
    : input(in)
    , output(out)
{
}

void ConsoleView::ShowMainMenu()
{
    output << "1. Start\n";
    output << "0. Exit\n";
}

int ConsoleView::ReadMenuChoice()
{
    int choice = 0;
    input >> choice;
    return choice;
}

void ConsoleView::ShowMessage(const std::string& message)
{
    output << message << "\n";
}
