#include <stdio.h>
#include <math.h>
#include <random>
#include <glut.h>
#include <list>
#include <string>
#include <sstream>


using namespace std;


//Variables
int screenwidth = 650;
int screenheight = 450;
int FPS = 30;
float timeElapsed = 0.0;

int barwidth = 60;

double ftime = 0.8;
double ydash = 0.0;
double xdash = 0.0;

int speY = 0;

int start = 0;
int sset = rand() % 3 + 1; 
int gameon = 0;
int endgame = 0;





// A good hackaround found here for to_string problems with GCC
// http://stackoverflow.com/questions/12975341/to-string-is-not-a-member-of-std-says-so-g
namespace patch
{
	template < typename T > std::string to_string(const T& n)
	{
		std::ostringstream stm;
		stm << n;
		return stm.str();
	}
}


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
	if (gameon) {
		
		if (speY) {
			ydash += 17; speY = 0;
		}
		else ydash += (-0.5 * 9.81) * (ftime * ftime); //free fall
	}
	drawcircle(screenwidth / 9, screenheight / 2, 10);
	glPopMatrix();
}

void drawrectangle(int x, int y,int w, int h) {

	glBegin(GL_POLYGON);
		glVertex3f(x, y, 0.0f);
		glVertex3f(x + w, y, 0.0f);
		glVertex3f(x + w, y + h, 0.0f);	
		glVertex3f(x, y + h, 0.0f);
	glEnd();

}

void set1(int bar1set1,int bar2set1,int bar3set1) {

	glColor3f(0, 1, 0.5);

	drawrectangle(bar1set1, 0, barwidth, 140);
	drawrectangle(bar1set1, 270, barwidth, 195);

	drawrectangle(bar2set1, 0, barwidth, 170);
	drawrectangle(bar2set1, 300, barwidth, 195);

	drawrectangle(bar3set1, 0, barwidth, 200);
	drawrectangle(bar3set1, 330, barwidth, 195);
}
void set2(int bar1set2,int bar2set2 , int bar3set2) {
	glColor3f(0, 0.7, 0.5);

	drawrectangle(bar1set2, 0, barwidth, 230);
	drawrectangle(bar1set2, 360, barwidth, 195);

	drawrectangle(bar2set2, 0, barwidth, 170);
	drawrectangle(bar2set2, 300, barwidth, 195);

	drawrectangle(bar3set2, 0, barwidth, 230);
	drawrectangle(bar3set2, 360, barwidth, 195);
}
void set3(int bar1set3, int bar2set3,int bar3set3) {

	glColor3f(0, 0.55, 0.5);

	drawrectangle(bar1set3, 0, barwidth, 230);
	drawrectangle(bar1set3, 360, barwidth, 195);

	drawrectangle(bar2set3, 0, barwidth, 170);
	drawrectangle(bar2set3, 300, barwidth, 195);

	drawrectangle(bar3set3, 0, barwidth, 170);
	drawrectangle(bar3set3, 300, barwidth, 195);
}

void drawBars() {

	glPushMatrix();
	glTranslated(-xdash, 0, 0);
	if (gameon) {
		xdash += 3;
	}
	

	int startm = (screenwidth / 2);
	int start1 = startm;
	int start2 = start1 + 480 + 160;
	int start3 = start2+ 480 + 160;

	int bar1set1 = start1;
	int bar2set1 = start1 + 160;
	int bar3set1 = start1 + (160 * 2);

	int bar1set2 = start2;
	int bar2set2 = start2 + 160;
	int bar3set2 = start2 + (160 * 2);

	int bar1set3 = start3;
	int bar2set3 = start3 + 160;
	int bar3set3 = start3 + (160 * 2);

	switch (sset) {
	case 1:
	
		set1(bar1set1,bar2set1,bar3set1);
		set2(bar1set2, bar2set2, bar3set2);
		set3(bar1set3, bar2set3, bar3set3);
		break;

	case 2:

		start2 = startm;
		start3 = start2 + 480 + 160;
		start1 = start3 + 480 + 160;
		set2(bar1set2, bar2set2, bar3set2);
	
		break;
	case 3:

		start3 = startm;
		start1 = start3 + 480 + 160;
		start2 = start1 + 480 + 160;
		set3(bar1set3, bar2set3, bar3set3);
		

		break;


	default:
		break;

	}

	glPopMatrix();
}

void spe(int k, int x, int y)// keyboard special key function takes 3 parameters
							// int k: is the special key pressed such as the keyboard arrows the f1,2,3 and so on
{
	if (k == GLUT_KEY_UP)
		speY =1;

	glutPostRedisplay();//redisplay to update the screen with the changes
}


void keyUp(unsigned char k, int x, int y)//keyboard up function is called whenever the keyboard key is released
{
	if (k)
		start = 1;
	glutPostRedisplay();//redisplay to update the screen with the changed
}


void drawBitmapText(string text, float x, float y, float z)
{

	glColor3f(1.0, 1.0, 1.0);
	glRasterPos3f(x, y, z);

	for (int i = 0; i < text.size(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
	}
}


void Timer(int value) {

	if (!endgame) {
		timeElapsed += FPS / 1000.0;
	}

	glutTimerFunc(FPS, Timer, 0);
	glutPostRedisplay();
}

void drawTimer() {
	string timeString = "Time : " + to_string(int(timeElapsed)) + " s";
	drawBitmapText(timeString, 10, 0, 0);
}


void Display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	if (!start) {
		drawBitmapText("Press any key to start", screenwidth / 2 - 70, screenheight / 2, 0);
	}
	else {
		gameon = 1;
	}
	glPopMatrix();
	drawBars();

	drawbird();
	

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
	glutKeyboardUpFunc(keyUp);		//call the keyboard up function

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	gluOrtho2D(0.0, screenwidth, 0.0, screenheight);

	glutMainLoop();
}
