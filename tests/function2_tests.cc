#include <gtest/gtest.h>

#include <function2/function2.h>

using namespace function2;
using namespace std;

TEST(Function2_Tests, SquareTest1) {
    const auto square1 = Function2::create_square(1, 2, 3);
    const auto square2 = Function2::create_square(2, 5, -4);

    EXPECT_NEAR(square1->function_x(1), 6, Epsilon);
    EXPECT_NEAR(square1->function_x(3), 18, Epsilon);

    EXPECT_NEAR(square2->function_x(2), 14, Epsilon);
    EXPECT_NEAR(square2->function_x(-3), -1, Epsilon);

    delete square1;
    delete square2;
}

TEST(Function2_Tests, GarmonicTest2) {
    const auto garmonic1 = Function2::create_garmonic(3, 2, 0);
    const auto garmonic2 = Function2::create_garmonic(2, 3, Pi / 2);

    EXPECT_NEAR(garmonic1->function_x(Pi / 6), 1.5, Epsilon);
    EXPECT_NEAR(garmonic1->function_x(0), 3, Epsilon);
    EXPECT_NEAR(garmonic1->function_x(Pi / 4), 0, Epsilon);
    EXPECT_NEAR(garmonic1->function_x(Pi / 2), -3, Epsilon);

    EXPECT_NEAR(garmonic2->function_x(Pi / 6), -2, Epsilon);
    EXPECT_NEAR(garmonic2->function_x(0), 0, Epsilon);
    EXPECT_NEAR(garmonic2->function_x(Pi / 18), -1, Epsilon);
    EXPECT_NEAR(garmonic2->function_x(Pi / 2), 2, Epsilon);

    delete garmonic1;
    delete garmonic2;
}

TEST(Function2_Tests, SproizvodTest3) {
    const auto square1 = Function2::create_square(1, 2, 3);
    const auto square2 = Function2::create_square(23, -2, 8);

    const auto square1_dx = square1->proizvod();
    const auto square2_dx = square2->proizvod();

    EXPECT_EQ(*square1->proizvod(), *Function2::create_square(0, 2, 3));
    EXPECT_EQ(*square2->proizvod(), *Function2::create_square(0, 46, -2));

    delete square1_dx;
    delete square2_dx;
    delete square1;
    delete square2;

}

TEST(Function2_Tests, GproizvodTest4) {


    const auto garmonic1 = Function2::create_garmonic(2, Pi, Pi / 2);
    const auto garmonic2 = Function2::create_garmonic(1, Pi / 2, 0);

    const auto garmonic1_dx = garmonic1->proizvod();
    const auto garmonic2_dx = garmonic2->proizvod();

    EXPECT_EQ(*garmonic1->proizvod(), *Function2::create_garmonic(2 * Pi, Pi, Pi / 2 + Pi / 2));
    EXPECT_EQ(*garmonic2->proizvod(), *Function2::create_garmonic(Pi / 2, Pi / 2, Pi / 2));

    delete garmonic1_dx;
    delete garmonic2_dx;
    delete garmonic1;
    delete garmonic2;
}

TEST(Function2_Tests, SpervoobrazTest5) {
    const auto square1 = Function2::create_square(10, 24, 3872);
    const auto square1_ = square1->pervoobraz();

    EXPECT_EQ(*square1->proizvod(), *Function2::create_square(0, 20, 24));

    delete square1_;
    delete square1;
}

TEST(Function2_Tests, GpervoobrazTest6) {
    const auto garmonic1 = Function2::create_garmonic(2 * Pi, Pi / 2, 0);
    const auto garmonic2 = Function2::create_garmonic(Pi * Pi, Pi / 3, Pi / 6);

    const auto garmonic1_ = garmonic1->pervoobraz();
    const auto garmonic2_ = garmonic2->pervoobraz();

    EXPECT_EQ(*garmonic1->pervoobraz(), *Function2::create_garmonic((-1) * 4, Pi / 2, Pi / 2));
    EXPECT_EQ(*garmonic2->pervoobraz(), *Function2::create_garmonic((-1) * 3 * Pi, Pi / 3, (Pi / 6) + (Pi / 2)));

    delete garmonic1_;
    delete garmonic2_;
    delete garmonic1;
    delete garmonic2;

}

TEST(Function2_Tests, Gb0Test7) {
    const auto garmonic1 = Function2::create_garmonic(2 * Pi, 0, 1);
    const auto garmonic1_ = garmonic1->pervoobraz();

    EXPECT_EQ(*garmonic1->pervoobraz(), *Function2::create_garmonic((-1) * 4, Pi / 2, Pi / 2));

    delete garmonic1_;
    delete garmonic1;
}

TEST(Index_last_max, NoResult) {
    Function2_list function;
    const auto index = last_max(function, 0);
    ASSERT_EQ(index, -1);
}

TEST(Index_last_max, ArgOne) {
    Function2_list function;
    function.Function_add(Function2::create_square(100, 24, 3));
    function.Function_add(Function2::create_garmonic(2, Pi, 0));
    function.Function_add(Function2::create_square(25, 30, 79));
    function.Function_add(Function2::create_garmonic(53, 1, Pi));
    function.Function_add(Function2::create_square(14, -24, 23));
    function.Function_add(Function2::create_garmonic(2, -Pi, Pi / 2));
    const auto index = last_max(function, 1);

    ASSERT_EQ(index, 2);
}

TEST(Index_last_max, ArgPi) {
    Function2_list function;
    function.Function_add(Function2::create_square(Pi, 24, 3));
    function.Function_add(Function2::create_garmonic(24, Pi, Pi));
    function.Function_add(Function2::create_square(140, 24, 2));
    function.Function_add(Function2::create_garmonic(2, -Pi, Pi / 6));
    function.Function_add(Function2::create_square(140, 24, 2));
    function.Function_add(Function2::create_garmonic(2, -Pi, Pi / 6));
    const auto index = last_max(function, 1);

    ASSERT_EQ(index, 4);
}

TEST(Instal_index, IndexTest1) {
    Function2_list function;
    function.Function_add(Function2::create_square(Pi, 24, 3));
    function.Function_add(Function2::create_garmonic(24, Pi, Pi));
    function.Function_add(Function2::create_square(140, 24, 2));
    function.Function_add(Function2::create_garmonic(2, -Pi, Pi / 6));
    function.Function_add(Function2::create_square(140, 24, 2));
    function.Function_add(Function2::create_garmonic(2, -Pi, Pi / 6));
    const auto index = 0;
    EXPECT_EQ(*function[index], *Function2::create_square(Pi, 24, 3));
}
TEST(Instal_index, IndexTest2) {
    Function2_list function;
    function.Function_add(Function2::create_square(Pi, 24, 3));
    function.Function_add(Function2::create_garmonic(24, Pi, Pi));
    function.Function_add(Function2::create_square(140, 24, 2));
    function.Function_add(Function2::create_garmonic(2, -Pi, Pi / 6));
    function.Function_add(Function2::create_square(140, 24, 2));
    function.Function_add(Function2::create_garmonic(2, -Pi, Pi / 6));
    const auto index = 0;
    function.Function_Instal(Function2::create_garmonic(2, -Pi, Pi / 6), index);
    EXPECT_EQ(*function[index], *Function2::create_garmonic(2, -Pi, Pi / 6));
}
TEST(Insert, InserTest) {
    Function2_list function;
    function.Function_add(Function2::create_square(Pi, 24, 3));
    function.Function_add(Function2::create_garmonic(24, Pi, Pi));
    function.Function_add(Function2::create_square(140, 24, 2));
    const auto index = 1;
    function.Function_Insert(Function2::create_garmonic(2, -Pi, Pi / 6), index);
    EXPECT_EQ(*function[index], *Function2::create_garmonic(2, -Pi, Pi / 6));
    EXPECT_EQ(*function[index + 1], *Function2::create_garmonic(24, Pi, Pi));
    EXPECT_EQ(*function[index + 2], *Function2::create_square(140, 24, 2));
    EXPECT_EQ(function.get_size(), 4);
}
TEST(Delete, DeleteTest) {
    Function2_list function;
    function.Function_add(Function2::create_square(Pi / 2, 2, 13));
    function.Function_add(Function2::create_garmonic(284, Pi * 6, Pi));
    function.Function_add(Function2::create_square(1, 25, 3));
    const auto index = 1;
    function.Function_Delete(index);
    EXPECT_EQ(*function[index], *Function2::create_square(1, 25, 3));
    EXPECT_EQ(function.get_size(), 2);
}

