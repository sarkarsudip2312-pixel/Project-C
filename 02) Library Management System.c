#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[100];
    int issued; // 0 = Available, 1 = Issued
};

struct Book books[MAX_BOOKS];
int count = 0;

/* Function Prototypes */
void loadBooks();
void saveBooks();
void addBook();
void viewBooks();
void searchBook();
void issueBook();
void returnBook();

int main() {
    int choice;

    loadBooks();

    while (1) {
        printf("\n=================================\n");
        printf("     LIBRARY MANAGEMENT SYSTEM\n");
        printf("=================================\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Save Books\n");
        printf("7. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                viewBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                saveBooks();
                break;

            case 7:
                saveBooks();
                printf("\nData Saved Successfully.\n");
                printf("Thank you for using the system!\n");
                return 0;

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}

/* Load books from file */
void loadBooks() {
    FILE *fp = fopen("books.txt", "r");

    if (fp == NULL) {
        return;
    }

    while (fscanf(fp, "%d|%99[^|]|%99[^|]|%d\n",
                  &books[count].id,
                  books[count].title,
                  books[count].author,
                  &books[count].issued) == 4) {
        count++;
    }

    fclose(fp);
}

/* Save books to file */
void saveBooks() {
    FILE *fp = fopen("books.txt", "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d|%s|%s|%d\n",
                books[i].id,
                books[i].title,
                books[i].author,
                books[i].issued);
    }

    fclose(fp);

    printf("\nBooks saved successfully!\n");
}

/* Add Book */
void addBook() {
    if (count >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &books[count].id);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", books[count].title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", books[count].author);

    books[count].issued = 0;

    count++;

    printf("\nBook Added Successfully!\n");
}

/* View Books */
void viewBooks() {
    if (count == 0) {
        printf("\nNo Books Available!\n");
        return;
    }

    printf("\n=========== BOOK LIST ===========\n");

    for (int i = 0; i < count; i++) {
        printf("\nBook %d\n", i + 1);
        printf("ID      : %d\n", books[i].id);
        printf("Title   : %s\n", books[i].title);
        printf("Author  : %s\n", books[i].author);
        printf("Status  : %s\n",
               books[i].issued ? "Issued" : "Available");
    }
}

/* Search Book */
void searchBook() {
    int id;
    int found = 0;

    printf("\nEnter Book ID to Search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("\nBook Found!\n");
            printf("ID      : %d\n", books[i].id);
            printf("Title   : %s\n", books[i].title);
            printf("Author  : %s\n", books[i].author);
            printf("Status  : %s\n",
                   books[i].issued ? "Issued" : "Available");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nBook Not Found!\n");
    }
}

/* Issue Book */
void issueBook() {
    int id;
    int found = 0;

    printf("\nEnter Book ID to Issue: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {

            if (books[i].issued) {
                printf("\nBook Already Issued!\n");
            } else {
                books[i].issued = 1;
                printf("\nBook Issued Successfully!\n");
            }

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nBook Not Found!\n");
    }
}

/* Return Book */
void returnBook() {
    int id;
    int found = 0;

    printf("\nEnter Book ID to Return: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {

            if (!books[i].issued) {
                printf("\nThis Book Was Not Issued!\n");
            } else {
                books[i].issued = 0;
                printf("\nBook Returned Successfully!\n");
            }

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nBook Not Found!\n");
    }
}