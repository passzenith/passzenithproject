#include <GL/glut.h>

/*  Initialize Direction for spotlight */
void init(void) 
{
	GLfloat dirVector[] = { 1.0, 0.0, 0.0 };

	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH);

	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dirVector);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30.0);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 2.5);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSolidSphere (1.5, 32, 16);
	glFlush ();
}

void reshape (int w, int h)
{
	glViewport (0, 0, w, h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho (-2, 2, -2*h/w, 2*h/w, -10.0, 10.0);
   else
		glOrtho (-2*w/h, 2*w/h, -2, 2, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (500, 500); 
	glutInitWindowPosition (50, 50);
	glutCreateWindow ("Spotlight");
	init ();
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutMainLoop();
}