#include <stdio.h>
#include <string.h>
#include <string.h>

typedef struct {
    char name[50];
    char author[50];
    char genre[30];
    int year;
    char isbn[13];
} Book;

typedef struct {
    Book *array;
    size_t used;
    size_t size;
} DynamicArray;

void initArray(DynamicArray *a, size_t initialSize) {
    a->array = (Book *)malloc(initialSize * sizeof(Book));
    a->used = 0;
    a->size = initialSize;
}

void insertArray(DynamicArray *a, Book book) {
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (Book *)realloc(a->array, a->size * sizeof(Book));
    }
    a->array[a->used++] = book;
}

void freeArray(DynamicArray *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

void saveBooksToFile(DynamicArray *books, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }
    for (size_t i = 0; i < books->used; i++) {
        fprintf(file, "%s,%s,%s,%d,%s\n", books->array[i].name, books->array[i].author, books->array[i].genre, books->array[i].year, books->array[i].isbn);
    }
    fclose(file);
}

void loadBooksFromFile(DynamicArray *books, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file for reading");
        return;
    }
    char buffer[200];
    while (fgets(buffer, sizeof(buffer), file)) {
        Book book;
        fscanf(buffer, "%[^,],%[^,],%[^,],%d,%[^,\n]", book.name, book.author, book.genre, &book.year, book.isbn);
        insertArray(books, book);
    }
    fclose(file);
}

void addBook(DynamicArray *books) {
    Book book;
    printf("Enter the name of the book: ");
    scanf("%s", book.name);
    printf("Enter the author of the book: ");
    scanf("%s", book.author);
    printf("Enter the genre of the book: ");
    scanf("%s", book.genre);
    printf("Enter the year of publication: ");
    scanf("%d", &book.year);
    printf("Enter the ISBN number: ");
    scanf("%s", book.isbn);
    insertArray(books, book);
}

void displayBooks(DynamicArray *books) {
    for (size_t i = 0; i < books->used; i++) {
        printf("Name: %s, Author: %s, Genre: %s, Year: %d, ISBN: %s\n", books->array[i].name, books->array[i].author, books->array[i].genre, books->array[i].year, books->array[i].isbn);
    }
}

void deleteBook(DynamicArray *books, const char *isbn) {
    for (size_t i = 0; i < books->used; i++) {
        if (strcmp(books->array[i].isbn, isbn) == 0) {
            for (size_t j = i; j < books->used - 1; j++) {
                books->array[j] = books->array[j + 1];
            }
            books->used--;
            printf("Book with ISBN %s deleted.\n", isbn);
            return;
        }
    }
    printf("Book with ISBN %s not found.\n", isbn);
}

int main() {
    DynamicArray books;
    initArray(&books, 5);
    loadBooksFromFile(&books, "books.txt");

    int choice;
    char isbn[13];

    do {
        printf("\n1. Add Book\n2. Display Books\n3. Delete Book by ISBN\n4. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(&books);
                break;
            case 2:
                displayBooks(&books);
                break;
            case 3:
                printf("Enter ISBN of the book to delete: ");
                scanf("%s", isbn);
                deleteBook(&books, isbn);
                break;
            case 4:
                saveBooksToFile(&books, "books.txt");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    freeArray(&books);
    return 0;
}