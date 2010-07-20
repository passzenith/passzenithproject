#include <GL/glut.h>      

void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0); 
    glMatrixMode (GL_PROJECTION);      
    gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}

void myDisplay (void)
{
	GLfloat y;			
	GLfloat Size;		
	glClear (GL_COLOR_BUFFER_BIT); 
	glColor3f (0.0, 0.0, 1.0);      
	Size = 1.0;						
	for (y=10; y<=140; y+=15)
	{
		glLineWidth (Size);
		glBegin (GL_LINES);
			glVertex2i (20, y); 			// Set line-segment geometry     
			glVertex2i (180, y);
		glEnd ( );
		Size += 1.0f;
	}
	glFlush ( );     
}

void main (int argc, char** argv)
{
	glutInit (&argc, argv);                         
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   
	glutInitWindowPosition (50, 100);
	glutInitWindowSize (400, 300);     
	glutCreateWindow ("Set Line Width in OpenGL Program"); 

	init ( );                            
	glutDisplayFunc (myDisplay);      
	glutMainLoop ( );                    
}
