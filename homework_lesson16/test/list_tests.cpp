#include <gtest/gtest.h>
#include "../include/MyList.hpp"

TEST(List, Create) {
    // Arrange
    MyList myList0{0};

    // Act (empty for this test)

    // Assert
    ASSERT_EQ(myList0.size(), 1);
}


// int main(int argc, char** argv) {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
