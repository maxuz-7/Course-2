#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main(int argc, char* argv[])
{
	int i=0, f1=0, f2=0, f3=0, f4=0, j=0, n, a=0, b=0, g=0, l=0, m;
	FILE* fd;
	char* s;
	char c[100][100];
	char d[1][100], r[1][100], t[1][100];
	if(argc<=1)
		{
			printf("Error");
			return 1;
		}
	if(argc>=3)
		{
			s=argv[1];
			while(s[i]!='\0')
			{
				if(s[i]=='c')
				f1++;
				if(s[i]=='o')
				f2++;
				if(s[i]=='n')
				f3++;
				if(s[i]=='f')
				f4++;
			i++;
			}
	}
	i=0;
	if(argc==2)
	{
		fd=fopen(argv[1], "r");
		while(fgets(c[i], 100, fd)!=NULL)
			i++;
		fclose(fd);
		n=i;
		for(i=0;i<n;i++)
		for(j=i;j<n;j++)
		{
			if(strcmp(c[i], c[j])>0)
			{
				strcpy(d[0], c[i]);
				strcpy(c[i], c[j]);
				strcpy(c[j], d[0]);
				for(m=0;m<100;m++)
			d[0][m]='\0';
			}
		}
		fd=fopen(argv[1], "w");
		i=0;
		for(i=0;i<n;i++)
			fputs(c[i], fd);
		fclose(fd);
		return 0;
	}
	fd=fopen(argv[2], "r");
	if(fd==NULL)
	{
	a=a+2;
	printf("%d", a);
	return 1;
	}
	while(fgets(c[i], 100, fd)!=NULL)
		i++;
	fclose(fd);
	n=i;
	if(f1>0)
	{
		for(i=0;i<n;i++)
		{
		for(j=i;j<n;j++)
			if(strcmp(c[i], c[j])>0)
			{
			a++;
			break;
			}
		if(a==1)
		break;
	}
	printf("%d", a);
	return 0;
	}
	if(f3>0)
	{
		for(g=0;g<n*n;g++)
		for(i=0;i<n-1;i++)
		{
			j=0;
			while(c[i][j]!=' ')
			j++;
			strncpy(r[0], c[i], j);
			b=atoi(r[0]);
			j=0;
			while(c[i+1][j]!=' ')
			j++;
			strncpy(t[0], c[i+1], j);
			l=atoi(t[0]);
			if(b>l)
			{
				strcpy(d[0], c[i+1]);
				strcpy(c[i+1], c[i]);
				strcpy(c[i], d[0]);
			}
			for(m=0;m<100;m++)
			{
			r[0][m]='\0';
			t[0][m]='\0';
		}
	}
	}
	if(f4>0)
	{
		fd=fopen(argv[2], "w");
		for(i=0;i<n;i++)
		{
			for(j=0;c[i][j]!='\0';j++)
			{
			if(c[i][j]>64 && c[i][j]<91)
			c[i][j]+=32;
			}
		}
		for(i=0;i<n;i++)
		for(j=i;j<n;j++)
		{
			if(strcmp(c[i], c[j])>0)
			{
				strcpy(d[0], c[i]);
				strcpy(c[i], c[j]);
				strcpy(c[j], d[0]);
			}
		}
	}
if(f2>0)
{
	fd=fopen(argv[3], "w");
	if(fd==NULL)
	{
		a=a+2;
		printf("%d", a);
		return 1;
	}
	for(i=0;i<n;i++)
			fputs(c[i], fd);
	fclose(fd);
}
else
{
	fd=fopen(argv[2], "w");
	for(i=0;i<n;i++)
			fputs(c[i], fd);
		fclose(fd);
}
return 0;
}




