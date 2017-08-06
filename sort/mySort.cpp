#include "mySort.h"

mySort::mySort()
{

}
mySort::~mySort()
{
}


/*交换函数，作用是交换数组中的两个元素的位置*/
void mySort::swap(int array[], int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

//最差情况下，直接插入排序的最大时间代价为θ(n²)，
//最小时间代价为θ(n)，平均时间代价为θ(n²)
void mySort::InsertSort(int array[], int n)
{
	for (int i = 1; i<n; i++)
	{
		for (int j = i; j>0; j--)
		{
			if (array[j]>array[j - 1])
				swap(array, j, j - 1);
			else
				break;
		}
	}
}

//冒泡排序的最大时间代价，
//最小时间代价和平均时间代价均为θ(n²)
void mySort::BubbleSort(int array[], int n)
{
	for (int i = 0; i<n - 1; i++)
	{
		for (int j = n - 1; j>i; j--)
		{
			if (array[j]<array[j - 1])
				swap(array, j, j - 1);
		}
	}
}

//选择排序的最大时间代价，最小时间代价和平均时间代价均为θ(n²)。
//选择排序不依赖于原始数组的输入顺序
void mySort::SelectionSort(int array[], int n)
{
	for (int i = 0; i<n - 1; i++)
	{
		int smallest = i;
		for (int j = i + 1; j<n; j++)
		{
			if (array[smallest]>array[j])
				smallest = j;
		}
		swap(array, i, smallest);
	}
}

/*
增量为2的shell排序的时间代价可以达到θ(n的3 / 2次方)，
有的增量可以达到θ(n的7 / 6次方)，很接近θ(n)*/

/*希尔排序*/
void mySort::ShellSort(int array[], int n)
{
	for (int delta = n / 2; delta>0; delta /= 2)
	{
		for (int i = 0; i<delta; i++)
		{
			for (int j = i + delta; j<n; j += delta)
			{
				for (int k = j; k>0; k -= delta)
				{
					if (array[k]<array[k - 1])
						swap(array, k, k - 1);
				}
			}
		}
	}
}

/*将轴值放到数组的适当的位置*/
int mySort::partition(int array[], int left, int right)
{
	int mid = (left + right) / 2;
	int tmp = array[mid];
	swap(array, mid, right);
	int i = left;
	int j = right;
	while (1)
	{
		/*i指针向右移动，直到找到一个大于轴值的值*/
		while (1)
		{
			/*如果i与j相遇则确定轴值位置，将其返回*/
			if (i == j)
			{
				array[i] = tmp;
				return i;
			}
			if (array[i]>tmp)
			{
				array[j] = array[i];
				j--;
				break;
			}
			i++;
		}
		/*j指针向左移动，直到找到一个小于轴值的值*/
		while (1)
		{
			/*如果i与j相遇则确定轴值位置，将其返回*/
			if (i == j)
			{
				array[j] = tmp;
				return j;
			}
			if (array[j]<tmp)
			{
				array[i] = array[j];
				i++;
				break;
			}
			j--;
		}
	}
}


//快速排序的最大时间代价为θ(n²)，最小时间代价为θ(n*logn)，
//平均时间代价为θ(n*logn)。注意：快速排序是一种不稳定的排序方式
//，其性能依赖于原始数组的有序程度
/*快速排序*/
void mySort::quickSort(int array[], int left, int right)
{
	if (right <= left)
		return;
	int pivot = partition(array, left, right);
	quickSort(array, left, pivot - 1);
	quickSort(array, pivot + 1, right);
}


//归并排序的最大时间代价，最小时间代价和平均时间代价均为θ(n*logn)。
//归并排序不依赖于原始数组的有序程度
/*归并过程--将两个有序数组合并成一个有序数组*/
void mySort::merge(int array[], int tempArray[], int left, int right, int middle)
{
	int index1 = left;
	int index2 = middle + 1;
	for (int i = left; (index1 <= middle) && (index2 <= right); i++)
	{
		if (array[index1]<array[index2])
			tempArray[i] = array[index1++];
		else
			tempArray[i] = array[index2++];
	}
	int i = 0;
	while (index1 <= middle)
		tempArray[i++] = array[index1++];
	while (index2 <= right)
		tempArray[i++] = array[index2++];
	for (i = left; i <= right; i++)
		array[i] = tempArray[i];
}

/*两路归并排序--array[]为待排数组，tempArray[]为临时数组，left和right分别是数组两端*/
void mySort::mergeSort(int array[], int tempArray[], int left, int right)
{
	if (left<right)
	{
		int middle = (left + right) / 2;
		mergeSort(array, tempArray, left, middle);
		mergeSort(array, tempArray, middle + 1, right);
		merge(array, tempArray, left, right, middle);
	}
}

/*计算关键字位数的最大值*/
int mySort::KeySize(int array[], int size)
{
	int key_size = 1;

	for (int i = 0; i<size; i++)
	{
		int temp = 1;
		int n = 10;
		while (array[i] / n>0)
		{
			temp++;
			n *= 10;
		}
		key_size = (temp>key_size) ? temp : key_size;
	}
	return key_size;
}

/*基数排序*/
void mySort::RadixSort(int array[], int size)
{
	int bucket[10000][10000] = { 0 };//定义基数桶  
	int order[10000] = { 0 };//保存每个基数桶之中的元素个数  
	int key_size = KeySize(array, size);//计算关键字位数的最大值  

	for (int n = 1; key_size>0; n *= 10, key_size--)
	{
		/*将待排序的元素按照关键值的大小依次放入基数桶之中*/
		for (int i = 0; i<size; i++)
		{
			int lsd = (array[i] / n) % 10;
			bucket[lsd][order[lsd]] = array[i];
			order[lsd]++;
		}

		/*将基数桶中的元素重新串接起来*/
		int k = 0;
		for (int i = 0; i<10; i++)
		{
			if (order[i] != 0)
			{
				for (int j = 0; j<order[i]; j++)
				{
					array[k] = bucket[i][j];
					k++;
				}
				order[i] = 0;
			}
		}
	}
}