#include <stdio.h>

struct Student {
    int id;
    char name[50];
    float cgpa;
};

int main() {
    struct Student s[100];
    int n = 0;
    int choice, i, searchId;
    
    while (1) {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("\nEnter Student ID: ");
            scanf("%d", &s[n].id);

            printf("Enter Student Name: ");
            scanf(" %[^\n]", s[n].name);

            printf("Enter CGPA: ");
            scanf("%f", &s[n].cgpa);

            n++;
            printf("Student Added Successfully!\n");
            break;

        case 2:
            if (n == 0) {
                printf("No Student Found!\n");
            } else {
                printf("\n--- Student List ---\n");
                for (i = 0; i < n; i++) {
                    printf("\nStudent %d\n", i + 1);
                    printf("ID   : %d\n", s[i].id);
                    printf("Name : %s\n", s[i].name);
                    printf("CGPA : %.2f\n", s[i].cgpa);
                }
            }
            break;

        case 3:
            printf("Enter Student ID to Search: ");
            scanf("%d", &searchId);

            int found = 0;

            for (i = 0; i < n; i++) {
                if (s[i].id == searchId) {
                    printf("\nStudent Found!\n");
                    printf("ID   : %d\n", s[i].id);
                    printf("Name : %s\n", s[i].name);
                    printf("CGPA : %.2f\n", s[i].cgpa);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Student Not Found!\n");
            }
            break;

        case 4:
            printf("Program Closed.\n");
            return 0;

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}