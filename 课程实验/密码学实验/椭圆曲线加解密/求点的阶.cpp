#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

class Point {
public:
    int x;
    int y;
};

Point P[100];
int num = 0;

// ȡģ
int my_mod(int a, int p) {
    int i = a / p;
    int re = a - i * p;
    if (re >= 0) {
        return re;
    } else {
        return re + p;
    }
}

// �ݴ����㣬��ģ���㣬��ֹ���
int my_pow(int a, int m, int p) {
    int result = 1;
    for (int i = 0; i < m; i++) {
        result = (result * a) % p;
    }
    return result;
}

// ������ y, ���ж�ƽ�����Ƿ�Ϊ���� 
int my_sqrt(int s) {
    int t;
    t = (int)sqrt(s);
    if (t * t == s) {
        return t;
    } else {
        return -1;
    }
}

// ������Բ�����ϵ����е�
void all_points(int a, int b, int p) {
    for (int i = 0; i < p; i++) {
        int s = i * i * i + a * i + b;
        while (s < 0) {
            s += p;
        }
        s = my_mod(s, p);
        int re = my_pow(s, (p - 1) / 2, p);
        if (re == 1) {
            int y;
            int f = my_sqrt(s);
            if (f != -1) {
                y = f;
            } else {
                int n = 1;
                for (; n <= p - 1; n++) {
                    s += p;
                    f = my_sqrt(s);
                    if (f != -1) {
                        y = f;
                        break;
                    }
                }
            }
            y = my_mod(y, p);
            P[num].x = i;
            P[num].y = y;
            num++;
            if (y != 0) {
                P[num].x = i;
                P[num].y = (p - y) % p;
                num++;
            }
        }
    }
}

// ��ӡ���е�
void show() {
    for (int i = 0; i < num; i++) {
        cout << P[i].x << " " << P[i].y << endl;
    }
}

// ��չŷ����÷����ݹ鷨
int extend(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = extend(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return r;
}

// ����
int inv(int a, int b) {
    int x, y;
    int r = extend(a, b, x, y);
    if (r != 1) {
        return 0;
    }
    x = x % b;
    if (x < 0) {
        x = x + b;
    }
    return x;
}

// ����ļӷ����� 
Point add(Point p1, Point p2, int a, int p) {
    long t;
    int flag = 0;
    int x1 = p1.x;
    int y1 = p1.y;
    int x2 = p2.x;
    int y2 = p2.y;
    int tx, ty;
    int x3, y3;

    if ((x2 == x1) && (y2 == y1)) {
        if (y1 == 0) {
            flag = 1;
        } else {
            t = (3 * x1 * x1 + a) * inv(2 * y1, p) % p;
        }
    } else {
        ty = y2 - y1;
        tx = x2 - x1;
        while (tx < 0) {
            tx = tx + p;
        }
        while (ty < 0) {
            ty = ty + p;
        }
        if (tx == 0 && ty != 0) {
            flag = 1;
        } else {
            t = ty * inv(tx, p) % p;
        }
    }

    if (flag == 1) {
        p2.x = -1;
        p2.y = -1;
    } else {
        x3 = (t * t - x1 - x2) % p;
        y3 = (t * (x1 - x3) - y1) % p;
        while (x3 < 0) {
            x3 += p;
        }
        while (y3 < 0) {
            y3 += p;
        }
        p2.x = x3;
        p2.y = y3;
    }
    return p2;
}

// �����Ľ�
int calculate_order(Point G, int a, int p) {
    Point current_point = G;
    Point initial_point = G;
    int order = 1;

    while (!(current_point.x == -1 && current_point.y == -1)) {
        current_point = add(current_point, initial_point, a, p);
        order++;
    }

    return order;
}

int main() {
    srand(time(NULL));
    int a, b, p;
    Point generator;

    cout << "��������Բ����Ⱥ��a,b,p����";
    cin >> a >> b >> p;

    // �������е�
    all_points(a, b, p);

    // ��ӡ���е�
    cout << "��Բ�����ϵ����е㣺" << endl;
    show();

    // �����Ľ�
    cout << "�����Ľף�ѡ��㣨x, y����";
    cin >> generator.x >> generator.y;
    int order = calculate_order(generator, a, p);
    cout << "�� (" << generator.x << ", " << generator.y << ") �Ľ�Ϊ: " << order << endl;

    return 0;
}
