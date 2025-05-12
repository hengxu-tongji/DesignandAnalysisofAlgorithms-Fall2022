#include <iostream>
#include <fstream>

using namespace std;

template <class Type>
void Swap(Type& x, Type& y) { //����Swap������������
	Type temp = x;
	x = y;
	y = temp;
}

//������������λ��
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

//��λ����λ�ö���Ϊn/2 
int QSforMidNum(int* a, int L, int R, int Location) { //��������˼������λ��
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
				else { //�Ѳ��ҵ���key�����ֵ
					a[j--] = a[i];
					break;
				}
			}
		}

		//���ҵ����������λ��
		int pivot = i; //��pivot��������λ��
		a[pivot] = key;
		//����key��ȵ���ֵ�ƶ���key����������
		for (int l = L;l < count1;l++) //�ƶ���߲���
		{
			a[l] = a[--i];
			a[i] = key;
		}
		for (int r = R;r > count2;r--) //�ƶ��ұ߲���
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
		else { //��ʱpivot>Location
			if (pivot - count1 + L <= Location) {
				return a[pivot];
			}
			else {
				QSforMidNum(a, L, pivot - count1 + L - 1, Location);
			}
		}
	}
	else { //��ʱL=Location
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
		cout << "����A����Ԫ��Ϊ" << Judge(a, QSforMidNum(a, 0, n - 1, n / 2), n);
	}
	else {
		cout << "����Aû����Ԫ��";
	}
	system("pause");
	return 0;
}
