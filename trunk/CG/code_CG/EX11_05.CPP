#include <GL/glut.h>

GLsizei winWidth = 500, winHeight = 500;   // Initial display-window size.

void init (void)
{

	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}

void display (void)
{
	glClearColor (1.0, 1.0, 0.0, 0.0);  
	glClear (GL_COLOR_BUFFER_BIT);     

	glColor3f (1.0, 0.0, 0.0);         
	glPointSize (4.0);                
}

void reshapeFcn (int newWidth, int newHeight)
{
	/*  Reset viewport and projection parameters  */
	glViewport (0, 0, newWidth, newHeight);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ( );
	gluOrtho2D (0.0, newWidth, 0.0, newHeight);

	/*  Reset display-window size parameters.  */
	winWidth = newWidth;
	winHeight = newHeight;
}

void plotPoint (int x, int y)
{
	glBegin (GL_POINTS);
		glVertex2i (x, y);
	glEnd ( );
}

void mouseFcn (int button, int action, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)
		plotPoint (x, winHeight - y);

	glFlush ( );
}

void main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition (100, 100);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize (winWidth, winHeight);
	glutCreateWindow ("Mouse Plot Points");
	init ( );
	glutDisplayFunc (display);
	glutReshapeFunc (reshapeFcn);
	glutMouseFunc (mouseFcn);
	glutMainLoop ( );
}