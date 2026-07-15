#include <gtest/gtest.h>
#include "Model/AppState.h"

TEST(AppStateTest, InitialStateIsMainMenuAndRunning)
{
    AppState state;

    EXPECT_EQ(state.GetCurrentMenu(), MenuState::Main);
    EXPECT_TRUE(state.IsRunning());
}

TEST(AppStateTest, StopSetsRunningFalse)
{
    AppState state;

    state.Stop();

    EXPECT_FALSE(state.IsRunning());
}

TEST(AppStateTest, SetCurrentMenuChangesCurrentMenu)
{
    AppState state;

    state.SetCurrentMenu(MenuState::SubMenuA);

    EXPECT_EQ(state.GetCurrentMenu(), MenuState::SubMenuA);
}
