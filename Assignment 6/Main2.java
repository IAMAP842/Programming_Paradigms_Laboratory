import java.util.Scanner;

class Student {
    private String name;
    private int age;
    private String department;
    private int year;

    public void readData() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter name:");
        name = scanner.nextLine();
        System.out.println("Enter age:");
        age = scanner.nextInt();
        scanner.nextLine(); 
        System.out.println("Enter department:");
        department = scanner.nextLine();
        System.out.println("Enter year:");
        year = scanner.nextInt();
    }

    public void printData() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Department: " + department);
        System.out.println("Year: " + year);
    }
}

public class Main2 {
    public static void main(String[] args) {
        Student student = new Student();
        student.readData();
        System.out.println("Student Information:");
        student.printData();
    }
}
