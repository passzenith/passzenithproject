#include <GL/glut.h>	
#include <stdio.h>
#include <stdlib.h>				
#define ESCAPE 27

GLfloat xangle=0.0,yangle=0.0,zangle=0.0;  
GLint window;           			

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);	
	glLineWidth(2.0);				
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


	glRotatef(xangle,1.0,0.0,0.0);			// Rotate x-axis
	glRotatef(yangle,0.0,1.0,0.0);			// Rotate y-axis
	glRotatef(zangle,0.0,0.0,1.0);			// Rotate z-axis
	glBegin (GL_POLYGON);
		glColor3f (1.0, 0.0, 0.0);			// Set color to red.
		glVertex2f (2.0, 1.0);
		glVertex2f (4.0, 1.0);
		glVertex2f (5.0, 3.0);
		glVertex2f (3.0, 4.0);
		glVertex2f (1.0, 3.0);
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
			xangle += 10.0; 			// Rotate Counter ClockWise x-axis
			glutPostRedisplay();
		break;

     case 'X':
			xangle -= 10.0;			// Rotate ClockWise x-axis
			glutPostRedisplay();
		break;

				case 'y':                    	 
			yangle += 10.0; 			// Rotate Counter ClockWise y-axis
			glutPostRedisplay();
		break;

		case 'Y':
			yangle -= 10.0;          			// Rotate ClockWise y-axis
			glutPostRedisplay();
		break;

		case 'z':                    	 
			zangle += 10.0; 			// Rotate Counter ClockWise z-axis
			glutPostRedisplay();
		break;

		case 'Z':                    	 
			zangle -= 10.0; 			// Rotate ClockWise z-axis
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
	glutCreateWindow("Rotation : x=CCW-x, X=CW-x, y=CCW-y, Y=CW-y, z=CCW-z,         Z=CW-z");	
	init();				
	glutDisplayFunc(myDisplay);	
	glutIdleFunc(myDisplay);
	glutKeyboardFunc(KeyboardAssign);
	glutMainLoop();	
    return 0;		
}
