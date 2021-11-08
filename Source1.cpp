////	Includes
//#include <stdlib.h>
//#include <cmath>
//#include <glut.h>
////-----------------
//
////	Methods Signatures
//void Display(void);
//void Anim(void);
////-----------------
//
////	Global Variables
//double drawingLim = 7;  // for drawing the batman sign gradually 
//double colAnim = 1;     // for fading the background color from white to black
//int fanWingCount = 0;   // for drawing the fan wings one by one
//double fanWingsRot = 0; // for the fan rotation
////-----------------
//
//void main(int argc, char** argr)
//{
//	glutInit(&argc, argr);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(50, 50);
//	glutCreateWindow("Batman");
//	glutDisplayFunc(Display);
//	glutIdleFunc(Anim);
//	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
//	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
//	glutMainLoop();
//}
//
//void Display(void)
//{
//	glClearColor(colAnim, colAnim, colAnim, 0.0f); // update the background color
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glPushMatrix(); // marking the initial state of the transformations matrix 
//
//	//-----------------
//	glTranslated(250, 250, 0); // relocate to the center of the window
//	glScaled(15, 15, 1);       // uniform sacle up by a factor of 15
//  //
//	// both of these transformations are applied on both the batman sign and the fan
//	//-----------------
//
//	glPushMatrix(); // marking the transformations matrix before adding the fan rotation
//
//	glRotated(fanWingsRot, 0, 0, 1); // fan rotation
//
//	//	drawing the fan wings
//	for (int rims = 0; rims < fanWingCount; rims++)
//	{
//		glPushMatrix();
//
//		glRotated(120 * rims, 0, 0, 1);
//
//		glBegin(GL_QUADS);
//
//		glColor3f(0.5, 0.5, 0.5);
//		glVertex3d(0, 0, 0);
//		glVertex3d(2, 0, 0);
//		glColor3f(0.25, 0.25, 0.25);
//		glVertex3d(-1, 5, 0);
//		glVertex3d(-3, 5, 0);
//
//		glColor3f(0.25, 0.25, 0.25);
//		glVertex3d(-3, 5, 0);
//		glVertex3d(-1, 5, 0);
//		glColor3f(0.5, 0.5, 0.5);
//		glVertex3d(2, 8, 0);
//		glVertex3d(0, 8, 0);
//
//		glEnd();
//		glPopMatrix();
//	}
//	//-----------------
//
//	glPopMatrix(); //	removing the fan rotation
//
//	// drawing the batman sign
//	glColor3f(0, 0, 0);
//
//	glBegin(GL_LINES);
//
//	for (double xcord = 7; xcord >= 4 && xcord >= drawingLim; xcord -= 0.01)
//	{
//		double ycordPos = 2 * sqrt((double)(-1 * (abs(abs(xcord) - 1)) * abs(3 - abs(xcord)) / ((abs(xcord) - 1) * (3 - abs(xcord))))) *
//			(1 + abs(abs(xcord) - 3) / (abs(xcord) - 3)) * sqrt((double)(1 - pow((xcord / 7), 2))) +
//			(5 + 0.97 * (abs(xcord - 0.5) + abs(xcord + 0.5)) - 3 * (abs(xcord - 0.75) + abs(xcord + 0.75))) *
//			(1 + abs(1 - abs(xcord)) / (1 - abs(xcord)));
//		glVertex3d(xcord, ycordPos, 0);
//
//		double ycordNeg = -3 * sqrt((double)(1 - pow((xcord / 7), 2))) * sqrt((double)(abs(abs(xcord) - 4) / (abs(xcord) - 4)));
//		glVertex3d(xcord, ycordNeg, 0);
//
//		glVertex3d(-xcord, ycordPos, 0);
//		glVertex3d(-xcord, ycordNeg, 0);
//	}
//
//	for (double xcord = 3.99; xcord >= drawingLim; xcord -= 0.01)
//	{
//		double ycordPosF = 0;
//		if (xcord >= 3 || xcord <= 1)
//		{
//			double ycordPos = 2 * sqrt((double)(-1 * (abs(abs(xcord) - 1)) * abs(3 - abs(xcord)) / ((abs(xcord) - 1) * (3 - abs(xcord))))) *
//				(1 + abs(abs(xcord) - 3) / (abs(xcord) - 3)) * sqrt((double)(1 - pow((xcord / 7), 2))) +
//				(5 + 0.97 * (abs(xcord - 0.5) + abs(xcord + 0.5)) - 3 * (abs(xcord - 0.75) + abs(xcord + 0.75))) *
//				(1 + abs(1 - abs(xcord)) / (1 - abs(xcord)));
//			ycordPosF = ycordPos;
//			glVertex3d(xcord, ycordPos, 0);
//		}
//		else
//		{
//			double ycordPos = 2.71052 + (1.5 - 0.5 * abs(xcord)) - 1.35526 * sqrt((double)(4 - pow(abs(xcord) - 1, 2))) *
//				sqrt((double)(abs(abs(xcord) - 1) / (abs(xcord) - 1))) + 0.9;
//			ycordPosF = ycordPos;
//			glVertex3d(xcord, ycordPos, 0);
//		}
//
//		double ycordNeg = abs(xcord / 2) - 0.0913722 * pow(xcord, 2) - 3 + sqrt((double)(1 - pow((abs(abs(xcord) - 2) - 1), 2)));
//		glVertex3d(xcord, ycordNeg, 0);
//
//		glVertex3d(-xcord, ycordPosF, 0);
//		glVertex3d(-xcord, ycordNeg, 0);
//	}
//
//	glEnd();
//	//-----------------
//
//	glPopMatrix(); //	returning to the initial state of the transformations matrix 
//
//	glFlush();
//}
//
//void Anim()
//{
//	if (drawingLim > -0.1) //	start of drawing and dimming phase
//	{
//		drawingLim -= 0.01;
//		colAnim -= 0.002;
//		for (int i = 0; i < 1000000; i++);
//	}
//	else
//	{
//		if (fanWingCount < 4) // start of drawing the fan phase
//		{
//			fanWingCount++;
//			for (int i = 0; i < 400000000; i++);
//		}
//		else //	start of the fan rotation phase
//		{
//			fanWingsRot++;
//		}
//	}
//
//	glutPostRedisplay();
//}
