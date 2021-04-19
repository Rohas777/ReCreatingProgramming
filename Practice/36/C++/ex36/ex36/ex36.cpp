#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

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

int main() {
    std::vector<Point> original;
    std::ifstream fin("data.txt");
    if (!fin.is_open()) {
        std::cout << "Can't open file" << std::endl;
        return 1;
    }
    else {
        while (!fin.eof()) {
            Point p;
            fin >> p;
            fin.ignore(2); // Точки разделены двумя символами ", "
            original.push_back(p);
        }
        fin.close();
    }

    std::vector<Point> simulacrum(original);
    for (auto& p : simulacrum) {
        std::cout << p;
        p.set_x(p.get_x() + 10);
        p.set_phi(p.get_phi() + 180 * PI / 180);
        p.set_y(-p.get_y());
        p.set_x(-p.get_x() - 10);
        std::cout << p << std::endl;
    }

    if (std::equal(original.begin(), original.end(), simulacrum.begin()))
        std::cout << "\nIt works!\n";
    else
        std::cout << "\nIt not works!\n";
}