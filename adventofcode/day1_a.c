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

    /*
    char * fgets( char * str, int size, FILE * stream );

    str: Ein char-Array, in welches der String geschrieben werden soll.
	size: Größe des String-Buffers str. fgets() liest damit maximal size-1 Zeichen und fügt ein Nullbyte an.
	stream: Stream, aus dem der String gelesen werden soll
    */

    // reading line by line, max 256 bytes
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];
    int value; 
    int value_old = -1; 
    int amount_increases = 0;
   

    while (fgets(buffer, MAX_LENGTH, fp)){

    	 value = atoi(buffer);
    	 
    	 //everytime value_old is smaller than value, increase the counter
    	 if((value_old < value) && (value_old != -1)){
    	 	amount_increases++;
    	 }

    	 value_old = value;
 
    }

    printf("%d", amount_increases); //result

    // close the file
    fclose(fp);

   return 0;
}