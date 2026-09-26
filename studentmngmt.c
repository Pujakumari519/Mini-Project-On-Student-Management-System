#include <stdio.h>

typedef struct Student
{
    int roll;
    char name[50];
    float marksC;
    float marksJava;
    float marksDB;
    float total;
    float average;
    char grade;
} Student;

void calculateResult(Student *s)
{
    s->total = s->marksC + s->marksJava + s->marksDB;
    s->average = s->total / 3;

    if (s->average >= 90)
        s->grade = 'A';
    else if (s->average >= 75)
        s->grade = 'B';
    else if (s->average >= 60)
        s->grade = 'C';
    else if (s->average >= 50)
        s->grade = 'D';
    else
        s->grade = 'F';
}

void addStudent(Student *s)
{
    printf("\nEnter Roll No: ");
    scanf("%d", &s->roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s->name);

    printf("\nEnter marks:\n");

    printf("C      : ");
    scanf("%f", &s->marksC);

    printf("Java   : ");
    scanf("%f", &s->marksJava);

    printf("DB     : ");
    scanf("%f", &s->marksDB);

    calculateResult(s);

    printf("\nStudent added successfully!\n");
}

void displayStudents(Student list[], int count)
{
    if (count == 0)
    {
        printf("\nNo students available!\n");
        return;
    }

    printf("\nRoll No    Name            Total     Average    Grade\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%-10d %-15s %-9.2f %-10.2f %c\n",
               list[i].roll,
               list[i].name,
               list[i].total,
               list[i].average,
               list[i].grade);
    }

    printf("\nAverage >= 90  -> A");
    printf("\nAverage >= 75  -> B");
    printf("\nAverage >= 60  -> C");
    printf("\nAverage >= 50  -> D");
    printf("\nAverage < 50   -> F\n");
}

void searchStudent(Student list[], int count)
{
    int roll;
    int found = 0;

    printf("\nEnter Roll No to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++)
    {
        if (list[i].roll == roll)
        {
            printf("\nStudent Found!\n");
            printf("Roll No : %d\n", list[i].roll);
            printf("Name    : %s\n", list[i].name);
            printf("C       : %.2f\n", list[i].marksC);
            printf("Java    : %.2f\n", list[i].marksJava);
            printf("DB      : %.2f\n", list[i].marksDB);
            printf("Total   : %.2f\n", list[i].total);
            printf("Average : %.2f\n", list[i].average);
            printf("Grade   : %c\n", list[i].grade);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent not found!\n");
    }
}

int main()
{
    Student list[50];
    int currentIndex = 0;
    int option;

    do
    {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                if (currentIndex < 50)
                {
                    addStudent(&list[currentIndex]);
                    currentIndex++;
                }
                else
                {
                    printf("\nStudent limit reached!\n");
                }
                break;

            case 2:
                displayStudents(list, currentIndex);
                break;

            case 3:
                searchStudent(list, currentIndex);
                break;

            case 4:
                printf("\nThank you! Program exited.\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (option != 4);

    return 0;
}
