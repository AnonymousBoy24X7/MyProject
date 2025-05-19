//Student Management System
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

#define Size 10

class Student {
public:
    string Name, Course;
    int Age, Rollno;

    void Getdata(string name, string course, int rollno, int age) {
        Name = name;
        Course = course;
        Rollno = rollno;
        Age = age;
    }

    void Displaydata() {
        cout << "\n-----------------------------";
        cout << "\nStudent Name   : " << Name;
        cout << "\nAge            : " << Age;
        cout << "\nRoll Number    : " << Rollno;
        cout << "\nCourse         : " << Course;
        cout << "\n-----------------------------";
    }

    int getRollNo() {
        return Rollno;
    }
};

Student arr[Size];
int a, r, currentSize = 0;
string n, c;

void AddStudent() {
    int num;
    cout << "\n=== Add Students ===";
    cout << "\nEnter Number Of Students To Add: ";
    cin >> num;
    cin.ignore();

    if (currentSize + num > Size) {
        cout << "\nCannot Add More Than " << Size << " Students In Total.\n";
        return;
    }

    for (int i = 0; i < num; i++) {
        cout << "\n--- Enter Details For Student " << currentSize + 1 << " ---";
        cout << "\nName        : ";
        getline(cin, n);
        cout << "Course      : ";
        getline(cin, c);
        cout << "Age         : ";
        cin >> a;
        cout << "Roll Number : ";
        cin >> r;
        cin.ignore();

        arr[currentSize].Getdata(n, c, r, a);
        currentSize++;
        cout << "Student Added Successfully.\n";
    }
}

void ViewStudent() {
    cout << "\n=== View All Students ===";
    if (currentSize == 0) {
        cout << "\nNo Student Records To Display.\n";
        return;
    }

    for (int i = 0; i < currentSize; i++) {
        arr[i].Displaydata();
    }
}

void DeleteStudent() {
    cout << "\n=== Delete Student ===";
    cout << "\nEnter Roll Number Of Student To Delete: ";
    cin >> r;

    bool found = false;

    for (int i = 0; i < currentSize; i++) {
        if (arr[i].getRollNo() == r) {
            for (int j = i; j < currentSize - 1; j++) {
                arr[j] = arr[j + 1];
            }
            currentSize--;
            found = true;
            cout << "Student Record Deleted Successfully.\n";
            break;
        }
    }

    if (!found) {
        cout << "No Student Found With Roll Number " << r << ".\n";
    }
}

void SearchStudent() {
    cout << "\n=== Search Student ===";
    cout << "\nEnter Roll Number To Search: ";
    cin >> r;

    bool found = false;
    int index = -1;

    for (int i = 0; i < currentSize; i++) {
        if (arr[i].getRollNo() == r) {
            found = true;
            index = i;
            break;
        }
    }

    if (!found) {
        cout << "No Student Found With Roll Number " << r << ".\n";
    } else {
        cout << "Student Found At Index " << index << ".\n";
        arr[index].Displaydata();
    }
}

void UpdateStudent() {
    cout << "\n=== Update Student Details ===";
    cout << "\nEnter Roll Number Of Student To Update: ";
    cin >> r;
    cin.ignore();

    bool found = false;

    for (int i = 0; i < currentSize; i++) {
        if (arr[i].getRollNo() == r) {
            found = true;
            cout << "\n--- Enter New Details For The Student ---";
            cout << "\nName        : ";
            getline(cin, n);
            cout << "Course      : ";
            getline(cin, c);
            cout << "Age         : ";
            cin >> a;
            cout << "Roll Number : ";
            cin >> r;
            cin.ignore();

            arr[i].Getdata(n, c, r, a);
            cout << "Student Record Updated Successfully.\n";
            break;
        }
    }

    if (!found) {
        cout << "No Student Found With The Provided Roll Number.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n========== Student Management Menu ==========";
        cout << "\n1) Add Student";
        cout << "\n2) Delete Student";
        cout << "\n3) Search Student";
        cout << "\n4) View All Students";
        cout << "\n5) Update Student";
        cout << "\n6) Exit";
        cout << "\n=============================================";
        cout << "\nEnter Your Choice (1-6): ";
        cin >> choice;

        switch (choice) {
        case 1:
            AddStudent();
            break;
        case 2:
            DeleteStudent();
            break;
        case 3:
            SearchStudent();
            break;
        case 4:
            ViewStudent();
            break;
        case 5:
            UpdateStudent();
            break;
        case 6:
            cout << "\nThank You For Using The Student Management System. Goodbye!\n";
            break;
        default:
            cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while (choice != 6);

    return 0;
}
