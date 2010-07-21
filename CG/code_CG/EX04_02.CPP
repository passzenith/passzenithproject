#define GL_PI 3.14159265f
#include <GL/glut.h>      		
#include <GL/gl.h>
#include <math.h>

const int screenWidth =640;
const int screenHeight =480; 

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);	// Set display-window color to white.
	glColor3f (0.0, 0.0, 1.0);		// Set point color to blue.
	glPointSize(2.0);				// Set Point size
	glMatrixMode (GL_PROJECTION);       		// Set projection parameters.
	glLoadIdentity ();
	gluOrtho2D (0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
}

void myDisplay (void)
{
	GLdouble A, B, C, D, x, func;
	A=screenWidth/4.0;
	B=0.0;
	C=screenHeight/2.0;
	D=C;
	glClear (GL_COLOR_BUFFER_BIT);  
	glBegin (GL_POINTS);
		// Plot red points to be a line for x-axis
		for (x=0; x<=screenWidth; x+=0.005)
		{
			glColor3f (1.0, 0.0, 0.0);		// Specify to red point
			glVertex2d (x, screenHeight/2.0);	// Plot points to be a line.
		}
		
		// Plot blue points from function
		for (x=0; x<=screenWidth ;x+=0.005)
		{
			glColor3f (0.0, 0.0, 1.0);		// Specify to blue point
			func = exp(-x) * cos(3*GL_PI*x);		// Function to be plotted
			glVertex2d (A*x+B, C*func+D);		// Command to plot function
		}
	glEnd ( );
	glFlush ( );     		
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);                         	
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   	
	glutInitWindowPosition (50, 50);			
	glutInitWindowSize (screenWidth, screenHeight);	
	glutCreateWindow ("Plot function using OpenGL");	

	init ( );					
	glutDisplayFunc (myDisplay);		
	glutMainLoop ( );	
    return 0;		
}
