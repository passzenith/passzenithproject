#include <GL/glut.h>      			

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);		
	glLineWidth(2.0);			

	/*  Set parameters for world-coordinate clipping window.  */
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (-100.0, 100.0, -100.0, 100.0);

	/*  Set mode for constructing geometric transformation matrix.  */
	glMatrixMode (GL_MODELVIEW); 
	glLoadIdentity ();
}

void myDisplay (void)
{
	glClear (GL_COLOR_BUFFER_BIT);  

	glColor3f (0.0, 0.0, 1.0);       			// Set Color to blue
	glViewport (0, 0, 300, 300);			// Set Left Viewport    

	glBegin (GL_TRIANGLES);		
		glVertex2i (-50,-25);	  
		glVertex2i ( 50,-25);		
		glVertex2i (  0, 50);		 
	glEnd ( );


    /*  Rotate triangle and display in right half of display window.  */
    glColor3f (1.0, 0.0, 0.0);       			// Set Color to red  
    glViewport (300, 0, 300, 300);     			// Set Right Viewport 
    glRotatef (90.0, 0.0, 0.0, 1.0);   		// Rotate about z-axis 

	glBegin (GL_TRIANGLES);		
		glVertex2i (-50,-25);	  
		glVertex2i ( 50,-25);		
		glVertex2i (  0, 50);		 
	glEnd ( );

	glFlush ( );     
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);                         		
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   	
	glutInitWindowPosition (50, 100);			
	glutInitWindowSize (600, 300);			
	glutCreateWindow ("Split-Screen Example"); 

	init ( );					
	glutDisplayFunc (myDisplay);		
	glutMainLoop ( );		
    return 0;	
}
