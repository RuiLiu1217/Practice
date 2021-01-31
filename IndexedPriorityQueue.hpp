#ifndef IndexPriorityQueueMin_H
#define IndexPriorityQueueMin_H
template<typename T>
	class IndexPriorityQueueMin {
	public:
		IndexPriorityQueueMin(int maxsize);
		IndexPriorityQueueMin(T* array,int nSize);
		IndexPriorityQueueMin(const IndexPriorityQueueMin<T>& rhs);
		IndexPriorityQueueMin<T>& operator=(const IndexPriorityQueueMin<T>& rhs);
		~IndexPriorityQueueMin();

		void Insert(const T data,int index); // insert a value associate with the index
		void Swim(int k);
		void Sink(int k);
		T PopMin();
		void PrintElements();
		bool isContain(int index);
		void ChangeValue(T value,int index);
		void Delete(int index);

		T GetValue(int index);

		bool isMinHeap(int k);
		bool isMinHeap();


		T  Min() const;

		bool IsEmpty() const;
		int Size() const;

	private:
		// 该数组根据索引保存元素值
		T *m_array;
		// 该数组根据顺序（从1开始递增）来保存索引值
		int *m_nIndexArray;
		// m_nIndexArray的反向索引数组
		int *m_nIndexArrayInverse;
		int m_nSize;
		int m_ncapacity;
	};

	template<typename T>
	IndexPriorityQueueMin<T>::IndexPriorityQueueMin(int nMaxsize) :m_ncapacity(nMaxsize)
	{
		m_array = NULL;
		m_array = new T[nMaxsize+1];
		if (m_array == NULL)
		{
			throw "Failed to allocate memory!";
		}

		m_nIndexArray = new int[nMaxsize+1];
		if (m_nIndexArray == NULL)
		{
			throw "Failed to allocate memory!";
		}

		m_nIndexArrayInverse = new int[nMaxsize+1];
		if (m_nIndexArrayInverse == NULL)
		{
			throw "Failed to allocate memory!";
		}

	//	memset(m_nIndexArray,-1,nMaxsize+1);
		for (int i=0;i<nMaxsize+1;i++)
		{
			m_nIndexArray[i] = -1;
		}
	//	memset(m_nIndexArrayInverse,-1,nMaxsize+1);
		for (int i=0;i<nMaxsize+1;i++)
		{
			m_nIndexArrayInverse[i] = -1;
		}

		m_nSize = 0;
	}

	template<typename T>
	IndexPriorityQueueMin<T>::IndexPriorityQueueMin(T* array,int nSize) :m_ncapacity(nSize),m_nSize(nSize)
	{
		m_array = new T[nSize+1];
		if (m_array == NULL)
		{
			throw "Failed to allocate memory!";
		}

		for (int i=0;i<m_nSize;i++)
		{
			m_array[i+1] = array[i];
		}

	}

	template<typename T>
	bool IndexPriorityQueueMin<T>::isContain(int index)
	{
		return m_nIndexArrayInverse[index] != -1;
	}

	template<typename T>
	void IndexPriorityQueueMin<T>::Insert(const T data,int index)
	{
//		if ( index<1 || index>m_ncapacity)
		if ( index<0 || index>m_ncapacity)
			throw "illegal index";

		if (isContain(index))
		    throw "index is already in queue";

		m_nSize++;

		// m_array数组根据索引来存放元素data
		// 这个数组可以索引0的位置可以使用
		m_array[index] = data;

		// m_nIndexArray数组由1开始填充，填充的是data的索引值
		// 通过这个索引可以定位m_array数组里的data
		// 索引优先队列主要是维护这个数组
		// 这个数组可以索引0的位置不可以使用
		m_nIndexArray[m_nSize] = index;

		// m_nIndexArray的反向索引数组
		/*
		 该方向数组的作用是操作m_array数组的时候，能快速定位到相应的m_nIndexArray
		 比如m_array是一个字符串数组，原来m_array[3] = "a"，此时想修改m_array[3] = "f"
		 修改以后，需要操作m_nIndexArray数组来调整队列
         如果没有这个反向索引数组的话，想找到m_nIndexArray的元素3，需要遍历数组
		 才能处理，现在加了一个方向索引数组
		 m_array[3]代表 index =3，也就是m_nIndexArrayInverse[3],一下子就能得到对应的m_nSize，
         也就是m_nIndexArray定位完成
		*/
		m_nIndexArrayInverse[index] = m_nSize;

		Swim(m_nSize);
	}


	// [上浮]调整父节点
	template<typename T>
	void IndexPriorityQueueMin<T>::Swim(int k)
	{
		// k>1且如果k的父节点大于K，则交换k和k的父节点
		while (k > 1 && m_array[m_nIndexArray[k/2]] > m_array[m_nIndexArray[k]]) 
		{ 
			// 交换m_nIndexArray[k]和m_nIndexArray[k/2]
			// 交换的是元素的索引
			ExchangeArrayElements(m_nIndexArray,k, k/2);

			// 同步反向索引数组
			m_nIndexArrayInverse[m_nIndexArray[k/2]] = k/2;
			m_nIndexArrayInverse[m_nIndexArray[k]] = k;

			k = k/2;
		}
	}

	// [下沉]调整子节点
	template<typename T>
	void IndexPriorityQueueMin<T>::Sink(int k)
	{
		while (2*k <= m_nSize) 
		{
			// k的左子节点
			int leftnode = 2*k;

			// 比较左/右节点 找出较小的节点
			if (leftnode < m_nSize && m_array[m_nIndexArray[leftnode]] > m_array[m_nIndexArray[leftnode+1]]) 
				leftnode++;
			// 比较父节点与较小的子节点
			if (m_array[m_nIndexArray[k]] < m_array[m_nIndexArray[leftnode]])
				break;

			// 如果左/右子节点比父节点小，则交换他们的位置
			ExchangeArrayElements(m_nIndexArray,k, leftnode);
			// 同步反向索引数组
			m_nIndexArrayInverse[m_nIndexArray[k]] = k;
			m_nIndexArrayInverse[m_nIndexArray[leftnode]] = leftnode;

			k = leftnode;

		}
	}

	template<typename T>
	bool IndexPriorityQueueMin<T>::IsEmpty() const
	{
		return m_nSize == 0;
	}

	template <typename T>
	T IndexPriorityQueueMin<T>::PopMin()
	{
		if (IsEmpty())
			throw "empty Queue";

		int min = m_nIndexArray[1];

		ExchangeArrayElements(m_nIndexArray,1,m_nSize);
		// 同步反向索引数组
		m_nIndexArrayInverse[m_nIndexArray[1]] = 1;
		m_nIndexArrayInverse[m_nIndexArray[m_nSize]] = m_nSize;

		m_nSize--;
		Sink(1);

		m_nIndexArrayInverse[min] = -1;        // delete
		m_nIndexArray[m_nSize+1] = -1;        // not needed

		return min;

	}

	template<typename T>
	void IndexPriorityQueueMin<T>::ChangeValue(T value,int index)
	{
	//	if ( index<1 || index>m_ncapacity)
		if ( index<0 || index>m_ncapacity)
			throw "illegal index";

/*		int oldIndex = m_nIndexArrayInverse[value];*/
		if (!isContain(index))
			throw "index is not in queue";

		m_array[index] = value;

		Swim(m_nIndexArrayInverse[index]);
		Sink(m_nIndexArrayInverse[index]);

		return;
	}

	template<typename T>
	void IndexPriorityQueueMin<T>::Delete(int index)
	{
	//	if ( index<1 || index>m_ncapacity)
		if ( index<0 || index>m_ncapacity)
			throw "illegal index";

		if (!isContain(index))
			throw "index is not in queue";

		int posinIndexArray = m_nIndexArrayInverse[index];
		ExchangeArrayElements(m_nIndexArray,posinIndexArray,m_nSize);
		// 同步反向索引数组
		m_nIndexArrayInverse[m_nIndexArray[posinIndexArray]] = posinIndexArray;
		m_nIndexArrayInverse[m_nIndexArray[m_nSize]] = m_nSize;
		m_nSize--;

		Swim(posinIndexArray);
		Sink(posinIndexArray);

		m_nIndexArrayInverse[index] = -1;
	}

	template<typename T>
	T IndexPriorityQueueMin<T>::GetValue(int index)
	{
		//if ( index<1 || index>m_ncapacity)
		if ( index<0 || index>m_ncapacity)
			throw "illegal index";

		if (!isContain(index))
			throw "index is not in queue";

		return m_array[index];

	}


	template <typename T>
	T IndexPriorityQueueMin<T>::Min() const
	{
		if (IsEmpty())
			throw "empty Queue";

		return m_array[m_nIndexArray[1]];
	}

	template<typename T>
	void IndexPriorityQueueMin<T>::PrintElements()
	{
		for (int i=0;i<=m_nSize;i++)
		{
			cout << m_array[m_nIndexArray[i]] << " ";
		}
		cout<< endl;
	}

	template<typename T>
	IndexPriorityQueueMin<T>::~IndexPriorityQueueMin()
	{
		delete[] m_array;
		delete[] m_nIndexArray;
		delete[] m_nIndexArrayInverse;
	}

#endif


//main.cpp

#include <time.h>
#include<windows.h>

#include <iostream>
#include <vector>
using namespace std;

#include "Component.h"
#include "Queue.h"
#include "PriorityQueueMax.h"
#include "PriorityQueueMin.h"
#include "IndexPriorityQueueMin.h"

using namespace jay;

int main(int argc, char* argv[])
{

	IndexPriorityQueueMin<int> myqueue(300); // 声明队列

	int test1[100] = {0,10,9,8,7,6,5,4,3,2,1,11,12,13,14,15,16,17,18,19,20};

	// 索引从1 开始 0不使用
	for (int i=1;i<=20;i++)
	{
		myqueue.Insert(test1[i],i);
	}

	test1[9] = 0;
	myqueue.ChangeValue(0,9);

	cout  << "当前获取的值: "<< myqueue.GetValue(1) << endl;
	cout  << "当前最小值: "<< myqueue.Min() << endl;

	myqueue.Delete(1);
	myqueue.Delete(2);
	myqueue.Delete(16);
	myqueue.PrintElements();

/*
	int p;
	TimeCalculator timec;
	cout << "堆初始化";
	timec.PrintTimeInfo();

	myqueue.PrintElements();
*/

	while(!myqueue.IsEmpty())
	{
		cout <<"当前出队列元素 " <<test1[myqueue.PopMin()]  << endl;
//		myqueue.PrintElements();
	}
	


}