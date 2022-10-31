#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *filename = "database.txt"; 
int number = 2; 
int length = 370; 

int fillList(); 
int cmpfunc (const void * a, const void * b);
int RandomInts(int amount, int limit, int *list); 

typedef struct {
    char Hungarian[20];
    char German[20];
} WordTuple;

WordTuple List[20]; 

int RunQuestionMode() {
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
        char row[100]; 
        while ((c = getc(file)) != EOF) {
            if (isspace(c)) {
                if (c == '\n') { // no "" just '' for \n
                    countNewLine++;
                    if (check == 1) {
                        if ((i+1) >= number) {
                            break; 
                        } else {
                            i++; 
                            // TODO: add new row 
                            printf("%s", row); 
                            row[100] = '\0'; 
                        } 
                    }
                }
                if (countNewLine == list[i]) {
                    check = 1; 
                    char charValue = c+'0';
                    char str[1] = "\0"; 
                    str[0] = charValue; 
                    strncat(row, str, 100); 
                }
            }
        }
        fclose(file);
    }
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