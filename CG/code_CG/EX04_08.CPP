#include <windows.h>   	
#include <gl/glut.h>

void drawDot (GLint x, GLint y)
{ 
  glColor3f(0.0,0.0,0.0);
  glBegin (GL_POINTS);
	  glVertex2i (x, y);
  glEnd();
}

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0);  
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	glPointSize(2.0);			
	glLineWidth(2.0);		
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

//<<<<<<< draw circles
void circlePoints (int x, int y, int xc, int yc)
{
	drawDot(xc+x,yc+y);
	drawDot (xc-x,yc+y);
	drawDot (xc+x,yc-y);
	drawDot (xc-x,yc-y);
	drawDot (xc+y,yc+x);
	drawDot (xc-y,yc+x);
	drawDot (xc+y,yc-x);
	drawDot (xc-y,yc-x);
}

void Circle (int xc, int yc, int rad)
{ 
	int x,y,d;
	x = 0;
	y = rad;
	circlePoints (x, y, xc, yc);
		d = 1 - rad;
	while (x < y)
  { 
    if (d < 0)
     x++;
    else
      { 
         x++;
         y—;
       }
    if (d < 0)
      d += 2*x +1;
    else
     d += 2*(x-y) + 1;
    circlePoints (x,y,xc,yc);
  }
}

void myDisplay(void)
{     
	glClear(GL_COLOR_BUFFER_BIT);    
	glColor3f(0.0f,0.0f,0.0f);		
	glBegin (GL_LINES);			// Horizontal line (x axis)
		glVertex2i (50,240);
		glVertex2i (590,240);
	glEnd();
	glBegin(GL_LINES);			// Vertical line (ellipse y axis)
		glVertex2i(320,50);
		glVertex2i(320,430);
	glEnd();

	Circle (320,240,150);
   
	glFlush();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);			
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	
	glutInitWindowSize(640,480);		
	glutInitWindowPosition(50, 50);		
	glutCreateWindow("Circle Drawing");	
	glutDisplayFunc(myDisplay);		
	myInit();					              
	glutMainLoop();				
}
