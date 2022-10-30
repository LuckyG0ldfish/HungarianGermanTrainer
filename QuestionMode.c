#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

char *filename = "database.txt"; 
int number = 20; 
int length = 200; 

typedef struct {
    char Hungarian[20];
    char German[20];
} WordTuple;

WordTuple List[20]; 

int RunQuestionMode() {
    List[5].Hungarian; 
    return 0; 
}

int fillList() {
    int c;
    FILE *file;
    file = fopen("test.txt", "r");
    if (file) {
        int *rngInts = RandomInts(number, length); 
        int i = 0; 
        int countNewLine = 0;  
        int countTab = 0;  
        int check = 0;
        char row[100]; 
        while ((c = getc(file)) != EOF) {
            if (isspace(c)) {
                if (c == "\n") {
                    countNewLine++;
                    if (check == 1) {
                        if ((i+1) >= number) {
                            break; 
                        } else {
                            i++; 
                            // TODO: add new row 
                        } 
                    }
                }
                if (countNewLine == rngInts[i]) {
                    check = 1; 
                    strcpy(row, tolower(c)); 
                }
            }
        }
        fclose(file);
    }
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int *RandomInts(int amount, int limit) {
    int list[amount]; 
    srand(time(NULL));   
    for (int i = 0; i < amount; i ++) {
        list[i] = rand()% (limit-1); 
    }
    qsort(list, amount, sizeof(int), cmpfunc); 
    return list; 
}

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