#include <windows.h>  

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

void symmetricPixels (int x, int y, int xc, int yc)	// Function to plot semmetricPixel
{ 
  drawDot (xc + x, yc + y);
  drawDot (xc - x, yc + y);
  drawDot (xc + x, yc - y);
  drawDot (xc - x, yc - y);
}

void Ellipse (int Rx, int Ry, int xc, int yc)	// Function to draw ellipse
{ 
  int RxSq,RySq,twoRxSq,twoRySq,d,dx,dy,x,y;

  RxSq = Rx*Rx;
  RySq = Ry*Ry;
  twoRxSq = 2*RxSq;
  twoRySq = 2*RySq;
  d = RySq - Ry*RxSq + RxSq/4;
  dx = 0;
  dy = twoRxSq*Ry;
  x = 0;
  y = Ry;
  symmetricPixels(x,y,xc,yc);
  while (dx < dy)
  { x++;
    dx += twoRySq;
    if (d >= 0)
    { y--;
      dy -= twoRxSq;
    }
    if (d < 0)
     d += RySq + dx;
    else
     d += RySq + dx - dy;
    symmetricPixels (x,y,xc,yc);
  }
  d = (int)(RySq*(x+0.5)*(x+0.5) + RxSq*(y-1)*(y-1) - RxSq*RySq);
  while (y > 0)
  { y--;
    dy -= twoRxSq;
    if (d <= 0)
    { x++;
      dx += twoRySq;
    }
    if (d > 0)
         d += RxSq - dy;
    else
         d += RxSq -dy +dx;
    symmetricPixels(x,y,xc,yc);
  }
}    

void myDisplay(void)
{     
   glClear(GL_COLOR_BUFFER_BIT);    
   glColor3f(0.0f,0.0f,0.0f);		// Set line & point to black
   glBegin (GL_LINES);				// Horizontal line (x axis)
     glVertex2i (50,240);
     glVertex2i (590,240);
   glEnd();
   glBegin(GL_LINES);				// Vertical line (ellipse y axis)
     glVertex2i(320,50);
     glVertex2i(320,430);
   glEnd();

   Ellipse (200,100,320,240);
   
   glFlush();
}

void main(int argc, char** argv)
{
        glutInit(&argc, argv);		
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	
        glutInitWindowSize(640,480);		
        glutInitWindowPosition(50, 50);		
        glutCreateWindow("Ellipse Drawing");
        glutDisplayFunc(myDisplay);		
        myInit();					                 
        glutMainLoop();				
}
