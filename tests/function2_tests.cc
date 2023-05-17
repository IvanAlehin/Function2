#include <gtest/gtest.h>

#include <function2/function2.h>

using namespace function2;
using namespace std;

TEST(Function2_Tests, SquareTest1) {
    const auto square1 = make_shared<SquareFunction>(1,2,3);
    const auto square2 = make_shared<SquareFunction>(2, 5, -4);

    EXPECT_NEAR(square1->function_x(1), 6, Epsilon);
    EXPECT_NEAR(square1->function_x(3), 18, Epsilon);

    EXPECT_NEAR(square2->function_x(2), 14, Epsilon);
    EXPECT_NEAR(square2->function_x(-3), -1, Epsilon);
    
}

TEST(Function2_Tests, GarmonicTest2) {
    const auto garmonic1 = make_shared<GarmonicFunction>(3, 2,0);
    const auto garmonic2 = make_shared<GarmonicFunction>(2, 3, Pi / 2);
    
    EXPECT_NEAR(garmonic1->function_x(Pi/6), 1.5, Epsilon);
    EXPECT_NEAR(garmonic1->function_x(0), 3, Epsilon);
    EXPECT_NEAR(garmonic1->function_x(Pi/4), 0, Epsilon);
    EXPECT_NEAR(garmonic1->function_x(Pi/2), -3, Epsilon);

    EXPECT_NEAR(garmonic2->function_x(Pi / 6), -2, Epsilon);
    EXPECT_NEAR(garmonic2->function_x(0), 0, Epsilon);
    EXPECT_NEAR(garmonic2->function_x(Pi/18), -1, Epsilon);
    EXPECT_NEAR(garmonic2->function_x(Pi / 2), 2, Epsilon);
    
}

TEST(Function2_Tests, SproizvodTest3) {
    const auto square1 = make_shared<SquareFunction>(1,2,3);
    const auto square2 = make_shared<SquareFunction>(23,-2,8);
    const auto square1_dx = square1->proizvod();
    const auto square2_dx = square2->proizvod();
    const auto expected_square1_dx = make_shared<SquareFunction>(0, 2, 2);
    const auto expected_square2_dx = make_shared<SquareFunction>(0, 46, -2);

    EXPECT_TRUE(square1_dx->equals(expected_square1_dx));
    EXPECT_TRUE(square2_dx->equals(expected_square2_dx));

    EXPECT_FALSE(square1_dx->equals(expected_square2_dx));
    EXPECT_FALSE(square2_dx->equals(expected_square1_dx));
}

TEST(Function2_Tests, GproizvodTest4) {

    
    const auto garmonic1 = make_shared<GarmonicFunction>(2, Pi, Pi / 2);
    const auto garmonic2 = make_shared<GarmonicFunction>(1, Pi / 2, 0);

    const auto garmonic1_dx = garmonic1->proizvod();
    const auto garmonic2_dx = garmonic2->proizvod();
    const auto expected_garmonic1_dx = make_shared<GarmonicFunction>(2 * Pi, Pi, Pi / 2 + Pi / 2);
    const auto expected_garmonic2_dx = make_shared<GarmonicFunction>(Pi / 2, Pi / 2, Pi / 2);

    EXPECT_TRUE(garmonic1_dx->equals(expected_garmonic1_dx));
    EXPECT_TRUE(garmonic2_dx->equals(expected_garmonic2_dx));

    EXPECT_FALSE(garmonic1_dx->equals(expected_garmonic2_dx));
    EXPECT_FALSE(garmonic2_dx->equals(expected_garmonic1_dx));

}

TEST(Function2_Tests, SpervoobrazTest5) {
    const auto square1 = make_shared<SquareFunction>(10, 24, 3872);
    const auto square1_ = square1->pervoobraz();
    const auto expected_square1_ = make_shared<SquareFunction>(0, 20, 24);

    EXPECT_TRUE(square1_->equals(expected_square1_));

    EXPECT_FALSE(square1_->equals(expected_square1_));

}

TEST(Function2_Tests, GpervoobrazTest6) {
    const auto garmonic1 = make_shared<GarmonicFunction>(2 * Pi, Pi / 2, 0);
    const auto garmonic2 = make_shared<GarmonicFunction>(Pi * Pi, Pi / 3, Pi / 6);

    const auto garmonic1_ = garmonic1->pervoobraz();
    const auto garmonic2_ = garmonic2->pervoobraz();
    const auto expected_garmonic1_ = make_shared<GarmonicFunction>((-1) * 4, Pi / 2, Pi / 2);
    const auto expected_garmonic2_ = make_shared<GarmonicFunction>((-1) * 3 * Pi, Pi / 3, (Pi / 6) + (Pi / 2));

    EXPECT_TRUE(garmonic1_->equals(expected_garmonic1_));
    EXPECT_TRUE(garmonic2_->equals(expected_garmonic2_));

    EXPECT_FALSE(garmonic1_->equals(expected_garmonic2_));
    EXPECT_FALSE(garmonic2_->equals(expected_garmonic1_));
}

TEST(Function2_Tests, Gb0Test7) {
    const auto garmonic1 = make_shared<GarmonicFunction>(2 * Pi, 0, 1);
    const auto garmonic1_ = garmonic1->pervoobraz();
    const auto expected_garmonic1_ = make_shared<GarmonicFunction>((-1) * 4, Pi / 2, Pi / 2);
    EXPECT_TRUE(garmonic1_->equals(expected_garmonic1_));
    EXPECT_FALSE(garmonic1_->equals(expected_garmonic1_));

}

TEST(Index_last_max, NoResult) {
    Function2_list function;
    const auto index = last_max(function, 0);
    ASSERT_EQ(index, -1);
}

TEST(Index_last_max, ArgOne) {
    Function2_list function;
    function.Function_add(make_shared<SquareFunction>(100,24,3));
    function.Function_add(make_shared<GarmonicFunction>(2,Pi,0));
    function.Function_add(make_shared<SquareFunction>(25,30,79));
    function.Function_add(make_shared<GarmonicFunction>(53,1,Pi));
    function.Function_add(make_shared<SquareFunction>(14, -24, 23));
    function.Function_add(make_shared<GarmonicFunction>(2, -Pi, Pi/2));
    const auto index = last_max(function, 1);

    ASSERT_EQ(index, 2);
}

TEST(Index_last_max, ArgPi) {
    Function2_list function;
    function.Function_add(make_shared<SquareFunction>(Pi, 24, 3));
    function.Function_add(make_shared<GarmonicFunction>(24, Pi, Pi));
    function.Function_add(make_shared<SquareFunction>(140, 24, 2));
    function.Function_add(make_shared<GarmonicFunction>(2, -Pi, Pi / 6));
    function.Function_add(make_shared<SquareFunction>(140, 24, 2));
    function.Function_add(make_shared<GarmonicFunction>(2, -Pi, Pi / 6));
    const auto index = last_max(function, 1);

    ASSERT_EQ(index, 4);
}

TEST(Instal, IndexTest) {
    Function2_list function;
    function.Function_add(make_shared<SquareFunction>(Pi, 24, 3));
    function.Function_add(make_shared<GarmonicFunction>(24, Pi, Pi));
    function.Function_add(make_shared<SquareFunction>(140, 24, 2));
    function.Function_add(make_shared<GarmonicFunction>(2, -Pi, Pi / 6));
    function.Function_add(make_shared<SquareFunction>(140, 24, 2));
    function.Function_add(make_shared<GarmonicFunction>(2, -Pi, Pi / 6));
    const auto index = 0;
    function.Function_Instal(make_shared<GarmonicFunction>(2, -Pi, Pi / 6),index);
    const auto n = function.size();
    ASSERT_EQ(n, 6);
}
TEST(Insert, InsertTest) {
    Function2_list function;
    function.Function_add(make_shared<SquareFunction>(Pi, 24, 3));
    function.Function_add(make_shared<GarmonicFunction>(24, Pi, Pi));
    function.Function_add(make_shared<SquareFunction>(140, 24, 2));
    const auto index = 1;
    function.Function_Insert(make_shared<GarmonicFunction>(2, -Pi, Pi / 6), index);
    const auto n = function.size();
    ASSERT_EQ(n, 4);
}
TEST(Delete, DeleteTest) {
    Function2_list function;
    function.Function_add(make_shared<SquareFunction>(Pi/2, 2, 13));
    function.Function_add(make_shared<GarmonicFunction>(284, Pi*6, Pi));
    function.Function_add(make_shared<SquareFunction>(1, 25, 3));
    const auto index = 1;
    function.Function_Delete(index);
    const auto n = function.size();
    ASSERT_EQ(n,2);
}

