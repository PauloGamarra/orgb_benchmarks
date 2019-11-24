#include <stdio.h>

#define I_WIDTH1 5
#define I_WIDTH2 5
#define K_WIDTH1 3
#define K_WIDTH2 3

int main(){

    for (int m = -1; m <= 1; m++)
    {
        printf("%d",m);
    }

    float I[I_WIDTH1][I_WIDTH2] = {10, 20, 30, 40, 50,
                                   10, 220, 222, 218, 10,
                                   10, 86, 222, 226, 10,
                                   10, 85, 221, 224, 10,
                                   10, 10, 10, 10, 10};

    float K[K_WIDTH1][K_WIDTH2] = {0, 1, 2,
                                   0, 1, 2,
                                   0, 1, 2};

    float O[I_WIDTH1][I_WIDTH2] ={};

    convolution_2D(I, K, O);

    for(int i=0;i<I_WIDTH1;i++){
       for(int j=0;j<I_WIDTH2;j++){
            printf("%f\t", O[i][j]);
        }
        printf("\n");
    }

    return;
}


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

