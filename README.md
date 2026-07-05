# 🎓 Student Management System

A simple console-based **Student Management System** built in **C++** that allows you to manage student records with full CRUD operations and file-based data persistence.

---

## 📋 Features

- ➕ **Add Student** — Register a new student with ID, Name, Age, and GPA
- 📄 **Display All Students** — View all student records in a formatted table
- 🔍 **Search Student** — Find a student by their unique ID
- ✏️ **Update Student** — Modify an existing student's details
- 🗑️ **Delete Student** — Remove a student record by ID
- 💾 **File Persistence** — All data is automatically saved to `students.dat`

---

## 🛠️ Tech Stack

- **Language:** C++ (C++11 or later)
- **Libraries:** `iostream`, `fstream`, `vector`, `string`, `iomanip`, `algorithm`
- **Storage:** Plain text file (`students.dat`)

---

## 🚀 Getting Started

### Prerequisites

- A C++ compiler: `g++` (GCC), `clang++`, or MSVC

### Clone the Repository

```bash
git clone https://github.com/<your-username>/student-management-system.git
cd student-management-system
```

### Compile

**Using g++ (Linux/macOS/Windows):**
```bash
g++ student_management.cpp -o student_management
```

**Using MSVC (Windows):**
```bash
cl student_management.cpp
```

### Run

```bash
# Linux/macOS
./student_management

# Windows
student_management.exe
```

---

## 📌 Usage

Once the program starts, you'll see the main menu:

```
===== Student Management System =====
1. Add Student
2. Display All
3. Search Student
4. Update Student
5. Delete Student
0. Exit
Enter choice:
```

### Example — Adding a Student

```
Enter ID: 101
Enter Name: John Doe
Enter Age: 20
Enter GPA: 3.85
Student added successfully.
```

### Example — Display All Students

```
ID    Name                Age   GPA
--------------------------------------
101   John Doe            20    3.85
102   Jane Smith          21    3.92
```

---

## 📁 Project Structure

```
student-management-system/
├── student_management.cpp   # Main source file
├── students.dat             # Auto-generated data file (after first run)
└── README.md                # Project documentation
```

---

## 🔧 Student Record Fields

| Field | Type   | Description              |
|-------|--------|--------------------------|
| ID    | int    | Unique student identifier |
| Name  | string | Full name of the student  |
| Age   | int    | Age of the student        |
| GPA   | float  | Grade Point Average       |

---

## ⚠️ Notes

- Student **IDs must be unique**. Duplicate IDs are rejected.
- The `students.dat` file is created automatically on first use.
- Do **not** manually edit `students.dat` to avoid data corruption.

---


## 📄 License

This project is open source and available under the [MIT License](LICENSE).

---

## 🙋‍♂️ Author

Made with ❤️ using C++  
Feel free to fork, star ⭐, and contribute!
