#include <GL/glut.h>

void init(void) 
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glShadeModel (GL_FLAT);
}

void display(void)
{
	GLdouble eqn[4] = {0.0, 1.0, 0.0, 0.0};
	GLdouble eqn2[4] = {1.0, 0.0, 0.0, 0.0};

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f (0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef (0.0, 0.0, -5.0);

/*    clip lower half — y < 0          */
	glClipPlane (GL_CLIP_PLANE0, eqn);
	glEnable (GL_CLIP_PLANE0);
/*    clip left half — x < 0           */
	glClipPlane (GL_CLIP_PLANE1, eqn2);
	glEnable (GL_CLIP_PLANE1);
	glRotatef (90.0, 1.0, 0.0, 0.0);
	glutWireSphere(2.0, 20, 16);
	glPopMatrix();
	glFlush ();
}

void reshape (int w, int h)
{
	glViewport (0, 0, w, h); 
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(60.0, w/h, 1.0, 20.0);
	glMatrixMode (GL_MODELVIEW);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500); 
	glutInitWindowPosition (50, 50);
	glutCreateWindow ("Clip 3D Sphere");
	init ();
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutMainLoop();
}
