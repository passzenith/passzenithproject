#include <GL/glut.h>	
#include <stdio.h>
#include <stdlib.h>				
#define ESCAPE 27

GLint window;           			

void init (void)
{
	glClearColor (1.0, 1.0, 1, 0.0);	
	glLineWidth(1.0);					
	glColor3f (1.0, 0.0, 0.0);			
	glMatrixMode (GL_PROJECTION);       
	glLoadIdentity ();
	glOrtho(-6,6,-6,6,-6,6);
}

void myDisplay (void)
{
	glClear (GL_COLOR_BUFFER_BIT);  	

	glPushMatrix();
	glBegin (GL_LINES);					// Draw x-axis
		glVertex2f (-5.5, 0.0);
		glVertex2f ( 5.5, 0.0);
	glEnd ( );
	
	glBegin (GL_LINES);					// Draw y-axis
		glVertex2f (0.0,-5.5);
		glVertex2f (0.0, 5.5);
	glEnd ( );

	glBegin (GL_LINES);					// Draw y=x
		glVertex2f (-5.5,-5.5);
		glVertex2f ( 5.5, 5.5);
	glEnd ( );

	glBegin (GL_POLYGON);
		glVertex2f (2.0, 3.0);
		glVertex2f (1.0, 5.0);
		glVertex2f (0.0, 4.0);
	glEnd ( );

	glBegin (GL_POLYGON);
		glVertex2f (-1.0, -5.0);
		glVertex2f (-2.0, -3.0);
		glVertex2f (-4.0, -5.0);
	glEnd ( );

	glPopMatrix();
	glutSwapBuffers();

	glFlush ( );     
}

void KeyboardAssign (GLubyte key, GLint x, GLint y) 
{
    switch ( key )    
	{ 
     case ESCAPE :
        printf("escape pressed. exit.\n");
		glutDestroyWindow(window);	
		exit(0); 				                 
        break;					

		     case 'x':                          
		glColor3f (0.0, 0.0, 1.0);	

		glPopMatrix();
		glRotatef(-45, 1.0, 1.0, 0.0);		
		glRotatef(180, 1.0, 1.0, 0.0);		
		glRotatef( 45, 1.0, 1.0, 0.0);		
		glPopMatrix();

  		glBegin (GL_POLYGON);
			glVertex2f (2.0, 3.0);
			glVertex2f (1.0, 5.0);
			glVertex2f (0.0, 4.0);
		glEnd ( );

		glBegin (GL_POLYGON);
			glVertex2f (-1.0, -5.0);
			glVertex2f (-2.0, -3.0);
			glVertex2f (-4.0, -5.0);
		glEnd ( );
		
		glutSwapBuffers();
        glutPostRedisplay();
        break;

     default:
	break;
    }
}


int main (int argc, char** argv)
{
	glutInit (&argc, argv);                       
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowPosition (50, 50);
	glutInitWindowSize(500, 500);	
	glutCreateWindow("Reflect y=x : Press x for reflect y=x");	
	init();				
	glutDisplayFunc(myDisplay);	
	glutIdleFunc(myDisplay);
	glutKeyboardFunc(KeyboardAssign);
	glutMainLoop();			
	return 0;
}
