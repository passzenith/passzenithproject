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
    	GLfloat y, r, g, b;					// Define variables
	GLint count, color; 					// Define variables
	glClear (GL_COLOR_BUFFER_BIT);  			// Clear display-window.
	count = 1;
	for (y=25.0; y<=475.0; y+=25.0)
    	{
		color = count % 4;
		glLineWidth (y/25.0);				// Specify line width.
		if (color == 1)  
			{
				r=1.0;
				g=0.0;
				b=0.0;
			}
		else if (color == 2) 
			{
				r=0.0;
				g=1.0;
				b=0.0;
			}
		else if (color == 3) 
			{
				r=0.0;
				g=0.0;
				b=1.0;
			}
		else
			{
				r=0.0;
				g=0.0;
				b=0.0;
			}

		glBegin (GL_LINES);
			glColor3f (r, g, b);  			// Set line segment color.
			glVertex2f (50.0, y);       			// Specify first coordinate.
			glVertex2f (350.0, y);			// Specify second coordinate.
	    	glEnd ( );
		count++;
	}
    glFlush ( );     
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);                         			
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   	
	glutInitWindowPosition (50, 100);			
	glutInitWindowSize (400, 500);			
	glutCreateWindow ("Display variety of width and color of lines"); 
	init ( );					
	glutDisplayFunc (myDisplay);		
	glutMainLoop ( );	
    return 0;		
}
