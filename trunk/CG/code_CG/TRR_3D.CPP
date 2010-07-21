#include <GL/glut.h>	
#include <stdio.h>
#include <stdlib.h>		
#define ESCAPE 27

GLfloat xt=0.0, yt=0.0, zt=0.0;
GLfloat xs=1.0, ys=1.0, zs=1.0;
GLfloat xangle=20.0,yangle=20.0,zangle=20.0;  
GLint window;           			 

void init(void)
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0, 1.0, 1.0, 0.0);	
	glMatrixMode(GL_PROJECTION);		
    glOrtho(-6,6,-6,6,-6,6);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	
	// Anti-Alias
	glEnable (GL_LINE_SMOOTH);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glColor3f(1.0, 0.0, 0.0);				// Set color to blue.
	glBegin (GL_LINES);					// Draw x-axis
		glVertex3f (-5.5, 0.0, 0.0);
		glVertex3f ( 5.5, 0.0, 0.0);
	glEnd ( );

	glBegin (GL_LINES);					// Draw y-axis
		glVertex3f (0.0,-5.5, 0.0);
		glVertex3f (0.0, 5.5, 0.0);
	glEnd ( );

	glPushMatrix();
	glTranslatef(xt, yt, 0.0);			// Translation
	glScalef(xs, ys, 1.0);				// Scaling
	glRotatef(xangle, 1.0, 0.0, 0.0);		// Rotate x-axis
	glRotatef(yangle, 0.0, 1.0, 0.0);		// Rotate y-axis
	glRotatef(zangle, 0.0, 0.0, 1.0);		// Rotate z-axis
	glColor3f(0.0, 0.0, 1.0);				// Set color to blue.

	glutWireCube (2); 
	//glutWireTeapot (2); 
	
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

		case 't':
			xt += 0.2;                      						// xt = xt*2
			glutPostRedisplay();
			break;

		case 'T':
			yt += 0.2;                      						// xt = xt*2
			glutPostRedisplay();
			break;

		case 's':                    	 
			xs += 0.2; 						// Scale y up
			glutPostRedisplay();
			break;

		case 'S':                    	 
			ys += 0.2; 						// Scale y up
			glutPostRedisplay();
			break;

		case 'x':                          
			xangle += 10.0; 			// Rotate Counter ClockWise x-axis
			glutPostRedisplay();
			break;

		case 'y':                    	 
			yangle += 10.0; 			// Rotate Counter ClockWise y-axis
			glutPostRedisplay();
			break;

		case 'z':                    	 
			zangle += 10.0; 			// Rotate Counter ClockWise z-axis
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
	glutInitWindowPosition (50, 50)	;
	glutInitWindowSize(500, 500);		
	glutCreateWindow("t=tran x, T=tran y, s=scale x, S=scale y, x=rot x, y=rot y, z=rot z");		
	init();					
	glutDisplayFunc(myDisplay);		
	glutIdleFunc(myDisplay);
	glutKeyboardFunc(KeyboardAssign);
	glutMainLoop();	
    return 0;			
}
