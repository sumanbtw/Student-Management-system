#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
    float gpa;
};

const string FILE_NAME = "students.dat";

void saveToFile(const vector<Student>& students) {
    ofstream file(FILE_NAME);
    for (const auto& s : students)
        file << s.id << "\n" << s.name << "\n" << s.age << "\n" << s.gpa << "\n";
}

vector<Student> loadFromFile() {
    vector<Student> students;
    ifstream file(FILE_NAME);
    Student s;
    while (file >> s.id) {
        file.ignore();
        getline(file, s.name);
        file >> s.age >> s.gpa;
        file.ignore();
        students.push_back(s);
    }
    return students;
}

void displayAll(const vector<Student>& students) {
    if (students.empty()) { cout << "No students found.\n"; return; }
    cout << left << setw(6) << "ID" << setw(20) << "Name" << setw(6) << "Age" << "GPA\n";
    cout << string(38, '-') << "\n";
    for (const auto& s : students)
        cout << left << setw(6) << s.id << setw(20) << s.name << setw(6) << s.age << s.gpa << "\n";
}

void addStudent(vector<Student>& students) {
    Student s;
    cout << "Enter ID: "; cin >> s.id;
    auto it = find_if(students.begin(), students.end(), [&](const Student& x){ return x.id == s.id; });
    if (it != students.end()) { cout << "ID already exists.\n"; return; }
    cin.ignore();
    cout << "Enter Name: "; getline(cin, s.name);
    cout << "Enter Age: "; cin >> s.age;
    cout << "Enter GPA: "; cin >> s.gpa;
    students.push_back(s);
    saveToFile(students);
    cout << "Student added successfully.\n";
}

void searchStudent(const vector<Student>& students) {
    int id; cout << "Enter ID to search: "; cin >> id;
    auto it = find_if(students.begin(), students.end(), [&](const Student& x){ return x.id == id; });
    if (it == students.end()) { cout << "Student not found.\n"; return; }
    cout << "ID: " << it->id << " | Name: " << it->name << " | Age: " << it->age << " | GPA: " << it->gpa << "\n";
}

void updateStudent(vector<Student>& students) {
    int id; cout << "Enter ID to update: "; cin >> id;
    auto it = find_if(students.begin(), students.end(), [&](const Student& x){ return x.id == id; });
    if (it == students.end()) { cout << "Student not found.\n"; return; }
    cin.ignore();
    cout << "Enter new Name: "; getline(cin, it->name);
    cout << "Enter new Age: "; cin >> it->age;
    cout << "Enter new GPA: "; cin >> it->gpa;
    saveToFile(students);
    cout << "Student updated successfully.\n";
}

void deleteStudent(vector<Student>& students) {
    int id; cout << "Enter ID to delete: "; cin >> id;
    auto it = find_if(students.begin(), students.end(), [&](const Student& x){ return x.id == id; });
    if (it == students.end()) { cout << "Student not found.\n"; return; }
    students.erase(it);
    saveToFile(students);
    cout << "Student deleted successfully.\n";
}

int main() {
    vector<Student> students = loadFromFile();
    int choice;
    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n2. Display All\n3. Search Student\n4. Update Student\n5. Delete Student\n0. Exit\n";
        cout << "Enter choice: "; cin >> choice;
        switch (choice) {
            case 1: addStudent(students); break;
            case 2: displayAll(students); break;
            case 3: searchStudent(students); break;
            case 4: updateStudent(students); break;
            case 5: deleteStudent(students); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}
