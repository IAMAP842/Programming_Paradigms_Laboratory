import java.util.Scanner;

class Person {
    String name;
    int age;
    char gender;
    String dept;

    public Person(String name, int age, char gender, String dept) {
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.dept = dept;
    }

    public void displayProfile() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Gender: " + gender);
        System.out.println("Department: " + dept);
    }
}

class Student extends Person {
    int year;

    public Student(String name, int age, char gender, String dept, int year) {
        super(name, age, gender, dept);
        this.year = year;
    }

    @Override
    public void displayProfile() {
        super.displayProfile();
        System.out.println("Year: " + year);
    }
}

class Professor extends Person {
    int courseLoad;
    double salary;

    public Professor(String name, int age, char gender, String dept, int courseLoad, double salary) {
        super(name, age, gender, dept);
        this.courseLoad = courseLoad;
        this.salary = salary;
    }

    @Override
    public void displayProfile() {
        super.displayProfile();
        System.out.println("Course Load: " + courseLoad);
        System.out.println("Salary: " + salary);
    }
}

public class Main3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter student details:");
        System.out.print("Name: ");
        String studentName = scanner.nextLine();
        System.out.print("Age: ");
        int studentAge = scanner.nextInt();
        System.out.print("Gender: ");
        char studentGender = scanner.next().charAt(0);
        System.out.print("Department: ");
        String studentDept = scanner.next();
        System.out.print("Year: ");
        int studentYear = scanner.nextInt();

        System.out.println("\nEnter professor details:");
        System.out.print("Name: ");
        String profName = scanner.next();
        System.out.print("Age: ");
        int profAge = scanner.nextInt();
        System.out.print("Gender: ");
        char profGender = scanner.next().charAt(0);
        System.out.print("Department: ");
        String profDept = scanner.next();
        System.out.print("Course Load: ");
        int courseLoad = scanner.nextInt();
        System.out.print("Salary: ");
        double salary = scanner.nextDouble();

        Student student = new Student(studentName, studentAge, studentGender, studentDept, studentYear);
        Professor professor = new Professor(profName, profAge, profGender, profDept, courseLoad, salary);

        System.out.println("\nStudent Profile:");
        student.displayProfile();

        System.out.println("\nProfessor Profile:");
        professor.displayProfile();

        scanner.close();
    }
}
