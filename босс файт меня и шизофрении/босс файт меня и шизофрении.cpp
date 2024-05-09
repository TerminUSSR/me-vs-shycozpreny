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
	cout << "\t1 2 3 4 5 6 7 8 9 10 \t \t 1 2 3 4 5 6 7 8 9 10\n";
	for (int i = 0; i < 10; i++) {
		cout << i + 1 << '\t';
		for (int j = 0; j < 10; j++) {
			if (field[i][j] == 0)
				cout << '-';
			else if (field[i][j] == 1)
				cout << '+';
			else if (field[i][j] == 2 || field[i][j] == 5 || field[i][j] == 6 || field[i][j] == 7 || field[i][j] == 8 || field[i][j] == 9)
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
//template <typename T>
//void tofind(T a[], int d, int c) {
//	if (a[d - 1][c] == 2) {
//		a[d - 1][c] = 3;
//		for (int i = 2; i < 3; i++) {
//			if (a[d - i][c] == 2) {
//				a[d - i][c] == 3;
//			}
//			else
//				break;
//		}
//		a[d][c] == 3;
//	}
//	else if (a[d + 1][c] == 2) {
//		a[d + 1][c] = 3;
//			for (int i = 2; i < 3; i++) {
//				if (a[d + i][c] == 2) {
//					a[d + i][c] == 3;
//				}
//				else
//					break;
//			}
//		a[d][c] == 3;
//	}
//	else if (a[d][c - 1] == 2) {
//		a[d][c - 1] = 3;
//			for (int i = 2; i < 3; i++) {
//				if (a[d][c - i] == 2) {
//					a[d][c - i] == 3;
//				}
//				else
//					break;
//			}
//		a[d][c] == 3;
//	}
//	else if (a[d][c + 1] == 2) {
//		a[d][c + 1] = 3;
//			for (int i = 2; i < 4; i++) {
//				if (a[d][c + i] == 2) {
//					a[d][c + i] == 3;
//				}
//				else
//					break;
//			}
//		a[d][c] == 3;
//	}
//	else
//		a[d][c] = 2;
//}
template <typename T>
void AI(T a[]) {
	int b, c;
	bool x = false;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (a[i][j] == 2) {
				x = true;
				if (a[i + 1][j] == 0 || a[i + 1][j] == 1){
					if (a[i + 1][j] == 1){
						a[i + 1][j] == 6;
						a[i][j] == 9;
					}
					else
						a[i + 1][j] == 4;
			    }
				else if (a[i - 1][j] == 0 || a[i - 1][j] == 1) {
					if (a[i - 1][j] == 1){
						a[i - 1][j] == 6;
						a[i][j] == 9;
					}
					else
						a[i - 1][j] == 4;
				}
				else if (a[i][j + 1] == 0 || a[i][j + 1] == 1) {
					if (a[i][j + 1] == 1){
						a[i][j + 1] == 7;
					    a[i][j] == 9;
				    }
					else
						a[i][j + 1] == 4;
				}
				else if (a[i][j - 1] == 0 || a[i][j - 1] == 1) {
					if (a[i][j - 1] == 1) {
						a[i][j - 1] == 8;
						a[i][j] == 9;
					}
					else
						a[i][j - 1] == 4;
				}
			}
		}
	}
	if (x == false) {
		do {
			b = rand() % 10, c = rand() % 10;
		} while (a[b][c] != 0 || a[b][c] != 1);
		if (a[b][c] == 0)
			a[b][c] == 4;
		else
			a[b][c] == 2;
	}
}
template <typename T>
void THEGAME(T f[], T f2[]) {
	int x=0, d, c;
	cout << " '-' -- пустота\n '=' -- ранил\n '%' -- убил\n '#'-мимо\n Приступай!\n";
	do {
		print(f, f2);
		cout << "Смотри какой живучий бот. Пальни по нему, зачем он такой.\n";
		cin >> d >> c;
		d--; c--;
		if (f2[d][c] == 0)
			f2[d][c] = 4;
		else if (f2[d][c] == 1) {
			f2[d][c] = 2;
			x++;
		}
		else
			cout << "мда.\n";
		AI(f);
	} while (x < 20);
}
template <typename T>
void fill(T a[], bool comp, T f[]) {
	if (comp) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < i + 1; j++) {
				while (hysteria(rand() % 10, rand() % 10, a, rand() % 4, 4 - i) == false) {}
			}
		}
	}
	else {
		int d, c, b;
		cout << "(1-ое значение координат должно быть цифрой, второе тоже. Стороны: 0-вправо, 1-влево, 2-вниз, 3-вверх.)\n";
		for (int i = 0; i < 4; i++) {
			cout << "введите координату головы (через пробел) и направление для " << 4 - i << "-палубных кораблей в количестве " << i+1 << " штук.\n";
			for (int j = 0; j < i + 1; j++) {
				cin >> d >> c >> b;
				if (hysteria(d-1, c-1, a, b, 4 - i) == false) {
					cout << "Ошибка. Судя по всему вы не шибко умный человек. Убедительная просьба вписать верное значение\n"; j--;
				}
				print(a, f);
			}
		}
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	char field[10][10]{}, field2[10][10]{};
	fill(field, 1, field2);
	fill(field2, 1, field);
	THEGAME(field, field2);
	return 0;
}