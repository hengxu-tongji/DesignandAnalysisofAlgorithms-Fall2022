#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
const int N = 1e6;

//维持最大堆性质
void max_heapify(int* a, int i, int n) 
{
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 
	int largest; 
	if (l < n && a[l] > a[i]) 
		largest = l;
	else
		largest = i;
	if (r < n && a[r] > a[largest]) 
		largest = r;
	if (largest != i) { 
		int temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		max_heapify(a, largest, n);
	}
}

//初始创建一个最大堆
void build_max_heap(int* a, int n)
{
	for (int i = n / 2;i >= 0;--i)
		max_heapify(a, i, n);
}

//找到第k小的值
int heap_findKthSmallest(int* nums, int k, int n)
{
	int heapSize = k;
	build_max_heap(nums, heapSize);
	for (int i = k; i <= n - 1; i++)
	{
		if (nums[i] >= nums[0]) continue;
		else {
			nums[0] = nums[i];
			max_heapify(nums, 0, k);
		}
	}
	return nums[0];
}

int main()
{
	clock_t start, end;
	start = clock();
	int n;
	int k;
	int a[10000];
	int i, j;
	cin >> n;
	for (i = 0;i < n;i++) 
		cin >> a[i];
	cin >> k;
	cout << heap_findKthSmallest(a, k, n) << endl;
	end = clock();
	double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	cout << "程序运行N次所需时间：" << time << "毫秒";
	system("pause");
	return 0;
}
