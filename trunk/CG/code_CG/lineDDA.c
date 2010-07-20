#include <stdlib.h>
#include <math.h>

inline int round (const float a)  { return int (a + 0.5); }

void lineDDA (int xStart, int yStart, int xEnd, int yEnd)
{
	int dx = xEnd - xStart,  dy = yEnd - yStart,  steps,  k;
	float xIncrement, yIncrement, x = xStart, y = yStart;

	if (fabs (dx) > fabs (dy))
		steps = fabs (dx);
	else
		steps = fabs (dy);

	xIncrement = float (dx) / float (steps);
	yIncrement = float (dy) / float (steps);

	setPixel (round (x), round (y));
	for (k = 0; k < steps; k++) 
	{
		x += xIncrement;
		y += yIncrement;
		setPixel (round (x), round (y));
	}
}
