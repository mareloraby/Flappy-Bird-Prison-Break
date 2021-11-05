//#include <stdlib.h> 
//#include <cmath>
//#include <glut.h>
//void Display(void);
//void Anim(void);
//void Timer(int t);
//float rot = 0;
//float red = 0;
//float green = 0;
//void main(int argc, char** argr)
//{
//	glutInit(&argc, argr);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(50, 50);
//	glutCreateWindow("Batman");
//	glutDisplayFunc(Display);
//	glutIdleFunc(Anim); // idle function: whenever the drawing is idle  
//	glutTimerFunc(1000, Timer, 5434); // every 1000ms call Timer
//	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
//	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
//	glutMainLoop();
//}
//
//void Timer(int t) { // t has to have a paramter 
//	/*if (red == 0) {
//		red = 1;
//		green = 0;
//	}
//	else {
//		red = 0;
//		green = 1;
//	}*/
//	glutTimerFunc(1000, Timer, 5434); // to keep calling itself (keep changing colours)
//}
//void Display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0, 0, 0); //change colurs here
//
//	glPushMatrix(); // push or pop onto the matrix - transform, scale, rotate each frame , because in each iteration I want to start with a new stack/matrix
//
//
//
//	// gltranslate d- double f-float glTranslated(250,250,0); 
//	//scaling order matters - scaling after translation
//
//	glTranslated(250, 250, 0);
//	glScaled(10, 10, 1); // z has be to be multiplied by 1 
//	glRotated(rot, 0, 0, 1);//rotation relative to the origin -angle,x,y,z //rot parameter to make the image rotate
//
//
//
//	glColor3f(0, 0, 0);
//	glBegin(GL_POINTS);
//
//	//for (double xcord = 7; xcord >= 4; xcord -= 0.01)
//	//{
//	//	double ycordPos = 2 * sqrt((double)(-1 * (abs(abs(xcord) - 1)) * abs(3 - abs(xcord)) / ((abs(xcord) - 1) * (3 - abs(xcord))))) *
//	//		(1 + abs(abs(xcord) - 3) / (abs(xcord) - 3)) * sqrt((double)(1 - pow((xcord / 7), 2))) +
//	//		(5 + 0.97 * (abs(xcord - 0.5) + abs(xcord + 0.5)) - 3 * (abs(xcord - 0.75) + abs(xcord + 0.75))) *
//	//		(1 + abs(1 - abs(xcord)) / (1 - abs(xcord)));
//
//	//	glVertex3d(xcord, ycordPos, 0);
//	//	glVertex3d(-xcord, ycordPos, 0);
//
//	//	double ycordNeg = -3 * sqrt((double)(1 - pow((xcord / 7), 2))) * sqrt((double)(abs(abs(xcord) - 4) / (abs(xcord) - 4)));
//	//	glVertex3d(xcord, ycordNeg, 0);
//	//	glVertex3d(-xcord, ycordNeg, 0);
//	//}
//
//	for (double xcord = 3.99; xcord >= 0; xcord -= 0.01)
//	{
//		double ycordPos=0;
//		if (xcord <= 1)
//		{
//			ycordPos =
//				(5 + 0.97 * (abs(xcord - 0.5) + abs(xcord + 0.5)) - 3 * (abs(xcord - 0.75) + abs(xcord + 0.75))) *
//				(1 + abs(1 - abs(xcord)) / (1 - abs(xcord)));
//		}
//		//else
//		//{
//		//	//ycordPos = 2.71052;/* + (1.5 - 0.5 * abs(xcord)) - 1.35526 * sqrt((double)(4 - pow(abs(xcord) - 1, 2))) *
//		//		sqrt((double)(abs(abs(xcord) - 1) / (abs(xcord) - 1))) + 0.9;*/
//		//}
//		glVertex3d(xcord, ycordPos, 0);
//	//	glVertex3d(-xcord, ycordPos, 0);
//
//		//double ycordNeg = abs(xcord / 2) - 0.0913722 * pow(xcord, 2) - 3 + sqrt((double)(1 - pow((abs(abs(xcord) - 2) - 1), 2)));
//		//glVertex3d(xcord, ycordNeg, 0);
//		//glVertex3d(-xcord, ycordNeg, 0);
//	}
//
//	glEnd();
//
//	glPopMatrix();
//
//	glFlush();
//}
//
//void Anim()
//{
////	rot += 0.05; // I need to make it hvae an effect // the smaller the value, the slower the rotation :)
//	glutPostRedisplay(); // Display -> Anim
//	// It is named Anim 
//}