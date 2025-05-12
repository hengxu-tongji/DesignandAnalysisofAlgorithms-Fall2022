#include <iostream>
#include <fstream>

using namespace std;

int FindPopularElement(int a[], int n) { //
	int candidate, count = 0;
	for (int i = 0;i <= n - 1;i++) {
		if (count > n / 2) { //����ǰ�ҵ���Ԫ�أ�����a[i]
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

bool isPopularElement(int a[], int n, int candidate) { //�ж�candidate�Ƿ����Ϊ��Ԫ��
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
		cout << "����A����Ԫ��Ϊ" << FindPopularElement(a, n);
	}
	else {
		cout << "����Aû����Ԫ��";
	}
	system("pause");
	return 0;
}