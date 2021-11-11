//  Includes
//#include <stdio.h>
//#include <math.h>
//#include <random>
//#include <glut.h>
//#include <string>
//#include <string.h>
//#include <cstdlib>
//#include <time.h>
//#include <sstream>
//#include <iostream>
//#define PI 3.1415926535897932384626433832795
//-----------------
//using namespace std;
//  Global Variables
//
//int setNumber = 0;
//int screenWidth = 800;
//int screenHeight = 600;
//
//int birdBodyX = 20; ////int x, int y, float r
//int birdY = (screenHeight / 2);
//float birdBodyR = 15.0f;
//float bird = birdBodyX + birdBodyR;
//
//float birdBeakX = 25.0f;
//float birdBeakY = (screenHeight / 2) + 6;
//float birdBeakB = 20.0f;
//float birdBeakH = 20.0f;
//
//float birdEyebrowX = 30.0f;
//float birdEyebrowY = (screenHeight / 2) + 5;
//float birdEyebrowRot = 50.0f;
//float birdEyebrowH = 10.0f;
//
//int birdEyeX = 22;
//int birdEyeY = (screenHeight / 2) + 2;
//float birdEyeR = 5.0f;
//
//---------------------------------------------//
//float barrierWidth = 80.0f;
//float barrierGap = 250.0f;
//float birdGap = 190.0f; //will be added to random value
//float roofWidth = 100.0f;
//float barrierHeight = 0.0f; //will be randomized
//float roofHeight = 40.0f;
//
//float r1;
//float r2;
//float r3;
//float r4;
//float r5;
//float r6;
//float r7;
//float r8;
//float r9;
//
//float ro1;
//float ro2;
//float ro3;
//float ro4;
//float ro5;
//float ro6;
//float ro7;
//float ro8;
//float ro9;
//
//
//
//
//set 1
//float barrierX1 = 160.0f;
//float roofX1 = barrierX1 - 10;
//float endX1 = barrierX1 + 500;
//bool canDrawFirstSet = true;
//
//set2
//float barrierX2 = 910.0f;
//float roofX2 = barrierX2 - 10;
//float endX2 = barrierX2 + 500;
//bool canDrawSecondSet = true;
//
//set3
//float barrierX3 = 1660.0f;
//float roofX3 = barrierX3 - 10;
//float endX3 = barrierX3 + 500;
//bool canDrawThirdSet = true;
//
//
//bool flag1 = true;
//bool flag2 = true;
//bool flag3 = true;
//
//
//int random = 0;
//
//int lives = 3;
//
//int powerup = 120;
//int powerupBottom = 44.5;
//int powerupTop = 37;
//bool powerupFlag = false;
//
//
//-----------------
//
//  Game Code
//
/////////// main shapes ///////////
//
//void drawHalfCircle()
//{
//    float radius = 18;
//    float twoPI = 2 * PI;
//
//    glBegin(GL_TRIANGLE_FAN);
//
//    for (float i = PI; i <= twoPI; i += 0.001)
//        glVertex2f((sin(i) * radius), (cos(i) * radius));
//
//    glEnd();
//    glFlush();
//}
//
//
//
//void drawLine(float x, float y, float w, float h) {
//    glBegin(GL_LINE_LOOP);
//    glVertex3f(x, y, 0.0f);
//    glVertex3f(x, y + h, 0.0f);
//    glVertex3f(x + w, y + h, 0.0f);
//    glVertex3f(x + w, y, 0.0f);
//    glEnd();
//}
//
//void drawCircle(int x, int y, float r) {
//    glPushMatrix();
//    glTranslatef(x, y, 0);
//    GLUquadric* quadObj = gluNewQuadric();
//    gluDisk(quadObj, 0, r, 50, 50);
//    glPopMatrix();
//}
//
//void drawTriangle(float x, float y, float b, float h) {
//    glPushMatrix();
//     glTranslatef(x, y, 0);
//     glRotatef(180.0f, 0.0f, 0.0f, 0.0f);
//    glBegin(GL_POLYGON);
//    glVertex3f(x, y, 0.0f);  ///P1
//    glVertex3f((x + b), y - (h / 2), 0.0f);  ///P2
//    glVertex3f(x, y - h, 0.0f);  ///P3
//    glEnd();
//    glPopMatrix();
//}
//
//void drawRectangle(float x, float y, float w, float h) {
//    glBegin(GL_POLYGON);
//    glVertex3f(x, y, 0.0f);
//    glVertex3f(x, y + h, 0.0f);
//    glVertex3f(x + w, y + h, 0.0f);
//    glVertex3f(x + w, y, 0.0f);
//    glEnd();
//}
//
////////////// shapes in action ////////////////
//
//void drawBarrier(float x, float y, float w, float h, std::string type) {
//
//    if (type == "normal") {
//        glColor3f(0.0f, 0.6f, 0.1f);
//        drawRectangle(x, y, w, h);
//        glColor3f(0.0f, 0.0f, 0.0f);
//        drawLine(x, y, w, h);
//    }
//    else if (type == "powerup") {
//        glColor3f(1.0f, 0.7f, 0.0f);
//        drawRectangle(x, y, w, h);
//        glColor3f(0.0f, 0.0f, 0.0f);
//        drawLine(x, y, w, h);
//    }
//}
//
//void print(int x, int y, char* string)
//{
//    int len, i;
//
//    set the position of the text in the window using the x and y coordinates
//    glRasterPos2f(x, y);
//
//    get the length of the string to display
//    len = (int)strlen(string);
//
//    loop to display character by character
//    for (i = 0; i < len; i++)
//    {
//        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
//    }
//}
//
//void printScore() {
//
//    for (int i = 0; i < 100; i++) {
//        glColor3f(0, 0, 0);
//        char* p0s[20];
//        sprintf((char*)p0s, "Score: %d", i);
//        print(700, 567, (char*)p0s);
//    }
//
//    glFlush();
//}
//
//void printLives() {
//
//
//    glColor3f(0, 0, 0);
//    char* p0s[20];
//    sprintf((char*)p0s, "Lives: %d", lives);
//    print(30, 50, (char*)p0s);
//
//    if (lives == 3) {
//        glColor3f(0.0f, 0.3f, 0.0f);
//        drawRectangle(30, 20, 200, 10);
//    }
//    else if (lives == 2) {
//        glColor3f(0.8f, 0.4f, 0.0f);
//        drawRectangle(30, 20, 150, 10);
//    }
//    else if (lives == 1) {
//        glColor3f(0.5f, 0.0f, 0.0f);
//        drawRectangle(30, 20, 100, 10);
//    }
//    else {
//        print game over and stop the game and display total score
//    }
//
//    glFlush();
//}
//
//
//
//
//void drawBird() {
//
//    glPushMatrix();
//
//    beak
//    glColor3f(0.9f, 0.4f, 0.0f);
//    drawTriangle(birdBeakX, birdY + 6, birdBeakB, birdBeakH); //x,y,b,h
//
//    body
//    glColor3f(1.0f, 1.0f, 0.6f);
//    drawCircle(birdBodyX, birdY, birdBodyR);
//
//    eyebrow
//    glColor3f(0.0f, 0.0f, 0.0f);
//    glPushMatrix();
//    glTranslatef(birdEyebrowX, birdY + 5, 0);
//    glRotatef(birdEyebrowRot, 0, 0, 1);
//    drawLine(0, 0, 0, birdEyebrowH);
//    glPopMatrix();
//
//    eye
//    glColor3f(0.0f, 0.0f, 0.0f);
//    drawCircle(birdEyeX, birdY + 2, birdEyeR);
//
//    glPopMatrix();
//
//}
//
//void drawPowerup() {
//
//    glPushMatrix();
//
//    glPushMatrix();
//
//    glColor3f(1.0f, 1.0f, 1.0f);
//    glTranslatef(barrierX2 + powerupBottom, r4 + powerup, 0);
//    glRotatef(180, 0, 0, 1);
//    drawRectangle(0, 0, 15, 17);
//
//    glPopMatrix();
//
//    glColor3f(0.7f, 0.0f, 0.0f);
//
//    glTranslatef(barrierX2 + powerupTop, r4 + powerup, 0);
//    glRotatef(-90, 0, 0, 1);
//    drawHalfCircle();
//    glPopMatrix();
//
//
//
//}
//
//string sets(int setNum, string type) {
//    ///calculations for symmetry:-
//         gap bird will fly in = Ylower barrier roof + 190
//         gap between barriers = 250
//    random = (rand() % 3) + 1;
//
//    switch (setNum) {
//
//    case 1:
//
//        lower barrier1
//        drawBarrier(barrierX1, 0, barrierWidth, r1, type); //x,y,w,h,type
//        drawBarrier(roofX1, r1, roofWidth, roofHeight, type); //roof
//        upper barrier1
//        drawBarrier(barrierX1, r1 + birdGap, barrierWidth, ro1, type);
//        drawBarrier(roofX1, r1 + birdGap, roofWidth, roofHeight, type); //roof
//
//        lower barrier2
//        drawBarrier(barrierX1 + barrierGap, 0, barrierWidth, r2, type); //x,y,w,h,type
//        drawBarrier(roofX1 + barrierGap, r2, roofWidth, roofHeight, type); //roof
//        upper barrier2
//        drawBarrier(barrierX1 + barrierGap, r2 + birdGap, barrierWidth, ro2, type); //x,y,w,h,type
//        drawBarrier(roofX1 + barrierGap, r2 + birdGap, roofWidth, roofHeight, type); //roof
//
//        lower barrier3
//        drawBarrier(barrierX1 + (2 * barrierGap), 0, barrierWidth, r3, type); //x,y,w,h,type
//        drawBarrier(roofX1 + (2 * barrierGap), r3, roofWidth, roofHeight, type); //roof
//        upper barrier3
//        drawBarrier(barrierX1 + (2 * barrierGap), r3 + birdGap, barrierWidth, ro3, type); //x,y,w,h,type
//        drawBarrier(roofX1 + (2 * barrierGap), r3 + birdGap, roofWidth, roofHeight, type); //roof
//        cout << "barrierX1" << barrierX1 << endl;
//        return type;
//        break;
//
//    case 2:
//        lower barrier1
//        drawBarrier(barrierX2, 0, barrierWidth, r4, type); //x,y,w,h,type
//        drawBarrier(roofX2, r4, roofWidth, roofHeight, type); //roof
//        upper barrier1
//        drawBarrier(barrierX2, r4 + birdGap, barrierWidth, ro4, type);
//        drawBarrier(roofX2, r4 + birdGap, roofWidth, roofHeight, type); //roof
//
//        lower barrier2
//        drawBarrier(barrierX2 + barrierGap, 0, barrierWidth, r5, type); //x,y,w,h,type
//        drawBarrier(roofX2 + barrierGap, r5, roofWidth, roofHeight, type); //roof
//        upper barrier2
//        drawBarrier(barrierX2 + barrierGap, r5 + birdGap, barrierWidth, ro5, type); //x,y,w,h,type
//        drawBarrier(roofX2 + barrierGap, r5 + birdGap, roofWidth, roofHeight, type); //roof
//
//        lower barrier3
//        drawBarrier(barrierX2 + (2 * barrierGap), 0, barrierWidth, r6, type); //x,y,w,h,type
//        drawBarrier(roofX2 + (2 * barrierGap), r6, roofWidth, roofHeight, type); //roof
//        upper barrier3
//        drawBarrier(barrierX2 + (2 * barrierGap), r6 + birdGap, barrierWidth, ro6, type); //x,y,w,h,type
//        drawBarrier(roofX2 + (2 * barrierGap), r6 + birdGap, roofWidth, roofHeight, type); //roof
//        cout << "barrierX2" << barrierX2 << endl;
//        return type;
//        break;
//
//    case 3:
//        lower barrier1
//        drawBarrier(barrierX3, 0, barrierWidth, r7, type); //x,y,w,h,type
//        drawBarrier(roofX3, r7, roofWidth, roofHeight, type); //roof
//        upper barrier1
//        drawBarrier(barrierX3, r7 + birdGap, barrierWidth, ro7, type);
//        drawBarrier(roofX3, r7 + birdGap, roofWidth, roofHeight, type); //roof
//
//        lower barrier2
//        drawBarrier(barrierX3 + barrierGap, 0, barrierWidth, r8, type); //x,y,w,h,type
//        drawBarrier(roofX3 + barrierGap, r8, roofWidth, roofHeight, type); //roof
//        upper barrier2
//        drawBarrier(barrierX3 + barrierGap, r8 + birdGap, barrierWidth, ro8, type); //x,y,w,h,type
//        drawBarrier(roofX3 + barrierGap, r8 + birdGap, roofWidth, roofHeight, type); //roof
//
//        lower barrier3
//        drawBarrier(barrierX3 + (2 * barrierGap), 0, barrierWidth, r9, type); //x,y,w,h,type
//        drawBarrier(roofX3 + (2 * barrierGap), r9, roofWidth, roofHeight, type); //roof
//        upper barrier3
//        drawBarrier(barrierX3 + (2 * barrierGap), r9 + birdGap, barrierWidth, ro9, type); //x,y,w,h,type
//        drawBarrier(roofX3 + (2 * barrierGap), r9 + birdGap, roofWidth, roofHeight, type); //roof
//
//        drawPowerup();
//        return type;
//        break;
//
//    }
//}
//
//void generateRandomSet() {
//
//    srand(time(0));
//    random = (rand() % 3) + 1;
//
//    if (random == 1) {
//        sets(1);
//    }
//    if (random == 2) {
//        sets(2);
//    }
//    if (random == 3) {
//        sets(3);
//    }
//
//}
//void Anim() {
//
//    birdY -= 0.1;
//
//    barrierX1 -= 1.5;
//    roofX1 -= 1.5;
//
//    barrierX2 -= 1.5;
//    roofX2 -= 1.5;
//
//    barrierX3 -= 1.5;
//    roofX3 -= 1.5;
//
//    glutPostRedisplay();
//}
//
//void powerUpCollision(int setNumCol, string type) {
//    if ((bird == (barrierX2 + powerupBottom)) || (bird == (barrierX2 + powerupTop)) || (birdY == (r2 + powerup))) {
//        powerupBottom = 1000000000;
//        powerupTop = 10000000000;
//        powerupFlag;
//    }
//}
//
//
//void collision() {
//
//    if (flag1) {
//        first set
//        if ((bird >= barrierX1) && (bird <= (barrierX1 + barrierWidth))) {
//            if ((birdY <= r1) || (birdY >= ro1)) {
//
//                reposition bird
//                birdY = r1 + 120;
//
//                decrease lives
//                lives -= 1;
//                printLives();
//            }
//        }
//        if ((roofX1 <= bird) && (bird <= (roofX1 + roofWidth))) {
//            if ((birdY <= (r1 + roofHeight) || (birdY >= (ro1 + roofHeight)))) {
//
//                reposition bird
//                birdY = r1 + 120;
//
//                decrease lives
//                lives -= 1;
//                printLives();
//            }
//        }
//
//        ---//
//        if ((bird >= (barrierX1 + barrierGap)) && (bird <= ((barrierX1 + barrierGap) + barrierWidth))) {
//            if ((birdY <= r2) || (birdY >= ro2)) {
//
//                
//                reposition bird
//                birdY = r2 + 120;
//
//                decrease lives
//                lives -= 1;
//                printLives();
//            }
//        }
//        if (((roofX1 + barrierGap) <= bird) && (bird <= ((roofX1 + barrierGap) + roofWidth))) {
//            if ((birdY <= (r2 + roofHeight)) || (bird >= (ro2 + roofHeight))) {
//
//                reposition bird
//                birdY = r2 + 120;
//
//                decrease lives
//                lives -= 1;
//                printLives();
//            }
//        }
//        ---//
//        if ((bird >= (barrierX1 + (2 * barrierGap))) && (bird <= ((barrierX1 + (2 * barrierGap) + barrierWidth)))) {
//            if ((birdY <= r3) || (birdY >= ro3)) {
//
//                reposition bird
//                birdY = r3 + 120;
//
//                decrease lives
//                lives -= 1;
//                printLives();
//            }
//        }
//        if (((roofX1 + (2 * barrierGap)) <= bird) && (bird <= ((roofX1 + (2 * barrierGap)) + roofWidth))) {
//            if ((birdY <= (r3 + roofHeight)) || (birdY >= (ro3 + roofHeight))) {
//
//                reposition bird
//                birdY = r3 + 120;
//
//                decrease lives
//                lives -= 1;
//                printLives();
//            }
//        }
//            set 2
//        if ((bird >= (barrierX2)) && (bird <= ((barrierX2)+barrierWidth))) {
//            if ((birdY <= r4) || (birdY >= ro4)) {
//
//                reposition bird
//                birdY = r4 + 120;
//
//                decrease lives
//                lives -= 1;
//                printLives();
//            }
//        }
//        if (((roofX2) <= bird) && (bird <= (roofX2 + roofWidth))) {
//            if ((birdY <= (r4 + roofHeight)) || (bird >= (ro4 + roofHeight))) {
//
//                reposition bird
//                birdY = r4 + 120;
//
//                decrease lives
//                lives -= 1;
//                printLives();
//            }
//        }
//
//        if (((roofX2) <= bird) && (bird <= (roofX2 + roofWidth))) {
//            if ((birdY <= (r4 + roofHeight)) || (bird > (ro4 + roofHeight))) {
//
//        ---// r5 then r6
//        if ((bird >= (barrierX2 + barrierGap)) && (bird <= ((barrierX2 + barrierGap) + barrierWidth))) {
//            if ((birdY <= r5) || (birdY >= ro5)) {
//
//                reposition bird
//                birdY = r5 + 120;
//
//                decrease lives
//                lives -= 1;
//                printLives();
//            }
//        }
//        if (((roofX2 + (barrierGap)) <= bird) && (bird <= ((roofX2 + (barrierGap)) + roofWidth))) {
//            if ((bird <= (r5 + roofHeight)) || (bird >= (ro5 + roofHeight))) {
//
//                reposition bird
//                birdY = r5 + 120;
//
//                decrease lives
//                lives -= 1;
//                printLives();
//            }
//
//        }
//
//        ---//r6
//        if ((bird >= (barrierX2 + (2 * barrierGap))) && (bird <= ((barrierX2 + (2 * barrierGap)) + barrierWidth))) {
//            if ((birdY <= r6) || (birdY >= ro6)) {
//
//                reposition bird
//                birdY = r6 + 120;
//
//                decrease lives
//                lives -= 1;
//                printLives();
//            }
//        }
//        if (((roofX2 + (2 * barrierGap)) <= bird) && (bird <= ((roofX2 + (2 * barrierGap)) + roofWidth))) {
//            if ((bird <= (r6 + roofHeight)) || (bird >= (ro6 + roofHeight))) {
//
//                reposition bird
//                birdY = r6 + 120;
//
//                decrease lives
//                lives -= 1;
//                printLives();
//            }
//
//        }
//        ---// r7 then r8
//
//        set 3
//        if ((bird >= (barrierX3)) && (bird <= ((barrierX3)+barrierWidth))) {
//            if ((birdY <= r7) || (birdY >= ro7)) {
//
//                reposition bird
//                birdY = r7 + 120;
//
//                decrease lives
//                lives -= 1;
//                printLives();
//            }
//        }
//
//        if (((roofX3) <= bird) && (bird <= ((roofX3)+roofWidth))) {
//            if ((birdY <= (r7 + roofHeight)) || (birdY >= (ro7 + roofHeight))) {
//
//                reposition bird
//                birdY = r7 + 120;
//
//                decrease lives
//                lives -= 1;
//                printLives();
//            }
//        }
//
//        ---// r8
//        if ((bird >= (barrierX3 + barrierGap)) && (bird <= ((barrierX3 + barrierGap) + barrierWidth))) {
//            if ((birdY <= r8) || (birdY >= ro8)) {
//
//                reposition bird
//                birdY = r8 + 120;
//
//                decrease lives
//                lives -= 1;
//                printLives();
//            }
//        }
//        if (((roofX3 + (barrierGap)) <= bird) && (bird <= ((roofX3 + (barrierGap)) + roofWidth))) {
//            if ((birdY <= (r8 + roofHeight)) || (birdY >= (ro8 + roofHeight))) {
//
//                reposition bird
//                birdY = r8 + 120;
//
//                decrease lives
//                lives -= 1;
//                printLives();
//            }
//
//        }
//
//        ---// r8
//        if ((bird >= (barrierX3 + (2 * barrierGap))) && (bird <= ((barrierX3 + (2 * barrierGap) + barrierWidth)))) {
//            if ((birdY <= r9) || (birdY >= ro9)) {
//
//                reposition bird
//                birdY = r9 + 120;
//
//                decrease lives
//                lives -= 1;
//                printLives();
//            }
//        }
//        if (((roofX3 + (2 * barrierGap)) <= bird) && (bird <= ((roofX3 + (2 * barrierGap)) + roofWidth))) {
//            if ((birdY <= r9) || (birdY >= ro9)) {
//
//                reposition bird
//                birdY = r9 + 120;
//
//                decrease lives
//                lives -= 1;
//                printLives();
//            }
//
//        }
//    }
//
//
//}
//
//void keyBoard(unsigned char key, int x, int y) {
//    if (key == 'f') {
//        birdY += 20;
//    }
//    glutPostRedisplay();
//}
//
//void Display() {
//    glClearColor(0.0f, 0.7f, 1.0f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    for (int i = 0; i < 100; i++) {
//        glColor3f(0, 0, 0);
//        char* p0s[20];
//        sprintf((char*)p0s, "Score: %d", i);
//        print(700, 567, (char*)p0s);
//    }
//    generateRandomSet();
//    drawBird();
//
//    sets(1, "normal");
//    sets(2, "normal");
//    sets(3, "normal");
//
//    glutKeyboardFunc(keyBoard);
//
//    printScore();
//    printLives();
//    collision();
//
//    glutSwapBuffers();
//}
//
//
//void main(int argc, char** argr) {
//    glutInit(&argc, argr);
//
//    glutInitWindowSize(screenWidth, screenHeight);
//    glutInitWindowPosition(0, 0);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//
//    srand(time(NULL));
//    r1 = (rand() % 160) + 260;
//    r2 = (rand() % 160) + 90;
//    r3 = (rand() % 160) + 200;
//    r4 = (rand() % 160) + 50;
//    r5 = (rand() % 160) + 210;
//    r6 = (rand() % 160) + 80;
//    r7 = (rand() % 160) + 10;
//    r8 = (rand() % 160) + 150;
//    r9 = (rand() % 160) + 5;
//
//    ro1 = (rand() % 260) + (screenHeight);
//    ro2 = (rand() % 260) + (screenHeight);
//    ro3 = (rand() % 260) + (screenHeight);
//    ro4 = (rand() % 260) + (screenHeight);
//    ro5 = (rand() % 260) + (screenHeight);
//    ro6 = (rand() % 260) + (screenHeight);
//    ro7 = (rand() % 260) + (screenHeight);
//    ro8 = (rand() % 260) + (screenHeight);
//    ro9 = (rand() % 260) + (screenHeight);
//
//
//    glutCreateWindow("Flappy Bird");
//    glutDisplayFunc(Display);
//
//    glutIdleFunc(Anim);
//
//
//    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//    gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);
//    glutMainLoop();
//
//}