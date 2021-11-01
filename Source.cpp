//#include <time.h>
//#include <stdlib.h>
//#include <iostream>
//#include <Windows.h>
//#include <MMSystem.h>
//#include <glut.h>
//
//GLuint stars;
//GLuint lightSpeed;
//
//int starsX = 0;
//int lightSpeedX = 0;
//
//int rep = 1;
//
//int shipX = 0;
//int shipY = 0;
//
//float t = 1.0;  //powerUp
//float t1 = 1.0; //obstacle
//
//int currentPowerUp = rand() % 5 + 1;
//
//int powerUpX_500 = 0; //5
//int powerUpY_500 = 0; //5
//int powerUpX_400 = 0; //4
//int powerUpY_400 = 0; //4
//int powerUpX_300 = 0; //3
//int powerUpY_300 = 0; //3
//int powerUpX_200 = 0; //2
//int powerUpY_200 = 0; //2
//int powerUpX_100 = 0; //1
//int powerUpY_100 = 0; //1
//
//int currentObstacle = rand() % 6 + 1;
//
//int obstacleX_550 = 0; //6 
//int obstacleY_550 = 0; //6 
//int obstacleX_450 = 0; //5
//int obstacleY_450 = 0; //5
//int obstacleX_350 = 0; //4
//int obstacleY_350 = 0; //4
//int obstacleX_250 = 0; //3
//int obstacleY_250 = 0; //3
//int obstacleX_150 = 0; //2
//int obstacleY_150 = 0; //2
//int obstacleX_50 = 0; //1
//int obstacleY_50 = 0; //1
//
//bool won = false;
//bool lost = false;
//bool endGame = false;
//
//int obstacleCounter = 0;
//bool okayToPowerUp = false;
//
//void drawDestination() {
//	glPushMatrix();
//	glColor3f(0.725f, 0.612f, 0.420f);
//	glTranslatef(900, 300, 0);
//	GLUquadric* quadObj1 = gluNewQuadric();
//	gluDisk(quadObj1, 0, 200, 8, 8);
//	glPopMatrix();
//}
//
//void drawMainObject() {
//
//	glPushMatrix();
//
//	glTranslatef(shipX - 50, shipY, 0);
//
//	glBegin(GL_TRIANGLES);
//	glColor3f(0.0f, 0.0f, 0.35f);
//	glVertex3f(500.0f, 325.0f, 0.0f);
//	glVertex3f(525.0f, 300.0f, 0.0f);
//	glVertex3f(500.0f, 275.0f, 0.0f);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glColor3f(0.0f, 0.0f, 0.4f);
//	glVertex3f(500.0f, 325.0f, 0.0f);
//	glVertex3f(500.0f, 275.0f, 0.0f);
//	glVertex3f(400.0f, 275.0f, 0.0f);
//	glVertex3f(400.0f, 325.0f, 0.0f);
//	glEnd();
//
//	glPushMatrix();
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glTranslatef(470, 300, 0);
//	GLUquadric* quadObj = gluNewQuadric();
//	gluDisk(quadObj, 0, 15, 50, 50);
//	glPopMatrix();
//
//	glPushMatrix();
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glTranslatef(430, 300, 0);
//	GLUquadric* quadObj1 = gluNewQuadric();
//	gluDisk(quadObj1, 0, 15, 50, 50);
//	glPopMatrix();
//
//	glBegin(GL_TRIANGLES);
//	glColor3f(0.2f, 0.2f, 0.2f);
//	glVertex3f(400.0f, 325.0f, 0.0f);
//	glVertex3f(430.0f, 325.0f, 0.0f);
//	glVertex3f(415.0f, 355.0f, 0.0f);
//	glEnd();
//
//	glBegin(GL_TRIANGLES);
//	glColor3f(0.2f, 0.2f, 0.2f);
//	glVertex3f(400.0f, 275.0f, 0.0f);
//	glVertex3f(430.0f, 275.0f, 0.0f);
//	glVertex3f(415.0f, 245.0f, 0.0f);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glColor3f(0.2f, 0.2f, 0.2f);
//	glVertex3f(400.0f, 325.0f, 0.0f);
//	glVertex3f(375.0f, 325.0f, 0.0f);
//	glVertex3f(375.0f, 275.0f, 0.0f);
//	glVertex3f(400.0f, 275.0f, 0.0f);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glColor3f(0.3f, 0.3f, 0.3f);
//	glVertex3f(395.0f, 320.0f, 0.0f);
//	glVertex3f(380.0f, 320.0f, 0.0f);
//	glVertex3f(380.0f, 280.0f, 0.0f);
//	glVertex3f(395.0f, 280.0f, 0.0f);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glColor3f(0.3f, 0.3f, 0.3f);
//	glVertex3f(490.0f, 275.0f, 0.0f);
//	glVertex3f(480.0f, 275.0f, 0.0f);
//	glVertex3f(480.0f, 265.0f, 0.0f);
//	glVertex3f(490.0f, 265.0f, 0.0f);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glColor3f(0.4f, 0.4f, 0.4f);
//	glVertex3f(480.0f, 265.0f, 0.0f);
//	glVertex3f(500.0f, 265.0f, 0.0f);
//	glVertex3f(500.0f, 245.0f, 0.0f);
//	glVertex3f(480.0f, 245.0f, 0.0f);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glColor3f(0.3f, 0.3f, 0.3f);
//	glVertex3f(490.0f, 325.0f, 0.0f);
//	glVertex3f(480.0f, 325.0f, 0.0f);
//	glVertex3f(480.0f, 335.0f, 0.0f);
//	glVertex3f(490.0f, 335.0f, 0.0f);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glColor3f(0.4f, 0.4f, 0.4f);
//	glVertex3f(480.0f, 355.0f, 0.0f);
//	glVertex3f(500.0f, 355.0f, 0.0f);
//	glVertex3f(500.0f, 335.0f, 0.0f);
//	glVertex3f(480.0f, 335.0f, 0.0f);
//	glEnd();
//
//	glPopMatrix();
//
//}
//
//int* bezier(float t, int* p0, int* p1, int* p2, int* p3)
//{
//	int res[2];
//	res[0] = pow((1 - t), 3) * p0[0] + 3 * t * pow((1 - t), 2) * p1[0] + 3 * pow(t, 2) * (1 - t) * p2[0] + pow(t, 3) * p3[0];
//	res[1] = pow((1 - t), 3) * p0[1] + 3 * t * pow((1 - t), 2) * p1[1] + 3 * pow(t, 2) * (1 - t) * p2[1] + pow(t, 3) * p3[1];
//	return res;
//}
//
//void Display(void) {
//
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	//////////background//////////
//
//	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
//
//	glEnable(GL_TEXTURE_2D);
//	glPushMatrix();
//	glTranslated(starsX, 0, 0);
//	glBindTexture(GL_TEXTURE_2D, stars);
//	glBegin(GL_QUADS);
//	glTexCoord2f(0.0f, 0.0f);			glVertex3f(0, 0, 0);
//	glTexCoord2f(rep, 0.0f);			glVertex3f(0, 600, 0);
//	glTexCoord2f(rep, rep);				glVertex3f(800, 600, 0);
//	glTexCoord2f(0.0f, rep);			glVertex3f(800, 0, 0);
//	glEnd();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslated(lightSpeedX, 0, 0);
//	glBindTexture(GL_TEXTURE_2D, lightSpeed);
//	glBegin(GL_QUADS);
//	glTexCoord2f(0.0f, 0.0f);			glVertex3f(800, 0, 0);
//	glTexCoord2f(rep, 0.0f);			glVertex3f(800, 600, 0);
//	glTexCoord2f(rep, rep);				glVertex3f(1600, 600, 0);
//	glTexCoord2f(0.0f, rep);			glVertex3f(1600, 0, 0);
//	glEnd();
//	glPopMatrix();
//	glDisable(GL_TEXTURE_2D);
//
//	//////////space ship//////////
//
//	drawMainObject();
//
//	//////////destination//////////
//
//	drawDestination();
//
//	//////////power ups//////////
//
//	glPushMatrix();
//	glColor3f(1, 1, 0);
//	glTranslated(powerUpX_500, powerUpY_500, 0);
//	glBegin(GL_POINTS);
//	glVertex3d(900, 500, 0);
//	glEnd();
//	glPopMatrix();
//
//	glPushMatrix();
//	glColor3f(1, 1, 0);
//	glTranslated(powerUpX_400, powerUpY_400, 0);
//	glBegin(GL_POINTS);
//	glVertex3d(900, 400, 0);
//	glEnd();
//	glPopMatrix();
//
//	glPushMatrix();
//	glColor3f(1, 1, 0);
//	glTranslated(powerUpX_300, powerUpY_300, 0);
//	glBegin(GL_POINTS);
//	glVertex3d(900, 300, 0);
//	glEnd();
//	glPopMatrix();
//
//	glPushMatrix();
//	glColor3f(1, 1, 0);
//	glTranslated(powerUpX_200, powerUpY_200, 0);
//	glBegin(GL_POINTS);
//	glVertex3d(900, 200, 0);
//	glEnd();
//	glPopMatrix();
//
//	glPushMatrix();
//	glColor3f(1, 1, 0);
//	glTranslated(powerUpX_100, powerUpY_100, 0);
//	glBegin(GL_POINTS);
//	glVertex3d(900, 100, 0);
//	glEnd();
//	glPopMatrix();
//
//	//////////obstacles//////////
//
//	glPushMatrix();
//	glColor3f(1.0f, 0.0f, 0.0f);
//	glTranslatef(900, 550, 0);
//	glTranslatef(obstacleX_550, obstacleY_550, 0);
//	GLUquadric* quadObj6 = gluNewQuadric();
//	gluDisk(quadObj6, 0, 12.5, 5, 5);
//	glPopMatrix();
//
//	glPushMatrix();
//	glColor3f(0.25f, 0.55f, 0.75f);
//	glTranslatef(900, 450, 0);
//	glTranslatef(obstacleX_450, obstacleY_450, 0);
//	GLUquadric* quadObj5 = gluNewQuadric();
//	gluDisk(quadObj5, 0, 12.5, 6, 6);
//	glPopMatrix();
//
//	glPushMatrix();
//	glColor3f(0.25f, 0.75f, 0.70f);
//	glTranslatef(900, 350, 0);
//	glTranslatef(obstacleX_350, obstacleY_350, 0);
//	GLUquadric* quadObj4 = gluNewQuadric();
//	gluDisk(quadObj4, 0, 12.5, 7, 7);
//	glPopMatrix();
//
//	glPushMatrix();
//	glColor3f(1.0f, 0.0f, 1.0f);
//	glTranslatef(900, 250, 0);
//	glTranslatef(obstacleX_250, obstacleY_250, 0);
//	GLUquadric* quadObj3 = gluNewQuadric();
//	gluDisk(quadObj3, 0, 12.5, 4, 4);
//	glPopMatrix();
//
//	glPushMatrix();
//	glColor3f(0.85f, 0.5f, 0.75f);
//	glTranslatef(900, 150, 0);
//	glTranslatef(obstacleX_150, obstacleY_150, 0);
//	GLUquadric* quadObj2 = gluNewQuadric();
//	gluDisk(quadObj2, 0, 12.5, 30, 30);
//	glPopMatrix();
//
//	glPushMatrix();
//	glColor3f(0.9f, 0.5f, 0.9f);
//	glTranslatef(900, 50, 0);
//	glTranslatef(obstacleX_50, obstacleY_50, 0);
//	GLUquadric* quadObj1 = gluNewQuadric();
//	gluDisk(quadObj1, 0, 12.5, 3, 3);
//	glPopMatrix();
//
//	glFlush();
//}
//
//
//void animate() {
//
//	//////////background//////////
//
//	if (starsX <= -798) {
//		starsX = 798;
//	}
//	if (lightSpeedX <= -1596) {
//		lightSpeedX = 0;
//	}
//	starsX -= 3;
//	lightSpeedX -= 3;
//	for (int i = 0; i < 10000000; i++);
//
//	//////////power ups//////////
//
//	if (okayToPowerUp && currentPowerUp == 5) {
//		if (t > 0) {
//			int p0[2] = { 0,553 };
//			int p1[2] = { 0,600 };
//			int p2[2] = { 800,600 };
//			int p3[2] = { 800,545 };
//			int* p = bezier(t, &p0[0], &p1[0], &p2[0], &p3[0]);
//			int x = p[0];
//			int y = p[1];
//			//to get to x,y 
//			//x = 900 - powerUpX_500
//			//y = 500 - powerUpY_500
//			powerUpX_500 = -(900 - x);
//			powerUpY_500 = -(500 - y);
//			t -= 0.01;
//		}
//		if (powerUpX_500 <= -900) {
//			powerUpX_500 = 0;
//			powerUpY_500 = 0;
//			t = 1.0;
//			currentPowerUp = rand() % 5 + 1; //generate random number between 1 and 5
//			okayToPowerUp = false;
//		}
//		if (powerUpX_500 + 900 >= shipX + 375 && powerUpX_500 + 900 <= shipX + 525 && powerUpY_500 + 500 <= shipY + 325 && powerUpY_500 + 500 >= shipY + 275) {
//			for (int i = 0; i < 10000000; i++);
//			shipX += 100;
//			powerUpX_500 = 0;
//			powerUpY_500 = 0;
//			t = 1.0;
//			currentPowerUp = rand() % 5 + 1;
//			okayToPowerUp = false;
//		}
//		powerUpX_500 -= 10;
//		if (powerUpX_500 <= -100 && powerUpX_500 >= -110) {
//		}
//		for (int i = 0; i < 10000000; i++);
//	}
//
//	if (okayToPowerUp && currentPowerUp == 4) {
//		if (t > 0) {
//			int p0[2] = { 0,275 };
//			int p1[2] = { 82,590 };
//			int p2[2] = { 665,26 };
//			int p3[2] = { 800,375 };
//			int* p = bezier(t, &p0[0], &p1[0], &p2[0], &p3[0]);
//			int x = p[0];
//			int y = p[1];
//			//to get to x,y 
//			//x = 900 - powerUpX_400
//			//y = 500 - powerUpY_400
//			powerUpX_400 = -(900 - x);
//			powerUpY_400 = -(400 - y);
//			t -= 0.01;
//		}
//		if (powerUpX_400 <= -900) {
//			powerUpX_400 = 0;
//			powerUpY_400 = 0;
//			t = 1.0;
//			currentPowerUp = rand() % 5 + 1; //generate random number between 1 and 5
//			okayToPowerUp = false;
//		}
//		if (powerUpX_400 + 900 >= shipX + 375 && powerUpX_400 + 900 <= shipX + 525 && powerUpY_400 + 400 <= shipY + 325 && powerUpY_400 + 400 >= shipY + 275) {
//			PlaySound(TEXT("powerUp-collide.wav"), NULL, SND_FILENAME | SND_ASYNC);
//			for (int i = 0; i < 10000000; i++);
//			shipX += 100;
//			powerUpX_400 = 0;
//			powerUpY_400 = 0;
//			t = 1.0;
//			currentPowerUp = rand() % 5 + 1;
//			okayToPowerUp = false;
//		}
//		powerUpX_400 -= 10;
//		if (powerUpX_400 <= -100 && powerUpX_400 >= -110) {
//		}
//		for (int i = 0; i < 10000000; i++);
//	}
//
//	if (okayToPowerUp && currentPowerUp == 3) {
//		if (t > 0) {
//			int p0[2] = { 0,450 };
//			int p1[2] = { 0,350 };
//			int p2[2] = { 800,450 };
//			int p3[2] = { 800,350 };
//			int* p = bezier(t, &p0[0], &p1[0], &p2[0], &p3[0]);
//			int x = p[0];
//			int y = p[1];
//			//to get to x,y 
//			//x = 900 - powerUpX_300
//			//y = 500 - powerUpY_300
//			powerUpX_300 = -(900 - x);
//			powerUpY_300 = -(300 - y);
//			t -= 0.01;
//		}
//		if (powerUpX_300 <= -900) {
//			powerUpX_300 = 0;
//			powerUpY_300 = 0;
//			t = 1.0;
//			currentPowerUp = rand() % 5 + 1; //generate random number between 1 and 5
//			okayToPowerUp = false;
//		}
//		if (powerUpX_300 + 900 >= shipX + 375 && powerUpX_300 + 900 <= shipX + 525 && powerUpY_300 + 300 <= shipY + 325 && powerUpY_300 + 300 >= shipY + 275) {
//			for (int i = 0; i < 10000000; i++);
//			shipX += 100;
//			powerUpX_300 = 0;
//			powerUpY_300 = 0;
//			t = 1.0;
//			currentPowerUp = rand() % 5 + 1;
//			okayToPowerUp = false;
//		}
//		powerUpX_300 -= 10;
//		if (powerUpX_300 <= -100 && powerUpX_300 >= -110) {
//		}
//		for (int i = 0; i < 10000000; i++);
//	}
//
//	if (okayToPowerUp && currentPowerUp == 2) {
//		if (t > 0) {
//			int p0[2] = { 0,250 };
//			int p1[2] = { 0,350 };
//			int p2[2] = { 800,250 };
//			int p3[2] = { 800,350 };
//			int* p = bezier(t, &p0[0], &p1[0], &p2[0], &p3[0]);
//			int x = p[0];
//			int y = p[1];
//			//to get to x,y 
//			//x = 900 - powerUpX_200
//			//y = 500 - powerUpY_200
//			powerUpX_200 = -(900 - x);
//			powerUpY_200 = -(200 - y);
//			t -= 0.01;
//		}
//		if (powerUpX_200 <= -900) {
//			powerUpX_200 = 0;
//			powerUpY_200 = 0;
//			t = 1.0;
//			currentPowerUp = rand() % 5 + 1; //generate random number between 1 and 5
//			okayToPowerUp = false;
//		}
//		if (powerUpX_200 + 900 >= shipX + 375 && powerUpX_200 + 900 <= shipX + 525 && powerUpY_200 + 200 <= shipY + 325 && powerUpY_200 + 200 >= shipY + 275) {
//			for (int i = 0; i < 10000000; i++);
//			shipX += 100;
//			powerUpX_200 = 0;
//			powerUpY_200 = 0;
//			t = 1.0;
//			currentPowerUp = rand() % 5 + 1;
//			okayToPowerUp = false;
//		}
//		powerUpX_200 -= 10;
//		if (powerUpX_200 <= -100 && powerUpX_200 >= -110) {
//		}
//		for (int i = 0; i < 10000000; i++);
//	}
//
//	if (okayToPowerUp && currentPowerUp == 1) {
//		if (t > 0) {
//			int p0[2] = { 0,200 };
//			int p1[2] = { 0,100 };
//			int p2[2] = { 800,100 };
//			int p3[2] = { 800,200 };
//			int* p = bezier(t, &p0[0], &p1[0], &p2[0], &p3[0]);
//			int x = p[0];
//			int y = p[1];
//			//to get to x,y 
//			//x = 900 - powerUpX_100
//			//y = 500 - powerUpY_100
//			powerUpX_100 = -(900 - x);
//			powerUpY_100 = -(100 - y);
//			t -= 0.01;
//		}
//		if (powerUpX_100 <= -900) {
//			powerUpX_100 = 0;
//			powerUpY_100 = 0;
//			t = 1.0;
//			currentPowerUp = rand() % 5 + 1; //generate random number between 1 and 5
//			okayToPowerUp = false;
//		}
//		if (powerUpX_100 + 900 >= shipX + 375 && powerUpX_100 + 900 <= shipX + 525 && powerUpY_100 + 100 <= shipY + 325 && powerUpY_100 + 100 >= shipY + 275) {
//			for (int i = 0; i < 10000000; i++);
//			shipX += 100;
//			powerUpX_100 = 0;
//			powerUpY_100 = 0;
//			t = 1.0;
//			currentPowerUp = rand() % 5 + 1;
//			okayToPowerUp = false;
//		}
//		powerUpX_100 -= 10;
//		if (powerUpX_100 <= -100 && powerUpX_100 >= -110) {
//		}
//		for (int i = 0; i < 10000000; i++);
//	}
//
//	//////////obstacles//////////
//
//	if (currentObstacle == 6) {
//		if (t1 > 0) {
//			int p0[2] = { 0,550 };
//			int p1[2] = { 800,600 };
//			int p2[2] = { 0,350 };
//			int p3[2] = { 800,600 };
//			int* p = bezier(t1, &p0[0], &p1[0], &p2[0], &p3[0]);
//			int x = p[0];
//			int y = p[1];
//			//to get to x,y 
//			//x = 900 - obstacleX_550
//			//y = 500 - obstacleY_550
//			obstacleX_550 = -(900 - x);
//			obstacleY_550 = -(550 - y);
//			t1 -= 0.01;
//		}
//		if (obstacleX_550 <= -900) {
//			obstacleX_550 = 0;
//			obstacleY_550 = 0;
//			t1 = 1.0;
//			currentObstacle = rand() % 6 + 1; //generate random number between 1 and 6
//			obstacleCounter++;
//			if (obstacleCounter == 5) {
//				obstacleCounter = -1;
//				okayToPowerUp = true;
//			}
//		}
//		if (obstacleX_550 + 900 >= shipX + 375 && obstacleX_550 + 900 <= shipX + 525 && obstacleY_550 + 550 <= shipY + 325 && obstacleY_550 + 550 >= shipY + 275) {
//			for (int i = 0; i < 10000000; i++);
//			shipX -= 100;
//			obstacleX_550 = 0;
//			obstacleY_550 = 0;
//			t1 = 1.0;
//			currentObstacle = rand() % 6 + 1;
//			obstacleCounter++;
//			if (obstacleCounter == 5) {
//				obstacleCounter = -1;
//				okayToPowerUp = true;
//			}
//		}
//		obstacleX_550 -= 10;
//		if (obstacleX_550 <= -100 && obstacleX_550 >= -110) {
//		}
//		for (int i = 0; i < 10000000; i++);
//	}
//
//	if (currentObstacle == 5) {
//		if (t1 > 0) {
//			int p0[2] = { 0,525 };
//			int p1[2] = { 800,425 };
//			int p2[2] = { 0,425 };
//			int p3[2] = { 800,525 };
//			int* p = bezier(t1, &p0[0], &p1[0], &p2[0], &p3[0]);
//			int x = p[0];
//			int y = p[1];
//			//to get to x,y 
//			//x = 900 - obstacleX_450
//			//y = 500 - obstacleY_450
//			obstacleX_450 = -(900 - x);
//			obstacleY_450 = -(450 - y);
//			t1 -= 0.01;
//		}
//		if (obstacleX_450 <= -900) {
//			obstacleX_450 = 0;
//			obstacleY_450 = 0;
//			t1 = 1.0;
//			currentObstacle = rand() % 6 + 1; //generate random number between 1 and 6
//			obstacleCounter++;
//			if (obstacleCounter == 5) {
//				obstacleCounter = -1;
//				okayToPowerUp = true;
//			}
//		}
//		if (obstacleX_450 + 900 >= shipX + 375 && obstacleX_450 + 900 <= shipX + 525 && obstacleY_450 + 450 <= shipY + 325 && obstacleY_450 + 450 >= shipY + 275) {
//			for (int i = 0; i < 10000000; i++);
//			shipX -= 100;
//			obstacleX_450 = 0;
//			obstacleY_450 = 0;
//			t1 = 1.0;
//			currentObstacle = rand() % 6 + 1;
//			obstacleCounter++;
//			if (obstacleCounter == 5) {
//				obstacleCounter = -1;
//				okayToPowerUp = true;
//			}
//		}
//		obstacleX_450 -= 10;
//		if (obstacleX_450 <= -100 && obstacleX_450 >= -110) {
//		}
//		for (int i = 0; i < 10000000; i++);
//	}
//
//	if (currentObstacle == 4) {
//		if (t1 > 0) {
//			int p0[2] = { 0,350 };
//			int p1[2] = { 800,425 };
//			int p2[2] = { 0,425 };
//			int p3[2] = { 800,475 };
//			int* p = bezier(t1, &p0[0], &p1[0], &p2[0], &p3[0]);
//			int x = p[0];
//			int y = p[1];
//			//to get to x,y 
//			//x = 900 - obstacleX_350
//			//y = 500 - obstacleY_350
//			obstacleX_350 = -(900 - x);
//			obstacleY_350 = -(350 - y);
//			t1 -= 0.01;
//		}
//		if (obstacleX_350 <= -900) {
//			obstacleX_350 = 0;
//			obstacleY_350 = 0;
//			t1 = 1.0;
//			currentObstacle = rand() % 6 + 1; //generate random number between 1 and 6
//			obstacleCounter++;
//			if (obstacleCounter == 5) {
//				obstacleCounter = -1;
//				okayToPowerUp = true;
//			}
//		}
//		if (obstacleX_350 + 900 >= shipX + 375 && obstacleX_350 + 900 <= shipX + 525 && obstacleY_350 + 350 <= shipY + 325 && obstacleY_350 + 350 >= shipY + 275) {
//			for (int i = 0; i < 10000000; i++);
//			shipX -= 100;
//			obstacleX_350 = 0;
//			obstacleY_350 = 0;
//			t1 = 1.0;
//			currentObstacle = rand() % 6 + 1;
//			obstacleCounter++;
//			if (obstacleCounter == 5) {
//				obstacleCounter = -1;
//				okayToPowerUp = true;
//			}
//		}
//		obstacleX_350 -= 10;
//		if (obstacleX_350 <= -100 && obstacleX_350 >= -110) {
//		}
//		for (int i = 0; i < 10000000; i++);
//	}
//
//	if (currentObstacle == 3) {
//		if (t1 > 0) {
//			int p0[2] = { 0,275 };
//			int p1[2] = { 800,150 };
//			int p2[2] = { 0,150 };
//			int p3[2] = { 800,275 };
//			int* p = bezier(t1, &p0[0], &p1[0], &p2[0], &p3[0]);
//			int x = p[0];
//			int y = p[1];
//			//to get to x,y 
//			//x = 900 - obstacleX_250
//			//y = 500 - obstacleY_250
//			obstacleX_250 = -(900 - x);
//			obstacleY_250 = -(250 - y);
//			t1 -= 0.01;
//		}
//		if (obstacleX_250 <= -900) {
//			obstacleX_250 = 0;
//			obstacleY_250 = 0;
//			t1 = 1.0;
//			currentObstacle = rand() % 6 + 1; //generate random number between 1 and 6
//			obstacleCounter++;
//			if (obstacleCounter == 5) {
//				obstacleCounter = -1;
//				okayToPowerUp = true;
//			}
//		}
//		if (obstacleX_250 + 900 >= shipX + 375 && obstacleX_250 + 900 <= shipX + 525 && obstacleY_250 + 250 <= shipY + 325 && obstacleY_250 + 250 >= shipY + 275) {
//
//			for (int i = 0; i < 10000000; i++);
//			shipX -= 100;
//			obstacleX_250 = 0;
//			obstacleY_250 = 0;
//			t1 = 1.0;
//			currentObstacle = rand() % 6 + 1;
//			obstacleCounter++;
//			if (obstacleCounter == 5) {
//				obstacleCounter = -1;
//				okayToPowerUp = true;
//			}
//		}
//		obstacleX_250 -= 10;
//		if (obstacleX_250 <= -100 && obstacleX_250 >= -110) {
//		}
//		for (int i = 0; i < 10000000; i++);
//	}
//
//	if (currentObstacle == 2) {
//		if (t1 > 0) {
//			int p0[2] = { 0,225 };
//			int p1[2] = { 0,155 };
//			int p2[2] = { 800,155 };
//			int p3[2] = { 800,225 };
//			int* p = bezier(t1, &p0[0], &p1[0], &p2[0], &p3[0]);
//			int x = p[0];
//			int y = p[1];
//			//to get to x,y 
//			//x = 900 - obstacleX_150
//			//y = 500 - obstacleY_150
//			obstacleX_150 = -(900 - x);
//			obstacleY_150 = -(150 - y);
//			t1 -= 0.01;
//		}
//		if (obstacleX_150 <= -900) {
//			obstacleX_150 = 0;
//			obstacleY_150 = 0;
//			t1 = 1.0;
//			currentObstacle = rand() % 6 + 1; //generate random number between 1 and 6
//			obstacleCounter++;
//			if (obstacleCounter == 5) {
//				obstacleCounter = -1;
//				okayToPowerUp = true;
//			}
//		}
//		if (obstacleX_150 + 900 >= shipX + 375 && obstacleX_150 + 900 <= shipX + 525 && obstacleY_150 + 150 <= shipY + 325 && obstacleY_150 + 150 >= shipY + 275) {
//			for (int i = 0; i < 10000000; i++);
//			shipX -= 100;
//			obstacleX_150 = 0;
//			obstacleY_150 = 0;
//			t1 = 1.0;
//			currentObstacle = rand() % 6 + 1;
//			obstacleCounter++;
//			if (obstacleCounter == 5) {
//				obstacleCounter = -1;
//				okayToPowerUp = true;
//			}
//		}
//		obstacleX_150 -= 10;
//		if (obstacleX_150 <= -100 && obstacleX_150 >= -110) {
//		}
//		for (int i = 0; i < 10000000; i++);
//	}
//
//	if (currentObstacle == 1) {
//		if (t1 > 0) {
//			int p0[2] = { 0,0 };
//			int p1[2] = { 0,50 };
//			int p2[2] = { 800,50 };
//			int p3[2] = { 800,0 };
//			int* p = bezier(t1, &p0[0], &p1[0], &p2[0], &p3[0]);
//			int x = p[0];
//			int y = p[1];
//			//to get to x,y 
//			//x = 900 - obstacleX_50
//			//y = 500 - obstacleY_50
//			obstacleX_50 = -(900 - x);
//			obstacleY_50 = -(50 - y);
//			t1 -= 0.01;
//		}
//		if (obstacleX_50 <= -900) {
//			obstacleX_50 = 0;
//			obstacleY_50 = 0;
//			t1 = 1.0;
//			currentObstacle = rand() % 6 + 1; //generate random number between 1 and 6
//			obstacleCounter++;
//			if (obstacleCounter == 5) {
//				obstacleCounter = -1;
//				okayToPowerUp = true;
//			}
//		}
//		if (obstacleX_50 + 900 >= shipX + 375 && obstacleX_50 + 900 <= shipX + 525 && obstacleY_50 + 50 <= shipY + 325 && obstacleY_50 + 50 >= shipY + 275) {
//			for (int i = 0; i < 10000000; i++);
//			shipX -= 100;
//			obstacleX_50 = 0;
//			obstacleY_50 = 0;
//			t1 = 1.0;
//			currentObstacle = rand() % 6 + 1;
//			obstacleCounter++;
//			if (obstacleCounter == 5) {
//				obstacleCounter = -1;
//				okayToPowerUp = true;
//			}
//		}
//		obstacleX_50 -= 10;
//		if (obstacleX_50 <= -100 && obstacleX_50 >= -110) {
//		}
//		for (int i = 0; i < 10000000; i++);
//	}
//
//	if (shipX + 500 >= 800) {
//		won = true;
//	}
//
//	if (shipX + 375 - 50 <= 30) {
//		lost = true;
//	}
//
//	if (won || lost) {
//		if (endGame) {
//			exit(0);
//		}
//		endGame = true;
//	}
//
//	glutPostRedisplay();
//}
//
//
//void spe(int k, int x, int y)// keyboard special key function takes 3 parameters
//							 // int k: is the special key pressed such as the keyboard arrows the f1,2,3 and so on
//{
//	if (k == GLUT_KEY_UP)//if the up arrow is pressed, then the object will be translated in the y axis by 40. (moving upwords)
//		if (shipY + 325 <= 600) {
//			shipY += 30;
//		}
//	if (k == GLUT_KEY_DOWN)//if the down arrow is pressed, then the object will be translated in the y axis by -40. (moving downwords)
//		if (shipY + 275 >= 0) {
//			shipY -= 30;
//		}
//	glutPostRedisplay();//redisplay to update the screen with the changes
//}
//
//void main(int argc, char** argv) {
//
//	glutInit(&argc, argv);
//
//	glutInitWindowSize(800, 600);
//	glutInitWindowPosition(50, 50);
//
//	glutCreateWindow("STAR: Force Wars");
//	glutDisplayFunc(Display);
//
//	glutSpecialFunc(spe);
//
//	glPointSize(25);
//
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//
//	gluOrtho2D(0, 800, 0, 600);
//
//	glutIdleFunc(animate);
//
//
//	srand(time(NULL));
//
//	glutMainLoop();
//}