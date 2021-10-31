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

int start = screenwidth - screenwidth / 3;

int startgame = 0;
int sset = rand() % 3 + 1;
int gameon = 0;
int endgame = 0;

list <int> sets = {};


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
void set1(int startpos) {

	glColor3f(0, 1, 0.5);

	drawrectangle(startpos, 0, barwidth, 140);
	drawrectangle(startpos, 270, barwidth, 195);
	startpos += 150;

	drawrectangle(startpos, 0, barwidth, 170);
	drawrectangle(startpos, 300, barwidth, 195);
	startpos += 150;

	drawrectangle(startpos, 0, barwidth, 200);
	drawrectangle(startpos, 330, barwidth, 195);
	

}
void set2(int startpos) {


	glColor3f(0, 0.7, 0.5);
	drawrectangle(startpos, 0, barwidth, 230);
	drawrectangle(startpos, 360, barwidth, 195);
	startpos += 150;


	drawrectangle(startpos, 0, barwidth, 170);
	drawrectangle(startpos, 300, barwidth, 195);
	startpos += 150;


	drawrectangle(startpos, 0, barwidth, 230);
	drawrectangle(startpos, 360, barwidth, 195);
	
	
}
void set3(int startpos) {

	glColor3f(0, 0.55, 0.5);

	drawrectangle(startpos, 0, barwidth, 230);
	drawrectangle(startpos, 360, barwidth, 195);
	startpos += 150;


	drawrectangle(startpos, 0, barwidth, 170);
	drawrectangle(startpos, 300, barwidth, 195);
	startpos += 150;


	drawrectangle(startpos, 0, barwidth, 170);
	drawrectangle(startpos, 300, barwidth, 195);
	
}


void drawBars(int sset) {

	glPushMatrix();
	glTranslated(-xdash, 0, 0);
	if (gameon) {
		xdash += 3;
	}

	
	int set = sset;
	switch (set) {
	case 1:
		set1(start);
		break;

	case 2:
		set2(start);
		break;
	case 3:
		set3(start);
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
		startgame = 1;
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
	if (!startgame) {
		drawBitmapText("Press any key to start", screenwidth / 2 - 70, screenheight / 2, 0);
	}
	else {
		gameon = 1;

	}
	glPopMatrix();
	
	drawbird();

	drawBars(sset);






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
