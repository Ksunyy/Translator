#include "Stack.h"
#include <gtest.h>

// --------------- Positive tests ------------- //

TEST(Stack, can_create_default_stack) {
	ASSERT_NO_THROW(Stack<char> arr);
}

TEST(Stack, can_get_size) {
	Stack<int> arr;
	arr.push(1);
	arr.push(2);
	arr.push(3);
	EXPECT_EQ(3, arr.get_size());

}

TEST(Stack, get_top_value) {
	Stack<int> arr;
	arr.push(1);
	EXPECT_EQ(1, arr.top());
}

TEST(Stack, can_push_val) {
	Stack<int> arr;
	arr.push(3);
	EXPECT_EQ(3, arr.top());
}

TEST(Stack, change_size_push) {
	Stack<int> arr;
	arr.push(3);
	arr.push(3);
	arr.push(3);
	EXPECT_EQ(3, arr.get_size());
}

TEST(Stack, can_pop_value) {
	Stack<int> arr;
	arr.push(4);
	arr.push(2);
	arr.pop();
	EXPECT_EQ(1, arr.get_size());
}

TEST(Stack, change_size_pop) {
	Stack<int>arr;
	arr.push(1);
	arr.push(1);
	arr.push(1);
	arr.pop();
	EXPECT_EQ(2, arr.get_size());
}


TEST(Stack, chek_empty) {
	Stack<int> arr;
	EXPECT_EQ(1, arr.empty());
}

// --------------- Negative tests ------------- //


TEST(Stack, throw_pop_val_empty) {
	Stack<int> arr;
	ASSERT_ANY_THROW(arr.pop());

}

TEST(Stack, throw_top_val_empty) {
	Stack<int> arr;
	ASSERT_ANY_THROW(arr.top());
}