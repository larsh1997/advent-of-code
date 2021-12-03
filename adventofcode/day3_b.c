#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_LENGTH 256



int binaryToInteger(int arr[], int sizeOf_array);
void deleteLine(FILE *fp, FILE *fp_tmp, int val, int iteration);

int main() {

    FILE *fp = fopen("day3_data.txt", "r+");            //open file in read+ mode
    FILE *fp_tmp = fopen("day3_tmp.txt", "r+");         //temporary txt file 
    const int arraySize = 12;                           //12 digits binary numbers are given in the day 3 data
    int firstNumber[arraySize];                        
    int most_common_bit; 
    char *a;
    char val;
    int iteration = 0;
 

    if (fp == NULL || fp_tmp == NULL)
    {
        printf("Error: could not open file");
        return 1;
    }

 

    char buffer[MAX_LENGTH];

    int line_counter = 0;
        for (int i = 0; i < 12; i++){ 
     

           while (fgets(buffer, MAX_LENGTH, fp) != NULL){
            a = buffer;
            
            line_counter++;
            if(a[i] == '0'){
                most_common_bit--;  
            } else {
                most_common_bit++;  
            }
           
            
           if(most_common_bit >= 0){
                val = '1';   //for oxygen generator rating keep it like this, for CO2 scrubber rating invert it
           } else {  
                val = '0';   //for oxygen generator rating keep it like this, for CO2 scrubber rating invert it
           }
        } 

        if(line_counter == 1){

            for(int e = 0; e < arraySize; e++){
                firstNumber[e] = (int)(a[e]- '0'); //cast char to int
            }
            break;
        }

        line_counter = 0;
        deleteLine(fp, fp_tmp, val, iteration);  //delete irrelevant lines
        iteration++;
        
        most_common_bit = 0;            //reset most common bit for every iteration 
        rewind(fp);                     //jump back to first address of the txt file 

   }

        int result = binaryToInteger(firstNumber, arraySize);
        printf("%d ", result);
    
    // close the file
    fclose(fp);
    fclose(fp_tmp);

   return 0;
}

/*
Converts a binary number, where each digit is stored in an single array cell to a decimal number

@para      *arr             pointer to the array that holds the binary number
           arraySize     Size of said array

@return                     Decimal number for the given binary
*/
int binaryToInteger(int *arr, int arraySize){

    int result = 0;

    for(int k = 0; k < arraySize; k++){
        result += (arr[k] * (int)pow(2,(arraySize-k-1)));
    }
    return result;

}

/*
Deletes the lines corresponding the the given val value e.g. if val = 1, it deletes
the columns that contain a 0 

@para           *fp         textfile 1
                *fp_tmp     temporary textfile
                val         either 1 or 0
                iteration   corresponds to the current column (0-11)
*/

void deleteLine(FILE *fp, FILE *fp_tmp, int val, int iteration){


    char buffer[MAX_LENGTH];
    char *a;
    
    rewind(fp);
    fclose(fp_tmp);
    fp_tmp = fopen("day3_tmp.txt", "w+");

    while(fgets(buffer, MAX_LENGTH, fp) != NULL){
        a = buffer;

        if(a[iteration] != val){ 
            
            fputs(buffer,fp_tmp);
        }  
    }

    rewind(fp_tmp);

    fclose(fp);
    fp = fopen("day3_data.txt", "w+");  

    while(fgets(buffer, MAX_LENGTH, fp_tmp) != NULL){
            fputs(buffer,fp);
    }

    fclose(fp);
    fp = fopen("day3_data.txt", "r+");

}

