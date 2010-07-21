#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>	
#define ESCAPE 27

GLfloat xt=1.0,yt=1.0;  
GLint window;           

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);	
	glLineWidth(2.0);				
	glMatrixMode (GL_PROJECTION);       
	glLoadIdentity ();
	gluOrtho2D (0.0, 500.0, 0.0, 500.0);
}

void myDisplay (void)
{
	glClear (GL_COLOR_BUFFER_BIT);  // Clear display window.

	glPushMatrix();
	glTranslatef(xt,yt,0.0);			// Translation
	glBegin (GL_POLYGON);
		glColor3f (1.0, 0.0, 0.0);		// Set color to red.
		glVertex2f ( 75.0, 50.0);
		glVertex2f (125.0, 50.0);
		glVertex2f (150.0,100.0);
		glVertex2f (100.0,125.0);
		glVertex2f ( 50.0,100.0);
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
			glutDestroyWindow(window);			// Kill our window 
			exit(0); 						             
		break;						

				case 'x':                          
			xt += 10.0; 					// Translate to right
			glutPostRedisplay();
		break;

		case 'X':
			xt -= 10.0;              					// Translate to left
			glutPostRedisplay();
		break;

		case 'y':                    	 
			yt += 10.0; 					// Translate up
			glutPostRedisplay();
		break;

     case 'Y':
			yt -= 10.0;              					// Translate down 
			glutPostRedisplay();
		break;

		case '2':
			xt *= 2.0;                      					// xt = xt*2
			yt *= 2.0;                      					// yt = yt*2
			glutPostRedisplay();
		break;

		case '3':
			xt *= 3.0;                      					// xt = xt*3
			yt *= 3.0;                      					// yt = yt*3
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
	glutCreateWindow("Translation : x=right, X=Left, y=up, Y=down, 2=Double, 3=Triple");	
	init();			
		glutDisplayFunc(myDisplay);	
	glutIdleFunc(myDisplay);
	glutKeyboardFunc(KeyboardAssign);
	glutMainLoop();	
    return 0;	
}
