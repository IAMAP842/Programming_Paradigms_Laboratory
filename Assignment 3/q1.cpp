#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Student
{
private:
    const int MAX_STUDENTS = 100;
    static int count;
    string name;
    int age;
    string department;
    int year;

public:
    Student() : name(""), age(0), department(""), year(0) {}
    Student(const string &n, int a, const string &d, int y) : name(n), age(a), department(d), year(y)
    {
        count++;
    }
    Student(const Student &other) : name(other.name), age(other.age), department(other.department), year(other.year) {}
    void ReadStudentData()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter department: ";
        cin >> department;
        cout << "Enter year: ";
        cin >> year;
    }
    void PrintStudentData() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Department: " << department << endl;
        cout << "Year: " << year << endl;
    }
    static int GetCount()
    {
        return count;
    }
    Student<T> &operator=(const Student<T> &other)
    {
        if (this == &other)
            return *this;
        name = other.name;
        age = other.age;
        department = other.department;
        year = other.year;
        return *this;
    }
    static void ResetCount()
    {
        count = 0;
    }
};
template <typename T>
int Student<T>::count = 0;
int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    Student<int> students[n];
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter details for student " << i + 1 << ":" << endl;
        students[i].ReadStudentData();
    }
    cout << "\nStudent Details:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "Student " << i + 1 << ":\n";
        students[i].PrintStudentData();
        cout << endl;
    }
    return 0;
}