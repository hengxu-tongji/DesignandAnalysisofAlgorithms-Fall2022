#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

const int N = 1e6;

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

template<class Type>
int RandomizedPartition(Type a[], int p, int r) { //产生随机的划分基准
	srand(time(0));
	int i = (rand() % (r - p)) + p; 
	Swap(a[i], a[p]);
	return Partition(a, p, r);
}

template <class Type>
Type RandomizedSelect(Type a[], int p, int r, int k) {
	if (p == r) { //考虑极端情况
		return a[p];
	}
	int i = RandomizedPartition(a, p, r);
	int j = i - p + 1; 
	if (k <= j) { 
		return RandomizedSelect(a, p, i, k);
	}
	else 
	{
		return RandomizedSelect(a, i + 1, r, k - j);
	}
}

int main()
{
	//clock_t start, end;
	//start = clock();
	int k;
	int a[10000];
	int n;
	int ans;
	cin >> n;
	for (int i = 0;i <= n - 1; i++) {
		cin >> a[i];
	}
	cin >> k;
	for (int t = 0;t < N;t++) { 
		ans = RandomizedSelect(a, 0, n - 1, k);
	}
	//end = clock();
	cout << ans << endl;
	//double time = static_cast<double>(end - start) / CLOCKS_PER_SEC; 
	//cout << "程序运行N次所需时间：" << time << "毫秒";
	system("pause");
	return 0;
}
