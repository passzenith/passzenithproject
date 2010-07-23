#include <GL/glut.h>	
#include <stdio.h>
#include <stdlib.h>			
#define ESCAPE 27

GLfloat xs=1.0,ys=1.0;  
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
	glClear (GL_COLOR_BUFFER_BIT);  

	glPushMatrix();
	glScalef(xs,ys,1.0);					// Scaling
	glBegin (GL_POLYGON);
		glColor3f (1.0, 0.0, 0.0);				// Set color to red.
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
			glutDestroyWindow(window);		
			exit(0); 					                   
		break;						

     case 'x':                          
			xs += 0.2; 						// Scale x up
			glutPostRedisplay();
		break;

     case 'X':
			xs -= 0.2;              						// Scale x down 
        glutPostRedisplay();
		break;

		case 'y':                    	 
			ys += 0.2; 						// Scale y up
			glutPostRedisplay();
		break;

		     case 'Y':
			ys -= 0.2;              						// Scale y down 
			glutPostRedisplay();
		break;

     case '2':
			xs *= 2.0;                      						// xs = xs*2
			ys *= 2.0;           						// ys = ys*2
			glutPostRedisplay();
		break;

		case '3':
			xs *= 3.0;                      						// xs = xs*3
			ys *= 3.0;                      						// ys = ys*3
        glutPostRedisplay();
		break;

		case '-':
			xs /= 2.0;                      						// xs = xs/2
			ys /= 2.0;                      						// ys = ys/2
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
	glutCreateWindow("Scaling : x=x up, X=x down, y=y up, Y=y down, 2=Double, 3=Triple, -=Double Down");	
	init();			
	glutDisplayFunc(myDisplay);	
	glutIdleFunc(myDisplay);
	glutKeyboardFunc(KeyboardAssign);
	glutMainLoop();	
    return 0;	
}
