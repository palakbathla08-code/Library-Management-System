#include <stdio.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int issued;   // 0 = available, 1 = issued
};

int main() {
    struct Book books[100];
    int count = 0;   // number of books stored
    int choice, i, id, found;

    do {
        printf("\n--- LIBRARY MANAGEMENT SYSTEM ---\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (count >= 100) {
                printf("Library is full!\n");
                break;
            }
            printf("Enter book ID: ");
            scanf("%d", &books[count].id);
            printf("Enter title: ");
            scanf(" %[^\n]", books[count].title);
            printf("Enter author: ");
            scanf(" %[^\n]", books[count].author);
            books[count].issued = 0;
            count++;
            printf("Book added!\n");
            break;

        case 2:
            if (count == 0) {
                printf("No books yet.\n");
            }
            for (i = 0; i < count; i++) {
                printf("\nID: %d\n", books[i].id);
                printf("Title: %s\n", books[i].title);
                printf("Author: %s\n", books[i].author);
                if (books[i].issued == 1)
                    printf("Status: Issued\n");
                else
                    printf("Status: Available\n");
            }
            break;

        case 3:
            printf("Enter book ID to search: ");
            scanf("%d", &id);
            found = 0;
            for (i = 0; i < count; i++) {
                if (books[i].id == id) {
                    printf("Found! Title: %s, Author: %s\n", books[i].title, books[i].author);
                    found = 1;
                }
            }
            if (found == 0)
                printf("Book not found.\n");
            break;

        case 4:
            printf("Enter book ID to issue: ");
            scanf("%d", &id);
            found = 0;
            for (i = 0; i < count; i++) {
                if (books[i].id == id) {
                    found = 1;
                    if (books[i].issued == 1)
                        printf("Book is already issued.\n");
                    else {
                        books[i].issued = 1;
                        printf("Book issued!\n");
                    }
                }
            }
            if (found == 0)
                printf("Book not found.\n");
            break;

        case 5:
            printf("Enter book ID to return: ");
            scanf("%d", &id);
            found = 0;
            for (i = 0; i < count; i++) {
                if (books[i].id == id) {
                    found = 1;
                    if (books[i].issued == 0)
                        printf("This book was not issued.\n");
                    else {
                        books[i].issued = 0;
                        printf("Book returned!\n");
                    }
                }
            }
            if (found == 0)
                printf("Book not found.\n");
            break;

        case 6:
            printf("Thank you!\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}