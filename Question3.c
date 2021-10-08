#include <stdio.h>
#include <string.h>

int main()
{
    int N;
    printf("Enter the length of the string :");
    scanf("%d", &N);
    if(N < 1 || N > 100){ //length constraint
        printf("Invalid length !");
        return 0;
    }

    char S[N];
    char T[N];

    printf("Enter string S : ");
    scanf("%s", S); //converting string

    printf("Enter string T : ");
    scanf("%s", T); //keeping this string same

    int count = 0;
    while (strcmp(T , S) != 0) { //until the strings become same
        char first = S[0];  //this character is used to append to the last
        for (int i = 0; i < N; i++){
            S[i] = S[i + 1];
        }
        S[N - 1] = first;
        count++;

        if(count > N){
            printf("Can't convert the string S into T\n");
            return 0;
        }
    }

    printf("%d\n",count);
    return 0;
}

