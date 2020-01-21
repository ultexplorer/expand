#include <stdio.h>
#define LIM 1000

void str_copy(char s2[], char s1[]);


int main()
{
    char s1[LIM]="--!---0---D----F---a------de----------g----~-----";
    char s2[LIM]=" ";
    str_copy(s2, s1);

    printf("%s\n", s2);

    return 0;
}

void str_copy(char s2[], char s1[])
{
    int i,j,k,n;  
    for(i=0, j=0; s1[i]!='\0'; ++i, ++j)
    {
        switch (s1[i])
        {
              case '-':            
                while(i!=0 && s1[i]=='-' && s1[i+1]!='\0')
                {
                  ++i;
                }
             default:
                s2[j]=s1[i];
        }
    }   
    s2[j]='\0';

    if(s2[0]=='-')  k=2;    
    else k=1;
       
    for(k; s2[k]!='\0'; ++k)
    {
        if(s2[k]-s2[k-1]>1)
        {        
            for(n=j; n>k; --n)
            {
                s2[n]=s2[n-1];
            }
            s2[k]=s2[k-1]+1;
            j++;
            s2[j]='\0';            
        }
    }        
}

