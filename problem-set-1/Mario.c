#include <stdio.h>
#include <cs50.h>

void buildPyramid(int height);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    buildPyramid(height);
}


void buildPyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int k = height - i; k > 1; k--)
        {
            printf(" ");
        }
        
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
