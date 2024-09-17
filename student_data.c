#include <stdio.h>
#include <string.h>

// Declare the structure for date of birth
struct dob
{
    int day;
    int month;
    int year;
};

// Declare the main structure for student
struct student
{
    char name[30];
    struct dob d; // Format for date of birth in date struct
    int roll_no;
    float m1, m2, m3; // Marks for three subjects
};

int main()
{
    int n, i;

    // Ask the user for the number of student record
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Declare an array of structure to store multiple students
    struct student s[n];

    // Loop to input student details
    for (i = 0; i < n; i++)
    {
        printf("\nEnter detail for student %d:\n", i + 1);

        printf("Enter name: ");
        scanf(" %[^\n]s", s[i].name);

        printf("Enter date of birth (dd mm yyyy): ");
        scanf("%d %d %d", &s[i].d.day, &s[i].d.month, &s[i].d.year);

        printf("Enter roll number: ");
        scanf("%d", &s[i].roll_no);

        printf("Enter marks for three subjects: ");
        scanf("%f %f %f", &s[i].m1, &s[i].m2, &s[i].m3);
    }

    // Display the details of all students
    printf("\nStudent Information:\n");
    for (i = 0; i < n; i++)
    {
        i != 0 ? printf("\n\nDetail for student %d: ", i + 1) : printf("\nDetails for student %d: ", i + 1);
        printf("\nName: %s", s[i].name);
        printf("\nDate of Birth: %02d/%02d/%d", s[i].d.day, s[i].d.month, s[i].d.year);
        printf("\nRoll No: %d", s[i].roll_no);
        printf("\nMarks: %.2f, %.2f, %.2f", s[i].m1, s[i].m2, s[i].m3);
    }

    // Write all the details to the text file
    FILE *file = fopen("student_data.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "Student Information:\n");
    for (i = 0; i < n; i++)
    {
        i != 0 ? fprintf(file, "\n\nDetail for student %d: ", i + 1) : fprintf(file, "\nDetails for student %d: ", i + 1);
        fprintf(file, "\nName: %s", s[i].name);
        fprintf(file, "\nDate of Birth: %02d/%02d/%d", s[i].d.day, s[i].d.month, s[i].d.year);
        fprintf(file, "\nRoll No: %d", s[i].roll_no);
        fprintf(file, "\nMarks: %.2f, %.2f, %.2f", s[i].m1, s[i].m2, s[i].m3);
    }

    // Close the file
    fclose(file);
    printf("\n\nStudent data written to 'student_data.txt' successfully!\n");

    return 0;
}