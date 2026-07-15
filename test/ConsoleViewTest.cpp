#include <gtest/gtest.h>
#include <sstream>
#include "View/ConsoleView.h"

TEST(ConsoleViewTest, ShowMainMenuPrintsMenuOptions)
{
    std::istringstream in;
    std::ostringstream out;
    ConsoleView view(in, out);

    view.ShowMainMenu();

    EXPECT_NE(out.str().find("1"), std::string::npos);
    EXPECT_NE(out.str().find("0"), std::string::npos);
}

TEST(ConsoleViewTest, ReadMenuChoiceReturnsInputNumber)
{
    std::istringstream in("2\n");
    std::ostringstream out;
    ConsoleView view(in, out);

    EXPECT_EQ(view.ReadMenuChoice(), 2);
}

TEST(ConsoleViewTest, ShowMessagePrintsGivenMessage)
{
    std::istringstream in;
    std::ostringstream out;
    ConsoleView view(in, out);

    view.ShowMessage("Hello");

    EXPECT_NE(out.str().find("Hello"), std::string::npos);
}
