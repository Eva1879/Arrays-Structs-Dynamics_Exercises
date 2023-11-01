#include <stdio.h>
#include <string.h>

// Define symbolic constants
#define numOfSubjects 5
#define numOfStudents 100

// Define the Student struct
struct Student {
    char FirstName[50];
    char LastName[50];
    int StudentID;
    float SubjectMarks[numOfSubjects];
    int AggregateMarks;
    char Grade[20];
};

// Function to enroll a student
void enroll(struct Student students[], int index) {
    printf("Enter Student ID: ");
    scanf("%d", &students[index].StudentID);
    
    printf("Enter First Name: ");
    scanf("%s", students[index].FirstName);
    
    printf("Enter Last Name: ");
    scanf("%s", students[index].LastName);
    
    for (int i = 0; i < numOfSubjects; i++) {
        printf("Enter marks for Subject %d: ", i);
        scanf("%f", &students[index].SubjectMarks[i]);
    }

    // Calculate AggregateMarks
    students[index].AggregateMarks = 0;
    for (int i = 0; i < numOfSubjects; i++) {
        students[index].AggregateMarks += students[index].SubjectMarks[i];
    }

    // Calculate Grade based on AggregateMarks
    if (students[index].AggregateMarks >= 85) {
        strcpy(students[index].Grade, "HD");
    } else if (students[index].AggregateMarks >= 75) {
        strcpy(students[index].Grade, "D");
    } else if (students[index].AggregateMarks >= 65) {
        strcpy(students[index].Grade, "C");
    } else if (students[index].AggregateMarks >= 50) {
        strcpy(students[index].Grade, "P");
    } else {
        strcpy(students[index].Grade, "F");
    }
}

// Function to search and update a student
void searchUpdate(struct Student students[], int studentCount) {
    int choice;
    printf("Search by Student ID (1) or Last Name (2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Search by Student ID
        int studentID;
        printf("Enter Student ID: ");
        scanf("%d", &studentID);
        for (int i = 0; i < studentCount; i++) {
            if (students[i].StudentID == studentID) {
                // Print student details
                printf("Found Student:\n");
                printf("First Name: %s\n", students[i].FirstName);
                printf("Last Name: %s\n", students[i].LastName);
                printf("Student ID: %d\n", students[i].StudentID);
                printf("Aggregate Marks: %d\n", students[i].AggregateMarks);
                printf("Grade: %s\n", students[i].Grade);

                // Update student details
                char updateChoice;
                printf("Do you want to update student details (y/n)? ");
                scanf(" %c", &updateChoice);
                if (updateChoice == 'y') {
                    // Update attributes as needed
                    printf("Update First Name: ");
                    scanf("%s", students[i].FirstName);
                    // Update other attributes...
                }
                return; // Found and updated
            }
        }
        printf("Student not found.\n");
    } else if (choice == 2) {
        // Search by Last Name (case insensitive)
        char lastName[50];
        printf("Enter Last Name: ");
        scanf("%s", lastName);
        for (int i = 0; i < studentCount; i++) {
            if (strcasecmp(students[i].LastName, lastName) == 0) {
                // Print and update student details (similar to above)
                // ...
                return; // Found and updated
            }
        }
        printf("Student not found.\n");
    } else {
        printf("Invalid choice.\n");
    }
}

// Function to print top students
void topStudents(struct Student students[], int studentCount) {
    int highestMarks = 0;
    printf("Top Students:\n");
    for (int i = 0; i < studentCount; i++) {
        if (students[i].AggregateMarks > highestMarks) {
            highestMarks = students[i].AggregateMarks;
        }
    }

    for (int i = 0; i < studentCount; i++) {
        if (students[i].AggregateMarks == highestMarks) {
            // Print student details
            printf("First Name: %s\n", students[i].FirstName);
            printf("Last Name: %s\n", students[i].LastName);
            printf("Student ID: %d\n", students[i].StudentID);
            printf("Aggregate Marks: %d\n", students[i].AggregateMarks);
            printf("Grade: %s\n", students[i].Grade);
        }
    }
}

int main() {
    struct Student students[numOfStudents];
    int studentCount = 0;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Enroll\n");
        printf("2. Search and Update\n");
        printf("3. Top Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (studentCount < numOfStudents) {
                    enroll(students, studentCount);
                    studentCount++;
                } else {
                    printf("Maximum number of students reached.\n");
                }
                break;

            case 2:
                searchUpdate(students, studentCount);
                break;

            case 3:
                topStudents(students, studentCount);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}