#include <stdio.h>
#include <string.h>

#define MAX 20
#define ROOMS 20

// Structure to store student details
typedef struct
{
    int roll;
    char name[50];
    char department[30];
    int year;
    int room;
    float fee;
    float paid;
} Student;

Student s[MAX];
int count = 0;

// Function declarations
void loadData();
void saveData();
void registerStudent();
void allocateRoom();
void feeDetails();
void vacancyReport();
void searchStudent();
int findStudent(int roll);
int roomOccupied(int room);

// Main function
int main()
{
    int choice;

    loadData();

    do
    {
        printf("\n===== HOSTEL MANAGEMENT SYSTEM =====\n");
        printf("1. Student Registration\n");
        printf("2. Room Allocation\n");
        printf("3. Fee Details\n");
        printf("4. Room Vacancy Report\n");
        printf("5. Student Search\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            registerStudent();
            break;

        case 2:
            allocateRoom();
            break;

        case 3:
            feeDetails();
            break;

        case 4:
            vacancyReport();
            break;

        case 5:
            searchStudent();
            break;

        case 6:
            saveData();
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}

// Load records from file
void loadData()
{
    FILE *fp = fopen("hostel.txt", "r");

    if (fp == NULL)
        return;

    while ((count < MAX) &&
           (fscanf(fp, "%d\n%49[^\n]\n%29[^\n]\n%d\n%d\n%f\n%f\n",
                   &s[count].roll,
                   s[count].name,
                   s[count].department,
                   &s[count].year,
                   &s[count].room,
                   &s[count].fee,
                   &s[count].paid) == 7))
    {
        count++;
    }

    fclose(fp);
}

// Save records to file
void saveData()
{
    FILE *fp = fopen("hostel.txt", "w");

    if (fp == NULL)
    {
        printf("Error saving data!\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%d\n%s\n%s\n%d\n%d\n%.2f\n%.2f\n",
                s[i].roll,
                s[i].name,
                s[i].department,
                s[i].year,
                s[i].room,
                s[i].fee,
                s[i].paid);
    }

    fclose(fp);
}

// Find student using roll number
int findStudent(int roll)
{
    for (int i = 0; i < count; i++)
    {
        if (s[i].roll == roll)
            return i;
    }

    return -1;
}

// Check whether room is occupied
int roomOccupied(int room)
{
    for (int i = 0; i < count; i++)
    {
        if (s[i].room == room)
            return 1;
    }

    return 0;
}

// 1. Student Registration
void registerStudent()
{
    int roll;

    if (count >= MAX)
    {
        printf("Registration limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");

    scanf("%d", &roll);

    if (findStudent(roll) != -1)
    {
        printf("Roll number already exists!\n");
        return;
    }

    s[count].roll = roll;

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", s[count].name);

    printf("Enter Department: ");
    scanf(" %29[^\n]", s[count].department);

    printf("Enter Year (1-4): ");

    scanf("%d", &s[count].year);

    s[count].room = 0;
    s[count].fee = 30000;
    s[count].paid = 0;

    count++;

    saveData();

    printf("Student registered successfully!\n");
}

// 2. Room Allocation
void allocateRoom()
{
    int roll, room, index;

    printf("\nEnter Roll Number: ");

    scanf("%d", &roll);

    index = findStudent(roll);

    if (index == -1)
    {
        printf("Student not found!\n");
        return;
    }

    if (s[index].room != 0)
    {
        printf("Student already has Room %d\n",
               s[index].room);
        return;
    }

    printf("Enter Room Number (1-%d): ", ROOMS);

    scanf("%d", &room);

    if (room < 1 || room > ROOMS)
    {
        printf("Invalid room number!\n");
        return;
    }

    if (roomOccupied(room))
    {
        printf("Room already occupied!\n");
        return;
    }

    s[index].room = room;

    saveData();

    printf("Room allocated successfully!\n");
}

// 3. Fee Details
void feeDetails()
{
    int roll, index;
    float amount;

    printf("\nEnter Roll Number: ");

    scanf("%d", &roll);

    index = findStudent(roll);

    if (index == -1)
    {
        printf("Student not found!\n");
        return;
    }

    printf("\nStudent Name: %s\n", s[index].name);
    printf("Total Fee: %.2f\n", s[index].fee);
    printf("Paid Amount: %.2f\n", s[index].paid);
    printf("Balance Amount: %.2f\n", s[index].fee - s[index].paid);

    printf("\nEnter Additional Fee Payment: ");

    scanf("%f", &amount);

    if (amount < 0 || s[index].paid + amount > s[index].fee)
    {
        printf("Invalid payment amount!\n");
        return;
    }

    s[index].paid += amount;

    saveData();

    printf("Payment updated successfully!\n");
    printf("Remaining Balance: %.2f\n",
           s[index].fee - s[index].paid);
}

// 4. Room Vacancy Report
void vacancyReport()
{
    int occupied = 0;

    printf("\n===== ROOM VACANCY REPORT =====\n");

    for (int i = 0; i < count; i++)
    {
        if (s[i].room != 0)
            occupied++;
    }

    printf("Total Rooms: %d\n", ROOMS);
    printf("Occupied Rooms: %d\n", occupied);
    printf("Vacant Rooms: %d\n", ROOMS - occupied);

    printf("\nVacant Room Numbers:\n");

    for (int room = 1; room <= ROOMS; room++)
    {
        if (!roomOccupied(room))
            printf("%d ", room);
    }

    printf("\n");
}

// 5. Student Search
void searchStudent()
{
    int roll, index;

    printf("\nEnter Roll Number to Search: ");

    scanf("%d", &roll);

    index = findStudent(roll);

    if (index == -1)
    {
        printf("Student not found!\n");
        return;
    }

    printf("\n===== STUDENT DETAILS =====\n");
    printf("Roll Number: %d\n", s[index].roll);
    printf("Name: %s\n", s[index].name);
    printf("Department: %s\n", s[index].department);
    printf("Year: %d\n", s[index].year);

    printf("Room Number: ");

    if (s[index].room == 0)
        printf("Not Allocated\n");
    else
        printf("%d\n", s[index].room);

    printf("Total Fee: %.2f\n", s[index].fee);
    printf("Paid Fee: %.2f\n", s[index].paid);
    printf("Balance Fee: %.2f\n",
           s[index].fee - s[index].paid);
}
