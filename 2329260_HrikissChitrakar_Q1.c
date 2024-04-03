#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Variable declarations
    int x, y;
    int n = 0;         // Number of data points
    float sumX = 0.0;  // Sum of x values
    float sumY = 0.0;  // Sum of y values
    float sumXX = 0.0; // Sum of x squared
    float sumXY = 0.0; // Sum of x * y
    float a, b;        // Coefficients of the linear regression equation (y = b*x + a)

    // File pointers for input datasets
    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    FILE *fp4;

    // Open input files
    fp1 = fopen("datasetLR1.txt", "r");
    fp2 = fopen("datasetLR2.txt", "r");
    fp3 = fopen("datasetLR3.txt", "r");
    fp4 = fopen("datasetLR4.txt", "r");

    // Read data from the first dataset
    while (fscanf(fp1, "%d,%d", &x, &y) != EOF)
    {
        sumX += x;
        sumY += y;
        sumXX += x * x;
        sumXY += x * y;
        n++;
    }

    // Read data from the second dataset
    while (fscanf(fp2, "%d,%d", &x, &y) != EOF)
    {
        sumX += x;
        sumY += y;
        sumXX += x * x;
        sumXY += x * y;
        n++;
    }

    // Read data from the third dataset
    while (fscanf(fp3, "%d,%d", &x, &y) != EOF)
    {
        sumX += x;
        sumY += y;
        sumXX += x * x;
        sumXY += x * y;
        n++;
    }

    // Read data from the fourth dataset
    while (fscanf(fp4, "%d,%d", &x, &y) != EOF)
    {
        sumX += x;
        sumY += y;
        sumXX += x * x;
        sumXY += x * y;
        n++;
    }

    // Calculate coefficients for linear regression
    float b_num = ((n * sumXY) - (sumX * sumY));
    float b_den = ((n * sumXX) - (sumX * sumX));
    b = b_num / b_den;

    a = (sumY - b * sumX) / n;

    // Output results
    printf("a = %f\n", a);
    printf("b = %f\n", b);
    printf("Linear Regression Equation: y = %f * x + %f\n", b, a);
    printf("Sum of x values = %f, Sum of y values = %f, Sum of x squared = %f, Sum of x * y = %f, Number of data points = %d\n", sumX, sumY, sumXX, sumXY, n);

    // Get user input for x and calculate corresponding y
    float X;
    printf("Enter the value of x: ");
    scanf("%f", &X);

    float Y = b * X + a;
    printf("The value of y for x = %f: %f\n", X, Y);

    // Close input files
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);

    return 0;
}
