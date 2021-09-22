#include <stdio.h>
#include <string.h>
#include<stdbool.h> 
int main()
{
    const unsigned int MAX = 255;
    char user_input[MAX];

    char unique_chars[MAX];
    unsigned int top = 0; //* keep track of how much filled above array

    printf("please input a string : ");
    scanf("%s",user_input);
    
    unsigned int length = strlen(user_input); //? length of user input

    for (int i = 0; i < length; i++)
    {
        //? user_input[i] is having selected char
        if(i == 0) {    //?Because first char is always unique
            unique_chars[0] = user_input[0];
            top++;
            continue;
        }
        bool found = false;
        for (int k = 0; k < strlen(unique_chars); k++)
        {
            if(user_input[i] == unique_chars[k]) //! Duplicate found
            {
                found = true;
                //* keep track if found
            }
        }
        if(found == false)
        {
            unique_chars[top] = user_input[i];
            top++;
        }
        found = false; //? reset
    }
    printf("unique_chars -> %s     length -> %d \n",unique_chars , strlen(unique_chars));
    printf("user_input -> %s       length -> %d \n",user_input ,strlen(user_input));

    return 0;
}