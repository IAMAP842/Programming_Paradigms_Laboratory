#include <bits/stdc++.h>
using namespace std;
struct Student
{
    string name;
    int age;
    string department;
    int year;
};

void ReadStudentData(Student &student)
{
    cout << "Enter student name: ";
    getline(cin >> ws, student.name);
    cout << "Enter student age: ";
    cin >> student.age;
    cout << "Enter student department: ";
    getline(cin >> ws, student.department);
    cout << "Enter student year: ";
    cin >> student.year;
}

void PrintStudentData(const Student &student)
{
    cout << "Name: " << student.name << ", Age: " << student.age << ", Department: " << student.department << ", Year: " << student.year << endl;
}

int main()
{
    cout << "enter no of students N" << endl;
    int N;
    cin >> N;

    Student students[N];

    for (int i = 0; i < N; ++i)
    {
        cout << "Enter details for student " << i + 1 << ":\n";
        ReadStudentData(students[i]);
    }

    cout << "\nStudent Information:\n";
    for (const auto &student : students)
    {
        PrintStudentData(student);
    }
}