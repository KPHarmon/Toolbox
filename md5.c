#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>
#define LN 1

/*Compile: 	gcc -Wall md5.c -o md5 -lcrypto -lssl*/

char *str2md5(const char *str, int length){
	int n;
	MD5_CTX c;
	unsigned char digest[16];
	char *out = (char*)malloc(33);
	MD5_Init(&c);
	while (length > 0){
		if(length > 512){
			MD5_Update(&c, str, 512);
		} else{
			MD5_Update(&c, str, length);
		}
		length -= 512;
		str += 512;
	}
	MD5_Final(digest, &c);
	for(n = 0; n < 16; ++n){
		snprintf(&(out[n*2]), 16*2, "%02x", (unsigned int)digest[n]);
	}
	return out;
}

int main(int argc, char **argv) {
	FILE *fp;
	int flag;
	char targetHash[33], buffer[80];
	printf("Input your MD5 Hash: ");
	scanf("%s", targetHash);
	fp = fopen("/usr/share/wordlists/rockyou.txt", "r");
	while(fread(buffer, sizeof(buffer), 1, fp) == 1){
		char *check = str2md5(buffer, strlen(buffer));
		if(targetHash == check){
			printf("\a");
			printf("\nHash Decoded!\nThe answer is: %s\n", buffer);
			flag = 1;
			free(check);
			break;
		}
	}
	if(flag != 1){
		printf("Hash not found\n");		
	}
	return 0;
}
