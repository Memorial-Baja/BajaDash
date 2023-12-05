#include <stdio.h>
#include <math.h>

void calculateSemiCircle(double centerX, double centerY, double radius, double startAngle, double endAngle, double stepSize) {
	// Convert angles to radians
	startAngle = startAngle * M_PI / 180.0;
	endAngle = endAngle * M_PI / 180.0;

	// Calculate the number of steps
	int numSteps = ceil((endAngle - startAngle) / stepSize);

	// Calculate the angle increment per step
	double angleIncrement = (endAngle - startAngle) / numSteps;

	// Calculate and print the coordinates
	printf("Coordinates on the semi-circle:\n");
	for (int i = 0; i <= numSteps; i++) {
		double angle = startAngle + i * angleIncrement;
		double x = centerX + radius * cos(angle);
		double y = centerY + radius * sin(angle);
		printf("x = %lf, y = %lf\n", x, y);
	}
}

int main() {
	double centerX, centerY, radius, startAngle, endAngle, stepSize;

	printf("Enter the center coordinates (x, y) of the semi-circle: ");
	scanf("%lf %lf", &centerX, &centerY);

	printf("Enter the radius of the semi-circle: ");
	scanf("%lf", &radius);

	printf("Enter the start angle (in degrees) of the interval: ");
	scanf("%lf", &startAngle);

	printf("Enter the end angle (in degrees) of the interval: ");
	scanf("%lf", &endAngle);

	printf("Enter the step size (in degrees) for the interval: ");
	scanf("%lf", &stepSize);

	calculateSemiCircle(centerX, centerY, radius, startAngle, endAngle, stepSize);

	return 0;
}
