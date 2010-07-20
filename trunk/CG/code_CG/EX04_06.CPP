#include <GL/glut.h>      			

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);		
	glColor3f (0.0, 0.0, 1.0);			
	glLineWidth(2.0);			
	glMatrixMode (GL_PROJECTION);       
	glLoadIdentity ();
	gluOrtho2D (0.0, 550.0, 0.0, 300.0);
}

void myDisplay (void)
{
	glClear (GL_COLOR_BUFFER_BIT);  

//	For function GL_QUADS.
	glBegin (GL_QUADS);		// 2 quads separate v0-v1-v2-v3 and v4-v5-v6-v7.
		glVertex2i (50,50); 		// v0      
		glVertex2i (80,200);		// v1
		glVertex2i (200,250);		// v2
		glVertex2i (200,50);		// v3
		glVertex2i (350,50);		// v4
		glVertex2i (350,250);		// v5
		glVertex2i (470,200);		// v6
		glVertex2i (500,50);		// v7
	glEnd ( );

	//	For function GL_QUAD_STRIP.
/*	glBegin (GL_QUAD_STRIP);// 2 quads strip v0-v1-v3-v2, v2-v3-v5-v4, v4-v5-v7-v6.
		glVertex2i (50,50);		// v0
		glVertex2i (80,200);		// v1
		glVertex2i (200,50);		// v2
		glVertex2i (200,250);		// v3
		glVertex2i (350,50);		// v4
		glVertex2i (350,250);		// v5
		glVertex2i (500,50);		// v6
		glVertex2i (470,200);		// v7
	glEnd ( );
*/
	glFlush ( );     
}

void main (int argc, char** argv)
{
	glutInit (&argc, argv);                         		
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   	
	glutInitWindowPosition (50, 100);			
	glutInitWindowSize (550, 300);			
	glutCreateWindow ("Draw Quad with OpenGL Program"); 

	init ( );					
	glutDisplayFunc (myDisplay);		
	glutMainLoop ( );			
}
