
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Define a structure
struct Employee {
    int id;
    char name[50];
    float salary;
};

// Function to write array of structures to a file
void writeToFile(const char *filename, struct Employee *empArray, int size) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Unable to open file for writing");
        exit(EXIT_FAILURE);
    }
    fwrite(empArray, sizeof(struct Employee), size, file);
    fclose(file);
}

// Function to read array of structures from a file
void readFromFile(const char *filename, struct Employee *empArray, int size) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Unable to open file for reading");
        exit(EXIT_FAILURE);
    }
    fread(empArray, sizeof(struct Employee), size, file);
    fclose(file);
}

// Main function
int main() {
    struct Employee empArray[MAX] = {
        {1, "John Doe", 50000.0},
        {2, "Jane Smith", 60000.0},
        {3, "Sam Brown", 55000.0},
        {4, "Lisa White", 58000.0},
        {5, "Tom Black", 62000.0}
    };

    const char *filename = "employees.dat";

    // Write the array of structures to file
    writeToFile(filename, empArray, MAX);
    printf("Data written to file successfully.\n");

    // Read the array of structures from file
    struct Employee readArray[MAX];
    readFromFile(filename, readArray, MAX);
    printf("Data read from file:\n");

    // Display the data read from file
    for (int i = 0; i < MAX; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", readArray[i].id, readArray[i].name, readArray[i].salary);
    }

    return 0;
}
