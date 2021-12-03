#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>



int binaryToInteger(int arr[], int sizeOf_array);

int main() {

    char *filename = "day3_data.txt";             //input data in txt file
    FILE *fp = fopen(filename, "r");              //open file in read mode
    const unsigned int arraySize = 12;            //12 digits binary numbers a given in the day 3 data
    int gamma[arraySize];                         //Stores the gamma value as a binary number
    int epsilon[arraySize];                       //Stores the epsilon value as a binary number
    int most_common_bit; 
    char *a;

    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];

        for (int i = 0; i < arraySize; i++){ 

           while (fgets(buffer, MAX_LENGTH, fp)){
            a = buffer;
           
            if(a[i] == '0'){
                most_common_bit--;
            } else {
                most_common_bit++;
            }
           
           //epsilon is just gamma inverted
           if(most_common_bit > 0){
            gamma[i] = 1;
            epsilon[i] = 0;
           } else {
            gamma[i] = 0;
            epsilon[i] = 1;
           }

        } 
        most_common_bit = 0;            //reset most common bit for every iteration 
        rewind(fp);                     //jump back to first address of the txt file

   }
    
   

    int result_gamma = binaryToInteger(gamma, arraySize);
    int result_epsilon = binaryToInteger(epsilon, arraySize);
    printf("result  %d \n", result_gamma * result_epsilon);  //print result

    // close the file
    fclose(fp);

   return 0;
}

/*
Converts a binary number, where each digit is stored in an single array cell to a decimal number

@para      *arr             pointer to the array that holds the binary number
           sizeOf_array     Size of said array

@return                     Decimal number for the given binary
*/
int binaryToInteger(int *arr, int sizeOf_array){

    int result = 0;
    for(int k = 0; k < sizeOf_array; k++){
        result += arr[k] * pow(2,(sizeOf_array-k-1));
    }
    return result;

}
