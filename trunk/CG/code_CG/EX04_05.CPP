#include <GL/glut.h>      			

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);		
	glColor3f (0.0, 0.0, 1.0);			
	glLineWidth(2.0);			
	glMatrixMode (GL_PROJECTION);      	
	glLoadIdentity ();
	gluOrtho2D (0.0, 550.0, 0.0, 400.0);
}

void myDisplay (void)
{
	glClear (GL_COLOR_BUFFER_BIT);  

//	For function GL_TRIANGLES.
	glBegin (GL_TRIANGLES);	// 2 triangle separate v0-v1-v2 and v3-v4-v5.
		glVertex2i (230,50);		// v0    
		glVertex2i (50,50);		// v1 
		glVertex2i (80,200);		// v2 
		glVertex2i (230,250);		// v3 
		glVertex2i (380,200);		// v4 
		glVertex2i (410,50);		// v5 
	glEnd ( );


//	For function GL_TRIANGLE_STRIP.
/*	glBegin (GL_TRIANGLE_STRIP);// 4 strip v0-v1-v2, v2-v1-v3, v2-v3-v4, v4-v3-v5.
		glVertex2i (50,320);    		// v0    
		glVertex2i (50,50);		// v1 
		glVertex2i (230,320);		// v2 
		glVertex2i (320,50);		// v3 
		glVertex2i (410,320);		// v4 
		glVertex2i (500,50);		// v5 
	glEnd ( );
*/

//	For function GL_TRIANGLE_FAN.
/*	glBegin (GL_TRIANGLE_FAN);// 4 fan v0-v1-v2, v0-v2-v3, v0-v3-v4, v0-v4-v5 .
		glVertex2i (230,50);       		// v0 
		glVertex2i (50,50);		// v1 
		glVertex2i (80,200);		// v2 
		glVertex2i (230,250);		// v3 
		glVertex2i (380,200);		// v4 
		glVertex2i (410,50);		// v5 
	glEnd ( );
*/

	glFlush ( );     
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);                         		
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   	
	glutInitWindowPosition (50, 100);			
	glutInitWindowSize (550, 400);			
	glutCreateWindow ("Draw Triangle with OpenGL Program"); 

	init ( );					
	glutDisplayFunc (myDisplay);		
	glutMainLoop ( );	
    return 0;		
}
