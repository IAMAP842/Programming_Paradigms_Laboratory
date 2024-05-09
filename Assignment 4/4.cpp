#include <iostream>
#include <vector>
#include <cmath>

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

class ShapeStack
{
private:
    vector<Shape *> shapes;

public:
    ~ShapeStack()
    {
        for (auto &shape : shapes)
        {
            delete shape;
        }
    }

    void push(Shape *shape)
    {
        shapes.push_back(shape);
    }

    void pop()
    {
        if (!shapes.empty())
        {
            delete shapes.back();
            shapes.pop_back();
        }
    }

    void display() const
    {
        cout << "Shapes in the stack:" << endl;
        for (const auto &shape : shapes)
        {
            cout << "- Area: " << shape->area() << endl;
        }
    }

    double totalAreaCovered() const
    {
        double totalArea = 0;
        for (const auto &shape : shapes)
        {
            totalArea += shape->area();
        }
        return totalArea;
    }
};

int main()
{
    ShapeStack shapeStack;
   
    shapeStack.push(new Triangle(3, 4));
   
    shapeStack.push(new Rectangle(2, 5));
   
    shapeStack.push(new Circle(2.5));

    shapeStack.display();
    cout << "Total area covered by the shapes: " << shapeStack.totalAreaCovered() << endl;

    shapeStack.pop();
    shapeStack.display();
    cout << "Total area covered by the shapes after popping one shape: " << shapeStack.totalAreaCovered() << endl;

    return 0;
}