#include <GL/glut.h>      		// (or others, depending on the system in use)

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);	// Set display-window color to white.
	glColor3f (0.0, 0.0, 1.0);		// Set point color to blue.
	glPointSize(4.0);				// Set Point size
	glMatrixMode (GL_PROJECTION);       		// Set projection parameters.
	glLoadIdentity ();
	gluOrtho2D (0.0, 400.0, 0.0, 300.0);
}

void myDisplay (void)
{
	glClear (GL_COLOR_BUFFER_BIT);  		// Clear display window.
	glBegin (GL_POINTS);
		glVertex2i (50,50);       			// Specify point(50,50).
		glVertex2i (100,100);			// Specify point(100,100).
		glVertex2i (100,150);			// Specify point(100,150).
		glVertex2i (200,200);			// Specify point(200,200).
		glVertex2i (250,150);			// Specify point(250,150).
	glEnd ( );
	glFlush ( );     		// Process all OpenGL routines as quickly as possible.
}

void main (int argc, char** argv)
{
	glutInit (&argc, argv);                         			// Initialize GLUT.
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   	// Set display mode.
	glutInitWindowPosition (50, 100);// Set top-left display-window position.
	glutInitWindowSize (400, 300);	// Set display-window width and height.
	glutCreateWindow (“Display 5 Points with OpenGL Program”);// Create display window.

	init ( );					// Execute initialization procedure.
	glutDisplayFunc (myDisplay);	// Send graphics to display window.
	glutMainLoop ( );			// Display everything and wait.
}
