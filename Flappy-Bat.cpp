#include <stdio.h>
#include <math.h>
#include <random>
#include <list>
#include <string>
#include <sstream>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <tchar.h>


#include <cstdlib>   // rand and srand
//#include "TextureBuilder.h"
#include <glut.h>

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
//
//GLuint texID;
//int rep = 2;

int screenwidth = 600; //360
int screenheight = 450;

int FPS = 30;
float timeElapsed = 0.0;
int barwidth = 60;

double ftime = 0.08;
double xdash = 0.0;
double step = 0.09;
double falld = 0;
double slided = 0;
double rot = 0;
int jump = 0;


int start = screenwidth - screenwidth / 3;
int lives = 3;
int score = 0;
float powerupx = 0;
float powerupy = 0;
int powerupon = 0;
int powerset = 0;

int startgame = 0;
int gamerun = 0;
int gameover = 0;
int gamewin = 0;

// Get the system time.
unsigned seed = time(0);

int sset = rand() % 3 + 1;
int rand2 = rand() % 2 + 1;

	

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
int ys3b4h = 270;

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
int ys3b4y = 400;

int finishline = 0;


void drawBitmapText(string text, float x, float y, float z);
void drawcircle(int x, int y, int r);
void drawbird();
void drawrectangle(int x, int y, int w, int h);
void drawBars(int sset);
void drawPowerUp(int x,int y);
void Display();


void drawcircle(int x, int y, int r) {
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(x, y, 0);
	GLUquadric* quadObj = gluNewQuadric();
	gluDisk(quadObj, 0, r, 50, 50);
	glPopMatrix();
}


void drawbird() {

	glPushMatrix();
	glTranslatef(slided, falld, 0);
	glColor3f(1, 1, 1);
	
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
	int cx = screenwidth / 9;
	int cy = screenheight / 2;



	drawcircle(cx, cy, 10);

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
	glVertex2f(cx - 7.5, cy + 7);
	glVertex2f(cx + 7.5, cy + 7);
	glVertex2f(cx + 11, cy + 0);
	glVertex2f(cx - 11, cy + 0);
	glEnd();
	
	drawcircle(cx+5, cy+4, 2.5);

	glColor3f(0.3, 0.3, 0.3);
	drawrectangle(cx - 15, cy + 1, 5, 3); 

	glBegin(GL_POLYGON);
	glColor3f(1, 0.5, 0);
	glVertex2f(cx + 10, cy + 3);
	glVertex2f(cx + 15, cy);
	glVertex2f(cx + 10, cy-3);
	glEnd();



	glPopMatrix();
}

void drawPowerUp(int x, int y) {

	glPushMatrix();


	if (!powerupon) {
		
		glBegin(GL_POLYGON);

		glColor3f(0, 0.9, 1);
		glVertex2f(x,y - 10);
		glVertex2f(x + 10, y);
		glVertex2f(x + 5, y + 5);
		glVertex2f(x - 5, y + 5);
		glVertex2f(x - 10, y);

		glEnd();


		glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glVertex2f(x - 10, y);
		glVertex2f(x + 10, y);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glVertex2f(x - 5, y);
		glVertex2f(x, y - 10);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glVertex2f(x - 4 , y );
		glVertex2f(x, y - 10);
		glEnd();

		//glBegin(GL_LINES);
		//glColor3f(1, 1, 1);
		//glVertex2f(x - 3, y);
		//glVertex2f(x, y - 10);
		//glEnd();

		glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glVertex2f(x - 2, y);
		glVertex2f(x, y - 10);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glVertex2f(x + 2, y);
		glVertex2f(x, y - 10);
		glEnd();


		glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glVertex2f(x - 4, y);
		glVertex2f(x-2, y +5);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glVertex2f(x + 4, y);
		glVertex2f(x+2, y+5);
		glEnd();



		//glBegin(GL_LINES);
		//glColor3f(1, 1, 1);
		//glVertex2f(x + 3, y);
		//glVertex2f(x, y - 10);
		//glEnd();

		glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glVertex2f(x + 4, y);
		glVertex2f(x, y - 10);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glVertex2f(x + 5, y);
		glVertex2f(x, y - 10);
		glEnd();

	}
	glPopMatrix();
}



void drawbarrier(int x, int y, int w, int h) {

}



void drawrectangle(int x, int y, int w, int h) {
	

	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
		glVertex2f(x, y+h);
		glVertex2f(x+w, y+h);
	glEnd();
	glPopMatrix();

	glBegin(GL_POLYGON);
	glVertex3f(x, y, 0.0f);
	glVertex3f(x + w, y, 0.0f);
	glVertex3f(x + w, y + h, 0.0f);
	glVertex3f(x, y + h, 0.0f);
	glEnd();

}
//
//void drawbackground() {
//
//	//glClear(GL_COLOR_BUFFER_BIT);
//	
//	glPushMatrix();
//	glBindTexture(GL_TEXTURE_2D, texID);
//	//important
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT); //(s,R)
//
//	glBegin(GL_QUADS);
//	glTexCoord2f(0.0f, 0.0f); //take color from loaded texture
//	glVertex3f(0, 0, 0);
//
//	glTexCoord2f(rep, 0.0f); //rep: repeat  - hy-map 0,0 1,0
//	glVertex3f(0, screenheight, 0);
//
//	glTexCoord2f(rep, rep);
//	glVertex3f(screenwidth, screenheight, 0);
//
//	glTexCoord2f(0.0f, rep);
//	glVertex3f(screenwidth, 0, 0);
//
//	glEnd();
//
//	glPopMatrix();
//}


void set1(int startpos) {
	//glPushMatrix();
	if (powerupon && powerset == 1) {
		glColor3f(0, 0.9, 1);


	}
	else {
		glColor3f(0.7, 0.7, 0.7);
	}
	

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
	if (powerupon && powerset == 2) {

		glColor3f(0, 0.9, 1);
	}
	else {
		glColor3f(0.5, 0.5, 0.5);
	}

	//glPushMatrix();
	
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

	if (powerupon && powerset == 3) {

		glColor3f(0, 0.9, 1);

	}
	else {
		glColor3f(0.3, 0.3, 0.3);
	}

	//	glPushMatrix();
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
	startpos += 150;
	drawrectangle(startpos, 0, barwidth, ys3b4h);
	drawrectangle(startpos, ys3b4y, barwidth, 195);
	xs3b4 = startpos;
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



		if (rand2 == 2) {
			set1(start);
			set3(start + 455 + 150);
			set2(start + 910 + 150 + 150);

		}
		else if (rand2 == 1) {
			set1(start);
			set2(start + 455 + 150);
			set3(start + 910 + 150 + 150);

		}

		

		Finish_Line(start + 1365 + 150 + 150 + 100);
		break;

	case 2:



		if (rand2 == 2) {

			set2(start);
			set1(start + 455 + 150);
			set3(start + 910 + 150 + 150);

		}
		else if (rand2 == 1) {


			set2(start);
			set3(start + 455 + 150);
			set1(start + 910 + 150 + 150);
		}


		Finish_Line(start + 1365 + 150 + 150 + 100);
		break;
	case 3:

		if (rand2 == 2) {

			set3(start);
			set2(start + 455 + 150);
			set1(start + 910 + 150 + 150);
		}
		else if (rand2 == 1) {

			set3(start);
			set1(start + 455 + 150);
			set2(start + 910 + 150 + 150);
		}

		Finish_Line(start + 1365 + 150 + 150 + 100);

		break;


	default:
		break;
	}
	glPopMatrix();
}



void addPowers() {
	
	if (sset == 3 && rand2 == 1) {
		powerupx = xs1b1 + 30 - xdash;
		powerupy = (ys1b1h + ys1b1y) / 2;
		drawPowerUp(powerupx, powerupy);
		powerset = 1;
	}
	else if (sset == 3 && rand2 == 2) {

		powerupx = xs2b1 + 30 - xdash;
		powerupy = (ys2b1h + ys2b1y) / 2;
		drawPowerUp(powerupx, powerupy);
		powerset = 2;
	
	}
	else if (sset == 2 && rand2 == 1) {
		powerupx = xs3b1 + 30 - xdash;
		powerupy = (ys3b1h + ys3b1y) / 2;
		drawPowerUp(powerupx, powerupy);
		powerset = 3;
	}
	else if (sset == 2 && rand2 == 2) {
		powerupx = xs1b1 + 30 - xdash;
		powerupy = (ys1b1h + ys1b1y) / 2;
		drawPowerUp(powerupx, powerupy);
		powerset = 1;

	}
	else if (sset == 1 && rand2 == 1) {
		powerupx = xs2b1 + 30 - xdash;
		powerupy = (ys2b1h + ys2b1y) / 2;
		drawPowerUp(powerupx, powerupy);
		powerset = 2;
	}
	else if (sset == 1 && rand2 == 2) {

		powerupx = xs3b1 + 30 - xdash;
		powerupy = (ys3b1h + ys3b1y) / 2;
		drawPowerUp(powerupx, powerupy);
		powerset = 3;

	}

	

}


void collisionActions() {



	if (falld < - screenheight / 2  - 13) {
		gameover = 1;
		gamewin = 0;
		gamerun = 0;

	}

	if (falld > screenheight / 2 + 13) {
		gameover = 1;
		gamerun = 0;
		gamewin = 0;
	}

	if (lives <= 0) {
	
		gameover = 1;
		gamerun = 0;
		gamewin = 0;

	}


	int ballposy = falld + 225;
	int ballposx = screenwidth / 9;

	if (ballposx >= finishline - xdash) {
	
		gamerun = 0;
		gamewin = 1;
		gameover = 1;
		cout << "finished!!" << endl;
	}


	if (ballposx > powerupx -10 && ballposx < powerupx +9  && ballposy > powerupy - 19 && ballposy < powerupy + 9) {
		//sndPlaySound(TEXT("/audio/solid.wav"), SND_ASYNC);
		//bool played1=sndPlaySound (_T("/audio/solid.wav"),  SND_ASYNC);
		powerupon = 1;
		PlaySound( TEXT("powerup.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}

	if (ballposx >= xs1b1 -xdash  && ballposx < xs1b4 + 60 - xdash) {
		if (powerset != 1) {
			powerupon = 0;
		}
	}
	if (ballposx >= xs2b1 - xdash && ballposx < xs2b4 + 60 - xdash) {
		if (powerset != 2) {
			powerupon = 0;
		}
	}
	
	if (ballposx >= xs3b1 - xdash && ballposx < xs3b4 +60 - xdash) {
		if (powerset != 3) {
			powerupon = 0;
		}
	}


	if (gamerun) {



		if (((ballposx >= xs1b1 - xdash && ballposx <= xs1b1 + 60 - xdash) && (ballposy <= ys1b1h || ballposy >= ys1b1y))) {
			falld = (ys1b1h + ys1b1y) / 2 - 225;
			PlaySound(TEXT("/audio/solid.wav"), NULL, SND_FILENAME | SND_ASYNC);

			//cout << "CRASH1" << endl;
			if (!powerupon) {
				lives--;
				score--;
				if (score <= 0) {
					score = 0;
				}
			}
			

		}
		else if (ballposx > (xs1b1 + 60 - xdash) && ballposx < (xs1b1 + 60 - xdash) + step) {
			score++;
		/*	cout << score << endl;
			cout << xs1b1 + 60 - xdash << endl;*/



		
		}

		if (((ballposx >= xs1b2 - xdash && ballposx <= xs1b2 + 60 - xdash) && (ballposy <= ys1b2h || ballposy >= ys1b2y))) {

			falld = (ys1b2h + ys1b2y) / 2 - 225;
			PlaySound(TEXT("/audio/solid.wav"), NULL, SND_FILENAME | SND_ASYNC);

		//	cout << "CRASH1" << endl;
			if (!powerupon) {
				lives--;
				score--;
				if (score <= 0) {
					score = 0;
				}
			}


		}
		else if (ballposx > (xs1b2 + 60 - xdash) && ballposx < (xs1b2 + 60 - xdash) + step) {

			score++;
		/*	cout << score << endl;
			cout << xs1b2 + 60 - xdash << endl;*/

		
		}

		if (((ballposx >= xs1b3 - xdash && ballposx <= xs1b3 + 60 - xdash) && (ballposy <= ys1b3h || ballposy >= ys1b3y))) {


			falld = (ys1b3h + ys1b3y) / 2 - 225;
			PlaySound(TEXT("/audio/solid.wav"), NULL, SND_FILENAME | SND_ASYNC);

		//	cout << "CRASH1" << endl;
			if (!powerupon) {
				lives--;
				score--;
				if (score <= 0) {
					score = 0;
				}
			}


		}
		else if (ballposx > (xs1b3 + 60 - xdash) && ballposx < (xs1b3 + 60 - xdash) + step) {
			score++;
			/*cout << score << endl;
			cout << xs1b3 + 60 - xdash << endl;*/

		}
		
		if (((ballposx >= xs1b4 - xdash && ballposx <= xs1b4 + 60 - xdash) && (ballposy <= ys1b4h || ballposy >= ys1b4y))) {


			falld = (ys1b4h + ys1b4y) / 2 - 225;
			PlaySound(TEXT("/audio/solid.wav"), NULL, SND_FILENAME | SND_ASYNC);

			//cout << "CRASH1" << endl;
			if (!powerupon) {
				lives--;
				score--;
				if (score <= 0) {
					score = 0;
				}
			}


		}
		else if (ballposx > (xs1b4 + 60 - xdash) && ballposx < (xs1b4 + 60 - xdash) + step) {
			score++;
		/*	cout << score << endl;
			cout << xs1b4 + 60 - xdash << endl;*/

		}




		if (((ballposx >= xs2b1 - xdash && ballposx <= xs2b1 + 60 - xdash) && (ballposy <= ys2b1h || ballposy >= ys2b1y))) {
			falld = (ys2b1h + ys2b1y) / 2 - 225;
			PlaySound(TEXT("/audio/solid.wav"), NULL, SND_FILENAME | SND_ASYNC);

			//cout << "CRASH2" << endl;
			if (!powerupon) {
				lives--;
				score--;
				if (score <= 0) {
					score = 0;
				}
			}

		}
		else if (ballposx > (xs2b1 + 60 - xdash) && ballposx < (xs2b1 + 60 - xdash) + step) {
			score++;
		/*	cout << score << endl;
			cout << xs2b1 + 60 - xdash << endl;*/

		}

		if (((ballposx >= xs2b2 - xdash && ballposx <= xs2b2 + 60 - xdash) && (ballposy <= ys2b2h || ballposy >= ys2b2y))) {
			falld = (ys2b2h + ys2b2y) / 2 - 225;
			PlaySound(TEXT("/audio/solid.wav"), NULL, SND_FILENAME | SND_ASYNC);

		//	cout << "CRASH2" << endl;
			if (!powerupon) {
				lives--;
				score--;
				if (score <= 0) {
					score = 0;
				}
			}

		}
		else if (ballposx > (xs2b2 + 60 - xdash) && ballposx < (xs2b2 + 60 - xdash) + step) {
			score++;
			/*cout << score << endl;
			cout << xs2b2 + 60 - xdash << endl;*/

		}

		if (((ballposx >= xs2b3 - xdash && ballposx <= xs2b3 + 60 - xdash) && (ballposy <= ys2b3h || ballposy >= ys2b3y))) {
			falld = (ys2b3h + ys2b3y) / 2 - 225;
			PlaySound(TEXT("/audio/solid.wav"), NULL, SND_FILENAME | SND_ASYNC);

		//	cout << "CRASH2" << endl;
			if (!powerupon) {
				lives--;
				score--;
				if (score <= 0) {
					score = 0;
				}
			}

		}
		else if (ballposx > (xs2b3 + 60 - xdash) && ballposx < (xs2b3 + 60 - xdash) + step) {
			score++;
		/*	cout << score << endl;
			cout << xs2b3 + 60 - xdash << endl;*/

		}

		if (((ballposx >= xs2b4 - xdash && ballposx <= xs2b4 + 60 - xdash) && (ballposy <= ys2b4h || ballposy >= ys2b4y))) {
			falld = (ys2b4h + ys2b4y) / 2 - 225;
			PlaySound(TEXT("/audio/solid.wav"), NULL, SND_FILENAME | SND_ASYNC);

		//	cout << "CRASH2" << endl;
			if (!powerupon) {
				lives--;
				score--;
				if (score <= 0) {
					score = 0;
				}
			}

		}
		else if (ballposx > (xs2b4 + 60 - xdash) && ballposx < (xs2b4 + 60 - xdash) + step) {
			score++;
		/*	cout << score << endl;
			cout << xs2b4 + 60 - xdash << endl;*/

		}




		if (((ballposx >= xs3b1 - xdash && ballposx <= xs3b1 + 60 - xdash) && (ballposy <= ys3b1h || ballposy >= ys3b1y))) {
			falld = (ys3b1h + ys3b1y) / 2 - 225;
			PlaySound(TEXT("/audio/solid.wav"), NULL, SND_FILENAME | SND_ASYNC);

		//	cout << "CRASH3" << endl;
			if (!powerupon) {
				lives--;
				score--;
				if (score <= 0) {
					score = 0;
				}
			}
		}
		else if (ballposx > (xs3b1 + 60 - xdash) && ballposx < (xs3b1 + 60 - xdash)+step) {
			score++;
		/*	cout << score << endl;
			cout << xs3b1 + 60 - xdash << endl;*/

		}

		if (((ballposx >= xs3b2 - xdash && ballposx <= xs3b2 + 60 - xdash) && (ballposy <= ys3b2h || ballposy >= ys3b2y))) {
			falld = (ys3b2h + ys3b2y) / 2 - 225;
			PlaySound(TEXT("/audio/solid.wav"), NULL, SND_FILENAME | SND_ASYNC);

		//	cout << "CRASH3" << endl;
			if (!powerupon) {
				lives--;
				score--;
				if (score <= 0) {
					score = 0;
				}
			}

		}
		else if (ballposx > (xs3b2 + 60 - xdash) && ballposx < (xs3b2 + 60 - xdash) + step) {
			score++;
		/*	cout << score << endl;
			cout << xs3b2 + 60 - xdash << endl;*/

		}

		if (((ballposx >= xs3b3 - xdash && ballposx <= xs3b3 + 60 - xdash) && (ballposy <= ys3b3h || ballposy >= ys3b3y))) {
			falld = (ys3b3h + ys3b3y) / 2 - 225;
			PlaySound(TEXT("/audio/solid.wav"), NULL, SND_FILENAME | SND_ASYNC);

		//	cout << "CRASH3" << endl;
			if (!powerupon) {
				lives--;
				score--;
				if (score <= 0) {
					score = 0;
				}
			}
		}
		else if (ballposx > (xs3b3 + 60 - xdash) && ballposx < (xs3b3 + 60 - xdash) + step) {
			score++;
		/*		cout << score << endl;
				cout << xs3b3 + 60 - xdash << endl;*/

		}

		if (((ballposx >= xs3b4 - xdash && ballposx <= xs3b4 + 60 - xdash) && (ballposy <= ys3b4h || ballposy >= ys3b4y))) {

			falld = (ys3b4h + ys3b4y) / 2 - 225;
			PlaySound(TEXT("/audio/solid.wav"), NULL, SND_FILENAME | SND_ASYNC);

		//	cout << "CRASH3" << endl;
			if (!powerupon) {
				lives--;
				score--;
				if (score <= 0) {
					score = 0;
				}
			}
		}
		else if (ballposx > (xs3b4 + 60 - xdash) && ballposx < (xs3b4 + 60 - xdash) + step) {
			score++;
			/*		cout << score << endl;
					cout << xs3b3 + 60 - xdash << endl;*/

		}

		

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
	//drawbackground();
	if (!gameover) {

		addPowers();
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

			drawBitmapText("You Won!", screenwidth / 2 - 50, 300, 0);
			drawBitmapText("You managed to escape in " + patch::to_string(int(timeElapsed)) + " seconds", screenwidth/ 2 - 150 , 270, 0);
			drawBitmapText("with a score of "+ patch::to_string(int(score)) +".", screenwidth / 2 - 75 , 240, 0);

//			drawBitmapText("Press R to restart", 385, 230, 0);
		}
		else {
			for (int i = 0; i < 300000000;i++);


			string timeString = "Game Over :(";
			drawBitmapText(timeString, screenwidth / 2 - 50, screenheight / 2 - 7, 0);
			drawBitmapText("Your score is " + patch::to_string(int(score)), screenwidth / 2 - 60, screenheight / 2 - 37, 0);
		}

	}


	glFlush();
}

void Anim()
{
	if (gamerun)
	{
		xdash += step;
		rot += 0.05;
	}
	if (gameover) xdash += 0.2;
	glutPostRedisplay();
}

void main(int argc, char** argr) {
	glutInit(&argc, argr);

	// Seed the random number generator.
	srand(seed);

	sset = rand() % 3 + 1;
	rand2 = rand() % 2 + 1;

	glutInitWindowSize(screenwidth, screenheight);
	glutInitWindowPosition(150, 150);

	glutCreateWindow("Flappy Bird");
	glutDisplayFunc(Display);
	glutTimerFunc(0, Timer, 0);
	glutKeyboardFunc(key);			//call the keyboard function
	glutIdleFunc(Anim);
	//glEnable(GL_TEXTURE_2D);

	//loadBMP(&texID, "Textures/brickwall2.bmp", true);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	gluOrtho2D(0.0, screenwidth, 0.0, screenheight);

	glutMainLoop();
}