#include <GL/glut.h>      			

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);		
	glColor3f (0.0, 0.0, 1.0);			
	glLineWidth(2.0);			
	glMatrixMode (GL_PROJECTION);       	
	glLoadIdentity ();
	gluOrtho2D (0.0, 500.0, 0.0, 500.0);
}

void myDisplay (void)
{
	glClear (GL_COLOR_BUFFER_BIT);  

	glBegin (GL_POLYGON);		// Polygon with 7 vertices.
		glVertex2i (100, 40);		// v0
		glVertex2i (40, 160); 		// v1
		glVertex2i (80, 300); 		// v2
		glVertex2i (220, 450); 		// v3
		glVertex2i (360, 400); 		// v4
		glVertex2i (440, 160); 		// v5
		glVertex2i (340, 60); 		// v6
	glEnd ( );

		glFlush ( );     
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);                         			
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   	
	glutInitWindowPosition (50, 50);			
	glutInitWindowSize (500, 500);			
	glutCreateWindow ("Draw Polygon with OpenGL Program"); 

	init ( );					
	glutDisplayFunc (myDisplay);		
	glutMainLoop ( );	
    return 0;		
}
