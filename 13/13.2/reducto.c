/*************************************************************************
	> File Name: reducto.c
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2021年07月04日 星期日 15时52分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])
{
	FILE *in;
	FILE *out;
	int ch;
	int count=0;
	char name[40];
	if(argc<2)
	{
		fprintf(stderr,"usage:%s filename.\n",argv[0]);
		exit(1);
	}
	if((in = fopen(argv[1],"r"))==NULL)
	{
		fprintf(stderr,"i couldn't open the file %s\n",argv[1]);
		exit(2);
	}
	strcpy(name,argv[1]);
	strcat(name,".red");
	if((out = fopen(name,"w")) == NULL)
	{
		fprintf(stderr,"can't create output file.\n");
		exit(3);
	}
	while((ch=getc(in))!=EOF)
	{
		if(count++%3==0)
			putc(ch,out);
	}
	if(fclose(in)!=0||fclose(out)!=0)
		fprintf(stderr,"error ouccur when closing file");
	return 0;
}

