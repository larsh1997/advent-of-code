#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    
   int current_horizontal = 0; //staring at 0
   int current_depth = 0; //starting at 0

    char *filename = "day2_data.txt";      //input data in txt file
    FILE *fp = fopen(filename, "r");       //open file in read mode

    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];
    while (fgets(buffer, MAX_LENGTH, fp)){

    //foward
    if(buffer[0] == 'f'){
        current_horizontal += atoi(&buffer[8]);
     } 
        
     //down
     else if (buffer[0] == 'd'){
        current_depth += atoi(&buffer[5]);
     } 
        
     //up 
     else if (buffer[0] == 'u'){
        current_depth -= atoi(&buffer[3]);
     } 
    
     }

     printf("Result: %d", current_horizontal*current_depth);

    // close the file
    fclose(fp);

   return 0;
}
