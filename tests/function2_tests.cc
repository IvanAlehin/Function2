#include <gtest/gtest.h>

#include <function2/function2.h>

using namespace function2;
using namespace std;

TEST(Function2_Tests, Test1) {
    Function2 one1(TypeF::Square, 1, 2, 3);
    Function2 one2(TypeF::Square, 2, 5, -4);

    EXPECT_NEAR(one1.function_x(1), 6, Epsilon);
    EXPECT_NEAR(one1.function_x(3), 18, Epsilon);

    EXPECT_NEAR(one2.function_x(2), 14, Epsilon);
    EXPECT_NEAR(one2.function_x(-3), -1, Epsilon);
}

TEST(Function2_Tests, Test2) {
    Function2 two1(TypeF::Garmonic, 3, 2);
    Function2 two2(TypeF::Garmonic, 2, 3, Pi / 2);

    EXPECT_NEAR(two1.function_x(Pi / 6), 1.5, Epsilon);
    EXPECT_NEAR(two1.function_x(0), 3, Epsilon);
    EXPECT_NEAR(two1.function_x(Pi / 4), 0, Epsilon);
    EXPECT_NEAR(two1.function_x(Pi / 2), -3, Epsilon);

    EXPECT_NEAR(two2.function_x(Pi / 6), -2, Epsilon);
    EXPECT_NEAR(two2.function_x(0), 0, Epsilon);
    EXPECT_NEAR(two2.function_x(Pi / 18), -1, Epsilon);
    EXPECT_NEAR(two2.function_x(Pi / 2), 2, Epsilon);
}

TEST(Function2_Tests, Test3) {
    Function2 three(TypeF::Square, 3, 2, 1);
    Function2 time = three.proizvod();

    EXPECT_NEAR(time.function_x(1), 8, Epsilon);
    EXPECT_NEAR(time.function_x(3), 20, Epsilon);
    EXPECT_NEAR(time.function_x(-2), -10, Epsilon);
}

TEST(Function2_Tests, Test4) {
    Function2 four(TypeF::Garmonic, 2, Pi, Pi / 2);
    Function2 time = four.proizvod();
    Function2 four2(TypeF::Garmonic, 1, Pi / 2, 0);
    Function2 time2 = four2.proizvod();

    EXPECT_NEAR(time.function_x(0.5), 0, Epsilon);
    EXPECT_NEAR(time.function_x(1), 2 * Pi, Epsilon);

    EXPECT_NEAR(time2.function_x(3), Pi / 2, Epsilon);
    EXPECT_NEAR(time2.function_x(2), 0, Epsilon);
}

TEST(Function2_Tests, Test5) {
    Function2 five(TypeF::Square, 6, 2, 5);
    Function2 time = five.pervoobraz();

    EXPECT_NEAR(time.function_x(-2), -22, Epsilon);
    EXPECT_NEAR(time.function_x(1), 8, Epsilon);
    EXPECT_NEAR(time.function_x(3), 78, Epsilon);
}

TEST(Function2_Tests, Test6) {
    Function2 six(TypeF::Garmonic, 2 * Pi, Pi / 2, 0);
    Function2 time = six.pervoobraz();
    Function2 six2(TypeF::Garmonic, Pi * Pi, Pi / 3, Pi / 6);
    Function2 time2 = six2.pervoobraz();

    EXPECT_NEAR(time.function_x(1), 4, Epsilon);
    EXPECT_NEAR(time.function_x(3), -4, Epsilon);

    EXPECT_NEAR(time2.function_x(-1), (-3 * Pi) / 2, Epsilon);
    EXPECT_NEAR(time2.function_x(-2), -3 * Pi, Epsilon);
}

TEST(Function2_Tests, Test7) {
    Function2 seven(TypeF::Garmonic, Pi / 2, 2, 0);
    Function2 time = seven.pervoobraz();

    EXPECT_NEAR(time.function_x(3), 2, Epsilon);
}

TEST(Function2_Tests, Test8)
{
    Function2_list function;

    Function2 eight(TypeF::Square, 5, 1, -2);
    for (int i = 0; i < Function2_list::COUNTER; ++i) {
        function.Function_add(eight);
    }
    ASSERT_ANY_THROW(function.Function_add(eight));
}

TEST(Function2_list_Test, Test9) {
    Function2_list _function;
    Function2 One(TypeF::Square, 0, 2, 3),
        Two(TypeF::Square, -2, 25, -3),
        Three(TypeF::Garmonic, 66, Pi, 2),
        Four(TypeF::Garmonic, 0, 2, 3);
    _function.Function_add(One);
    _function.Function_add(Two);
    _function.Function_add(Three);
    _function.Function_add(Four);

    int index = _function.last_max(_function, -6);

    ASSERT_EQ(index, 1);
}


TEST(Function2_list_Test, Test10) {
    Function2_list _function;
    Function2 One(TypeF::Garmonic, 1, 2, 3),
        Two(TypeF::Garmonic, 1, 2, 3),
        Three(TypeF::Garmonic, 1, 2, 3),
        Four(TypeF::Garmonic, 1, 2, 3);
    _function.Function_add(One);
    _function.Function_add(Two);
    _function.Function_add(Three);
    _function.Function_add(Four);

    int index = _function.last_max(_function, 0.5);

    ASSERT_EQ(index, 3);
}
TEST(Function2_list_Test, Test11) {
    Function2_list _function;
    Function2 One(TypeF::Square, -5, 2, 1),
        Two(TypeF::Garmonic, Pi, 2, Pi / 2),
        Three(TypeF::Square, 1, 5, 6),
        Four(TypeF::Garmonic, 1, Pi, 3),
        Five(TypeF::Square, 5, 1, 66),
        Six(TypeF::Garmonic, 5, Pi / 2, Pi / 6);
    _function.Function_add(One);
    _function.Function_add(Two);
    _function.Function_add(Three);
    _function.Function_add(Four);
    _function.Function_add(Five);
    _function.Function_add(Six);

    int index = _function.last_max(_function, 3);

    ASSERT_EQ(index, 4);
}
