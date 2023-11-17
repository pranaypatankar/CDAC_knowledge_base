#include <stdio.h>
#include <math.h>

double find_tan(double my_sin, double my_cos);

int main()
{
	double x = 90.89;

	double my_sin = sin(x);
	double my_cos = cos(x);

	double my_tan = find_tan(my_sin, my_cos);

	printf("my_sin = %.2f, my_cos = %.2f\n", my_sin, my_cos);
	printf("tan(%.2f) = %.2f\n", x, tan(x));
	printf("my_tan(%.2f) = %.2f\n", x, my_tan);

	return 0;
}	
