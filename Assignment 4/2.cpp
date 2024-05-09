#include <bits/stdc++.h>
using namespace std;

class Person {
protected:
    string name;
    int age;
    char gender;

public:
    Person(string n, int a, char g) : name(n), age(a), gender(g) {}

    virtual void displayProfile() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

class Student : public Person {
private:
    string dept;
    int year;

public:
    Student(string n, int a, char g, string d, int y) : Person(n, a, g), dept(d), year(y) {}

    void displayProfile() const override {
        cout << "Student Details:" << endl;
        Person::displayProfile();
        cout << "Department: " << dept << endl;
        cout << "Year: " << year << endl;
    }
};

class Clerk : public Person {
private:
    int workload;
    double salary;

public:
    Clerk(string n, int a, char g, int w, double s) : Person(n, a, g), workload(w), salary(s) {}

    void displayProfile() const override {
        cout << "Clerk Details:" << endl;
        Person::displayProfile();
        cout << "Workload: " << workload << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Professor : public Person {
private:
    string dept;
    int courseLoad;
    double salary;

public:
    Professor(string n, int a, char g, string d, int c, double s) : Person(n, a, g), dept(d), courseLoad(c), salary(s) {}

    void displayProfile() const override {
        cout << "Professor Details:" << endl;
        Person::displayProfile();
        cout << "Department: " << dept << endl;
        cout << "Course Load: " << courseLoad << " courses" << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    Student student("Aritra Pal", 20, 'M', "Computer Science and Technology", 2);
    Clerk clerk("Emilia", 35, 'F', 40, 45000);
    Professor professor("Dr. Brown", 45, 'M', "Physics", 3, 80000);

    student.displayProfile();
    cout << endl;
    clerk.displayProfile();
    cout << endl;
    professor.displayProfile();

    return 0;
}
