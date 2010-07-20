#include <GL/glut.h>

int vpWidth, vpHeight;

void init()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glColor3f(0, 0, 0);
	glClearDepth(1);
}

void drawScene()
{
	glColor3f(1.0, 0, 0);

	glPushMatrix();
	glTranslatef(0, -1, 0);

	glBegin(GL_QUADS);
		glVertex3f(2, 0, 2);
		glVertex3f(2, 0, -2);
		glVertex3f(-2, 0, -2);
		glVertex3f(-2, 0, 2);
	glEnd();

	glPopMatrix();

	glColor3f(0.0, 0.0, 1.0);

	glutWireTeapot(1);
}


void reshape (int w, int h)
{
	vpWidth = w;
	vpHeight = h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2, 2, -2, 2, -50, 50);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display()
{
	glClear( GL_COLOR_BUFFER_BIT | 	GL_DEPTH_BUFFER_BIT );
	glEnable(GL_DEPTH_TEST);
	//bottom left
	glViewport(0, 0, vpWidth/2, vpHeight/2); 	
	glPushMatrix();
	gluLookAt(1, 0, 0,   0, 0, 0,  0, 1, 0); 
 
	//looking down x axis
	drawScene();
	glPopMatrix();

	//bottom right 
	glViewport(vpWidth/2, 0, vpWidth/2, vpHeight/2);	
	glPushMatrix();
 
	//looking down z axis 
	gluLookAt(0, 0, 1,   0, 0, 0,   0, 1, 0); 
	drawScene();
	glPopMatrix();

	//top left
	glViewport(0, vpHeight/2, vpWidth/2, vpHeight/2); 
	glPushMatrix();

	//down the y axis z-axis is up
	gluLookAt(0, 1, 0, 0, 0, 0, 0, 0, 1); 
	drawScene();
	glPopMatrix();

	////////next one drawn in perspective
	//top right
	glViewport(vpWidth/2, vpHeight/2, vpWidth/2, vpHeight/2); 

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPushMatrix();                    
 
	gluPerspective(20, 1, 1, 10000);  
 
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();                 

	gluLookAt(10, 10, 10, 0, 0, 0, 0, 1, 0);
	drawScene();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();                  


	glMatrixMode(GL_MODELVIEW);
	glPopMatrix(); 
 
	glFlush();

};

void main()
{
	vpWidth = 600;
	vpHeight = 600;

	glutInitDisplayMode(GLUT_SINGLE | 	GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(vpWidth, vpHeight);
	glutCreateWindow ("Sample Viewports");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
}
