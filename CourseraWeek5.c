/* This program is for calculating the average of elephants 
   from a given file  */

#define MAX_SEALS 1000 

#include "stdio.h"



int main(void){

    FILE *file;
    char filename[] = "elephant_seals_data.txt"; // reading the file

    int weights[MAX_SEALS];
    long sum = 0; // Caluculating the total of weights
    int cnt = 0; // Counting the total of elephants
        
    file = fopen(filename, "r"); //opening file

    if (file == NULL){
        printf("Error opening the file"); // Checking file not empty
        return 1;
    }

    while (fsacnf(file, "%d", &weights[cnt]) == 1 && count < MAX_SEALS){
        sum += weights[cnt];
        cnt++; 
    }
    fclose(file); //closing file


    // Cheking if there is DATA
    if (cnt == 0){
        printf("No DATA found");
        return 1;
    }

    double avg = (double)sum / cnt; // Calculating the average
    printf("the average of elephants weight is : %ld", avg); //Printing the average
    return 0;
}