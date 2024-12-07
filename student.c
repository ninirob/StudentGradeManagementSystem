#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5 // Max number of students we want to handle

// Define a structure to hold student information
struct Student {
    int id;               // Student ID
    char name[50];        // Student name
    float grade;          // Student grade
};

// Function to display a student's details
void displayStudent(struct Student s) {
    printf("ID: %d, Name: %s, Grade: %.2f\n", s.id, s.name, s.grade);
}

// Function to input student details
void inputStudent(struct Student *s) {
    printf("Enter Student ID: ");
    scanf("%d", &s->id);  // Get student ID

    printf("Enter Student Name: ");
    getchar();  // To consume the newline character left by previous input
    fgets(s->name, sizeof(s->name), stdin);  // Get student name (with spaces)
    s->name[strcspn(s->name, "\n")] = 0;  // Remove newline character from the name string

    printf("Enter Student Grade: ");
    scanf("%f", &s->grade);  // Get student grade
}

// Function to sort the students by grade (Bubble Sort)
void sortStudentsByGrade(struct Student students[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].grade < students[j + 1].grade) {
                // Swap students[j] and students[j + 1] if they are in the wrong order
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Function to search for a student by ID
void searchStudentByID(struct Student students[], int n, int id) {
    int found = 0;  // Flag to track if student is found
    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            displayStudent(students[i]);  // If ID matches, display student details
            found = 1;  // Set flag to indicate the student was found
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);  // If student is not found
    }
}

// Function to edit a student's details by ID
void editStudentByID(struct Student students[], int n, int id) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            found = 1;
            printf("Editing Student: %d\n", id);
            // Modify the student's details
            printf("Enter new Name: ");
            getchar();  // Clear newline character
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = 0;  // Remove newline

            printf("Enter new Grade: ");
            scanf("%f", &students[i].grade);
            printf("Student details updated.\n");
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

// Function to delete a student by ID
void deleteStudentByID(struct Student students[], int *n, int id) {
    int found = 0;
    for (int i = 0; i < *n; i++) {
        if (students[i].id == id) {
            found = 1;
            // Shift all students after the deleted one one position left
            for (int j = i; j < *n - 1; j++) {
                students[j] = students[j + 1];
            }
            (*n)--;  // Decrease the total number of students
            printf("Student with ID %d deleted.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

int main() {
    struct Student students[MAX_STUDENTS]; // Array to hold multiple students
    int numberOfStudents = 0;  // Variable to track how many students have been entered

    // Input students
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("\nEnter details for Student #%d\n", i + 1);
        inputStudent(&students[i]);  // Input student details
        numberOfStudents++;  // Increase the count of students entered
    }

    // Sort the students by grade
    sortStudentsByGrade(students, numberOfStudents);

    // Display sorted students
    printf("\n--- Sorted Student Details by Grade (Highest to Lowest) ---\n");
    for (int i = 0; i < numberOfStudents; i++) {
        displayStudent(students[i]);  // Display each student's details
    }

    // Menu for actions (search, edit, delete)
    int choice;
    int id;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Search for Student\n");
        printf("2. Edit Student\n");
        printf("3. Delete Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Search for a student by ID
                printf("\nEnter Student ID to search for: ");
                scanf("%d", &id);
                searchStudentByID(students, numberOfStudents, id);
                break;
            case 2:
                // Edit a student's details by ID
                printf("\nEnter Student ID to edit: ");
                scanf("%d", &id);
                editStudentByID(students, numberOfStudents, id);
                break;
            case 3:
                // Delete a student by ID
                printf("\nEnter Student ID to delete: ");
                scanf("%d", &id);
                deleteStudentByID(students, &numberOfStudents, id);
                break;
            case 4:
                // Exit the program
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}