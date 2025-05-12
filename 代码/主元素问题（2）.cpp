#include <iostream>
#include <fstream>

using namespace std;

template <class Type>
void Swap(Type& x, Type& y) { //利用Swap函数便利交换
	Type temp = x;
	x = y;
	y = temp;
}

//快速排序求中位数
void FindMid(int& p, int& q, int& r) { 
	if ((p < q && q < r) || (r < q && q < p)) {
		Swap(p, q);
	}
	else {
		if ((q < r && r < p) || (p < r && r < q)) {
			Swap(p, r);
		}
	}
}

//中位数的位置定义为n/2 
int QSforMidNum(int* a, int L, int R, int Location) { //快速排序思想求中位数
	if (L < R) {
		int mid = (L + R) / 2;
		FindMid(a[L], a[mid], a[R]); 
		int key = a[L]; 
		int i = L, j = R; 
		int count1 = L, count2 = R; 
		while (i < j) {
			while (i<j && a[j]>key) {
				j--;
			}
			while (i < j) {
				if (a[j] == key) { 
					a[j] = a[count2];
					a[count2] = key;
					count2--;
					j--; 
					while (i<j && a[j]>key) { 
						j--;
					}
				}
				else {
					a[i++] = a[j];
					break; 
				}
			}
			while (i < j && a[i] < key) { 
				i++;
			}
			while (i < j) {
				if (a[i] == key) {
					a[i] = a[count1];
					a[count1] = key;
					count1++;
					i++; 
					while (i < j && a[i] < key) {
						i++;
					}
				}
				else { //已查找到比key更大的值
					a[j--] = a[i];
					break;
				}
			}
		}

		//已找到枢轴的最终位置
		int pivot = i; //用pivot保存枢轴位置
		a[pivot] = key;
		//将与key相等的数值移动到key的左右两边
		for (int l = L;l < count1;l++) //移动左边部分
		{
			a[l] = a[--i];
			a[i] = key;
		}
		for (int r = R;r > count2;r--) //移动右边部分
		{
			a[r] = a[++j];
			a[j] = key;
		}
		if (pivot == Location) {
			return a[pivot];
		}
		else if (pivot < Location) {
			if (pivot + R - count2 >= Location) {
				return a[pivot];
			}
			else {
				QSforMidNum(a, pivot + R - count2 + 1, R, Location);
			}
		}
		else { //此时pivot>Location
			if (pivot - count1 + L <= Location) {
				return a[pivot];
			}
			else {
				QSforMidNum(a, L, pivot - count1 + L - 1, Location);
			}
		}
	}
	else { //此时L=Location
		return a[L];
	}
}

int Judge(int* a, int midnum, int len) {
	int sum = 0;
	int ans = -1;
	for (int i = 0;i < len;i++) {
		if (a[i] == midnum) {
			sum++;
		}
	}
	if (sum > len / 2) {
		ans = midnum;
	}
	return ans;
}

int main() {
	int a[10000];
	int n;
	cin >> n;
	for (int i = 0;i <= n - 1; i++) {
		cin >> a[i];
	}
	QSforMidNum(a, 0, n - 1, n / 2);
	if (Judge(a, QSforMidNum(a, 0, n - 1, n / 2), n) != -1) {
		cout << "数组A的主元素为" << Judge(a, QSforMidNum(a, 0, n - 1, n / 2), n);
	}
	else {
		cout << "数组A没有主元素";
	}
	system("pause");
	return 0;
}
