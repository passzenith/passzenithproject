#include <GL/glut.h>
 
void init(void) 
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display (void)
{
	glClear (GL_COLOR_BUFFER_BIT);   
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glPushMatrix();
	glutSolidTeapot(0.5);				// Draw the Teapot 
	glPopMatrix();
	glutSwapBuffers();
}
 
void specialkey (int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_F1:
			glColor3f(1.0, 0.0, 0.0);			// Set color to red
			glutPostRedisplay();
			break;
		case GLUT_KEY_INSERT:
			glColor3f(0.0, 1.0, 0.0);			// Set color to green
			glutPostRedisplay();
			break;
					case GLUT_KEY_HOME:
			glColor3f(0.0, 0.0, 1.0);			// Set color to blue
			glutPostRedisplay();
			break;
		case GLUT_KEY_PAGE_UP:
			glColor3f(1.0, 1.0, 0.0);			// Set color to yellow
			glutPostRedisplay();
			break;
		case GLUT_KEY_LEFT:
			glColor3f(1.0, 0.0, 1.0);			// Set color to magenta
			glutPostRedisplay();
			break;
		case GLUT_KEY_RIGHT:
			glColor3f(0.0, 1.0, 1.0);			// Set color to cyan
			glutPostRedisplay();
			break;
		default:
			break;
	}
}

void main (int argc, char **argv)
{
	glutInit (&argc, argv);             
	glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE);     
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow ("Special key : F1=red, INSERT=green, HOME=blue, PgUp=yellow, left=magenta, right=cyan");         
	glutDisplayFunc(display);           
	glutSpecialFunc (specialkey);
	glutMainLoop ();                    
}
