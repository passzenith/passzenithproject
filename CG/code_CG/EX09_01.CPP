#include <GL/glut.h>

// Rotation amounts
GLfloat xRot = 0.0;
GLfloat yRot = 0.0;

void init (void)
{
	// White background
	glClearColor(1.0, 1.0, 1.0, 0.0 );

	glEnable(GL_DEPTH_TEST);	
	glEnable(GL_DITHER);
	glShadeModel(GL_SMOOTH);
}

void myDisplay (void)
{
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glPushMatrix();

	glRotatef(xRot, 1.0, 0.0, 0.0);
	glRotatef(yRot, 0.0, 1.0, 0.0);

	// Draw six quads
	glBegin(GL_QUADS);
		// Front Face
			// White
				glColor3f(1.0, 1.0, 1.0);
				glVertex3f(50.0,50.0,50.0);

			// Yellow
				glColor3f(1.0, 1.0, 0.0);
				glVertex3f(50.0,-50.0,50.0);

			// Red
				glColor3f(1.0, 0.0, 0.0);
				glVertex3f(-50.0,-50.0,50.0);

			// Magenta
				glColor3f(1.0, 0.0, 1.0);
				glVertex3f(-50.0,50.0,50.0);

		// Back Face
			// Cyan
				glColor3f(0.0, 1.0, 1.0);
				glVertex3f(50.0,50.0,-50.0);

			// Green
				glColor3f(0.0, 1.0, 0.0);
				glVertex3f(50.0,-50.0,-50.0);
		
			// Black
				glColor3f(0.0, 0.0, 0.0);
				glVertex3f(-50.0,-50.0,-50.0);

			// Blue
				glColor3f(0.0, 0.0, 1.0);
				glVertex3f(-50.0,50.0,-50.0);
	
		// Top Face
			// Cyan
				glColor3f(0.0, 1.0, 1.0);
				glVertex3f(50.0,50.0,-50.0);

			// White
				glColor3f(1.0, 1.0, 1.0);
				glVertex3f(50.0,50.0,50.0);

			// Magenta
				glColor3f(1.0, 0.0, 1.0);
				glVertex3f(-50.0,50.0,50.0);

			// Blue
				glColor3f(0.0, 0.0, 1.0);
				glVertex3f(-50.0,50.0,-50.0);
	
		// Bottom Face
			// Green
				glColor3f(0.0, 1.0, 0.0);
				glVertex3f(50.0,-50.0,-50.0);

			// Yellow
			glColor3f(1.0, 1.0, 0.0);
			glVertex3f(50.0,-50.0,50.0);

			// Red
				glColor3f(1.0, 0.0, 0.0);
				glVertex3f(-50.0,-50.0,50.0);

			// Black
				glColor3f(0.0, 0.0, 0.0);
				glVertex3f(-50.0,-50.0,-50.0);
	
		// Left face
			// White
				glColor3f(1.0, 1.0, 1.0);
				glVertex3f(50.0,50.0,50.0);

			// Cyan
				glColor3f(0.0, 1.0, 1.0);
				glVertex3f(50.0,50.0,-50.0);

			// Green
				glColor3f(0.0, 1.0, 0.0);
				glVertex3f(50.0,-50.0,-50.0);

			// Yellow
				glColor3f(1.0, 1.0, 0.0);
				glVertex3f(50.0,-50.0,50.0);
	
		// Right face
			// Magenta
				glColor3f(1.0, 0.0, 1.0);
				glVertex3f(-50.0,50.0,50.0);

			// Blue
				glColor3f(0.0, 0.0, 1.0);
				glVertex3f(-50.0,50.0,-50.0);

			// Black
				glColor3f(0.0, 0.0, 0.0);
				glVertex3f(-50.0,-50.0,-50.0);

			// Red
				glColor3f(1.0, 0.0, 0.0);
				glVertex3f(-50.0,-50.0,50.0);
	glEnd();

	glPopMatrix();

	// Show the graphics
	glutSwapBuffers();
	
}

void SpecialKey (int key, int x, int y) 
{
	if(key == GLUT_KEY_UP)
		xRot-= 5.0;

	if(key == GLUT_KEY_DOWN)
		xRot += 5.0;

	if(key == GLUT_KEY_LEFT)
		yRot -= 5.0;

	if(key == GLUT_KEY_RIGHT)
		yRot += 5.0;

	if(key > 356.0)
		xRot = 0.0;

	if(key < -1.0)
		xRot = 355.0;

	if(key > 356.0)
		yRot = 0.0;

	if(key < -1.0)
		yRot = 355.0;

	// Refresh the Window
	glutPostRedisplay();
}


void reshape(int w, int h)
{
	GLfloat fAspect;

	// Prevent a divide by zero
	if(h == 0)
		h = 1;

	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	fAspect = (GLfloat)w / (GLfloat)h;
	gluPerspective(35.0, fAspect, 1.0, 1000.0);
     
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -400.0);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);		
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition (50, 50);	
	glutInitWindowSize(500,500);	
    	glutCreateWindow("RGB Cube Color");
	init ();				
	glutReshapeFunc(reshape);
	glutSpecialFunc(SpecialKey);
	glutDisplayFunc(myDisplay);	
	glutMainLoop();	
    return 0;		
}
