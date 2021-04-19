#include <iostream>
using namespace std;

double sqr(double a);
bool equal(double a, double b, double e = 1E-10);
const auto PI = 3.141592653589793;
enum Coord_system { Cartesian, Polar };

class Point {
private:
    double x, y;

public:
    Point(double a1 = 0, double a2 = 0, Coord_system coord_system = Cartesian) {

        if (coord_system == Cartesian) {
            this->x = a1;
            this->y = a2;
        }
        else {
            this->x = a1 * cos(a2);
            this->y = a1 * sin(a2);
        }

    }

    double get_x() {
        return x;
    }
    double get_y() {
        return y;
    }
    double get_r() {
        return sqrt(x * x + y * y);
    }
    double get_phi() {
        return atan2(y, x);
    }

    void set_x(double a) {
        this->x = a;
    }
    void set_y(double a) {
        this->y = a;
    }
    void set_r(double a) {
        double fi = get_phi();
        this->x = a * cos(fi);
        this->y = a * sin(fi);
    }
    void set_phi(double fi) {
        double a = get_r();
        this->x = a * cos(fi);
        this->y = a * sin(fi);
    }

    bool operator ==(Point p) {
        if (fabs(this->x - p.x) < exp(-10) && fabs(this->y - p.y) < exp(-10)) return true;
        else return false;
    }
    bool operator !=(Point p) {
        return (!(*this == p)) ? true : false;
    }
    friend std::istream& operator >> (std::istream& in, Point& p) {

        in.ignore(1);
        in >> p.x;
        in.ignore(1);
        in >> p.y;
        in.ignore(1);

        return in;
    }
    friend std::ostream& operator << (std::ostream& out, Point& p) {

        out << '(' << p.x << ", " << p.y << ") ";

        return out;
    }
};

class Vector {
private:
    Point start;
    double x1, x2, y1, y2, x, y;
public:
    Vector() {
        x1 = start.get_x();
        x2 = x1 + 1;
        y1 = start.get_y();
        y2 = y1;
        this->x = this->x2 - this->x1;
        this->y = this->y2 - this->y1;
    }
    Vector(Point end) {
        this->x1 = start.get_x();
        this->y1 = start.get_y();
        this->x2 = end.get_x();
        this->y2 = end.get_y();
        this->x = this->x2 - this->x1;
        this->y = this->y2 - this->y1;
    }
    Vector(Point begin, Point end) {
        this->x1 = begin.get_x();
        this->y1 = begin.get_y();
        this->x2 = end.get_x();
        this->y2 = end.get_y();
        this->x = this->x2 - this->x1;
        this->y = this->y2 - this->y1;
    }


    double length() {
        return sqrt(sqr(x)+sqr(y));
    }

    bool operator ==(Vector right) {
        if (fabs(this->length()) == fabs(right.length())) return true;
        else return false;
    }

    Vector operator -() {
        Vector temp;
        temp.x = this->x;
        temp.y = this->y;
        return temp;
    }

    Vector operator +(Vector& right) {
        Vector temp;
        temp.x = this->x + right.x;
        temp.y = this->y + right.y;
        return temp;
    }

    Vector operator -(Vector& right) {
        Vector temp;
        temp.x = this->x - right.x;
        temp.y = this->y - right.y;
        return temp;
    }

    Vector operator *(double right) {
        Vector temp;
        temp.x = this->x * right;
        temp.y = this->y * right;
        return temp;
    }

    double operator *(Vector& right) {
        return this->x * right.x + this->y * right.y;
    }

};

int main()
{
    Vector a(Point(1, 2)), b(Point(-2, 0), Point(-1, 2));
    if (a == b && b == a) cout << "Equality test passed\n";
    else cout << "Equality test failed\n";

    Vector na(Point(-1, -2)), ox(Point(1, 0)), nox(Point(-1, 0)), oy(Point(0, 1)), noy(Point(0, -1));
    if (a == -na && na == -a && -ox == nox && -oy == noy) cout << "Invert test passed\n";
    else cout << "Invert test failed\n";
   

    if (ox + oy + oy == a && -ox == -a + oy + oy) cout << "Summation test passed\n";
    else cout << "Summation test failed\n";
    
    if (-ox + oy == oy - ox && -oy + ox == ox - oy) cout << "Subtraction test passed\n";
    else cout << "Subtraction test failed\n";
    
    if (ox * 3 == ox + ox + ox &&
        oy * 3 == oy + oy + oy &&
        ox * (-3) == -ox - ox - ox &&
        oy * (-3) == -oy - oy - oy) cout << "Multiplication by number test passed\n";
    else cout << "Multiplication by number test failed\n";

    if (equal(ox.length(), 1) &&
        equal(oy.length(), 1) &&
        equal((ox * 3 + oy * 4).length(), 5)) cout << "Length test passed\n";
    else cout << "Length test failed\n";
    
    if (equal(ox * ox, sqr(ox.length())) &&
        equal(oy * oy, sqr(oy.length())) &&
        equal((ox * 3 + oy * 4) * (ox * 3 + oy * 4), sqr((ox * 3 + oy * 4).length()))) cout << "Multiplication by Vector test passed\n";
    else cout << "Multiplication by Vector test failed\n";
    
}

bool equal(double a, double b, double e) {
    if (-e < a - b && a - b < e) return true;
    else return false;
}

double sqr(double a) {
    return a * a;
}