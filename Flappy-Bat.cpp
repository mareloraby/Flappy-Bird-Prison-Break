#include <stdio.h>
#include <math.h>
#include <random>
#include <glut.h>
#include <list>
#include <string>
#include <sstream>
#include <iostream>


using namespace std;

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

//Variables
int screenwidth = 650;
int screenheight = 450;
int FPS = 30;
float timeElapsed = 0.0;
int barwidth = 60;

double ftime = 0.08;
double xdash = 0.0;
double step = 0.05;
double falld = 0;
double slided = 0;
int jump = 0;


int start = screenwidth - screenwidth / 3;
int lives = 3;
int score = 0;

int startgame = 0;
int gamerun = 0;
int gameover = 0;
int gamewin = 0;

int sset = rand() % 2 + 1;

int xs1b1 = 0;
int xs1b2 = 0;
int xs1b3 = 0;
int xs1b4 = 0;

int xs2b1 = 0;
int xs2b2 = 0;
int xs2b3 = 0;
int xs2b4 = 0;

int xs3b1 = 0;
int xs3b2 = 0;
int xs3b3 = 0;
int xs3b4 = 0;

int ys1b1h = 140;
int ys1b2h = 170;
int ys1b3h = 200;
int ys1b4h = 230;

int ys2b1h = 230;
int ys2b2h = 170;
int ys2b3h = 230;
int ys2b4h = 170;

int ys3b1h = 230;
int ys3b2h = 170;
int ys3b3h = 170;
int ys3b4h = 0;

int ys1b1y = 270;
int ys1b2y = 300;
int ys1b3y = 330;
int ys1b4y = 360;

int ys2b1y = 360;
int ys2b2y = 300;
int ys2b3y = 360;
int ys2b4y = 300;

int ys3b1y = 360;
int ys3b2y = 300;
int ys3b3y = 300;
int ys3b4y = 0;

int finishline = 0;


void drawBitmapText(string text, float x, float y, float z);
void drawbird();
void drawrectangle(int x, int y, int w, int h);
void drawBars(int sset);
void Display();




//Methods


void drawcircle(int x, int y, int r) {

	glColor3f(1, 1, 1);
	glTranslatef(x, y, 0);
	GLUquadric* quadObj = gluNewQuadric();
	gluDisk(quadObj, 0, r, 50, 50);

}

void drawbird() {

	glPushMatrix();
	glTranslatef(slided, falld, 0);
	
	if (gamerun) {
		if (jump) {
			falld += 17; jump = 0;
		}
		else falld += (-0.5 * 9.81) * (ftime * ftime); //free fall
	}

	if (gameover) {
		ftime = 0;
		falld = 0;
		gamerun = 0;
		
	}

	drawcircle(screenwidth / 9, screenheight / 2, 10);
	glPopMatrix();
}



void drawrectangle(int x, int y, int w, int h) {

	glBegin(GL_POLYGON);
	glVertex3f(x, y, 0.0f);
	glVertex3f(x + w, y, 0.0f);
	glVertex3f(x + w, y + h, 0.0f);
	glVertex3f(x, y + h, 0.0f);
	glEnd();

}



void set1(int startpos) {
	//glPushMatrix();
	glColor3f(0, 1, 0.5);
	
	drawrectangle(startpos, 0, barwidth, ys1b1h);
	drawrectangle(startpos, ys1b1y, barwidth, 195);
	xs1b1 = startpos;
	startpos += 150;
	drawrectangle(startpos, 0, barwidth, ys1b2h);
	drawrectangle(startpos, ys1b2y, barwidth, 195);
	xs1b2 = startpos;
	startpos += 150;
	drawrectangle(startpos, 0, barwidth, ys1b3h);
	drawrectangle(startpos, ys1b3y, barwidth, 195);
	xs1b3 = startpos;
	startpos += 150;
	drawrectangle(startpos, 0, barwidth, ys1b4h);
	drawrectangle(startpos, ys1b4y, barwidth, 195);
	xs1b4 = startpos;

	//	glPopMatrix();

}
void set2(int startpos) {

	//glPushMatrix();
	glColor3f(0, 0.7, 0.5);
	//glColor3f(1, 0, 0.5);
	drawrectangle(startpos, 0, barwidth, ys2b1h);
	drawrectangle(startpos, ys2b1y, barwidth, 195);
	xs2b1 = startpos;
	startpos += 150;
	drawrectangle(startpos, 0, barwidth, ys2b2h);
	drawrectangle(startpos, ys2b2y, barwidth, 195);
	xs2b2 = startpos;
	startpos += 150;
	drawrectangle(startpos, 0, barwidth, ys2b3h);
	drawrectangle(startpos, ys2b3y, barwidth, 195);
	xs2b3 = startpos;
	startpos += 150;
	drawrectangle(startpos, 0, barwidth, ys2b4h);
	drawrectangle(startpos, ys2b4y, barwidth, 195);
	xs2b4 = startpos;
	//glPopMatrix();

}
void set3(int startpos) {

	//	glPushMatrix();
	glColor3f(0, 0.55, 0.5);
	drawrectangle(startpos, 0, barwidth, ys3b1h);
	drawrectangle(startpos, ys3b1y, barwidth, 195);
	xs3b1 = startpos;
	startpos += 150;
	drawrectangle(startpos, 0, barwidth, ys3b2h);
	drawrectangle(startpos, ys3b2y, barwidth, 195);
	xs3b2 = startpos;
	startpos += 150;
	drawrectangle(startpos, 0, barwidth, ys3b3h);
	drawrectangle(startpos, ys3b3y, barwidth, 195);
	xs3b3 = startpos;
	//	glPopMatrix();


}

void Finish_Line(int startpos) {

	glColor3f(0, 0, 0);
	drawrectangle(startpos, 0, 3, screenheight);
	finishline = startpos;

}


void drawBars(int sset) {

	glPushMatrix();

	glTranslated(-xdash, 0, 0);
	switch (sset) {
	case 1:
		set1(start);
		set2(start + 455 + 150);
		set3(start + 910 + 150 + 150 );

		Finish_Line(start + 1365 + 150 + 100);
		break;

	case 2:
		set2(start);
		set3(start + 455 + 150);
		set1(start + 910 + 150 );

		Finish_Line(start + 1365 + 150 + 100);
		break;
	case 3:
		set3(start);
		set1(start + 455);
		set2(start + 910 + 150);

		Finish_Line(start + 1365 + 150 + 100);

		break;

	default:
		break;
	}
	glPopMatrix();
}


//void drawbuilding() {
//
//	glColor3f(0.7, 0.7, 0.7);
//	drawrectangle(5, 0, 75, 195);
//	glColor3f(0.5, 0.5, 0.5);
//	drawrectangle(4, 195, 77, 5);
//	glColor3f(1, 1, 0);
//	drawrectangle(25, 50, 10, 25);
//}


void collisionActions() {

//	cout << finishline << endl;



	if (falld < -220) {
		falld = -220;
	}

	if (falld > 220) {
		falld = 220;
	}

	if (lives <= 0) {
	
		gameover = 1;
		gamerun = 0;

	}


	int ballposy = falld + 225;
	int ballposx = screenwidth / 9;

	if (ballposx >= finishline - xdash) {
	
	
		gamerun = 0;
		gamewin = 1;
		gameover = 1;
		cout << "finished!!" << endl;


	}


	

	if (gamerun) {

		


		if (((ballposx >= xs1b1 - xdash && ballposx <= xs1b1 + 60 - xdash) && (ballposy <= ys1b1h || ballposy >= ys1b1y))) {
			falld = (ys1b1h + ys1b1y) / 2 - 225;
			cout << "CRASH1" << endl;
			lives--;
			score--;
		}
		else if (ballposx > (xs1b1 + 60 - xdash) && ballposx < (xs1b1 + 60 - xdash) + step) {
			score++;
			cout << score << endl;
			cout << xs1b1 + 60 - xdash << endl;



		
		}

		if (((ballposx >= xs1b2 - xdash && ballposx <= xs1b2 + 60 - xdash) && (ballposy <= ys1b2h || ballposy >= ys1b2y))) {

			falld = (ys1b2h + ys1b2y) / 2 - 225;
			cout << "CRASH1" << endl;
			lives--;
			score--;


		}
		else if (ballposx > (xs1b2 + 60 - xdash) && ballposx < (xs1b2 + 60 - xdash) + step) {

			score++;
			cout << score << endl;
			cout << xs1b2 + 60 - xdash << endl;

		
		}

		if (((ballposx >= xs1b3 - xdash && ballposx <= xs1b3 + 60 - xdash) && (ballposy <= ys1b3h || ballposy >= ys1b3y))) {


			falld = (ys1b3h + ys1b3y) / 2 - 225;
			cout << "CRASH1" << endl;
			lives--;
			score--;


		}
		else if (ballposx > (xs1b3 + 60 - xdash) && ballposx < (xs1b3 + 60 - xdash) + step) {
			score++;
			cout << score << endl;
			cout << xs1b3 + 60 - xdash << endl;

		}
		
		if (((ballposx >= xs1b4 - xdash && ballposx <= xs1b4 + 60 - xdash) && (ballposy <= ys1b4h || ballposy >= ys1b4y))) {


			falld = (ys1b4h + ys1b4y) / 2 - 225;
			cout << "CRASH1" << endl;
			lives--;
			score--;


		}
		else if (ballposx > (xs1b4 + 60 - xdash) && ballposx < (xs1b4 + 60 - xdash) + step) {
			score++;
			cout << score << endl;
			cout << xs1b4 + 60 - xdash << endl;

		}




		if (((ballposx >= xs2b1 - xdash && ballposx <= xs2b1 + 60 - xdash) && (ballposy <= ys2b1h || ballposy >= ys2b1y))) {
			falld = (ys2b1h + ys2b1y) / 2 - 225;
			cout << "CRASH2" << endl;
			lives--;
			score--;

		}
		else if (ballposx > (xs2b1 + 60 - xdash) && ballposx < (xs2b1 + 60 - xdash) + step) {
			score++;
			cout << score << endl;
			cout << xs2b1 + 60 - xdash << endl;

		}

		if (((ballposx >= xs2b2 - xdash && ballposx <= xs2b2 + 60 - xdash) && (ballposy <= ys2b2h || ballposy >= ys2b2y))) {
			falld = (ys2b2h + ys2b2y) / 2 - 225;
			cout << "CRASH2" << endl;
			lives--;
			score--;


		}
		else if (ballposx > (xs2b2 + 60 - xdash) && ballposx < (xs2b2 + 60 - xdash) + step) {
			score++;
			cout << score << endl;
			cout << xs2b2 + 60 - xdash << endl;

		}

		if (((ballposx >= xs2b3 - xdash && ballposx <= xs2b3 + 60 - xdash) && (ballposy <= ys2b3h || ballposy >= ys2b3y))) {
			falld = (ys2b3h + ys2b3y) / 2 - 225;
			cout << "CRASH2" << endl;
			lives--;
			score--;


		}
		else if (ballposx > (xs2b3 + 60 - xdash) && ballposx < (xs2b3 + 60 - xdash) + step) {
			score++;
			cout << score << endl;
			cout << xs2b3 + 60 - xdash << endl;

		}

		if (((ballposx >= xs2b4 - xdash && ballposx <= xs2b4 + 60 - xdash) && (ballposy <= ys2b4h || ballposy >= ys2b4y))) {
			falld = (ys2b4h + ys2b4y) / 2 - 225;
			cout << "CRASH2" << endl;
			lives--;
			score--;


		}
		else if (ballposx > (xs2b4 + 60 - xdash) && ballposx < (xs2b4 + 60 - xdash) + step) {
			score++;
			cout << score << endl;
			cout << xs2b4 + 60 - xdash << endl;

		}




		if (((ballposx >= xs3b1 - xdash && ballposx <= xs3b1 + 60 - xdash) && (ballposy <= ys3b1h || ballposy >= ys3b1y))) {
			falld = (ys3b1h + ys3b1y) / 2 - 225;
			cout << "CRASH3" << endl;
			lives--;
			score--;

		}
		else if (ballposx > (xs3b1 + 60 - xdash) && ballposx < (xs3b1 + 60 - xdash)+step) {
			score++;
			cout << score << endl;
			cout << xs3b1 + 60 - xdash << endl;

		}

		if (((ballposx >= xs3b2 - xdash && ballposx <= xs3b2 + 60 - xdash) && (ballposy <= ys3b2h || ballposy >= ys3b2y))) {
			falld = (ys3b2h + ys3b2y) / 2 - 225;
			cout << "CRASH3" << endl;
			lives--;
			score--;


		}
		else if (ballposx > (xs3b2 + 60 - xdash) && ballposx < (xs3b2 + 60 - xdash) + step) {
			score++;
			cout << score << endl;
			cout << xs3b2 + 60 - xdash << endl;

		}

		if (((ballposx >= xs3b3 - xdash && ballposx <= xs3b3 + 60 - xdash) && (ballposy <= ys3b3h || ballposy >= ys3b3y))) {
			falld = (ys3b3h + ys3b3y) / 2 - 225;
			cout << "CRASH3" << endl;
			lives--;
			score--;


		}
		else if (ballposx > (xs3b3 + 60 - xdash) && ballposx < (xs3b3 + 60 - xdash) + step) {
			score++;
			cout << score << endl;
			cout << xs3b3 + 60 - xdash << endl;

		}

		/*if (((ballposx >= xs3b4 - xdash && ballposx <= xs3b4 + 60 - xdash) && (ballposy <= ys3b4h || ballposy >= ys3b4y))) {
			falld = (ys3b4h + ys3b4y) / 2 - 225;
			cout << "CRASH3" << endl;
			lives--;

		}*/

	}


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


void key(unsigned char k, int x, int y)
{
	if (k == 32) jump = 1; if(!gamerun)startgame = 1;
	glutPostRedisplay();//redisplay to update the screen with the changed

}


void Timer(int value) {

	if (!gameover) {
		timeElapsed += FPS / 1000.0;
	}
	glutTimerFunc(FPS, Timer, 0);
	glutPostRedisplay();
}

void drawTimer() {
	string timeString = "";
	if (gamerun) {
		 timeString = "Time : " + to_string(int(timeElapsed)) + " s";
	}
	else {
		 timeString = "Time : 0 s";
	}
		drawBitmapText(timeString, screenwidth - 95, 10, 0);
	
}

void drawLives() {
	string livestring = "Lives : " + to_string(int(lives));
	drawBitmapText(livestring, 10, 10, 0);
}

void drawScore() {

	string timeString = "";
	if (gamerun) {
		timeString = to_string(int(score));
	}
	else {
		timeString = "0";
	}
	drawBitmapText(timeString, screenwidth/2 - 7, screenheight - 30, 0);
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT);

	if (!gameover) {

		

		drawbird();
		drawBars(sset);
		drawScore();
		drawTimer();
		drawLives();
		glPushMatrix();
		if (!startgame) {
			drawBitmapText("Press SPACEBAR to start", screenwidth / 2 - 70, screenheight / 2, 0);
		}
		else {
			gamerun = 1;
		}
		glPopMatrix();

		collisionActions();
	}
	else {

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

		if (gamewin) {
			drawBitmapText("You Won!", 400, 300, 0);
			drawBitmapText("You managed to escape in " + patch::to_string(int(timeElapsed)) + " seconds", 305, 270, 0);
			drawBitmapText("with a score of "+ patch::to_string(int(score)),375 , 240, 0);

//			drawBitmapText("Press R to restart", 385, 230, 0);
		}
		else {

			string timeString = "Game Over :(";
			drawBitmapText(timeString, screenwidth / 2 - 50, screenheight / 2 - 7, 0);
			drawBitmapText("Your score is " + patch::to_string(int(score)), screenwidth / 2 - 60, screenheight / 2 - 37, 0);
		}

	}


	glFlush();
}

void Anim()
{
	if (gamerun) xdash += step;
	if (gameover) xdash += 0.2;
	glutPostRedisplay();
}

void main(int argc, char** argr) {
	glutInit(&argc, argr);

	glutInitWindowSize(screenwidth, screenheight);
	glutInitWindowPosition(150, 150);

	glutCreateWindow("Flappy Bird");
	glutDisplayFunc(Display);
	glutTimerFunc(0, Timer, 0);
	glutKeyboardFunc(key);			//call the keyboard function
	glutIdleFunc(Anim);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	gluOrtho2D(0.0, screenwidth, 0.0, screenheight);

	glutMainLoop();
}