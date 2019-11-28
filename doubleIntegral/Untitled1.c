#include <stdio.h>
#include <math.h>

// C++ program to calculate
// double integral value


// Change the function according to your need
float givenFunction(float x, float y)
{
    return pow(x,2)/(1 + pow(y,2));
}


float wrty(int i, float lx, float ly, float ny, float h)
{
    float a = 0;
    for (int j = 0; j < ny; ++j) {
        if (j == 0 || j == ny - 1)
            a += givenFunction(lx + i * h, ly + j * h);
        else if (j % 2 == 0)
            a += 2 * givenFunction(lx + i * h, ly + j * h);
        else
            a += 4 * givenFunction(lx + i * h, ly + j * h);
    }
    a *= (h / 3);

    return a;
}


// Function to find the double integral value
float doubleIntegral(float h, float lx, float ux, float ly, float uy)
{
    int nx, ny;

    // Calculating the numner of points
    // in x and y integral
    nx = (ux - lx) / h + 1;
    ny = (uy - ly) / h + 1;

    float answer = 0;

    // Calculating the final integral value
    // using the integral obtained in the above step
    for (int i = 0; i < nx; ++i) {
        if (i == 0 || i == nx - 1)
            answer += wrty(i, lx, ly, ny, h);
        else if (i % 2 == 0)
            answer += 2 * wrty(i, lx, ly, ny, h);
        else
            answer += 4 * wrty(i, lx, ly, ny, h);
    }
    answer *= (h / 3);

    return answer;
}

// Driver Code
int main()
{
    // lx and ux are upper and lower limit of x integral
    // ly and uy are upper and lower limit of y integral
    // h is the step size for integration wrt x
    // h is the step size for integration wrt y
    float h, lx, ux, ly, uy;

    lx = 1, ux = 2, ly = 1,
	uy = 2, h = 0.004;

    printf("%f", doubleIntegral(h, lx, ux, ly, uy));
    return 0;
}
