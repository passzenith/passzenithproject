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
	glShadeModel (GL_SMOOTH);

	for (y=40.0; y<=80.0; y+=20.0)
    {
		glLineWidth (y/5.0);

		glBegin (GL_LINES);
			
			// Set color from Red —> Green.
			glColor3f (1.0, 0.0, 0.0);  	// Set line segment color to red.
			glVertex2f (50.0, y);		// Specify first coordinate.
			glColor3f (0.0, 1.0, 0.0);  	// Set line segment color to green.
			glVertex2f (350.0, y);		// Specify second coordinate.
			
			//  Set color from Green —> Blue.
			glColor3f (0.0, 1.0, 0.0);  	// Set line segment color to green.
			glVertex2f (50.0, y+100.0); 	// Specify first coordinate.
			glColor3f (0.0, 0.0, 1.0);  	// Set line segment color to blue.
			glVertex2f (350.0, y+100.0);	// Specify second coordinate.
	    
			//  Set color from Blue —> Red.
			glColor3f (0.0, 0.0, 1.0);  	// Set line segment color to blue.
			glVertex2f (50.0, y+200.0); 	// Specify first coordinate.
			glColor3f (1.0, 0.0, 0.0);  	// Set line segment color to red.
			glVertex2f (350.0, y+200.0);	// Specify second coordinate.
	    
			//  Set color from Black —> White.
			glColor3f (0.0, 0.0, 0.0);  	// Set line segment color to black.
			glVertex2f (50.0, y+300.0); 	// Specify first coordinate.
			glColor3f (1.0, 1.0, 1.0);  	// Set line segment color to white.
			glVertex2f (350.0, y+300.0);	// Specify second coordinate.
					//  Set color from White —> Red.
			glColor3f (1.0, 1.0, 1.0);  	// Set line segment color to white.
			glVertex2f (50.0, y+400.0); 	// Specify first coordinate.
			glColor3f (1.0, 0.0, 0.0);  	// Set line segment color to red.
			glVertex2f (350.0, y+400.0);	// Specify second coordinate.
		glEnd ( );
	}
		glFlush ( );     
}

void main (int argc, char** argv)
{
	glutInit (&argc, argv);                         		
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);	
	glutInitWindowPosition (100, 100);		
	glutInitWindowSize (400, 400);		
	glutCreateWindow ("Display color effect of lines"); 	
	init ( );					
	glutDisplayFunc (myDisplay);		
	glutMainLoop ( );			
}
