#include <iostream> 
#include <fstream>
#include <math.h>

using namespace std;

double line[100][100]; //line[i][j]�洢��i�͵�j�����ıߵĳ���

double C_triangle(int i, int k, int j) { //�ʷ������ε��ܳ���Ҳ������Ѳ�ߡ�ikj�ĳɱ�
	return line[i][k] + line[k][j] + line[i][j];
}

int main() {
	int n;
	int i, j;
	cin >> n;
	double m[100][100];
	double x[100], y[100];
	for (i = 0;i < n;i++) {
		cin >> x[i] >> y[i];
	}
	for (i = 0;i < n;i++) {
		for (j = i;j < n;j++) {
			double x_ = x[i] - x[j];
			double y_ = y[i] - y[j];
			line[i][j] = sqrt(pow(x_, 2) + pow(y_, 2));
		}
	}
	for (int i = 0;i <= n;i++) {
		m[i][i] = 0; 
	}
	//��ʼ����Ѳ������
	for (i = n - 1;i >= 1;i--) {
		for (j = i + 1;j <= n - 1;j++) { 
			m[i][j] = m[i][i] + m[i + 1][j] + C_triangle(i - 1, i, j);
			for (int k = i + 1;k < j;k++) { 
				double temp = m[i][k] + m[k + 1][j] + C_triangle(i - 1, k, j); 
				if (temp < m[i][j]) {
					m[i][j] = temp;
				}
			}
		}
	}
	cout << "��С�ܳɱ�Ϊ" << m[1][n - 1] << endl;
	system("pause");
	return 0;
}

