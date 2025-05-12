#include <iostream>
#include <fstream>

using namespace std;

int FindPopularElement(int a[], int n) { //
	int candidate, count = 0;
	for (int i = 0;i <= n - 1;i++) {
		if (count > n / 2) { //已提前找到主元素，返回a[i]
			return a[i];
		}
		if (count == 0) { 
			candidate = a[i]; 
			count++;
		}
		else {
			if (a[i] == candidate) 
				count++;
			else { 
				count--;
			}
		}
	}
	return candidate; 
}

bool isPopularElement(int a[], int n, int candidate) { //判断candidate是否真的为主元素
	int num = 0;
	for (int i = 0;i <= n - 1;i++) { 
		if (a[i] == candidate)
			num++;
		if (num > n / 2)
			return true;
	}
	return false;
}

int main() {
	int a[10000];
	int n;
	cin >> n;
	for (int i = 0;i <= n - 1; i++) {
		cin >> a[i];
	}
	if (isPopularElement(a, n, FindPopularElement(a, n))) {
		cout << "数组A的主元素为" << FindPopularElement(a, n);
	}
	else {
		cout << "数组A没有主元素";
	}
	system("pause");
	return 0;
}