#include <GL/glut.h>      			

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);		
	glColor3f (0.0, 0.0, 1.0);			
	glLineWidth(2.0);			
	glMatrixMode (GL_PROJECTION);       	
	glLoadIdentity ();
	gluOrtho2D (0.0, 400.0, 0.0, 400.0);
}

void myDisplay (void)
{
	glClear (GL_COLOR_BUFFER_BIT);		// Clear display window.
	glShadeModel (GL_SMOOTH);
	glBegin (GL_POLYGON);			// Polygon with 4 vertices.
		glColor3f (1.0, 0.0, 1.0);		// Set color to red.
		glVertex2i (100, 100);		
		glColor3f (0.0, 1.0, 0.0);		// Set color to green.
		glVertex2i (300, 100); 		
		glColor3f (0.0, 0.0, 1.0);		// Set color to blue.
		glVertex2i (300, 300); 		
		glColor3f (1.0, 1.0, 0.0);		// Set color to yellow.
		glVertex2i (100, 300); 		
	glEnd ( );

	glFlush ( );     
}

void main (int argc, char** argv)
{
	glutInit (&argc, argv);                         			
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   	
	glutInitWindowPosition (50, 50);			
	glutInitWindowSize (400, 400);			
	glutCreateWindow ("Draw Texture Fill-Pattern Polygon"); 

	init ( );					
	glutDisplayFunc (myDisplay);		
	glutMainLoop ( );			
}
