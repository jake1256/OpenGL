//
//  main.cpp
//  Step4
//
//  Created by Jake on 2016/01/11.
//  Copyright © 2016年 Jake. All rights reserved.
//

// step4 view port

#include <iostream>
#include <GLUT/glut.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    
    // 内部は頂点の色から保管された色で塗りつぶされる
    
    glColor3d(1.0, 0.0, 0.0); /* 赤 */
    glVertex2d(-0.9, -0.9);
    glColor3d(0.0, 1.0, 0.0); /* 緑  */
    glVertex2d(0.9, -0.9);
    glColor3d(0.0, 0.0, 1.0); /* 青 */
    glVertex2d(0.9, 0.9);
    glColor3d(1.0, 1.0, 0.0); /* 黄 */
    glVertex2d(-0.9, 0.9);
    glEnd();
    glFlush();
}

void resize(int w , int h){
    /* ウィンドウ全体をビューポートにする */
    glViewport(0, 0, w, h);
    /* 変換行列の初期あ */
    glLoadIdentity();
    /* スクリーン上の表示領域をビューポートの大きさに比例させる */
    glOrtho(-w / 200.0 , w / 200.0, -h / 200.0, h / 200.0, -1.0, 1.0);
    
}

void init(void){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

int main(int argc, char *argv[])
{
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(320, 240);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    init();
    glutMainLoop();
    return 0;
}

