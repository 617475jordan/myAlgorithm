#include <iostream>  
using namespace std;

/*最大堆定义*/
class MaxHeap
{
private:
	int size; //最大堆的元素数目  
	int * array;  //最大堆数组的首地址指针  
public:
	MaxHeap(int array[], int n); //用已有数组初始化一个最大堆   
	void buildHeap();   //构建最大堆  
	void siftDown(int index);  //向下筛选法  
	void swap(int index1, int index2);  //交换位置为index1与index2的元素  
	void removeMax();  //删除堆顶的最大值--与数组最后一个元素交换位置并重新构建最大堆  
	int leftChild(int index);  //返回左孩子的位置  
	int rightChild(int index);  //返回右孩子的位置  

	void heapSort(int array[], int n);
};