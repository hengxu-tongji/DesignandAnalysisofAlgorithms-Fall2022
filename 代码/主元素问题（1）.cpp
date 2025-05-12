#include <iostream> 
#include <fstream>

using namespace std;

template <class Type>
void Swap(Type& x, Type& y) { //����Swap������������
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
void QuickSort(Type a[], int p, int r) { //��������
	if (p < r) {
		int q = Partition(a, p, r);
		QuickSort(a, p, q - 1); //����������
		QuickSort(a, q + 1, r); //���Ұ������
	}
}

template <class Type>
int Judge(Type a[], int n) { //�ж������ҳ���Ϊn������a[]�Ƿ�����Ԫ��
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
		cout << "����A����Ԫ��Ϊ" << Judge(a, n);
	}
	else {
		cout << "����Aû����Ԫ��";
	}
	system("pause");
	return 0;
}
