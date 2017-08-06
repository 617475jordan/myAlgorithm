#pragma once
#include <iostream>
using namespace std;

class mySort
{
public:
	mySort();
	~mySort();
	void swap(int array[], int i, int j);
	/*��������*/
	void InsertSort(int array[], int n);
	/*ð������*/
	void BubbleSort(int array[], int n);
	/*ѡ������*/
	void SelectionSort(int array[], int n);
	/*ϣ������*/
	void ShellSort(int array[], int n);

	/*����ֵ�ŵ�������ʵ���λ��*/
	int partition(int array[], int left, int right);
	/*��������*/
	void quickSort(int array[], int left, int right);

	/*�鲢����--��������������ϲ���һ����������*/
	void merge(int array[], int tempArray[], int left, int right, int middle);
	/*��·�鲢����--array[]Ϊ�������飬tempArray[]Ϊ��ʱ���飬left��right�ֱ�����������*/
	void mergeSort(int array[], int tempArray[], int left, int right);

	/*����ؼ���λ�������ֵ*/
	int KeySize(int array[], int size);
	/*��������*/
	void RadixSort(int array[], int size);
};

