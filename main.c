#include <stdio.h>
#include <stdlib.h>
#include "Inputmode.c"
#include "QuestionMode.c"

int getInput(); 
int RunInputMode(); 
int selectMode(int i);
int fillList(); 

char input[20];
char output[20];  
char solution[20]; 
bool correct; 
const int InputMode = 1; 
const int QuestionMode = 2; 


void main() {
    fillList(); 

}

int selectMode(int i) {
    if (i == InputMode) {
        RunInputMode(); 
    } else if (i == QuestionMode) {
        RunQuestionMode(); 
    } else {
        printf("Only '1' and '2' are viable inputs"); 
    }
    return 0; 
}

int getInput() {
    /*where store, length, stdin = standart input*/
    fgets(input, 20, stdin);
    return 1; 
}

int checkResponse() {
    return 0; 
}

