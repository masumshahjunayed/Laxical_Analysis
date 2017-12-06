#include<stdio.h>
#include<string.h>
#include<ctype.h>

void main()
{
    char expr[100],operators[20];
    char variables[20][20];
    int constants[20],ascii[100]={0};
    int cnt,i,number=0;
    int j=-1,k=-1,l=-1,n=0;
    int pr[10]={0},m=0;

    printf("\nLexical Analyzer\n\n");

    printf("Enter the String\n\n");

    scanf ("%[^\n]%*c", expr);

    cnt = strlen(expr);

    printf("\nString length: %d\n", cnt);

    for (i = 0; i < cnt; ++i)
    {
        ascii[i] = (int)expr[i];
    }

    for(i=0;i<cnt;++i)

    {

        if( isdigit(expr[i]) )
        {
            while(isdigit(expr[i]))
            {
                number=10*number+ ascii[i] -'0';
                i++;
            }
            j++;
            constants[j]=number;
            number=0;
        }

        if( isalpha(expr[i]) )
        {
            while( isalpha(expr[i]) || isdigit(expr[i]) || expr[i]=='_' )
            {
                k++;
                variables[m][k]=expr[i];
                i++;
            }
            m++;
            pr[n]=k;
            n++;
            k=-1;
        }

        if(expr[i]=='+'||expr[i]=='-'||expr[i]=='/'|| expr[i]=='*'|| expr[i]=='='|| expr[i]=='^')
        {
            l++;
            operators[l]= expr[i];
        }

    }

    printf("\nThe literals: \n\n");

    for(i=0;i<=j;i++)
    {
        printf("\tlit%d\t%d \n",i+1,constants[i]);
    }

    printf("\nThe operators: \n\n");

    for(i=0;i<=l;i++)
    {
        printf("\top%d\t%c\n",i+1,operators[i]);
    }

    printf("\nThe variables: \n\n");

    for(i=0;i<m;i++)
    {
        printf("\n\tid%d\t",i+1);
        for(j=0;j<=pr[i];j++)
        {
            printf("%c",variables[i][j]);
        }

    }

    printf("\n————– End of Lexical Analyzer ————\n\n");
}
