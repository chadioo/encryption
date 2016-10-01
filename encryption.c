#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define xor(A,B) (A)^=(B)
#define LENGTH(x)   (sizeof(x) / sizeof((x)[0]))

// Function declaration

char generateKeyByte(char S[]);

int main(int argc, char *argv[]) {

    // Declartions

    char keyF[256];
    char currentKey;
    char S[256]; char T[256];

    //char messageF[256];
    //int mFileLength;

    // Chad's code

    FILE *keyFile;
    int keyChar;
    int i;
    keyFile = fopen(argv[1], "r");
    assert(keyFile != NULL);
    i = 0;
    
    while ((keyChar = fgetc(keyFile))!=EOF) {
        keyF[i] = keyChar;
        i++;
    }
    
    for(i=0; i<256; i++){
        S[i] = i;
        T[i] = keyF[i % LENGTH(keyF)];
    }
    
    int j = 0;
    char temp;
    for(i=0; i<256; i++){
        j = (j+S[i]+T[i]) % 256;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }
    
    // print arrays for testing
    /* for(i=0; i<256; i++){
        printf("%c", S[i]);
    } */
    
    // Mike's code

    /* FILE *inputFile;
    FILE *outputFile;
    int inputChar;
        
    if (argc < 3) printf("Input and output files need to be specified\n");
    inputFile = fopen(argv[2], "r");
    outputFile = fopen(argv[3], "w");
        
    assert(inputFile != NULL);
    assert(outputFile != NULL);
        
        
    while ((inputChar = fgetc(inputFile))!=EOF) {
        currentKey = generateKeyByte(keyF);
        inputChar^=currentKey;
        fputc(inputChar, outputFile);
    }
    fclose(inputFile);
    fclose(outputFile); */
}

char generateKeyByte(char S[]){
    static int i = 0;
    static int j = 0;
    i = (i+1) % 256;
    j = (j+S[i]) % 256;
    char temp;
    temp = S[i];
    S[i] = S[j];
    S[j] = temp;
    t = (S[i]+S[j]) % 256;
    char keyByte;
    return keyByte = S[t];
}
