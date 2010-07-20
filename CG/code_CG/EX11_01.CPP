#include <GL/glut.h>
 
int x_angle = 0;			// the angle of rotation of our object.

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
}
 
void display (void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);			// Set color to red
	glPushMatrix();
	glRotatef(-30.0, 0.0, 1.0, 0.0);
	glRotatef(x_angle,1,0,0);			// Do the rotation 
	glutWireCube(1.0);				// Draw the cube 
	glutSwapBuffers();
	glPopMatrix();
}
 
void spin (void)					// Spin function
{
	x_angle += 1.0;
	glutPostRedisplay();          			// Display again     
 
}
 
void main (int argc, char **argv)
{
	glutInit (&argc, argv);             
	glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE);     
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow ("Callback function for Cube Animation");
	glutDisplayFunc(display);           
	glutIdleFunc(spin);				// Idle function            
	glutMainLoop ();                    
}