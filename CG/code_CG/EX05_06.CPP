#include <GL/glut.h>      			

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);		
	glLineWidth(2.0);			
	glMatrixMode (GL_PROJECTION);       
	glLoadIdentity ();
	gluOrtho2D (0.0, 500.0, 0.0, 500.0);
}

void myDisplay (void)
{
	glClear (GL_COLOR_BUFFER_BIT);  

	glBegin (GL_POLYGON);
		glColor3f (1.0, 0.0, 0.0);			// Set color to red.
		glVertex2i (100,350);
		glColor3f (0.0, 1.0, 0.0);			// Set color to green.
		glVertex2i (250,450);
		glColor3f (0.0, 0.0, 1.0);			// Set color to blue.
		glVertex2i (400,350);
		glColor3f (1.0, 0.0, 1.0);			// Set color to magenta.
		glVertex2i (400,150);
		glColor3f (1.0, 1.0, 0.0);			// Set color to yellow.
		glVertex2i (250,50);
		glColor3f (0.0, 1.0, 1.0);			// Set color to cyan.
		glVertex2i (100,150);

	glEnd ( );

	glFlush ( );     
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);                         		
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   	
	glutInitWindowPosition (50, 50);			
	glutInitWindowSize (500, 500);			
	glutCreateWindow ("Draw Polygon using color effect"); 

	init ( );					
	glutDisplayFunc (myDisplay);		
	glutMainLoop ( );
    return 0;			
}
