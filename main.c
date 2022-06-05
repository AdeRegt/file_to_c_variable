#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv){
	if(argc==2){
		FILE *bestand = fopen(argv[1],"r");
		if(!bestand){
			printf("Cannot open file %s !\n",argv[1]);
			return EXIT_FAILURE;
		}
		fseek(bestand,0,SEEK_END);
		int filesize = ftell(bestand);
		fseek(bestand,0,SEEK_SET);
		printf("char buffer[0x%x] = {",filesize);
		for(int i = 0 ; i < filesize ; i++){
			if(i!=0){
				printf(",");
			}
			printf("0x%x",fgetc(bestand)&0xFF);
		}
		printf("};\n");
		fclose(bestand);
	}else{
		printf("Invalid amount of arguments! Expected: %s [filepath] \n",argv[0]);
	}
	return EXIT_SUCCESS;
}
