#include <iostream>

using namespace std;

#include "Point.h"

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(double a, double b) {
    x = a;
    y = b;
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

const Point Point::operator+(const Point &rhs) const {
    Point p1;
    p1.x = this->x + rhs.x;
    p1.y = this->y + rhs.y;
    return p1;
}

const Point Point::operator-(const Point &rhs) const {
    Point p1;
    p1.x = this->x - rhs.x;
    p1.y = this->y - rhs.y;
    return p1;
}

Point Point::operator=(const Point &rhs) {
    this->x = rhs.x;
    this->y = rhs.y;
    return *this;
}

bool Point::operator==(const Point& p2) const {
        return x == p2.x && y == p2.y;
}

bool Point::operator!=(const Point& p2) const {
        return x != p2.x || y != p2.y;
}

const Point& Point::operator-=(const Point& p2) {
        x -= p2.x; y -= p2.y;
        return *this;
}

const Point& Point::operator+=(const Point& p2) {
        x += p2.x; y += p2.y;
        return *this;
}

ostream & operator<<(ostream& out, const Point& rhs) {
     out << "(" << rhs.x << ", " << rhs.y << ")";
     return out;
}