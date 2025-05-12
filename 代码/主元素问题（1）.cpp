#include <iostream> 
#include <fstream>

using namespace std;

template <class Type>
void Swap(Type& x, Type& y) { //利用Swap函数便利交换
	Type temp = x;
	x = y;
	y = temp;
}

template <class Type>
int Partition(Type a[], int p, int r) { 
	int i = p, j = r + 1;
	Type x = a[p]; 
	while (true) {
		while (a[++i] < x && i < r);
		while (a[--j] > x);
		if (i >= j) {
			break;
		}
		Swap(a[i], a[j]);
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}

template <class Type>
void QuickSort(Type a[], int p, int r) { //快速排序
	if (p < r) {
		int q = Partition(a, p, r);
		QuickSort(a, p, q - 1); //对左半段排序
		QuickSort(a, q + 1, r); //对右半段排序
	}
}

template <class Type>
int Judge(Type a[], int n) { //判定有序且长度为n的数组a[]是否有主元素
	int ans = -1; 
	int mid = a[n / 2]; 
	int prob = a[mid]; 
	int sum = 1;
	int i;
	bool equal;
	for (i = mid - 1;i >= 0;i--) {
		equal = false;
		if (a[i] == prob) {
			equal = true;
			sum++;
		}
		if (equal == false) {
			break;
		}
	}
	for (i = mid + 1;i <= n - 1;i++) {
		equal = false;
		if (a[i] == prob) {
			equal = true;
			sum++;
		}
		if (equal == false) {
			break;
		}
	}
	if (sum > n / 2)
		ans = prob;
	return ans;
}

int main()
{
	int a[10000];
	int n;
	cin >> n;
	for (int i = 0;i <= n - 1; i++) {
		cin >> a[i];
	}
	QuickSort(a, 0, n - 1); 
	if (Judge(a, n) != -1) {
		cout << "数组A的主元素为" << Judge(a, n);
	}
	else {
		cout << "数组A没有主元素";
	}
	system("pause");
	return 0;
}
