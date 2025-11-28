#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Ellipse {
    int rX, rY;
    int Rx, Ry;
};

struct Point {
    int i, j;
};

bool isPointInEllipse(const struct Point *p, const struct Ellipse *e ) {
    int dx = p->j - e->rX;
    int dy = p->i - e->rY;
    return (dx*dx) *(e->Ry*e->Ry)  + (dy*dy) * (e->Rx*e->Rx) <= (e->Ry*e->Ry) * (e->Rx*e->Rx);
};

int mod(int a, int b) {
    return (a % b + b) % b;
};

int max(int a, int b) {
    return (a > b ? a : b);
};

int min(int a, int b) {
    return (a < b ? a : b);
};

int sign(int a) {
    return (a >= 0 ? 1 : -1);
};

int main() {
    struct Ellipse e = {20, 0, 10, 5};
    struct Point p = {-24, 4};
    int l = -3;

    int k = 0;
    while (k < 50 && !isPointInEllipse(&p, &e)) {
        printf("k = %d, i = %d, j = %d\n", k, p.i, p.j);
        struct Point p0 = p;
        p.i = mod(abs((p0.i + k) * (p0.j + 2*k) * (l + 3*k)), 35);
        p.j = sign(max(p0.i, p0.j)) * min(mod((p0.i + k), 20), mod((p0.j + l), 20));
        l = p0.i/3 - abs(p0.i - k) * sign(l - p0.j);

        k = k + 1;
    }

    if (isPointInEllipse(&p, &e)) {
        printf("Point in ellipse: k = %d, i = %d, j = %d\n", k, p.i, p.j);
    } else {
        printf("Point not in ellipse: k = %d, i = %d, j = %d", k, p.i, p.j);
    }

    
    return 0;
}

