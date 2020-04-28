#include <iostream>
#include <string>
using namespace std;
const int MAX_SIZE = 100;
int C[MAX_SIZE][MAX_SIZE],B[MAX_SIZE][MAX_SIZE];
int m = 8, n = 5;
string X = " ACBDBACD", Y = " CDABA", ans;

void print(int i, int j) {
	if (!i || !j) {
		cout << "最长公共子序列为：" << ans << endl;
		return;
	}
	if (B[i][j] == 3) {
		ans = X[i] + ans;
		print(i - 1, j - 1);
	}
	else if (B[i][j] == 1)
		print(i - 1, j);
	else print(i, j - 1);
}

int main() {
	cout << "序列X" << X << endl;
	cout << "序列Y" << Y << endl;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (X[i] == Y[j]) {
				C[i][j] = C[i - 1][j - 1] + 1;
				B[i][j] = 3;
			}
			else {
				if (C[i][j - 1] >= C[i - 1][j]) {
					C[i][j] = C[i][j - 1];
					B[i][j] = 2;
				}
				else {
					C[i][j] = C[i - 1][j];
					B[i][j] = 1;
				}
			}
		}
	}

	cout << "最长公共子序列长度为：" << C[m][n] << endl;
	print(m, n);
}