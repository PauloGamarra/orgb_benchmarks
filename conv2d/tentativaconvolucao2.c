#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define I_WIDTH1 720
#define I_WIDTH2 1280
#define K_WIDTH1 3
#define K_WIDTH2 3

void convolution_2D(float I[I_WIDTH1][I_WIDTH2], float K[K_WIDTH1][K_WIDTH2], float O[I_WIDTH1][I_WIDTH2]) {

    for (int i = 0; i < I_WIDTH1; ++i)
    {
        for (int j = 1; j < I_WIDTH2-1; ++j)
        {
            if(i == 0 || i == I_WIDTH1 - 1 || j == 0 || j == I_WIDTH2 - 1)
            {
                O[i][j] = 0;
            }
            else
            {
                for (int m = -1; m <= 1; m++)
                {
                    for (int n = -1; n <= 1; n++)
                    {
                        O[i][j] += I[i+m][j+n] * K[1-m][1-n];
                    }
                }
            }
        }
    }
}


int main(){


    float I[I_WIDTH1][I_WIDTH2];

    float K[K_WIDTH1][K_WIDTH2] = {0, 1, 2,
                                   0, 1, 2,
                                   0, 1, 2};

    float O[I_WIDTH1][I_WIDTH2] ={};

    srand(time(0));
    for(int i =0; i<I_WIDTH1;i++)
        for(int j=0; j<I_WIDTH2;j++)
            I[i][j] = rand();


    convolution_2D(I, K, O);

    return 0;
}



