#include <iostream>
using namespace std;
class Point {
public:
    int x, y;
    Point(int a, int b) {
        x = a;
        y = b;
    }
    Point* move(int dx, int dy) {
        x = x + dx;
        y = y + dy;
        return this;
    }
    void show() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};
void change(Point* p) {
    p->x += 5;
    p->y += 5;
}
int main() {
    Point p(1, 2);
    cout << "Initial: ";
    p.show();
    p.move(2, 3)->move(-1, 4);
    cout << "After chained move: ";
    p.show();
    change(&p);
    cout << "After pointer update: ";
    p.show();
    return 0;
}
