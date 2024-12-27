#include <gtest.h>
#include "string"
#include "translator.h"



// --------------- POSITIVE TESTS ---------------- //

TEST(translator, can_convert_to_postfix) {
	Translator trans;
	std::string str = "2+4*10";
	EXPECT_EQ("2410*+", trans.ToPostFix(str));
}
TEST(translator, can_add) {
	Translator trans;
	std::string str = "2+3";
	std::string res = trans.ToPostFix(str);
	EXPECT_EQ(5, trans.CalcPostfix(res));
}
TEST(translator, can_mul) {
	Translator trans;
	std::string str = "2*3";
	std::string res = trans.ToPostFix(str);
	EXPECT_EQ(6, trans.CalcPostfix(res));
}
TEST(translator, can_div) {
	Translator trans;
	std::string str = "6/3";
	std::string res = trans.ToPostFix(str);
	EXPECT_EQ(2, trans.CalcPostfix(res));
}

TEST(translator, can_process_brackets) {
	Translator trans;
	std::string str = "5*6+(9-2)";
	EXPECT_EQ("56*92-+", trans.ToPostFix(str));
}

TEST(translator, can_calculate_postfix) {
	Translator trans;
	std::string str = "5*6+(9-2)";
	std::string res = trans.ToPostFix(str);
	EXPECT_EQ(37, trans.CalcPostfix(res));

}

TEST(translator, can_arange_priority) {
	Translator trans;
	EXPECT_EQ(1, (trans.Priority('+') < trans.Priority('*')));

}


// --------------- NEGATIVE TESTS ---------------- //

TEST(translator, throw_unnecessary_brackets) {
	std::string str = "2*)";
	Translator trans;
	ASSERT_ANY_THROW(trans.ToPostFix(str));
}

TEST(translator, throw_extra_brackets) {
	std::string str = "2*()))";
	Translator trans;
	ASSERT_ANY_THROW(trans.ToPostFix(str));
}

TEST(translator, throw_operators_without_vals) {
	std::string str = "+-/*";
	Translator trans;
	ASSERT_ANY_THROW(trans.ToPostFix(str));
}

TEST(translator, throw_uncorrect_values) {
	std::string str = "Happy New Year<@~";
	Translator trans;
	ASSERT_ANY_THROW(trans.ToPostFix(str));

}

TEST(translator, throw_division_by_zero) {
	std::string str = "2/0";
	Translator trans;
	std::string res = trans.ToPostFix(str);
	ASSERT_ANY_THROW(trans.CalcPostfix(res));
}

TEST(translator, throw_operator_before_arg) {
	Translator trans;
	std::string str = "*13";
	ASSERT_ANY_THROW(trans.ToPostFix(str));
}

TEST(translator, throw_left_bracket_without_couple) {
	Translator trans;
	std::string str = "((1+2)";
	ASSERT_ANY_THROW(trans.ToPostFix(str));
}

TEST(tranlator, throw_empty_string) {
	Translator trans;
	std::string str = "";
	ASSERT_ANY_THROW(trans.ToPostFix(str));
}
