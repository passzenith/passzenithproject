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

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	
	glBegin (GL_TRIANGLES);
		glEdgeFlag (GL_TRUE);		// Draw line after this function
		glVertex2i (100,250);
		glEdgeFlag (GL_FALSE);		// Do not draw line after this function.
		glVertex2i (200,300);
		glEdgeFlag (GL_TRUE);
		glVertex2i (200,200);

		glEdgeFlag (GL_TRUE);
		glVertex2i (250,400);
		glEdgeFlag (GL_FALSE);
		glVertex2i (300,300);
		glEdgeFlag (GL_TRUE);
		glVertex2i (200,300);

		glEdgeFlag (GL_TRUE);
		glVertex2i (400,250);
		glEdgeFlag (GL_FALSE);
		glVertex2i (300,200);
		glEdgeFlag (GL_TRUE);
		glVertex2i (300,300);

		glEdgeFlag (GL_TRUE);
		glVertex2i (250,100);
		glEdgeFlag (GL_FALSE);
		glVertex2i (200,200);
				glEdgeFlag (GL_TRUE);
		glVertex2i (300,200);

	glEnd ( );

	glFlush ( );     
}

void main (int argc, char** argv)
{
	glutInit (&argc, argv);                         		
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   	
	glutInitWindowPosition (50, 50);			
	glutInitWindowSize (500, 500);			
	glutCreateWindow ("Draw Polygon using function glEdgeFlag()"); 

	init ( );					
	glutDisplayFunc (myDisplay);		
	glutMainLoop ( );			
}
