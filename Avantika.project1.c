#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct definition for user credentials and student details
struct User
{
    char username[30];
    char password[10];
};

struct Student
{
    char StudentName[50];
    int marks;
    int rollNo;
};

void studentdetail(struct Student *data, int number)
{
    for (int i = 0; i < number; i++)
    {
        char username[50];
        printf("Enter student name of %d student:\n", i + 1);
        scanf(" %[^\n]", username);

        printf("Enter marks of %d student:\n", i + 1);
        scanf("%d", &data[i].marks);

        printf("Enter Rollno of %d student:\n", i + 1);
        scanf("%d", &data[i].rollNo);

        strcpy(data[i].StudentName, username);
    }
}

void showData(struct Student *data, int number)
{
    for (int i = 0; i < number; i++)
    {
        printf("Student name:%s\n", data[i].StudentName);
        printf("Marks:%d\n", data[i].marks);
        printf("Rollno:%d\n", data[i].rollNo);
    }
}

void signUpFun(struct User *signup)
{
    printf("Enter user name for Signup:\n");
    scanf("%s", signup->username);
    printf("Enter password for Signup:\n");
    scanf("%s", signup->password);
}

int login(struct User *log)
{
    char userName[30];
    char pass[10];
    printf("Enter user name for login:\n");
    scanf("%s", userName);
    printf("Enter password for login:\n");
    scanf("%s", pass);
    if (strcmp(userName, log->username) == 0 && strcmp(pass, log->password) == 0)
    {
        printf("Login successful\n");
        return 1; // Return 1 for successful login
    }
    else
    {
        printf("Invalid details\n");
        return 0; // Return 0 for failed login
    }
}

int main()
{
    int choice;
    struct User user;
    struct Student *studentData = NULL;
    int number = 0;
    int loggedIn = 0;

    do
    {
        printf("\n1.Sign up\n2.Login\n3.Exit\nEnter choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            signUpFun(&user);
            break;
        case 2:
            if (login(&user))
            {
                loggedIn = 1;
                printf("Login successful!\n");
                printf("Enter how many data you want to store:\n");
                scanf("%d", &number);
                studentData = (struct Student *)malloc(number * sizeof(struct Student));
                // if (studentData == NULL)
                // {
                //     printf("Memory allocation failed!\n");
                //     return -1;
                // }
                studentdetail(studentData, number);
            }
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Please enter again.\n");
            break;
        }
        if (loggedIn && choice == 2)
        {
            printf("\n1. Add data\n2. Show data\n3. Logout\nEnter choice:\n");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                studentdetail(studentData, number);
                break;

            case 2:
                showData(studentData, number);
                break;

            case 3:
                loggedIn = 0;
                free(studentData);  // Free allocated memory
                studentData = NULL; // Reset pointer to NULL
                printf("Logged out successfully.\n");
                break;

            default:
                printf("Invalid choice. Please enter again.\n");
                break;
            }
        }

    } while (choice != 3);


}
