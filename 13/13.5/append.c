/*************************************************************************
	> File Name: append.c
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2021年07月04日 星期日 21时35分42秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SLEN 81
#define BUFSIZE 1024
void append(FILE *source,FILE *dest);
int main(void)
{
	FILE *fa;
	char file_app[SLEN];
	char file_src[SLEN];
	FILE *fs;
	int files;
	puts("enter name destination file:");
	gets(file_app);
    if((fa=fopen(file_app,"a"))==NULL)
	{
		fprintf(stderr,"can't open %s\n",file_app);
		exit(1);
	}
	puts("enter name of first sourse file(empty line to quit):");
	while(gets(file_src)&&file_src[0]!='\0')
	{
		if(strcmp(file_src,file_app)==0)
			fputs("can't append file to itself\n",stderr);
		else if((fs=fopen(file_src,"r"))==NULL)
			fprintf(stderr,"can't open %s\n",file_src);
		else
		{
			append(fs,fa);
			if(ferror(fs)!=0)
				fprintf(stderr,"error in reading file %s.\n",file_app);
			if(ferror(fa)!=0)
				fprintf(stderr,"error in writing file %s.\n",file_src);
			fclose(fs);
			files++;
			printf("File %s appended.\n",file_src);
			puts("next file(empty line to quit):");
		}
	}
	printf("Done.%d files append.\n",files);
	fclose(fa);
	return 0;
}
void append(FILE *source,FILE *dest)
{
	size_t bytes;
	static char temp[BUFSIZE];
	while((bytes=fread(temp,sizeof(char),BUFSIZE,source))>0)
		fwrite(temp,sizeof(char),bytes,dest);
}
