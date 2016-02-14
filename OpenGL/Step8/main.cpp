//
//  main.cpp
//  Step8
//
//  Created by Jake on 2016/02/01.
//  Copyright © 2016年 Jake. All rights reserved.
//

// step8 3D rotate

#include <iostream>
#include <GLUT/glut.h>

GLdouble vertex[][3] = {
    { 0.0, 0.0, 0.0 },
    { 1.0, 0.0, 0.0 },
    { 1.0, 1.0, 0.0 },
    { 0.0, 1.0, 0.0 },
    { 0.0, 0.0, 1.0 },
    { 1.0, 0.0, 1.0 },
    { 1.0, 1.0, 1.0 },
    { 0.0, 1.0, 1.0 }
};

int edge[][2] = {
    { 0, 1 },
    { 1, 2 },
    { 2, 3 },
    { 3, 0 },
    { 4, 5 },
    { 5, 6 },
    { 6, 7 },
    { 7, 4 },
    { 0, 4 },
    { 1, 5 },
    { 2, 6 },
    { 3, 7 }
};

void display(void)
{
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    //glRotated(25.0, 0.0, 1.0, 0.0);// 傾かせる
    glColor3d(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    for (i = 0; i < 12; i++) {
        glVertex3dv(vertex[edge[i][0]]);
        glVertex3dv(vertex[edge[i][1]]);
    }
    glEnd();
    glFlush();
}

void resize(int w , int h){
    glViewport(0, 0, w, h);
    glLoadIdentity();
    //glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0); //平行投影
    gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0); // 透視投影
    //glTranslated(0.0, 0.0, -5.0);// object を動かす
    gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void init(void){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    init();
    glutMainLoop();
    return 0;
}





