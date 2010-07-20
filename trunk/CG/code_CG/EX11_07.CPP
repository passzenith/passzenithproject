#include <gl\glut.h> 

const int nMenus = 4;
int menu[nMenus]; 				// menus created
int shape;    						// current shape to draw
int color;    						// current color to draw with

void init(void)
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.5, 0.5, 0.5, 0.0);// Set display-window color to gray
	glColor3f(1.0, 1.0, 1.0);	
	glMatrixMode(GL_PROJECTION);	
	glRotatef (30.0, 0.0, 1.0, 1.0);
	glOrtho(-50,50,-50,50,-50,50);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Menu callback, responds to menu events
void menu1(int item) 
{
	glutSetMenu(menu[1]);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void menu2(int item) 
{
	glutSetMenu(menu[2]);
	glutAttachMenu(GLUT_RIGHT_BUTTON);  
}

void menu3(int item) 
{
	color = item;
	glutPostRedisplay();    		// redraw the shape in new color
}

void menu4(int item) 
{
	shape = item;
	glutPostRedisplay();    		// draw the new shape
}

void display (void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	
	glEnable (GL_LINE_SMOOTH);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	switch(color) 
	{
		case 0 : glColor3f(1.0, 0.0, 0.0);  break;
		case 1 : glColor3f(0.0, 1.0, 0.0);  break;
		case 2 : glColor3f(0.0, 0.0, 1.0);  
	}
  
	switch (shape) 
	{
		case 0 : glutWireTorus (5, 20, 10, 10); break;	// Draw wireTorus
		case 1 : glutWireSphere (30, 50, 20);  break; // Draw wireSphere
		case 2 : glutWireTeapot (25);	 break;	// Draw wireTeapot
  }
  
	glutSwapBuffers();
	glFlush ( );     
}

void main(int  argc, char *argv[])  
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition (50, 50);
	glutInitWindowSize (500, 500);
	glutCreateWindow("Glut Sub menus");
	init ( );
	// set glut callback functions
	glutDisplayFunc(display);

	// create popup menu
	menu[0] = glutCreateMenu(menu1);
	menu[1] = glutCreateMenu(menu2);
	menu[2] = glutCreateMenu(menu3);
	menu[3] = glutCreateMenu(menu4);

	glutSetMenu(menu[3]);
	glutAddMenuEntry("WireTorus", 0);
	glutAddMenuEntry("WireSphere", 1);
	glutAddMenuEntry("WireTEapot", 2);

	glutSetMenu(menu[2]);
	glutAddMenuEntry("Red", 0);
	glutAddMenuEntry("Green", 1);
	glutAddMenuEntry("Blue", 2);

	glutSetMenu(menu[1]);
	glutAddMenuEntry("Color menu", 0);
	glutAddSubMenu("Shapes", menu[3]);

	glutSetMenu(menu[0]);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAddMenuEntry("Shape menu", 0);
	glutAddSubMenu("Colors", menu[2]);

	// set current shape and color
	shape = color = 0;

	// release control to glut / opengl event manager
	glutMainLoop();
	for(int i=0; i < nMenus; i++)   glutDestroyMenu(menu[i]);

}