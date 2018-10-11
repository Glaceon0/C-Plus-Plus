#ifndef _POINT_H
#define _POINT_H

class Point {
    public:
        Point();
        Point(double a, double b);
        double getX() const;
        double getY() const;
        const Point operator+(const Point &rhs) const;
        const Point operator-(const Point &rhs) const;
        Point operator=(const Point &rhs);
        bool operator==(const Point &p2) const;
        bool operator!=(const Point &p2) const;
        const Point& operator-=(const Point& p2);
        const Point& operator+=(const Point& p2);
        friend ostream & operator<<(ostream& out, const Point& rhs); 
    private:
        double x;
        double y;
};

#endif