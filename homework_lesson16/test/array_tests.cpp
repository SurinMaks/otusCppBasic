#include <gtest/gtest.h>
#include "../include/MyArray.hpp"

TEST(Array, Create) {
    MyArray<int> myArray;

    ASSERT_EQ(myArray.size(), 0);
}

TEST(Array, push_back) {

    MyArray<int> myArray;

    myArray.insertFromEnd(1);
    std::string strRez = "1 ";
    std::string strGetList = myArray.getList();

    ASSERT_EQ(myArray.size(), 1);
    ASSERT_STREQ(strGetList.c_str() ,strRez.c_str());
}

TEST(Array, insertFromBegin) {

    MyArray<int> myArray;

    myArray.insertFromBegin(1);
    std::string strRez = "1 ";
    std::string strGetList = myArray.getList();
    
    ASSERT_EQ(myArray.size(), 1);
    ASSERT_STREQ(strGetList.c_str() ,strRez.c_str());
}

TEST(Array, insertFromPosition) {

    MyArray<int> myArray;

    myArray.insertFromEnd(1);
    myArray.insertFromEnd(2);
    myArray.insertFromEnd(3);
    myArray.insertFromPosition(10,2);
    std::string strRez = "1 10 2 3 ";
    std::string strGetList = myArray.getList();

    ASSERT_EQ(myArray.size(), 4);
    ASSERT_STREQ(strGetList.c_str() ,strRez.c_str());
}

TEST(Array, eraseFromEnd) {

    MyArray<int> myArray;

    myArray.insertFromEnd(1);
    myArray.insertFromEnd(2);
    myArray.eraseFromEnd();
    std::string strRez = "1 ";
    std::string strGetList = myArray.getList();
    ASSERT_EQ(myArray.size(), 1);
    ASSERT_STREQ(strGetList.c_str() ,strRez.c_str());
}

TEST(Array, eraseFromBegin) {

    MyArray<int> myArray;

    myArray.insertFromEnd(1);
    myArray.insertFromEnd(2);
    myArray.eraseFromBegin();
    std::string strRez = "2 ";
    std::string strGetList = myArray.getList();

    ASSERT_EQ(myArray.size(), 1);
    ASSERT_STREQ(strGetList.c_str() ,strRez.c_str());
}

TEST(Array, eraseFromPosition) {

    MyArray<int> myArray;
    myArray.insertFromEnd(1);
    myArray.insertFromEnd(2);
    myArray.insertFromEnd(3);

    myArray.eraseFromPosition(2);
    std::string strRez = "1 3 ";
    std::string strGetList = myArray.getList();

    ASSERT_EQ(myArray.size(), 2);
    ASSERT_STREQ(strGetList.c_str() ,strRez.c_str());
}

TEST(Array, getList) {

    MyArray<int> myArray;
    myArray.insertFromEnd(1);
    myArray.insertFromEnd(2);

    std::string strRez = "1 2 ";
    std::string strGetList = myArray.getList();

    ASSERT_EQ(myArray.size(), 2);
    ASSERT_STREQ(strGetList.c_str() ,strRez.c_str());
}

TEST(Array, size) {

    MyArray<int> myArray;
    
    myArray.insertFromEnd(1);
    myArray.insertFromEnd(2);

    ASSERT_EQ(myArray.size(), 2);
}