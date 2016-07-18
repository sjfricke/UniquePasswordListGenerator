//
// Created by SpencerFricke on 7/17/2016.
//
// Used to create a set amount of random all digit passwords and write out in JSON format
// Using C to utilize OpenMP
// pass the number of passwords wanted and number of digits
//     Needs to be less then max number with respect to digits and enough to fill the number passed
//
// Run with generatePasswords.exe <file output> [number of passwords] [length]

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define DEFAULT_COUNT 256
#define DEFAULT_LENGTH 6

double WTIME;

int main(int argc, char *argv[]) {

    int rs; //return status
    int i, j; //for loops C99 rule
    unsigned int  password_count, password_length;
    int *passwordArray;
    int tempPass;
    bool validPass = false;
    int max_num;
    char printStringLeading[2];
    char printString1[20] = "    \"%d\" : \"%0";
    char printString2[20] = "d\",\n";

    //checks if file name is passed
    if (argc < 2) {
        printf("Need to pass the file name as first parameter\n");
        printf("Example for Window: JSON_generator.exe passwordList.json 256 6\n");
        printf("Example for Linux/Mac: ./JSON_generator passwordList.json 256 6\n");
        return -1;
    }

    //creates file
    FILE *outputFile = fopen(argv[1], "w");
    if (outputFile == NULL)
    {
        printf("Error creating file!\n");
        return -2;
    }

    //sets password count
    if (argc < 3) {
        password_count = DEFAULT_COUNT;
    } else {
        rs = sscanf (argv[2],"%d",&password_count);
        if (rs < 1) {printf("ERROR: Invalid password_count parameter\n"); return -2;}
        if (password_count > 100000000 || password_count < 0) {printf("ERROR: Invalid password_count parameter amount\n"); return -2;}
    }

    //sets password length
    if (argc < 4) {
        password_length = DEFAULT_LENGTH;
    } else {
        rs = sscanf (argv[3],"%d",&password_length);
        if (rs < 1) {printf("ERROR: Invalid password_length parameter\n"); return -2;}
        if (password_length > 9 || password_count < 0) {printf("ERROR: Invalid password_length parameter amount\n"); return -2;}

    }

    passwordArray = malloc(sizeof(int) * password_count);

    max_num = pow(10, password_length);

    srand(password_count);

    //loops through for each password count
    for (i = 0; i < password_count; i++) {
        validPass = false;

        //keeps looping if password already used
        while (!validPass) {
            validPass = true;

            tempPass = (rand() * rand()) % max_num;

            //check for used password
            for (j = 0; j < i; j++) {
                if (tempPass == passwordArray[j]) {
                    validPass = false;
                    printf("Invalid: %d already at %d\n", tempPass, j);
                    break; //saves time and leaves this for loop
                }
            }
        }
        passwordArray[i] = tempPass;
    }


    //write out to json
    fprintf(outputFile, "{\n");

    //string parsing to allow for padding/leading 0 of password
    //pass string together via strcat()
    sprintf(printStringLeading, "%d", password_length);
    strcat(printString1, printStringLeading);
    strcat(printString1, printString2);

    //loops thorugh and prints out json
    for (i = 0; i < password_count - 1; i++){
        fprintf(outputFile, printString1, i, passwordArray[i]);
    }

    //sets up string for printing last json line without the comma
    strncpy(printString2, printString1, strlen(printString1) - 2);
    fprintf(outputFile, printString2, (password_count - 1), passwordArray[password_count - 1]);
    fprintf(outputFile,"\n}");

    //cleanup
    fclose(outputFile);
    free(passwordArray);
    return 0;


}