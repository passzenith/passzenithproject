#include <GL/glut.h>      			

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);		
	glMatrixMode (GL_PROJECTION);       	
	glLoadIdentity ();
	gluOrtho2D (0.0, 400.0, 0.0, 500.0);
}

void myDisplay (void)
{
	GLfloat y;
	glClear (GL_COLOR_BUFFER_BIT);  
	for (y=25.0; y<=475.0; y+=25.0)
	{
		glPointSize (y/25);				// Set Point size
		glBegin (GL_POINTS);
			glColor3f (1.0, 0.0, 0.0);		// Set point color to red.
			glVertex2i (50.0, y);       			// Specify point(50,y).
			glColor3f (0.0, 1.0, 0.0);		// Set point color to green.
			glVertex2i (100.0, y);			// Specify point(100,y).
			glColor3f (0.0, 0.0, 1.0);		// Set point color to blue.
			glVertex2i (150.0, y);			// Specify point(150,y).
			glColor3f (1.0, 1.0, 0.0);		// Set point color to yellow.
			glVertex2i (200.0, y);			// Specify point(200,y).
			glColor3f (1.0, 0.0, 1.0);		// Set point color to magenta.
			glVertex2i (250.0, y);			// Specify point(250,y).
			glColor3f (0.0, 1.0, 1.0);		// Set point color to cyan.
			glVertex2i (300.0, y);			// Specify point(300,y).
			glColor3f (0.0, 0.0, 0.0);		// Set point color to black.
			glVertex2i (350.0, y);			// Specify point(350,y).
		glEnd ( );
	}
	glFlush ( );     			
}

void main (int argc, char** argv)
{
	glutInit (&argc, argv);                         			
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   	
	glutInitWindowPosition (50, 100);			
	glutInitWindowSize (400, 500);			
	glutCreateWindow ("Display varity of size and color points"); 
	init ( );				
	glutDisplayFunc (myDisplay);		
	glutMainLoop ( );		
}
