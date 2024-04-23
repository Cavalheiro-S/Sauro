#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 50
#define DATABASE_FILE "database.txt"

// Define a structure to hold your data
typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Record;

// Function to add a record to the database
void addRecord(const char *name, const char *email) {
    FILE *file = fopen(DATABASE_FILE, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    fprintf(file, "%s,%s\n", name, email);
    fclose(file);
}

// Function to display all records in the database
void displayRecords() {
    FILE *file = fopen(DATABASE_FILE, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

// Function to search for a record by name
void searchRecord(const char *name) {
    FILE *file = fopen(DATABASE_FILE, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        if (strcmp(token, name) == 0) {
            printf("Name: %s, Email: %s", token, strtok(NULL, "\n"));
            fclose(file);
            return;
        }
    }
    printf("Record not found.\n");
    fclose(file);
}

int main() {
    addRecord("John Doe", "john@example.com");
    addRecord("Jane Smith", "jane@example.com");
    addRecord("Alice Johnson", "alice@example.com");

    printf("All Records:\n");
    displayRecords();

    printf("\nSearch Record:\n");
    searchRecord("Jane Smith");

    return 0;
}
