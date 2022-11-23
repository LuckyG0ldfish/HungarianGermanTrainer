#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include<unistd.h>

char *filename = "database.txt"; 
int number = 3; 
int length = 320; 
// const int maxGermanWords = 10; 
// const int maxHungarianWords = 10; 
const int maxWordLength = 50; 
const int German = 1; 
const int Hungarian = 0;

typedef struct {
    char Hungarian[10][50];
    char German[10][50];
    // char Hungarian[maxHungarianWords][maxWordLength];
    // char German[maxGermanWords][maxWordLength];
} WordTuple;

int fillList(WordTuple *list[]); 
int cmpfunc (const void * a, const void * b);
int RandomInts(int amount, int limit, int *list); 
int calcLength(); 
int getNumberOfWords(); 
WordTuple *rowToObject(char row[]); 
int transferString(char word[], int index, int lang, WordTuple *tuple); 
int printTuple(WordTuple *tuple); 

// WordTuple List[number]; 
WordTuple List[3]; 

int RunQuestionMode() {
    calcLength();
    getNumberOfWords();  
    WordTuple *list[number]; 
    fillList(list); 
    return 0; 
}

int fillList(WordTuple *tuple[]) {
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
        memset(row,0,200);
        int rowCounter = 0; 
        while ((c = fgetc(file)) != EOF) { 
            if (isspace(c)) {
                if (c == '\n') { // no "" just '' for \n
                    countNewLine++;
                    if (check == 1) {
                        // printf("%s\n", row); 
                        check = 0;
                        rowCounter = 0; 
                        if ((i+1) > number) {
                            return 1; 
                        } else {
                            // TODO: add new row 
                            printf("T1"); 
                            printf("%s",row);
                            tuple[i] = rowToObject(row);   
                            i++;
                            sleep(800); 
                            memset(row,0,200);
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

int calcLength(){
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

int getNumberOfWords() {
    int NumberOfWords;
    printf("Enter the number of words: ");
    scanf("%d", &NumberOfWords);  
    if (NumberOfWords < 1 || NumberOfWords > length) {
        printf("Please pick a number between 1 and the maximum amount of words in the database(%d)", length);
        getNumberOfWords(); 
    } else  {
        number = NumberOfWords; 
    }
    return 0;
}

WordTuple *rowToObject(char row[]) {
    printf("\nrow to object"); 
    int gerCounter = 0; 
    int hungCounter = 0;  
    int tabHappend = 0; 
    char word[maxWordLength]; 
    int wordIndex = 0; 
    WordTuple tuple; 
    int len = strlen(row); 
    int done = 0; 
    for (int i = 0; i < len; i++) {
        if (row[i] == ',' || row[i] == ';' || row[i] == '\t') {
            done = 1; 
            // printf(word); 
        } else {
            // add to word 
            char charValue = row[i];
            word[wordIndex] = charValue; 
            wordIndex++;
            if (i == len-1) {
                done = 1; 
            }
        }
        if (done == 1) {
            // next word
            if (tabHappend == 0) {
                // add to hungarian
                transferString(word, hungCounter, Hungarian, &tuple); 
                hungCounter ++; 
            } else {
                // add to german 
                transferString(word, gerCounter, German, &tuple);
                gerCounter ++; 
            }
            wordIndex = 0; 
            memset(word,0,maxWordLength);
            done = 0; 
        }
        if (row[i] == '\t'){
             // language switch 
            tabHappend = 1; 
        }
    }
    printTuple(&tuple); 
    return &tuple; 
}

int transferString(char word[], int index, int lang, WordTuple *tuple) {
    if (index > sizeof(tuple->Hungarian)) {
        printf("Too many words"); 
        return 0; 
    }

    int size; 
    if (strlen(word) <= sizeof(tuple->Hungarian[index])) {
        printf("word = max");
        size = strlen(word); 
    } else {
        printf("tuple = max");
        size = sizeof(tuple->Hungarian[index]); 
    }
    
    for (int i = 0; i < size; i++) {
        if (lang == German) {
            tuple->German[index][i] = word[i]; 
        } else {
            tuple->Hungarian[index][i] = word[i]; 
        }
    }
    return 0; 
}

int printTuple(WordTuple *tuple) {
    for (int i = 0; i < sizeof(tuple->Hungarian); i ++) {
        if (tuple->Hungarian[i] != NULL) {
            printf("%s", tuple->Hungarian[i]); 
            printf("\n"); 
        }
    }
    for (int i = 0; i < sizeof(tuple->German); i ++) {
        if (tuple->German[i] != NULL) {
            printf("%s",tuple->German[i]); 
            printf("\n");
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