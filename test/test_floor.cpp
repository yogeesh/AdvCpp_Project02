#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/floor.h"

using testing::Eq;
using std::string;

namespace {
    class TestFloor : public ::testing::Test {
    public:
        Floor<int> ifloor_;
        Floor<string> sfloor_;
        TestFloor() :
            ifloor_(10),
            sfloor_(20) {
        }

        void TEST_IFLOOR(Direction dir) {
            ASSERT_EQ(0ul, ifloor_.size(dir));
            ASSERT_THROW(ifloor_.remove(dir), TTException);
            ASSERT_THROW(ifloor_.front(dir), TTException);
            ASSERT_THROW(ifloor_.back(dir), TTException);
            ifloor_.insert(10, dir);
            ASSERT_EQ(10, ifloor_.front(dir));
            ASSERT_EQ(10, ifloor_.back(dir));
            ifloor_.insert(20, dir);
            ifloor_.insert(30, dir);
            ASSERT_EQ(3ul, ifloor_.size(dir));
            ASSERT_EQ(10, ifloor_.front(dir));
            ifloor_.remove(dir);
            ASSERT_EQ(2ul, ifloor_.size(dir));
            ifloor_.insert(40, dir);
            ASSERT_EQ(20, ifloor_.front(dir));
            ASSERT_EQ(40, ifloor_.back(dir));
            ifloor_.remove(dir);
            ASSERT_EQ(30, ifloor_.front(dir));
            ifloor_.remove(dir);
            ASSERT_EQ(40, ifloor_.front(dir));
            ifloor_.remove(dir);
            ASSERT_EQ(0ul, ifloor_.size(dir));
        }

        void TEST_SFLOOR(Direction dir) {
            ASSERT_EQ(0ul, sfloor_.size(dir));
            ASSERT_THROW(sfloor_.remove(dir), TTException);
            ASSERT_THROW(sfloor_.front(dir), TTException);
            ASSERT_THROW(sfloor_.back(dir), TTException);
            sfloor_.insert("apple", dir);
            ASSERT_EQ("apple", sfloor_.front(dir));
            ASSERT_EQ("apple", sfloor_.back(dir));
            sfloor_.insert("baby", dir);
            sfloor_.insert("candy", dir);
            sfloor_.insert("dog", dir);
            ASSERT_EQ(4ul, sfloor_.size(dir));
            ASSERT_EQ("apple", sfloor_.front(dir));
            sfloor_.remove(dir);
            ASSERT_EQ(3ul, sfloor_.size(dir));
            sfloor_.insert("eagle", dir);
            ASSERT_EQ("baby", sfloor_.front(dir));
            ASSERT_EQ("eagle", sfloor_.back(dir));
            sfloor_.remove(dir);
            ASSERT_EQ("candy", sfloor_.front(dir));
            sfloor_.remove(dir);
            ASSERT_EQ("dog", sfloor_.front(dir));
            sfloor_.remove(dir);
            ASSERT_EQ("eagle", sfloor_.front(dir));
            sfloor_.remove(dir);
            ASSERT_EQ(0ul, sfloor_.size(dir));
        }
    };
}

TEST_F(TestFloor, testiFloor) {
    ASSERT_EQ(10u, ifloor_.number());
    TEST_IFLOOR(EAST);
    TEST_IFLOOR(WEST);
}

TEST_F(TestFloor, testsFloor) {
    ASSERT_EQ(20u, sfloor_.number());
    TEST_SFLOOR(EAST);
    TEST_SFLOOR(WEST);
}

/**
 * The main function for the google test.
 *
 * @param argc argument count
 * @param argv command line arguments
 * @return the result of RUN_ALL_TESTS()
 */
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}