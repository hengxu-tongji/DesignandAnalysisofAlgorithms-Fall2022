#include <iostream> 
#include <ctime>
#include <fstream>

using namespace std;

const int N = 1e6;

template <class Type>
void Swap(Type& x, Type& y) 
{
	Type temp = x;
	x = y;
	y = temp;
}

template <class Type>
void BubbleSort(Type a[], int p, int r) 
{
	bool exchange; //记录一次遍历中是否有元素的交换，以避免不必要的检索
	for (int i = p;i <= r - 1;i++) {
		exchange = false; 
		for (int j = i + 1;j <= r;j++) {
			if (a[j] < a[j - 1]) {
				Swap(a[j], a[j - 1]);
				exchange = true; 
			}
		}
		if (exchange == false){
			break;
		}
	}
}

template <class Type>
int Partition(Type a[], int p, int r, Type x) 
{
	int i = p - 1, j = r + 1;
	while (true) {
		while (a[++i] < x && i < r);
		while (a[--j] > x);
		if (i >= j) {
			break;
		}
		Swap(a[i], a[j]);
	}
	return j;
}


template <class Type>
Type Select(Type a[], int p, int r, int k) {
	if (r - p < 75) {
		BubbleSort(a, p, r);
		return a[p + k - 1];
	}
	for (int i = 0;i <= (r - p - 4) / 5;i++) 
	{
		BubbleSort(a, p + 5 * i, p + 5 * i + 4);
		Swap(a[p + 5 * i + 2], a[p + i]);
	}
	//找中位数的中位数
	Type x = Select(a, p, p + (r - p - 4) / 5, (r - p - 4) / 10);
	int i = Partition(a, p, r, x);
	int j = i - p + 1;
	if (k <= j) {
		return Select(a, p, i, k);
	}
	else {
		return Select(a, i + 1, r, k - j);
	}
}

int main()
{
	clock_t start, end;
	start = clock();
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
		ans = Select(a, 0, n - 1, k);
	}
	end = clock();
	cout << ans << endl;
	double time = static_cast<double>(end - start) / CLOCKS_PER_SEC; 
	cout << "程序运行N次所需时间：" << time << "毫秒";
	system("pause");
	return 0;
}