#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LEN 100

int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    char ch, str[MAX_LEN], sen[MAX_LEN];
    scanf("%c%*c", &ch);
    scanf("%s%*c", &str);
    scanf("%[^\n]", &sen);
    
    printf("%c\n%s\n%s", ch, str, sen);
    return 0;
}
