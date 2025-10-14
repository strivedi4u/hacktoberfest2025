#include<stdio.h>
void main(){
    char s[50];
    int  count1,count2;
    count1=0;
    count2=0;
    printf("Enter a string\n");
    scanf("%[^\n]s",s);
    for(int i=0;s[i]!='\0';i++){
        if(s[i]==42)
            count1++;
        else if(s[i]==35)
            count2++;
    }
    if(count1==count2)
        printf("Valid String\n");
    else
        printf("Invalid String\n");

}
