#include <GL/glut.h>
int shape;
int color;

void init(void)
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.5, 0.5, 0.5, 0.0);	// Set display-window color to light gray
	glColor3f(1.0, 1.0, 1.0);	
	glMatrixMode(GL_PROJECTION);	
	glRotatef (30.0, 0.0, 1.0, 1.0);
      glOrtho(-50,50,-50,50,-50,50);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mainMenu (int option)
{
	switch (option) 
	{
		case 1: glClearColor (1.0, 1.0, 1.0, 0.0);  break;	// White background
		case 2: glClearColor (1.0, 1.0, 0.0, 0.0);  break;	// Yellow background
	}
	glutPostRedisplay ( );
}

void colorFcn (int item)
{
	color = item;
	glutPostRedisplay();
}

void shapeFcn (int item)
{
	shape = item;
	glutPostRedisplay();
}

void display (void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear display window.
	
	glEnable (GL_LINE_SMOOTH);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	switch (color)
	{
		case 1: glColor3f (1.0, 0.0, 0.0);	 break;	// Set color to red
		case 2: glColor3f (0.0, 1.0, 0.0);	 break;	// Set color to green
		case 3: glColor3f (0.0, 0.0, 1.0);	 break;	// Set color to blue
		case 4: glColor3f (0.0, 0.0, 0.0);	 break;	// Set color to black
	}

	switch (shape)
	{
		case 1 : glutWireTorus (5, 20, 10, 10); break;	// Draw wireTorus
		case 2 : glutWireSphere (30, 50, 20);  break; // Draw wireSphere
		case 3 : glutWireTeapot (25);	 break;	// Draw wireTeapot
	}

	glutSwapBuffers();
	glFlush ( );     
}

int main (int argc, char **argv)
{
	GLint subMenu1, subMenu2;			// Declare variable
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition (50, 50);
	glutInitWindowSize (500, 500);
	glutCreateWindow ("Menu & Submenu");

	init ( );
	glutDisplayFunc (display);

	subMenu1 = glutCreateMenu (colorFcn);	// Create submenu.
		glutAddMenuEntry ("Red", 1);
		glutAddMenuEntry ("Green", 2);
		glutAddMenuEntry ("Blue", 3);
		glutAddMenuEntry ("Black", 4);

	subMenu2 = glutCreateMenu (shapeFcn);	// Create submenu.
		glutAddMenuEntry ("WireTorus", 1);
		glutAddMenuEntry ("WireSphere", 2);
		glutAddMenuEntry ("WireTeapot", 3);

	glutCreateMenu (mainMenu);				// Create main pop-up menu.
		glutAddMenuEntry ("White Blackground", 1);
		glutAddMenuEntry ("Yellow Blackground", 2);
		glutAddSubMenu ("Color", subMenu1);
		glutAddSubMenu ("Shape", subMenu2);

	/*  Select a menu option using the right mouse button.  */
	glutAttachMenu (GLUT_RIGHT_BUTTON);
	shape = color = 1;	  // set current shape and color

	glutMainLoop ( );
	return 0;
}
