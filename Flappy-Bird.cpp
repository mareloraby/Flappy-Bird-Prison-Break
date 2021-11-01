//#include <stdio.h>
//#include <math.h>
//#include <random>
//#include <glut.h>
//#include <list>
//#include <string>
//#include <sstream>
//#include <iostream>
//
//
//using namespace std;
//
//
////Variables
//int screenwidth = 650;
//int screenheight = 450;
//int FPS = 30;
//float timeElapsed = 0.0;
//int barwidth = 60;
//
//double ftime = 0.01;
//double xdash = 0.0;
//double falld = 0;
//int jump = 0;
//
//
//int start = screenwidth - screenwidth / 3;
//int sset = 1;
//
//
//void drawrectangle(int x, int y,int w, int h) {
//	
//	glBegin(GL_POLYGON);
//		glVertex3f(x, y, 0.0f);
//		glVertex3f(x + w, y, 0.0f);
//		glVertex3f(x + w, y + h, 0.0f);	
//		glVertex3f(x, y + h, 0.0f);
//	glEnd();
//
//}
//void set1(int startpos) {
//	//glPushMatrix();
//	glColor3f(0, 1, 0.5);
//	drawrectangle(startpos, 0, barwidth, 140);
//	drawrectangle(startpos, 270, barwidth, 195);
//	startpos += 150;
//	drawrectangle(startpos, 0, barwidth, 170);
//	drawrectangle(startpos, 300, barwidth, 195);
//	startpos += 150;
//	drawrectangle(startpos, 0, barwidth, 200);
//	drawrectangle(startpos, 330, barwidth, 195);
//	startpos += 150;
//	drawrectangle(startpos, 0, barwidth, 230);
//	drawrectangle(startpos, 360, barwidth, 195);
////	glPopMatrix();
//
//}
//void set2(int startpos) {
//
////glPushMatrix();
////glColor3f(0, 0.7, 0.5);
//	glColor3f(1, 0, 0.5);
//	drawrectangle(startpos, 0, barwidth, 230);
//	drawrectangle(startpos, 360, barwidth, 195);
//	startpos += 150;
//	drawrectangle(startpos, 0, barwidth, 170);
//	drawrectangle(startpos, 300, barwidth, 195);
//	startpos += 150;
//	drawrectangle(startpos, 0, barwidth, 230);
//	drawrectangle(startpos, 360, barwidth, 195);
//	startpos += 150;
//	drawrectangle(startpos, 0, barwidth, 170);
//	drawrectangle(startpos, 300, barwidth, 195);
////glPopMatrix();
//
//}
//void set3(int startpos) {
//
////	glPushMatrix();
//	glColor3f(0, 0.55, 0.5);
//	drawrectangle(startpos, 0, barwidth, 230);
//	drawrectangle(startpos, 360, barwidth, 195);
//	startpos += 150;
//	drawrectangle(startpos, 0, barwidth, 170);
//	drawrectangle(startpos, 300, barwidth, 195);
//	startpos += 150;
//	drawrectangle(startpos, 0, barwidth, 170);
//	drawrectangle(startpos, 300, barwidth, 195);
////	glPopMatrix();
//
//
//}
//
//
//void drawBars(int sset) {
//
//	glPushMatrix();
//	glTranslated(-xdash, 0, 0);
//
//	switch (sset) {
//	case 1:
//		set1(start);
//		set2(start + 455 + 150);
//		set3(start + 910 + 150 + 150);
//		break;
//
//	case 2:
//		set2(start);
//		set3(start + 455 + 150);
//		set1(start + 910 + 150);
//		break;
//	case 3:
//		set3(start);
//		set1(start + 455);
//		set2(start + 910 + 150);
//		break;
//
//	default:
//		break;
//
//	}
//
//	glPopMatrix();
//}
//
//
//void drawcircle(int x, int y, int r) {
//
//	glColor3f(1, 1, 1);
//	glTranslatef(x, y, 0);
//	GLUquadric* quadObj = gluNewQuadric();
//	gluDisk(quadObj, 0, r, 50, 50);
//
//}
//
//void drawbird() {
//
//	glPushMatrix();
//	glTranslatef(0, falld, 0);
//
//		if (jump) {
//			falld += 17; jump = 0;
//		}
//		else falld += (-0.5 * 9.81) * (ftime * ftime); //free fall
//	
//		drawcircle(screenwidth / 9, screenheight / 2, 10);
//	glPopMatrix();
//}
//
//
//void spe(int k, int x, int y)// keyboard special key function takes 3 parameters
//							// int k: is the special key pressed such as the keyboard arrows the f1,2,3 and so on
//{
//	if (k == 32) {
//		jump = 1;
//	}
//	glutPostRedisplay();//redisplay to update the screen with the changes
//}
//void key(unsigned char k, int x, int y)
//{
//	if (k == 32)
//		jump = 1;
//	
//}
//
//
//
//
//void Timer(int value) {
//
//	timeElapsed += FPS / 1000.0;
//	glutTimerFunc(FPS, Timer, 0);
//	glutPostRedisplay();
//}
//
//
//void Display() {
//
//	glClear(GL_COLOR_BUFFER_BIT);
//	drawbird();
//	drawBars(sset);
//	glFlush();
//}
//
//
//void Anim()
//{
//	xdash += 0.0000019; 
//	glutPostRedisplay();
//}
//
//
//void main(int argc, char** argr) {
//	glutInit(&argc, argr);
//
//	glutInitWindowSize(screenwidth, screenheight);
//	glutInitWindowPosition(150, 150);
//	srand(time(0));
//
//	glutCreateWindow("Flappy Bird");
//	glutDisplayFunc(Display);
//	glutTimerFunc(0, Timer, 0);
//	//glutSpecialFunc(spe);			//call the keyboard special keys function
//	glutKeyboardFunc(key);			//call the keyboard function
//
//	glutIdleFunc(Anim);
//
//
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//	gluOrtho2D(0.0, screenwidth, 0.0, screenheight);
//
//	glutMainLoop();
//	
//	
//}
//
//
