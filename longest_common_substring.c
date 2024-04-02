#include<stdio.h>
#include<string.h>
int LongestString(char s1[], char s2[]){
    // printf("\n%s %s", s1, s2);
    int longest_suff[strlen(s1)][strlen(s2)];
    int result = 0, i, j;
    for(i = 0; i<=strlen(s1);i++){
        for(j =0; j<=strlen(s2); j++){
            if(i==0 || j==0){
                longest_suff[i][j] = 0;
            }else if(s1[i-1] == s2[j-1]){
                longest_suff[i][j] = longest_suff[i-1][j-1]+1;
                if(longest_suff[i][j] > result){
                    result = longest_suff[i][j];
                }
            }else{
                longest_suff[i][j] = 0;
            }
            printf("%d ", longest_suff[i][j]);
        }
        printf("\n");
    }
    return result;
}

int main(){
    char str1[] = "atrng2";
    char str2[] = "string2"; 
    // printf("%s %s", str1, str2);
    printf("%d", LongestString(str1, str2));
    return 0;
}
