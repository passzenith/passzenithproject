#include <GL/glut.h>      			

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);		
	glColor3f (0.0, 0.0, 1.0);			
	glLineWidth(4.0);			
	glMatrixMode (GL_PROJECTION);       
	glLoadIdentity ();
	gluOrtho2D (0.0, 400.0, 0.0, 400.0);
}

void myDisplay (void)
{

	glClear (GL_COLOR_BUFFER_BIT);  

	//	For function GL_LINES.
	glBegin (GL_LINES);						// Draw 3 lines.
		glVertex2i (50, 50);       
		glVertex2i (60, 350);
		glVertex2i (75, 50);       
		glVertex2i (125, 350);
		glVertex2i (100, 50);       
		glVertex2i (175, 350);
	glEnd ( );

	// With Anti-Alias function
	glEnable (GL_LINE_SMOOTH);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin (GL_LINES);						// Draw 3 lines.
		glVertex2i (350, 50);       
		glVertex2i (340, 350);
		glVertex2i (325, 50);       
		glVertex2i (275, 350);
		glVertex2i (300, 50);       
		glVertex2i (225, 350);
	glEnd ( );


	glFlush ( );     
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);                         	
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   	
	glutInitWindowPosition (50, 100);			
	glutInitWindowSize (400, 400);			
	glutCreateWindow ("Draw lines with Anti-Alias"); 

	init ( );					
	glutDisplayFunc (myDisplay);		
	glutMainLoop ( );
    return 0;			
}
