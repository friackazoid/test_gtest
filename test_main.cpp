
#include "class.hpp"
#include "class_2.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

// TEST to check if foo is called
TEST (FooUsageTest, FooIsCalled) 
{
    class MockFoo : public FooPureVirtual {
    public:
        MOCK_METHOD(void, foo, (), (override));
        MOCK_METHOD(void, bar, (), (override));
    };

    MockFoo mockFoo;
    UseFoo useFoo(&mockFoo);

    EXPECT_CALL(mockFoo, foo()).Times(1);
    useFoo.useFoo();
}

TEST (FooVirtual, FooIsCalled) 
{
    class MockFoo : public FooVirtual {
    public:
        MOCK_METHOD(void, foo, (), (override));
        MOCK_METHOD(void, bar, ());
    };

    MockFoo mockFoo;
    UseFoo2 useFoo(&mockFoo);

    EXPECT_CALL(mockFoo, foo()).Times(1);

    useFoo.useFoo();
}

int main (int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
