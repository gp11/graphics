#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define PI 3.1416

//static float	tx	=  0.0;
//static float	ty	=  0.0;


static int	tx	=  0;
static int	ty	=  0;
void circle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

	glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);

     glBegin(GL_LINE_STRIP);
     glVertex2f(18.0,18.0);
      glVertex2f(-18.0,18.0);
       glVertex2f(-18.0,-18.0);
        glVertex2f(18.0,-18.0);
        glVertex2f(18.0,18.0);
      glEnd();
    glBegin(GL_LINE_STRIP);
     glVertex2f(16.0,16.0);
      glVertex2f(-16.0,16.0);
       glVertex2f(-16.0,12.0);
       glVertex2f(12.0,12.0);

      glEnd();
       glBegin(GL_LINE_STRIP);
     glVertex2f(12.0,12.0);
    glVertex2f(12.0,-10.0);

 glEnd();
  glBegin(GL_LINE_STRIP);
     glVertex2f(16.0,16.0);
    glVertex2f(16.0,-14.0);

 glEnd();
  glBegin(GL_LINE_STRIP);
     glVertex2f(12.0,-10.0);
    glVertex2f(-16.0,-10.0);

 glEnd();
 glBegin(GL_LINE_STRIP);
     glVertex2f(16.0,-14.0);
    glVertex2f(-16.0,-14.0);

 glEnd();
 glBegin(GL_LINE_STRIP);
     glVertex2f(-16.0,-10.0);
    glVertex2f(-16.0,-14.0);

 glEnd();

	glPushMatrix();
		glTranslatef(tx,ty,0);
   //circle(1,1);
 glBegin(GL_QUADS);
     glVertex2f(-15.0,15.0);
    glVertex2f(-15.0,13.0);
    glVertex2f(-13.0,13.0);
    glVertex2f(-13.0,15.0);

 glEnd();
	glPopMatrix();
	glFlush();
}

void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glOrtho(-25.0, 25.0, -25.0, 25.0, -25.0, 25.0);
}


void spe_key(int key, int x, int y)
{

	switch (key) {

		case GLUT_KEY_LEFT:
		        if (tx<0) break;
                 if (tx<24 && tx>22) break;
                 if (ty<=-2 && ty>-26 && tx==28) break;
				tx -=2;
				printf("tx = left %d\n",tx);
				glutPostRedisplay();
				break;

		case GLUT_KEY_RIGHT:
		     if (tx>26) break;
				tx +=2;
				printf("tx = right %d\n",tx);
				glutPostRedisplay();
				break;

        case GLUT_KEY_DOWN:

            if (tx>=0 && tx<25) break;
               if (tx!=28) break;
                if (ty<=-25) break;
                    ty -=2;
                    printf("tx = down %d\n",ty);
				glutPostRedisplay();
				break;


		case GLUT_KEY_UP:
		             if (tx>=0 && tx<25 && ty==0) break;
		             if (!(tx==28 && ty>=-26 && ty<=-2)) break;
		                  ty +=2;
		                  printf("tx = up %d\n",ty);
				glutPostRedisplay();
				break;
	  default:
			break;
	}
}

int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("mist");
	init();
	glutDisplayFunc(display);
	glutSpecialFunc(spe_key);//up,down,left......
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}

