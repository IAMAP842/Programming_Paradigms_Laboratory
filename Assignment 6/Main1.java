import java.util.Scanner;

class Student {
    String name;
    int roll;

    public Student(String name, int roll) {
        this.name = name;
        this.roll = roll;
    }

    public void display() {
        System.out.println("Name: " + name + ", Roll Number: " + roll);
    }
}

public class Main1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter no of students: ");
        int n = sc.nextInt();

        Student[] students = new Student[n];

        for (int i = 0; i < n; i++) {
            System.out.println("\nEnter details for student " + (i + 1) + ":");
            System.out.print("Enter Name: ");
            sc.nextLine(); 
            String name = sc.nextLine();
            System.out.print("Enter Roll Number: ");
            int roll = sc.nextInt();
            students[i] = new Student(name, roll);
        }

        System.out.println("\nStudent details:");
        for (Student student : students) {
            student.display();
        }

        sc.close();
    }
}
