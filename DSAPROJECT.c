#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct Book {
    char title[100];
    char author[100];
    struct Book *next;
} Book;

// Function prototypes
void addBook(Book **library);
void deleteBook(Book **library, char *title);
void searchByTitle(Book *library, char *title);
void searchByAuthor(Book *library, char *author);
void displayBooks(Book *library);

int main() {
    Book *library = NULL;
    int choice;
    char title[100];
    char author[100];

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add a book\n");
        printf("2. Delete a book\n");
        printf("3. Search by title\n");
        printf("4. Search by author\n");
        printf("5. Display all books\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(&library);
                break;
            case 2:
                printf("Enter the title of the book to delete: ");
                scanf(" %[^\n]", title);
                deleteBook(&library, title);
                break;
            case 3:
                printf("Enter the title of the book to search: ");
                scanf(" %[^\n]", title);
                searchByTitle(library, title);
                break;
            case 4:
                printf("Enter the author of the book to search: ");
                scanf(" %[^\n]", author);
                searchByAuthor(library, author);
                break;
            case 5:
                displayBooks(library);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to add a book to the library
void addBook(Book **library) {
    Book *newBook = (Book *)malloc(sizeof(Book));
    printf("Enter the title of the book: ");
    scanf(" %[^\n]", newBook->title);
    printf("Enter the author of the book: ");
    scanf(" %[^\n]", newBook->author);
    newBook->next = *library;
    *library = newBook;
    printf("Book added successfully.\n");
}

// Function to delete a book from the library
void deleteBook(Book **library, char *title) {
    Book *current = *library;
    Book *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            if (prev == NULL) {
                *library = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Book deleted successfully.\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Book not found.\n");
}

// Function to search for a book by title
void searchByTitle(Book *library, char *title) {
    Book *current = library;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            printf("Book found:\n");
            printf("Title: %s\n", current->title);
            printf("Author: %s\n", current->author);
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

// Function to search for a book by author
void searchByAuthor(Book *library, char *author) {
    Book *current = library;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->author, author) == 0) {
            printf("Book found:\n");
            printf("Title: %s\n", current->title);
            printf("Author: %s\n", current->author);
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

// Function to display all books in the library
void displayBooks(Book *library) {
    if (library == NULL) {
        printf("Library is empty.\n");
        return;
    }

    Book *current = library;
    printf("Books in the library:\n");

    while (current != NULL) {
        printf("Title: %s\n", current->title);
        printf("Author: %s\n", current->author);
        current = current->next;
    }
}
