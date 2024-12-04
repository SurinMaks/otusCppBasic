#include <gtest/gtest.h>
#include "../include/MyArray.hpp"

TEST(Array, Create) {
    // Arrange
    MyArray<int> myArray;

    // Act (empty for this test)

    // Assert
    ASSERT_EQ(myArray.size(), 0);
}


// int main(int argc, char** argv) {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }