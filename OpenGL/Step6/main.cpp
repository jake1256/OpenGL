//
//  main.cpp
//  Step6
//
//  Created by Jake on 2016/01/11.
//  Copyright © 2016年 Jake. All rights reserved.
//

// step6 mouse drag

#include <stdio.h>
#include <GLUT/glut.h>

#define MAXPOINTS 100 /* 記憶する点の数 */
GLint point[MAXPOINTS][2]; /* 座標を記憶する配列 */
int pointnum = 0;
int rubberband = 0; /* ラバーバンドの消去 */

void display(void)
{
    int i;
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    if (pointnum > 1) {
        glColor3d(0.0, 0.0, 0.0);
        glBegin(GL_LINES);
        for (i = 0; i < pointnum; ++i) {
            glVertex2iv(point[i]);
        }
        glEnd();
    }
    glFlush();
}

void resize(int w , int h){
    /* ウィンドウ全体をビューポートにする */
    glViewport(0, 0, w, h);
    /* 変換行列の初期あ */
    glLoadIdentity();
    
    /* スクリーン上の座標系をマウスの座標系に一致させる */
    glOrtho(-0.5, (GLdouble)w - 0.5, (GLdouble)h - 0.5, -0.5, -1.0, 1.0);
    
}

void mouse(int button , int state , int x , int y){
    
    switch (button) {
        case GLUT_LEFT_BUTTON:
            printf("left");
            
            point[pointnum][0] = x;
            point[pointnum][1] = y;
            
            if (state == GLUT_UP) {
                /* ボタンを推した位置から離した位置まで線を引く */
                glColor3d(0.0, 0.0, 0.0);
                glBegin(GL_LINES);
                glVertex2iv(point[pointnum - 1]); // 一つ前は押した位置
                glVertex2iv(point[pointnum]); // 今の位置は離した位置
                glEnd();
                glFlush();
                
                /* 始点ではラバーバンドを描いていないので消さない */
                rubberband = 0;
            }
            
            if (pointnum < MAXPOINTS - 1) {
                ++pointnum;
            }
            
            break;
        case GLUT_MIDDLE_BUTTON:
            printf("middle");
            break;
        case GLUT_RIGHT_BUTTON:
            printf("right");
            break;
        default:
            break;
    }
    
    printf(" button is ");
    
    switch (state) {
        case GLUT_UP:
            printf("up");
            break;
        case GLUT_DOWN:
            printf("down");
            break;
        default:
            break;
    }
    
    printf(" at (%d , %d)\n" , x , y);
}

// ラバーバンドとは線をドラッグしているときに伸び縮みする線のこと
void motion(int x , int y){
    static GLint savepoint[2]; // 以前のラバーバンドの端点
    
    /* 論理演算機能 ON */
    glEnable(GL_COLOR_LOGIC_OP);
    glLogicOp(GL_INVERT);
    
    glBegin(GL_LINES);
    if (rubberband) {
        // 以前のラバーバンドを消す
        glVertex2iv(point[pointnum - 1]);
        glVertex2iv(savepoint);
    }
    
    glVertex2iv(point[pointnum - 1]);
    glVertex2i(x , y);
    glEnd();
    glFlush();
    
    /* 論理演算機能 OFF */
    glLogicOp(GL_COPY);
    glDisable(GL_COLOR_LOGIC_OP);
    
    /* 今書いたラバーバンドの端点を保存 */
    savepoint[0] = x;
    savepoint[1] = y;
    
    /* 今書いたラバーバンドは次のタイミングで消す */
    rubberband = 1;
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
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    init();
    glutMainLoop();
    return 0;
}



