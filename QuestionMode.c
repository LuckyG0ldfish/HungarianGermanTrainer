#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *filename = "database.txt"; 
const int number = 3; 
int length = 320; 
// const int maxGermanWords = 10; 
// const int maxHungarianWords = 10; 
const int maxWordLength = 40; 

int fillList(); 
int cmpfunc (const void * a, const void * b);
int RandomInts(int amount, int limit, int *list); 
int CalcLength(); 

typedef struct {
    char Hungarian[10][40];
    char German[10][40];
    // char Hungarian[maxHungarianWords][maxWordLength];
    // char German[maxGermanWords][maxWordLength];
} WordTuple;

// WordTuple List[number]; 
WordTuple List[3]; 

int RunQuestionMode() {
    CalcLength(); 
    fillList(); 
    return 0; 
}

int fillList() {
    int c;
    FILE *file;
    file = fopen("testDatabase.txt", "r");
    if (file) {
        int list[number]; 
        RandomInts(number, length, list); 
        int i = 0; 
        int countNewLine = 0;  
        int countTab = 0;  
        int check = 0;
        char row[200]; // s[number]
        int rowCounter = 0; 
        while ((c = fgetc(file)) != EOF) { 
            if (isspace(c)) {
                if (c == '\n') { // no "" just '' for \n
                    countNewLine++;
                    if (check == 1) {
                        printf("%s\n", row); 
                        check = 0;
                        rowCounter = 0; 
                        if ((i+1) > number) {
                            return 1; 
                        } else {
                            i++; 
                            // TODO: add new row 
                            memset(row,0,strlen(row));
                        } 
                    }
                }  
            }
            if (countNewLine == list[i]) {
                check = 1; 
                char charValue = c;
                row[rowCounter] = charValue; 
                rowCounter++;  
            }
        }
        fclose(file);
    }
    return 0; 
}

int CalcLength(){
    FILE *File = fopen("testDatabase.txt", "r");
    int CountLines = 0; 
    int c = 0 ; 
    if(File) {
        CountLines = 1; 
        while ((c = fgetc(File)) != EOF) { 
            if (c == '\n') {
                CountLines += 1; 
            }
        }
    }
    length = CountLines; 
    return CountLines; 
}

int rowToObject(int i, char row[]) {
    int gerCount = 0; 
    int hungCounter = 0;  
    int tabHappend = 0; 
    char word[maxWordLength]; 
    for (int i = 0; i < strlen(row); i++) {
        if (row[i] == '\t') {
            tabHappend = 1; 
        } else if (row[i] == ' ') {
            
        } else if (row[i] == ',') {
            
        }
    }
    return 0; 
}

int transferString(char word[], int index, int lang, WordTuple tuple) {
    for (int i = 0; i < strlen(word); i++) {
        if (lang == 0) {
            tuple.German[index][i] = word[i]; 
        } else {
            tuple.Hungarian[index][i] = word[i]; 
        }
    }
    return 0; 
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int RandomInts(int amount, int limit, int *list) { 
    srand(time(NULL));   
    for (int i = 0; i < amount; i ++) {
        list[i] = rand()% (limit-1);
    }
    qsort(list, amount, sizeof(int), cmpfunc);
    return 0; 
}

// tab == '\t'

// char *getWord(FILE *fp){
//     char word[100];
//     int ch, i=0;

//     while(EOF!=(ch=fgetc(fp)) && !isalpha(ch))
//         ;//skip
//     if(ch == EOF)
//         return NULL;
//     do{
//         word[i++] = tolower(ch);
//     }while(EOF!=(ch=fgetc(fp)) && isalpha(ch));

//     word[i]='\0';
//     return strdup(word);
// }
// void read(FILE *fp){
//     char *word;
//     while(word=getWord(fp)){
        
//     }
//     //rewind(fp1);
//     fclose(fp);
// }