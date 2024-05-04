#include <iostream>
using namespace std;
template <typename T>
bool hysteria(int a, int b, T k, int c, int size) {
	int f = a; int d = b;
	bool fl = false;
	if (k[a][b] != 1 && k[a - 1][b] != 1 && k[a][b - 1] != 1 && k[a + 1][b] != 1 && k[a][b + 1] != 1 && k[a + 1][b + 1] != 1 && k[a - 1][b - 1] != 1 && k[a - 1][b + 1] != 1 && k[a + 1][b - 1] != 1)
		k[a][b] = 1;
	else
		return false;
	if (c == 0)
		b++;
	else if (c == 1)
		b--;
	else if (c == 2)
		a++;
	else
		a--;
	for (int i = 0; i < size-1; i++) {
		if (c == 3)
			fl = true;
		if ((a >= 0 && a <= 9) && (b >= 0 && b <= 9) && k[a][b] != 1 && k[a + 1][b + 1] != 1 && k[a - 1][b - 1] != 1 && k[a - 1][b + 1] != 1 && k[a + 1][b - 1] != 1 && (c != 0 ? (c != 1 ? (c != 2 ? k[a - 1][b] != 1 : k[a + 1][b] != 1) : k[a][b - 1] != 1) : k[a][b + 1] != 1)) {
			k[a][b] = 5;
			if (c == 0)
				b++;
			else if (c == 1)
				b--;
			else if (c == 2)
				a++;
			else
				a--;
		}
		else {
			for (int j=0; j < 10; j++) {
				if (c == 0 || c == 1) {
					if (k[a][j] == 5)
						k[a][j] = 0;
				}
				else {
					if (k[j][b] == 5) {
						k[j][b] = 0;
					}
				}
			}
			if (c == 0)
				b=d;
			else if (c == 1)
				b=d;
			else if (c == 2)
				a=f;
			else
				a=f;
			i = -1;
			if (fl)
				c--;
			else {
				c++;
			}
			if (c < 0) {
				k[f][d] = 0;
				return false;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (k[i][j] == 5)
				k[i][j] = 1;
		}
	}
	return true;
}
template <typename T>
void print(T field[], T field2[]) {
	cout << "\tа б в г д е ё ж з и \t \t а б в г д е ё ж з и\n";
	for (int i = 0; i < 10; i++) {
		cout << i + 1 << '\t';
		for (int j = 0; j < 10; j++) {
			if (field[i][j] == 0)
				cout << '-';
			else if (field[i][j] == 1)
				cout << '+';
			else if (field[i][j] == 2)
				cout << '=';
			else if (field[i][j] == 3)
				cout << '%';
			else
				cout << '#';
			cout << ' ';
		}
		cout << "\t \t ";
		for (int j = 0; j < 10; j++) {
			if (field2[i][j] == 0 || field2[i][j] == 1)
				cout << '-';
			else if (field2[i][j] == 2)
				cout << '=';
			else if (field2[i][j] == 3)
				cout << '%';
			else
				cout << '#';
			cout << ' ';
		}
		cout << endl;
	}
}
template <typename T>
void fill(T a[], bool comp) {
	if (comp) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < i + 1; j++) {
				while (hysteria(rand() % 10, rand() % 10, a, rand() % 4, 4 - i) == false) {}
			}
		}
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	char field[10][10]{}, field2[10][10]{};
	fill(field, 1);
	print(field, field2);
	return 0;
}
//  а б в г д е ё ж з и
//1                   
//2
//3
//4   =  =  =
//5   +  +  =
//6   =  =  =
//7
//8
//9
//10