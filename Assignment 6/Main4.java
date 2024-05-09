import java.util.ArrayList;
import java.util.Scanner;

class Shape {
    double calculateArea() {
        return 0.0;
    }
}

class Triangle extends Shape {
    double base, height;

    Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    @Override
    double calculateArea() {
        return 0.5 * base * height;
    }
}

class Rectangle extends Shape {
    double length, width;

    Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    double calculateArea() {
        return length * width;
    }
}

class Circle extends Shape {
    double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    @Override
    double calculateArea() {
        return Math.PI * radius * radius;
    }
}

public class Main4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Shape> shapes = new ArrayList<>();

        System.out.print("Enter the number of shapes: ");
        int numShapes = scanner.nextInt();

        for (int i = 0; i < numShapes; i++) {
            System.out.println("Enter details for shape " + (i + 1));
            System.out.print("Enter type (1 for Triangle, 2 for Rectangle, 3 for Circle): ");
            int type = scanner.nextInt();
            switch (type) {
                case 1:
                    System.out.print("Enter base and height of Triangle: ");
                    double base = scanner.nextDouble();
                    double height = scanner.nextDouble();
                    shapes.add(new Triangle(base, height));
                    break;
                case 2:
                    System.out.print("Enter length and width of Rectangle: ");
                    double length = scanner.nextDouble();
                    double width = scanner.nextDouble();
                    shapes.add(new Rectangle(length, width));
                    break;
                case 3:
                    System.out.print("Enter radius of Circle: ");
                    double radius = scanner.nextDouble();
                    shapes.add(new Circle(radius));
                    break;
                default:
                    System.out.println("Invalid shape type. Skipping...");
            }
        }

        double totalArea = 0.0;
        for (Shape shape : shapes) {
            totalArea += shape.calculateArea();
        }

        System.out.println("Total area covered by all shapes: " + totalArea);
    }
}
