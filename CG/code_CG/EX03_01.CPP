#include <GL/glut.h>      // (or others, depending on the system in use)

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);  	// Set display-window color to white.
	glLineWidth (4.0);				// Set Line width to 4.0 pixel
	glMatrixMode (GL_PROJECTION);       		// Set projection parameters.
	gluOrtho2D (0.0, 300.0, 0.0, 300.0);
}

void LineAndRectangle (void)
{
	glClear (GL_COLOR_BUFFER_BIT);			// Clear display-window.
	glColor3f (0.0, 0.0, 1.0);			// Set object color to blue.		glRectf(180.0, 180.0, 280.0, 280.0);	// Draw rectangle
	glRectf(180.0, 180.0, 280.0, 280.0);	// Draw rectangle
	glBegin (GL_LINES);
		glColor3f (1.0, 0.0, 0.0);      		// Set line segment color to red.
		glVertex2i (20, 20);			// Specify first vertex of line.
		glVertex2i (150, 150);			// Specify second vertex of line.
    glEnd ( );

	glFlush ( );     		// Process all OpenGL routines as quickly as possible.
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);                         					// Initialize GLUT.
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   	// Set display mode.
	glutInitWindowPosition (50, 100);// Set top-left display-window position.
	glutInitWindowSize (400, 400);      	// Set display-window width and height.
	glutCreateWindow ("An Example OpenGL Program"); // Create display window.
	init ( );                            				// Execute initialization procedure.
	glutDisplayFunc (LineAndRectangle);       	// Send graphics to display window.
	glutMainLoop ( );                    				// Display everything and wait.
	return 0;
}
