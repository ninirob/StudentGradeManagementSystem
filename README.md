# N Roberts
# Student Grade Management System

## Description
A basic Student Grade Management System built in C. This program allows users to perform operations like:
- adding, editing, searching, and deleting student records. 
The project demonstrates essential C programming concepts, including file handling and modular programming.

## Features
- Add student records (ID, name, grades, etc.)
- Search for a specific student
- Edit student records
- Delete student records
- Save and load student data from a file

## File Structure
- `student.c`: Contains the main program logic.
- `CMakeLists.txt`: Configuration file for building the project using CMake.
- `README.md`: Project documentation.

## Installation and Usage
1. Clone the repository:
   ```bash
   git clone https://github.com/nilrob/StudentGradeManagementSystem.git
   
2. Navigate to the project directory:
   ```bash
   cd StudentGradeManagementSystem

3. Open the project in CLion or another C IDE that supports CMake.
  
Clean Up Files for GitHub**
If you're using GitHub, **do not upload the `cmake-build-debug` folder**, as it's a build artifact. Add a `.gitignore` file to exclude unnecessary files:

Create a file named `.gitignore` in your project folder and add:
cmake-build-debug/
*.o
*.exe
*.out

4. Build the project:
•	For CLion: Use the “Build” button.
•	For terminal: Run
   ```bash
   cmake .
   make

### **4. Add Files to GitHub**
- Open a terminal in your project folder.
- Run these commands to initialize a Git repository, add your files, and push to GitHub:
   ```bash
   git init
   git add .
   git commit -m "Initial commit of Student Grade Management System"
   git branch -M main
   git remote add origin https://github.com/nilrob/StudentGradeManagementSystem.git
   git push -u origin main

5.	Run the executable:
      ```bash 
      ./StudentGradeManagementSystem
   
## Example Usage

Here’s an example of how the program runs:

- Adding a Student

Input:
Enter student ID: 001
Enter student name: Alice Johnson
Enter GPA: 3.9

Output:
Student record added successfully!

- Searching for a Student

Input: Enter student ID to search: 001

Output: 
Student Found:
ID: 001
Name: Alice Johnson
GPA: 3.9
