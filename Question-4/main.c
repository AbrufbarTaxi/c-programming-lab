#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

// Function to open a file safely, return the file pointer
FILE *open_file(const char *filename, const char *mode)
{
    FILE *fptr;
    fptr = fopen(filename, mode);
    if (fptr == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    return fptr;
}

// Function to generate output filename for employee
void generate_output_filename(char *filename, const char *id)
{
    sprintf(filename, "payslip_%s.txt", id);
}

// Function to process one employee and generate payslip
void process_employee(const char *id, const char *name, const char *dept, const char *salary)
{
    char filename[100];
    char template_line[1024], output_line[1024];

    // Create output file name like payslip_101.txt using generate_output_filename function
    generate_output_filename(filename, id);

    // Open output file
    FILE *outputFile;
    outputFile = open_file(filename, "w");

    // Open template file
    FILE *templateFile;
    templateFile = open_file("template.txt", "r");

    // Read template line by line and feed it to replace_placeholder function
    while (fgets(template_line, sizeof(template_line), templateFile))
    {
        replace_placeholder(template_line, output_line, id, name, dept, salary);
        fputs(output_line, outputFile);
    }

    // Close open files
    fclose(templateFile);
    fclose(outputFile);
}

// Function to read employees.txt and process each record
void process_all_employees()
{
    // use open_file function to open employees.txt in read mode
    char id[20], name[50], dept[50], salary[20];

    // read id, name, dept, salary line by line and call process_employee function with required arguments
    FILE *empFile = open_file("employees.txt", "r");
    while(fscanf(empFile, "%s %s %s %s", id, name, dept, salary) == 4) {
        process_employee(id, name, dept, salary);
    }

    // close employees.txt file
    fclose(empFile);
}

int main()
{
    process_all_employees();
    printf("Payslips generated successfully!\n");
    return 0;
}
