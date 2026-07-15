#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Controller/MainController.h"
#include "Model/AppState.h"
#include "View/IView.h"

using ::testing::_;
using ::testing::HasSubstr;
using ::testing::Return;

class MockView : public IView
{
public:
    MOCK_METHOD(void, ShowMainMenu, (), (override));
    MOCK_METHOD(int, ReadMenuChoice, (), (override));
    MOCK_METHOD(void, ShowMessage, (const std::string& message), (override));
};

TEST(MainControllerTest, ValidChoiceKeepsAppRunning)
{
    AppState state;
    MockView view;
    EXPECT_CALL(view, ReadMenuChoice()).WillOnce(Return(1));
    EXPECT_CALL(view, ShowMessage(HasSubstr("Start")));

    MainController controller(state, view);
    controller.HandleInput();

    EXPECT_TRUE(state.IsRunning());
}

TEST(MainControllerTest, ZeroChoiceStopsApp)
{
    AppState state;
    MockView view;
    EXPECT_CALL(view, ReadMenuChoice()).WillOnce(Return(0));
    EXPECT_CALL(view, ShowMessage(_));

    MainController controller(state, view);
    controller.HandleInput();

    EXPECT_FALSE(state.IsRunning());
}

TEST(MainControllerTest, InvalidChoiceShowsErrorAndKeepsRunning)
{
    AppState state;
    MockView view;
    EXPECT_CALL(view, ReadMenuChoice()).WillOnce(Return(99));
    EXPECT_CALL(view, ShowMessage(HasSubstr("Invalid")));

    MainController controller(state, view);
    controller.HandleInput();

    EXPECT_TRUE(state.IsRunning());
}
