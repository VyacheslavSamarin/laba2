#include <gtest/gtest.h>
#include "../include/Octal.hpp"

TEST(OctalTest, DefaultConstructor)
{
    Octal o;
    std::stringstream ss;
    o.print(ss);
    EXPECT_EQ(ss.str(), "0");
}

TEST(OctalTest, InitializerListConstructor)
{
    Octal o({1, 2, 3});
    std::stringstream ss;
    o.print(ss);
    EXPECT_EQ(ss.str(), "321");
}

TEST(OctalTest, SizeConstructor)
{
    Octal o(3, 5);
    std::stringstream ss;
    o.print(ss);
    EXPECT_EQ(ss.str(), "555");
}

TEST(OctalTest, StringConstructorValid)
{
    Octal o("123");
    std::stringstream ss;
    o.print(ss);
    EXPECT_EQ(ss.str(), "123");
}

TEST(OctalTest, StringConstructorWithLeadingZeros)
{
    Octal o("000123");
    std::stringstream ss;
    o.print(ss);
    EXPECT_EQ(ss.str(), "123");
}

TEST(OctalTest, CopyConstructor)
{
    Octal o1("123");
    Octal o2(o1);
    std::stringstream ss;
    o2.print(ss);
    EXPECT_EQ(ss.str(), "123");
}

TEST(OctalTest, AssignmentOperator)
{
    Octal o1("123");
    Octal o2;
    o2 = o1;
    std::stringstream ss;
    o2.print(ss);
    EXPECT_EQ(ss.str(), "123");
}

TEST(OctalTest, AdditionOperator)
{
    Octal o1("123");
    Octal o2("456");
    o1 += o2;
    std::stringstream ss;
    o1.print(ss);
    EXPECT_EQ(ss.str(), "601");
}

TEST(OctalTest, SubtractionOperator)
{
    Octal o1("777");
    Octal o2("123");
    o1 -= o2;
    std::stringstream ss;
    o1.print(ss);
    EXPECT_EQ(ss.str(), "654");
}

TEST(OctalTest, EqualityOperator)
{
    Octal o1("123");
    Octal o2("123");
    EXPECT_TRUE(o1 == o2);
}

TEST(OctalTest, InequalityOperator)
{
    Octal o1("123");
    Octal o2("456");
    EXPECT_TRUE(o1 != o2);
}

TEST(OctalTest, LessThanOperator)
{
    Octal o1("123");
    Octal o2("456");
    EXPECT_TRUE(o1 < o2);
}

TEST(OctalTest, GreaterThanOperator)
{
    Octal o1("456");
    Octal o2("123");
    EXPECT_TRUE(o1 > o2);
}

TEST(OctalTest, InvalidOctalString)
{
    EXPECT_THROW(Octal("89"), std::invalid_argument);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
