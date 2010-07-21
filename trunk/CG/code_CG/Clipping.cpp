#include <GL/glut.h>      	

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);		
	glLineWidth(2.0);			
	glMatrixMode (GL_PROJECTION);      	
	glLoadIdentity ();
	gluOrtho2D (0.0, 300.0, 0.0, 300.0);
}

void myDisplay (void)
{
	glClear (GL_COLOR_BUFFER_BIT);  

	glBegin (GL_TRIANGLES);			// Center Triangle
		glColor3f (1.0, 0.0, 0.0);			
		glVertex2i (150,210);	  
		glVertex2i (210, 90);		
		glVertex2i ( 90, 90);		 
	glEnd ( );

	glBegin (GL_TRIANGLES);			// Top-right Triangle
		glColor3f (0.0, 0.0, 1.0);			
		glVertex2i (250,280);	  
		glVertex2i (330,240);		
		glVertex2i (250,200);		 
	glEnd ( );

	glBegin (GL_TRIANGLES);			// Bottom-left Triangle
		glColor3f (0.0, 1.0, 0.0);			
		glVertex2i ( 30, 50);	  
		glVertex2i ( 30,-50);		
		glVertex2i (-30,  0);		 
	glEnd ( );

	glBegin (GL_LINES);				// Top-left Line
		glColor3f (0.0, 1.0, 1.0);			
		glVertex2i ( 50,250);	  
		glVertex2i (-50,350);		
	glEnd ( );

	glBegin (GL_LINES);				// Bottom-right Line
		glColor3f (1.0, 0.0, 1.0);			
		glVertex2i (150,-50);	  
		glVertex2i (350, 90);		
	glEnd ( );

		glBegin (GL_QUADS);				// Center-left Quads
		glColor3f (1.0, 1.0, 0.0);			
		glVertex2i ( 50,200);	  
		glVertex2i ( 50,100);		
		glVertex2i (-50,100);	  
		glVertex2i (-50,200);		
	glEnd ( );


	glFlush ( );     
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);                        
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   
	glutInitWindowPosition (50, 100);			
	glutInitWindowSize (300, 300);			
	glutCreateWindow ("Clipped Objects"); 

	init ( );					
	glutDisplayFunc (myDisplay);		
	glutMainLoop ( );
    return 0;			
}
