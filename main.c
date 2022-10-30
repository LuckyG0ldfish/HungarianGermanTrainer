#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Inputmode.c"
#include "QuestionMode.c"

bool getInput(); 
bool RunInputMode(); 
bool selectMode(int i);

char input[20];
char output[20];  
char solution[20]; 
bool correct; 
const int InputMode = 1; 
const int QuestionMode = 2; 


void main() {
    printf("Hello, World!\n");
    getInput(); 
    printf("%s\n", input); 
    if (TestFile()) {
        printf("läuft"); 
    } else {
        printf("was is File?"); 
    }
}

bool selectMode(int i) {
    if (i == InputMode) {
        RunInputMode(); 
    } else if (i == QuestionMode) {
        RunQuestionMode(); 
    } else {
        printf("Only '1' and '2' are viable inputs"); 
    }
}

bool getInput() {
    /*where store, length, stdin = standart input*/
    fgets(input, 20, stdin);
    return true; 
}

bool checkResponse() {
    
}

