#include <gtest/gtest.h>
#include "../include/MyList.hpp"

TEST(List, Create) {

    MyList myList0{0};
    
    ASSERT_EQ(myList0.size(), 1);
}

TEST(List, push_back) {
    
    MyList myList0{0};
    
    myList0.insertFromEnd(1);
    std::string strRez = "0 1 ";
    std::string strGetList = myList0.getList();
    
    ASSERT_EQ(myList0.size(), 2);
    ASSERT_STREQ(strGetList.c_str() ,strRez.c_str());
}

TEST(List, insertFromBegin) {
    
    MyList myList0{0};
    
    myList0.insertFromBegin(1);
    std::string strRez = "1 0 ";
    std::string strGetList = myList0.getList();
    
    ASSERT_EQ(myList0.size(), 2);
    ASSERT_STREQ(strGetList.c_str() ,strRez.c_str());
}

TEST(List, insertFromPosition) {
    
    MyList myList0{0};
    myList0.insertFromEnd(1);
    myList0.insertFromEnd(2);
    
    myList0.insertFromPosition(10,2);
    std::string strRez = "0 10 1 2 ";
    std::string strGetList = myList0.getList();
    
    ASSERT_EQ(myList0.size(), 4);
    ASSERT_STREQ(strGetList.c_str() ,strRez.c_str());
}

TEST(List, eraseFromEnd) {
    
    MyList myList0{0};
    myList0.insertFromEnd(1);
    
    myList0.eraseFromEnd();
    std::string strRez = "0 ";
    std::string strGetList = myList0.getList();
    
    ASSERT_EQ(myList0.size(), 1);
    ASSERT_STREQ(strGetList.c_str() ,strRez.c_str());
}

TEST(List, eraseFromBegin) {
    
    MyList myList0{0};
    myList0.insertFromEnd(1);
    
    myList0.eraseFromBegin();
    std::string strRez = "1 ";
    std::string strGetList = myList0.getList();
    
    ASSERT_EQ(myList0.size(), 1);
    ASSERT_STREQ(strGetList.c_str() ,strRez.c_str());
}

TEST(List, eraseFromPosition) {
    
    MyList myList0{0};
    myList0.insertFromEnd(1);
    myList0.insertFromEnd(2);
    
    myList0.eraseFromPosition(2);
    std::string strRez = "0 2 ";
    std::string strGetList = myList0.getList();
    
    ASSERT_EQ(myList0.size(), 2);
    ASSERT_STREQ(strGetList.c_str() ,strRez.c_str());
}

TEST(List, getList) {
    
    MyList myList0{0};
    myList0.insertFromEnd(1);
    myList0.insertFromEnd(2);
    
    std::string strRez = "0 1 2 ";
    std::string strGetList = myList0.getList();
    
    ASSERT_EQ(myList0.size(), 3);
    ASSERT_STREQ(strGetList.c_str() ,strRez.c_str());
}

TEST(List, size) {
    
    MyList myList0{0};
    myList0.insertFromEnd(1);
    myList0.insertFromEnd(2);
    
    ASSERT_EQ(myList0.size(), 3);
}