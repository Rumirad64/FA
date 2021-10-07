#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    unsigned int length = 0;
    printf("Enter the length of the string :");
    scanf("%d", &length);
    printf("length is -> %d \n",length);
    if(length < 1 || length > 100)
    {
        printf("Invalid length !");
        return 0;
    }

    char str_s[length];
    char str_t[length];

    printf("Enter string S : ");
    scanf("%s", str_s); 

    printf("Enter string T : ");
    scanf("%s", str_t);//? remains same

    unsigned int iteration_count = 0;
    while (strcmp(str_t , str_s) != 0) //? iterate until equal
    {
        //printf("str_t ->  %s \n",str_s); //! DEBUG INFO
        char first = str_s[0];
        for (int i = 0; i < length; i++)
        {
            str_s[i] = str_s[i + 1];
        }
        str_s[length - 1] = first;
        iteration_count++;

        if(iteration_count > length)
        {
            printf("Cant convert the string S into T \n");
            return 0;
        }
    }
    //printf("str_s -> %s \t\t str_t %s \n",str_s,str_t); //! DEBUG INFO
    //printf("Number of iteration -> %d \n",iteration_count); //! DEBUG INFO

    printf(" %d \n",iteration_count); //! OUTPUT
    return 0;
}