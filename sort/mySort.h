#pragma once
#include <iostream>
using namespace std;

class mySort
{
public:
	mySort();
	~mySort();
	void swap(int array[], int i, int j);
	/*插入排序*/
	void InsertSort(int array[], int n);
	/*冒泡排序*/
	void BubbleSort(int array[], int n);
	/*选择排序*/
	void SelectionSort(int array[], int n);
	/*希尔排序*/
	void ShellSort(int array[], int n);

	/*将轴值放到数组的适当的位置*/
	int partition(int array[], int left, int right);
	/*快速排序*/
	void quickSort(int array[], int left, int right);

	/*归并过程--将两个有序数组合并成一个有序数组*/
	void merge(int array[], int tempArray[], int left, int right, int middle);
	/*两路归并排序--array[]为待排数组，tempArray[]为临时数组，left和right分别是数组两端*/
	void mergeSort(int array[], int tempArray[], int left, int right);

	/*计算关键字位数的最大值*/
	int KeySize(int array[], int size);
	/*基数排序*/
	void RadixSort(int array[], int size);
};

