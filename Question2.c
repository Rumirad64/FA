#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    int numOfPass = 0; 

    bool flag = true;
    while (flag)  //! PASSWORD LIST COUNT VALIDATION
    {
        printf("Enter the number of possible passwords : ");
        scanf("%d", &numOfPass);
        if (numOfPass < 1 || numOfPass > 100)
        {
            puts("Should be greater than 1 and lower than 100");
            puts("Please Re-enter !");
        }
        else
        {
            printf("You entered -> %d \n", numOfPass);
            flag = false;
        }
    }

    int row = numOfPass;
    const int col = 13;
    char grid[row][col]; //! Create 2d array for store inputs
    printf("Grid size: %d x %d \n", col, row);

    for (int i = 0; i < row; i++) //? erase 2d arr using (-) symbol
    {
        for (int j = 0; j < col; j++)
        {
            grid[i][j] = '-';
        }
    }
    flag = true;
    for (int i = 0; i < row; i++)
    {
        printf("Input the strings one by one : ");
        char input[13];
        scanf("%s", input);
        printf("Length of string is -> %zu \n", strlen(input));

        int input_length = strlen(input);

        if (input_length % 2 == 0) //! IF EVEN LENGTH , IGNORE IT AND RE-ENTER
        { //even
            printf("%s -> is even length and %d characters \n", input, input_length);
            printf("%s -> will be ignored \nPlease Re-enter ! \n", input);
            i--;
            continue;
        }
        else
        { //odd
            printf("%s is odd length and %d characters \n", input, input_length);
            for (int j = 0; j < input_length; j++)
            {
                grid[i][j] = input[j];
            }
        }
    }
    printf("\n");

    for (int i = 0; i < row; i++) //! DUMP THE ARRAY
    {
        for (int j = 0; j < col; j++)
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    int line = 0;
    while (line != row)
    {
        char selected[col];    //? SELECT EACH ROW AND REVERSE
        for (int j = 0; j < col; j++)
        {
            if (grid[line][j] == '-')
            {
                break;
            }
            selected[j] = grid[line][j];
        } 
        printf("Selected ->  %s \n", selected);
        strrev(selected);
        int char_len = strlen(selected);
        printf("Length of string is -> %zu \n", char_len);

        for (int i = 0; i < row; i++) //! COMPARE SELECTED STRING TO EACH STRINGS ONE BY ONE
        {
            char to_compare[col];
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '-') {
                    break;
                }
                to_compare[j] = grid[i][j];
                
                
            }
            printf("To compare ->  %s \n", to_compare);
            
            int matching_count = 0; // ?keep track matching chars
            for (int k = 0; k < char_len; k++) //? compare char one by one
            {
                printf("Comparing selected -> %c comparer -> %c \n",selected[k] , to_compare[k]);
                if(selected[k] == to_compare[k])
                {
                    printf("Matched selected -> %c comparer -> %c \n",selected[k] , to_compare[k]);
                    matching_count++;
                }
            }
            if(matching_count == char_len) //! IF match all chars 
            {
                printf("MATCHED ! AND FOUND ------> Selected %s toCompare %s \n",selected,to_compare);
                printf("LENGTH IS %d , MIDDLE CHAR IS %c \n",char_len,selected[char_len/2]);
                return 0;
            }
            //printf("Matched Selected %s toCompare %s \n",selected,to_compare);
            puts("for i ++");
        }
        line++;
        puts("While ++");
        //break;
    }
    return 0;
}