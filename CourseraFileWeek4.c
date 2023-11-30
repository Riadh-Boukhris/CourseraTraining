#include <stdio.h>
#include <stdlib.h> //exit() function


double calculateAverage(int data[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += data[i];
    }
    return (double)sum / size;
}


void readFile(FILE *ptr, int data[], int size){
    
    int counter = 0;

    while(fscanf(ptr, "%d", &data[counter]) == 1){
        counter++;
    }
}

int maxVal(int data[], int size){
    int max = data[0];
    for(int i = 1; i < size; i++){
        if (max < data[i]){
            max = data[i];
        }
    }
    return max;
}

int main(int argc, char *argv[]){


    FILE *ifp, *ofp;

    //Check files exucutables
    if (argc != 3){
        printf("Need executables input output files");
        exit(1);
    }
    
    //open files
    ifp = fopen(argv[1], "r");
    ofp = fopen(argv[2], "w");
    
    int size = 0;
    //reset file position to the beginning
    rewind(ifp);

    //get the size of data[] from the ifp file
    fscanf(ifp, "%d", &size);

    // Allocate memory for the array
    int *data = malloc(size * sizeof(int));

    // Read the remaining integers into the data array
    readFile(ifp, data, size);


    // Output results to the console
    printf("From the input file, the average was %f and the maximym value is %d", calculateAverage(data, size), maxVal(data, size));

     // Close the input file
    fclose(ifp);

    // Output results to the output file
    fprintf(ofp, "Average: %.2lf\n", calculateAverage(data, size));
    fprintf(ofp, "Max Value: %d\n", maxVal(data, size));

    // Close the output file
    fclose(ofp);

    // Free allocated memory
    free(data);


    return EXIT_SUCCESS;

}


void delete_element(list* element, list **prev, list **head){
    if (*head == *prev){
        head = element -> next;
    }
    else {
        (*prev) -> next = element -> next;
    }
    free(element);
}