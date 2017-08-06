#include <iostream>  
#include "MaxHeap.h"  
using namespace std;

/*最大堆成员函数实现*/
MaxHeap::MaxHeap(int array[], int n)
{
	this->array = array;
	size = n;
	buildHeap();
}

void MaxHeap::buildHeap()
{
	for (int i = size / 2 - 1; i >= 0; i--)
		siftDown(i);
}

void MaxHeap::siftDown(int index)
{
	int max_index = leftChild(index);
	while (max_index<size)
	{
		if (max_index<size - 1 && array[rightChild(index)]>array[max_index])
			max_index++;
		if (array[index]>array[max_index])
			break;
		swap(index, max_index);
		index = max_index;
		max_index = leftChild(index);
	}
}

void MaxHeap::swap(int index1, int index2)
{
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}

void MaxHeap::removeMax()
{
	swap(0, size - 1);
	size--;
	siftDown(0);
}

int MaxHeap::leftChild(int index)
{
	return index * 2 + 1;
}

int MaxHeap::rightChild(int index)
{
	return index * 2 + 2;
}

/*最大堆排序函数*/
void MaxHeap::heapSort(int array[], int n)
{
	MaxHeap max_heap = MaxHeap(array, n);

	/*删除堆的最大值（堆顶），即每次将最大值与数组的最后一个元素交换位置*/
	for (int i = 0; i<n; i++)
		max_heap.removeMax();
}