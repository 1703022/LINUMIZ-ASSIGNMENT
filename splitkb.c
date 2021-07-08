#define SEGMENT 1000
#include<string.h>
#include<stdio.h>
long file_size(char *name);
int main()
{
    int segments=0, i, len, accum;
    FILE *fp1, *fp2;
    char largeFileName[260];
    printf("enter name of the file:");
    gets(largeFileName);
    char filename[260];
    char smallFileName[260];
    char line[128];
    long sizeFile = file_size(largeFileName);
    segments = sizeFile/SEGMENT + 1;
    fp1 = fopen(largeFileName, "r");
    if(fp1)
    {
        for(i=0;i<segments;i++)        
{
            int accum = 0;
            sprintf(smallFileName, "filename%d.txt",i);
            fp2 = fopen(smallFileName, "w");
            if(fp2)
            {
                while(fgets(line, 128, fp1) && accum <= SEGMENT)
                {
                    accum += strlen(line);
                    fputs(line, fp2);
                }
                fclose(fp2);
            }
        }
        fclose(fp1);
    }
    return 0;
}

long file_size(char *name)
{
    FILE *fp = fopen(name, "rb"); 

    long size=-1;
    if(fp)
    {
        fseek (fp, 0, SEEK_END);
        size = ftell(fp)+1;
        fclose(fp);
    }
    return size;
}
