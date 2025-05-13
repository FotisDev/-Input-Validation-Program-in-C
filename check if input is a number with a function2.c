#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define STR_SIZE 2000000 // Define the maximum size for the input buffer

// Function to validate and retrieve an integer input
int intAfterCheck(char *msg) {
    char temp[STR_SIZE];
    int i, arith;
    bool flag;

    do {
        flag = 1;

        printf("%s", msg);
        gets(temp); // Reading user input

        if (strlen(temp) == 0)  // Check for empty input
            flag = 0;
        else if ((temp[0] == '+' || temp[0] == '-') && strlen(temp) == 1) // Check for a lone sign
            flag = 0;
        else if (temp[0] != '+' && temp[0] != '-') {
            // Check for non-digit characters
            for (i = 0; i < strlen(temp); i++) {
                if (isdigit(temp[i]) != 0)
                    flag = flag & 1;
                else
                    flag = flag & 0;
            }
        } else if ((temp[0] == '+' && temp[1] == '+') || (temp[0] == '+' && temp[1] == '-') || (temp[0] == '-' && temp[1] == '+') || (temp[0] == '-' && temp[1] == '-'))
            flag = 0;

        // Handle invalid inputs
        if (flag == 0) {
            printf("\n\nInvalid input! Please enter a valid integer.\n\n");
            system("pause");
            system("cls");
        }
    } while (flag == 0);

    arith = atoi(temp); // Convert the valid string input to an integer
    return arith;
}

// Function to validate and retrieve a float input
float floatAfterCheck(char *msg) {
    char temp[STR_SIZE];
    int i, count, flag = 0;
    float arith;

    do {
        flag = 1; 
        count = 0;

        printf("%s", msg);
        gets(temp); // Reading user input

        if (strlen(temp) == 0)  // Check for empty input
            flag = 0;
        else {
            // Check if there are multiple decimal points
            for (i = 0; i < strlen(temp) - 1; i++)
                if (temp[i] == '.')
                    count++;

            if (count >= 2)
                flag = 0;

            // Check if the input starts or ends with a decimal point
            if (temp[0] == '.' || temp[strlen(temp) - 1] == '.')
                flag = 0;

            if ((temp[0] == '+' || temp[0] == '-') && strlen(temp) == 1)
                flag = 0;

            if (temp[0] != '+' && temp[0] != '-') {
                // Validate each character in the string
                if (count <= 1) {
                    for (i = 0; i < strlen(temp); i++) {
                        if (temp[i] == '.')
                            continue;
                        else {
                            if (isdigit(temp[i]) != 0)
                                flag = flag * 1;
                            else
                                flag = flag * 0;
                        }
                    }
                }
            }

            // Handle invalid inputs
            if (flag == 0) {
                printf("\n\nInvalid input! Please enter a valid float.\n\n");
                system("pause");
                system("cls");
            }
        }
    } while (flag == 0);

    arith = atof(temp); // Convert the valid string input to a float
    return arith;
}

int main() {
    system("chcp 1253 > nul");

    int temp1;
    float temp2;

    // Prompt and validate integer input
    temp1 = intAfterCheck("Please enter an integer: ");
    printf("The valid integer input is %d.\n\n", temp1);

    // Prompt and validate float input
    temp2 = floatAfterCheck("Please enter a float: ");
    printf("The valid float input is %.2f.\n\n", temp2);

    system("pause");
    return 0;
}

