#include <iostream>
#define DEBUG
using std::cout;
using std::cin;
using std::endl;
enum status {
    empty, ship, dead, miss, temp, shot, hDown, hLeft, hUp, hRight
};
enum direction {
    right, left, down, up
};
template <typename T>
bool hysteria(int a, int b, T k, int c, int size) {
    int f = a; int d = b;
    bool fl = false;
    if (k[a][b] != ship && k[a - 1][b] != ship && k[a][b - 1] != ship && k[a + 1][b] != ship && k[a][b + 1] != ship && k[a + 1][b + 1] != ship && k[a - 1][b - 1] != ship && k[a - 1][b + 1] != ship && k[a + 1][b - 1] != ship)
        k[a][b] = ship;
    else
        return false;
    if (c == right)
        b++;
    else if (c == left)
        b--;
    else if (c == down)
        a++;
    else
        a--;
    for (int i = 0; i < size - 1; i++) {
        if (c == up)
            fl = true;
        if ((a >= 0 && a <= 9) && (b >= 0 && b <= 9) && k[a][b] != ship && k[a + 1][b + 1] != ship && k[a - 1][b - 1] != ship && k[a - 1][b + 1] != ship && k[a + 1][b - 1] != ship && (c != right ? (c != left ? (c != down ? k[a - 1][b] != ship : k[a + 1][b] != ship) : k[a][b - 1] != ship) : k[a][b + 1] != ship)) {
            k[a][b] = temp;
            if (c == right)
                b++;
            else if (c == left)
                b--;
            else if (c == down)
                a++;
            else
                a--;
        }
        else {
            for (int j = 0; j < 10; j++) {
                if (c == right || c == left) {
                    if (k[a][j] == temp)
                        k[a][j] = empty;
                }
                else {
                    if (k[j][b] == temp) {
                        k[j][b] = empty;
                    }
                }
            }
            if (c == right)
                b = d;
            else if (c == left)
                b = d;
            else if (c == down)
                a = f;
            else
                a = f;
            i = -1;
            if (fl)
                c--;
            else {
                c++;
            }
            if (c < 0) {
                k[f][d] = empty;
                return false;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (k[i][j] == temp)
                k[i][j] = ship;
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
            if (field[i][j] == empty)
                cout << '-';
            else if (field[i][j] == ship)
                cout << '+';
            else if (field[i][j] == shot || field[i][j] == hDown || field[i][j] == hUp || field[i][j] == hLeft || field[i][j] == hRight)
                cout << '=';
            else if (field[i][j] == dead)
                cout << '%';
            else
                cout << '#';
            cout << ' ';
        }
        cout << "\t \t ";
        for (int j = 0; j < 10; j++) {
#ifdef DEBUG
            if (field2[i][j] == empty)
                cout << '-';
            else if (field2[i][j] == ship)
                cout << '+';
#endif
#ifndef DEBUG
            if (field2[i][j] == empty || field2[i][j] == ship)
                cout << '-';
#endif
            else if (field2[i][j] == shot)
                cout << '=';
            else if (field2[i][j] == dead)
                cout << '%';
            else
                cout << '#';
            cout << ' ';
        }
        cout << endl;
    }
}
template <typename T>
void check(T a[], int& x, int& y) {
    int x1=x, x2=x;
    while ((x1+1 <= 9) && (a[x1 + 1][y] == shot)) {        
        x1++;
    }
    if (x1 + 1 <= 9 && a[x1 + 1][y] == ship) {
        return;
    }
    while ((x2 - 1 >= 0) && (a[x2 - 1][y] == shot)) {
        x2--;
    }
    if (x2 - 1 >= 0 && a[x2 - 1][y] == ship) {
        return; //👍👍👍👍
    }
    if (x1 != x2) {
        if (x1 + 1 <= 9) {
            a[x1 + 1][y] == miss;
            if (y + 1 <= 9)
                a[x1 + 1][y + 1] = miss;
            if (y - 1 >= 0)
                a[x1 + 1][y - 1] = miss;
        }
        if (x2 - 1 >= 0) {
            a[x2 - 1][y] == miss;
            if (y + 1 <= 9)
                a[x2 - 1][y + 1] = miss;
            if (y - 1 >= 0)
                a[x2 - 1][y - 1] = miss;
        }
        for (int i = x2; i < x1; i++) {
            a[i][y] = dead;
            if(y+1<=9)
                a[i][y + 1] = miss;
            if(y-1>=0)
                a[i][y - 1] = miss;
        }
        x = -1; y = -1;
        return;
    }
    if (a[x][y - 1] != ship && a[x][y - 1] != shot && a[x][y + 1] != ship && a[x][y + 1] != shot) {
        a[x][y] = dead;
        if (x - 1 >= 0) {
            a[x - 1][y] == miss;
            if (y + 1 <= 9) {
                a[x - 1][y + 1] = miss;
                a[x][y + 1] = miss;
                }
            if (y - 1 >= 0) {
                a[x - 1][y - 1] = miss;
                a[x][y - 1] == miss;
            }
        }
        if (x + 1 <= 9) {
            a[x + 1][y] == miss;
            if (y + 1 <= 9) {
                a[x + 1][y + 1] = miss;
                a[x][y + 1] == miss;
            }
            if (y - 1 >= 0){
                a[x + 1][y - 1] = miss;
                a[x][y - 1] == miss;
            }
        }
        x = -1; y = -1; return;
    }
    int y1 = y, y2 = y;
    while ((y1 + 1 <= 9) && (a[x][y1 + 1] == shot)) {
        y1++;
    }
    if (y1 + 1 <= 9 && a[x][y1 + 1] == ship) {
        return;
    }
    while ((y2 - 1 >= 0) && (a[x][y2 - 1] == shot)) {
        y2--;
    }
    if (y2 - 1 >= 0 && a[x][y2 - 1] == ship) {
        return;
    }
    if (y1 + 1 <= 9) {
        a[x][y1 + 1] == miss;
        if (x + 1 <= 9)
            a[x + 1][y1 + 1] = miss;
        if (x - 1 >= 0)
            a[x - 1][y1 + 1] = miss;
    }
    if (y2 - 1 >= 0) {
        a[x][y2 - 1] == miss;
        if (x + 1 <= 9)
            a[x + 1][y2 - 1] = miss;
        if (y - 1 >= 0)
            a[x - 1][y2 - 1] = miss;
    }
    for (int i = y2; i < y1; i++) {
        a[x][i] = dead;
        if (x + 1 <= 9)
            a[x + 1][i] = miss;
        if (x - 1 >= 0)
            a[x - 1][i] = miss;
    }
    x = -1; y = -1;
    return;
}
template <typename T>
void AI(T a[]) {
    static int i = -1, j = -1;
    int b, c;
    if (i >= 0 && j >= 0) {
        while (true) {
            if (a[i][j] == shot) {
                if (i == 9 || a[i + 1][j] == miss)
                    a[i][j] = hLeft;
                else if (a[i + 1][j] == ship) {
                    a[i + 1][j] = shot;
                    a[i][j] = hDown;
                    check(a, i, j);
                    break;
                }
                else {
                    a[i + 1][j] = miss;
                    a[i][j] = hLeft;
                    break;
                }
            }
            else if (a[i][j] == hDown) {
                int x = i + 1, y = j;
                bool flag = false;
                while (a[x][y] == shot) {
                    if (x < 9 && a[x + 1][y] != miss) x++;
                    else {
                        a[i][j] = hUp;
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    if (a[x][y] == empty)
                        a[x][y] = miss;
                    else {
                        a[x][y] = shot;
                        check(a, i, j);
                    }
                    break;
                }
            }
            else if (a[i][j] == hLeft) {
                int x = i, y = j - 1;
                if (y < 0 || a[x][y] == miss) {
                    a[i][j] = hUp;
                }
                else {
                    bool flag = false;
                    while (a[x][y] == shot) {
                        if (y >= 0 && a[x][y - 1] != miss) y--;
                        else {
                            a[i][j] = hRight;
                            flag = true;
                            break;
                        }
                    }
                    if (!flag) {
                        if (a[x][y] == empty)
                            a[x][y] = miss;
                        else {
                            a[x][y] = shot;
                            check(a, i, j);
                        }
                        break;
                    }
                }
            }
            else if (a[i][j] == hUp) {
                int x = i - 1, y = j;
                if (x < 0 || a[x][y] == miss) {
                    a[i][j] = hRight;
                }
                else {
                    while (a[x][y] == shot) { x--; }
                    a[x][y] = shot;
                    check(a, i, j);
                    break;
                }
            }
            else if (a[i][j] == hRight) {
                int x = i, y = j + 1;
                while (a[x][y] == shot) { y++; }
                a[x][y] = shot;
                check(a, i, j);
                break;
            }
        }
    }
    else {
        do {
            b = rand() % 10, c = rand() % 10;
        } while (a[b][c] != empty && a[b][c] != ship);
        if (a[b][c] == empty)
            a[b][c] = miss;
        else {
            a[b][c] = shot;
            i = b;
            j = c;
            check(a, i, j);
        }
    }
    //проверка на dead
}
template <typename T>
void THEGAME(T f[], T f2[]) {
    int x = 0, y = 0, d, c;
    cout << " '-' -- пустота\n '=' -- ранил\n '%' -- убил\n '#'-мимо\n Приступай!\n";
    do {
        print(f, f2);
        cout << "Смотри какой живучий бот. Пальни по нему, зачем он такой.\n";
        cin >> d >> c;
        if (f2[--d][--c] == empty)
            f2[d][c] = miss;
        else if (f2[d][c] == ship) {
            f2[d][c] = shot;
            x++;
            check(f, d, c);
        }
        else
            cout << "мда.\n";
        AI(f);
    } while (x < 20 || y < 20);
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
            cout << "введите координату головы (через пробел) и направление для " << 4 - i << "-палубных кораблей в количестве " << i + 1 << " штук.\n";
            for (int j = 0; j < i + 1; j++) {
                cin >> d >> c >> b;
                if (hysteria(d - 1, c - 1, a, b, 4 - i) == false) {
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