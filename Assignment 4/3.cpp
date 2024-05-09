#include <bits/stdc++.h>
using namespace std;

class Shape
{
public:
    virtual double area() const = 0;
};

class Triangle : public Shape
{
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override
    {
        return 0.5 * base * height;
    }
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override
    {
        return length * width;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double area() const override
    {
        return M_PI * radius * radius;
    }
};

int main()
{
    vector<Shape *> shapes;
    shapes.push_back(new Triangle(3, 4));
    shapes.push_back(new Rectangle(2, 5));
    shapes.push_back(new Circle(2.5));

    double totalArea = 0;
    for (const auto &shape : shapes)
    {
        totalArea += shape->area();
    }

    cout << "Total area covered by the shapes: " << totalArea << endl;

    for (auto &shape : shapes)
    {
        delete shape;
    }

    return 0;
}