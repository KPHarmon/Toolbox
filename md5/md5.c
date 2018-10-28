#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

/*Compile:	gcc -Wall md5.c -o md5 -lcrypto -lssl*/

char *str2md5(const char *str, int length){
	int n;
	MD5_CTX c;
	unsigned char digest[16];
	char *out = (char*)malloc(33); //allocate hash
	MD5_Init(&c); //initializes the MD5_CTX struct
	while (length > 0){//loops through the string, hashing chunks of size length
		if(length > 512)
			MD5_Update(&c, str, 512);
		else
			MD5_Update(&c, str, length);	
		length -= 512;
		str += 512;
	}
	MD5_Final(digest, &c);//makes sure there are 128 bits, and delete struct c
	for(n = 0; n < 16; ++n)//create result
		snprintf(&(out[n*2]), 16*2, "%02x", (unsigned int)digest[n]);
	return out;//return hash
}

int main(int argc, char **argv) {
	FILE *fp, *fp2;
	char *hash, targetHash[33];
	if(argc == 1){
		printf("Input your string: ");
		scanf("%s", targetHash);
		printf("The hash is %s\n", str2md5(targetHash, strlen(targetHash))); // print the hash
	}else{
		fp = fopen(argv[1], "r");
		fp2 = fopen("hashedfile.txt", "w");
		while(fscanf(fp, "%s", targetHash) == 1){
			hash = str2md5(targetHash, strlen(targetHash)); // hash the scanned word
			fprintf(fp2, "%s\n", hash);
		}
		printf("Hashed file created as \"hashedfile.txt\"\n");
	}	
}
