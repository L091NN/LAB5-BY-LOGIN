#include"gtest.h"
#include"TList.h"

TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<int> L);
}

TEST(TList, check_push_back_1_elem)
{
	TList<int> L;
	ASSERT_NO_THROW(L.push_back(1));
}

TEST(TList, check_push_back_more_1_elem)
{
	TList<int> L;
	for (int i = 0;i < 10; ++i)
	ASSERT_NO_THROW(L.push_back(1));
}