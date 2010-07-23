#include <GL/glut.h>
#include <stdlib.h>

static int leftFirst = GL_TRUE;

/*  Initialize alpha blending function.*/

void init(void)
{
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel (GL_FLAT);
	glClearColor (1.0, 1.0, 1.0, 0.0);
}

void drawLeftTriangle(void)
{
	/* Draw red triangle on LHS of screen */

	glBegin (GL_TRIANGLES);
		glColor4f(1.0, 0.0, 0.0, 0.7);
		glVertex3f(0.1, 0.9, 0.0); 
		glVertex3f(0.1, 0.1, 0.0); 
		glVertex3f(0.7, 0.5, 0.0); 
	glEnd();
}

void drawRightTriangle(void)
{
	/* Draw green triangle on RHS of screen */

	glBegin (GL_TRIANGLES);
		glColor4f(0.0, 1.0, 0.0, 0.7);
		glVertex3f(0.9, 0.9, 0.0); 
		glVertex3f(0.3, 0.5, 0.0); 
		glVertex3f(0.9, 0.1, 0.0); 
	glEnd();
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

   if (leftFirst) 
	{
		drawLeftTriangle();
		drawRightTriangle();
   }
   	else 
	{
		drawRightTriangle();
		drawLeftTriangle();
   }

	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h) 
		gluOrtho2D (0.0, 1.0, 0.0, 1.0*h/w);
   else 
		gluOrtho2D (0.0, 1.0*w/h, 0.0, 1.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
		case 't':
		case 'T':
			leftFirst = !leftFirst;
			glutPostRedisplay();	
			break;
		case 27:  				/*  Escape key  */
			exit(0);
			break;
		default:
			break;
   }
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (50, 50);	
	glutCreateWindow ("Draws several overlapping filled polygons —> t = togle");
	init();
	glutReshapeFunc (reshape);
	glutKeyboardFunc (keyboard);
	glutDisplayFunc (myDisplay);
	glutMainLoop();
	return 0;
}
