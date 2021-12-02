#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *filename = "day1_data.txt"; //input data in txt file
    FILE *fp = fopen(filename, "r");       //open file in read mode

    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];
    int value[1999]; 
    int i = 0;
    int amount_increases = 0;
   

    while (fgets(buffer, MAX_LENGTH, fp)){
         value[i] = atoi(buffer);
         i++; //Note: i increments to 2000 therefore the array size must be 1999, else this will not work
    }

    int value_a;
    int value_b;

    for(int j = 0; j < sizeof(value)/sizeof(int); j++){

        if(j+3 > sizeof(value)/sizeof(int)){
            printf("\n %d", amount_increases); //result
        } else {
            value_a = value[j] + value[j+1] + value[j+2];
            value_b = value[j+1] + value[j+2] + value[j+3];

        if(value_a < value_b){
            amount_increases++;
        }
    }

    printf("\n %d", amount_increases); //result
        }

    // close the file
    fclose(fp);

   return 0;
}
