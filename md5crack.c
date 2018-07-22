#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <openssl/md5.h"

//#include <openssl/md5.h>
#define HASHSIZE 33
#define LISTSIZE 1

int crackHash(FILE *, char *);

int main(){
	int i = 0;
	char result[HASHSIZE];
    char targetHash[HASHSIZE];
    char passwords[HASHSIZE];
    char lists[LISTSIZE][HASHSIZE];
    strcpy(lists[i], "/lists/rockyou.txt");
    FILE *fp;
    int flag = 0;
    printf("Insert your MD5 Hash: ");
    scanf("%s", &targetHash);
    printf("\n");
    for(i = 0; i < LISTSIZE; i++){
        fp = fopen(lists[i], "r");
        flag = crackHash(fp, targetHash);
        if(flag == 1){
			return 0;
        }
    }
    system("COLOR 3");
    printf("NOT FOUND");
    return 0;
}

int crackHash(FILE *fp, char *targetHash){
    while(fp != NULL){
		char password[40];
        fscanf(fp, "%s", &password);
        if(targetHash == password){
            system("COLOR 5");
            printf("\nFOUND\n");
            printf("Hash: %s", targetHash);
            return 1;
        }
    }
    return 0;
}