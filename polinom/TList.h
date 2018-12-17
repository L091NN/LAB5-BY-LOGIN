#ifndef __TLIST__
#define __TLIST__
#include<vector>

using namespace std;

template <class ElemType>
struct container
{
	container *pPref;
	ElemType content;
	container *pNext;

};

//template <class ElemType>
//class Iterator
//{
//	container<ElemType> *ptr;
//public:
//	Iterator()
//	{
//		this->ptr = nullptr;
//	}
//	Iterator(container<ElemType> &ptr)
//	{
//		this->ptr = ptr;
//	}
//	~Iterator()
//	{
//		delete[]ptr;
//	}
//	ElemType* operator=(const container<ElemType> &&Elem)
//	{
//		if (this->ptr != Elem)
//			ptr = Elem;
//		return this;
//	}
//	bool operator==(const container<ElemType> &&Elem)
//	{
//		if (ptr == Elem)
//			return 1;
//		return 0;
//	}
//	bool operator!=(const container<ElemType> &&Elem)
//	{
//		return !(Elem == ptr);
//	}
//
//
//};

template <class ElemType>
class TList
{
	container<ElemType> *pFirst;
	container<ElemType> *pEnd;
	int size;
public:
	TList()
	{
		size = 0;
		pFirst = nullptr;
		pEnd = nullptr;
	}
	~TList()
	{
		if (size)
		{
			auto p = pFirst;
			for (; p->pNext != nullptr; p = p->pNext)
			{
				if (p->pPref != nullptr)
					delete p->pPref;
			}
			delete p;
		}
	}

	void push_back(ElemType Elem)
	{
		if (pFirst == nullptr)
		{
			size = 1;
			pFirst = new container<ElemType>();
			pEnd = pFirst;
			pFirst->pPref = nullptr;
			pFirst->pNext = nullptr;
			pFirst->content = Elem;
		}
		else
		{
			size++;
			pEnd->pNext = new container<ElemType>();
			pEnd->pNext->pPref = pEnd;
			pEnd = pEnd->pNext;
			pEnd->pNext = nullptr;
			pEnd->content = Elem;
		}
	}
};

#endif

