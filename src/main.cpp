#include <iostream>

#ifdef _DEBUG
#include <gtest/gtest.h>
#endif

int main(int argc, char** argv)
{
#ifdef _DEBUG
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#else
    std::cout << "ConsoleMVC PoC" << std::endl;
    return 0;
#endif
}
