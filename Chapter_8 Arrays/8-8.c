#include <stdio.h>

int safe(int chess[8][8], int x, int y)
{
    int index;
    for(index = 0; index < 8; ++index)
    {
        if(chess[x][index])
            return 0;
        if(index < x && chess[index][y])
            return 0;
        if(x >= index && y >= index && chess[x - index][y - index])
            return 0;
        if(x >= index && (y + index) < 8 && chess[x - index][y + index])
            return 0;
    }
    return 1;
}

int print_chess(int chess[8][8])
{
    int x, y;
    static int total = 0;
    printf("%s\n", ++total);
    for(x = 0; x < 8; ++x)
    {
        for(y = 0; y < 8; ++y)
            printf("%-3d", chess[x][y]);
        printf("\n");
    }
    printf("\n");
}

int eight_queen(int chess[8][8], int x)
{
    for(int index = 0; index < 8; ++index)
    {
        if(safe(chess, x, index))
        {
            chess[x][index] = 1;
            if(x == 7)
                print_chess(chess);
            else
                eight_queen(chess, x + 1);
        }
        chess[x][index] = 0;
    }
}

int main()
{
    int chess[8][8] = {0};
    eight_queen(chess, 0);
    return 0;
}
