#include <stdio.h>
#include <math.h>
#include <random>
#include <glut.h>
#include <list>


using namespace std;


//Variables
int screenwidth = 650;
int screenheight = 450;


list<int> listSection = {1,2,3,4};

double ftime = 0.8;
double ydash = 0.0;
double xdash = 0.0;

int speY = 0;


//Methods


void drawcircle(int x, int y, int r) {

	glColor3f(1, 1, 1);
	glTranslatef(x,y, 0);
	GLUquadric* quadObj = gluNewQuadric();
	gluDisk(quadObj, 0, r, 50, 50);
	
}


void drawbird() {

	glPushMatrix();
	glTranslatef(0, ydash, 0);
	if (speY) {
		ydash += 15; speY = 0;
}
	
	else ydash += 0 + (-0.5 * 9.81) * (ftime * ftime); //free fall

	drawcircle(screenwidth / 9, screenheight / 2, 10);
	glPopMatrix();

	


}

void drawrectangle(int x, int y,int w, int h) {

	
	glBegin(GL_POLYGON);
		glColor3f(0, 1, 0);
		glVertex3f(x, y, 0.0f);
		glVertex3f(x + w, y, 0.0f);
		glVertex3f(x + w, y + h, 0.0f);	
		glVertex3f(x, y + h, 0.0f);
	glEnd();



}

void spe(int k, int x, int y)// keyboard special key function takes 3 parameters
							// int k: is the special key pressed such as the keyboard arrows the f1,2,3 and so on
{
	if (k == GLUT_KEY_UP)
		speY =1;

	glutPostRedisplay();//redisplay to update the screen with the changes
}

void Timer(int value) {

	glutTimerFunc(70, Timer, 0);
	glutPostRedisplay();
}


void Display() {
	glClear(GL_COLOR_BUFFER_BIT);

	drawbird();

	glPushMatrix();
	glTranslated(-xdash, 0, 0);
	xdash+=3;

	drawrectangle(320, 0, 60, 150);
	drawrectangle(320, 255, 60, 400);
	drawrectangle(460, 0, 60, 150);
	drawrectangle(460, 255, 60, 400);
	glPopMatrix();




	glFlush();
}

void main(int argc, char** argr) {
	glutInit(&argc, argr);

	glutInitWindowSize(screenwidth, screenheight);
	glutInitWindowPosition(150, 150);

	glutCreateWindow("Flappy Bird");
	glutDisplayFunc(Display);
	glutTimerFunc(0, Timer, 0);
    glutSpecialFunc(spe);			//call the keyboard special keys function

	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	gluOrtho2D(0.0, screenwidth, 0.0, screenheight);

	glutMainLoop();
}
