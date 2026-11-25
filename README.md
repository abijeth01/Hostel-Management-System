# Hostel Management System

A console-based Hostel Management System developed using **C Programming** as an academic mini project.

## About the Project

The Hostel Management System helps manage basic hostel administration activities through a menu-driven command-line interface. It supports student registration, room allocation, fee tracking, room vacancy reports, and student search.

## Features

- **Student Registration:** Register students with their roll number, name, department, and year.
- **Room Allocation:** Allocate an available room to a registered student.
- **Fee Management:** View total fees, paid amounts, and remaining balances; record additional payments.
- **Room Vacancy Report:** View occupied rooms, vacant rooms, and available room numbers.
- **Student Search:** Find student details using a roll number.
- **File Handling:** Load and save student records using a text file.

## Technologies and Concepts

- C programming
- Structures
- Arrays
- Functions
- File handling
- Standard input/output

## Requirements

- A C compiler such as GCC
- Terminal or command prompt

## How to Compile and Run

### macOS / Linux

```bash
gcc hostelManagementSys.c -o hostel
./hostel
```

### Windows (GCC)

```bash
gcc hostelManagementSys.c -o hostel.exe
hostel.exe
```

## Data Storage

The program reads student records from `hostel.txt` when it starts and saves changes to that file. The file is generated locally when the program saves data.

**Note:** `hostel.txt` is excluded from this repository because it contains runtime data. Do not commit real student information.

## Current Scope and Limitations

- The program supports up to 20 student records.
- It manages 20 rooms.
- Each room can be allocated to one student.
- The interface is command-line based.
- Student records are stored in a local text file.

## Possible Future Improvements

- Edit and delete student records.
- Support multiple students per room.
- Add administrator login and authentication.
- Improve input validation and error handling.
- Add a graphical user interface.

## Project Information

- **Project:** Hostel Management System
- **Type:** Academic Mini Project
- **Language:** C
- **Interface:** Command-Line Interface (CLI)

## Author

**Abijeth S J**  
B.Tech Computer Science and Engineering

---

*Developed to apply fundamental C programming concepts to a practical hostel administration problem.*
