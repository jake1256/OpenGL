//
//  main.cpp
//  Step12
//
//  Created by Jake on 2016/02/14.
//  Copyright © 2016年 Jake. All rights reserved.

// step12 component

#include <stdlib.h>
#include <GLUT/glut.h>

// 頂点
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

// 面
int face[][4] = {
    { 0, 1, 2, 3 }, /* A-B-C-D を結ぶ面 */
    { 1, 5, 6, 2 }, /* B-F-G-C を結ぶ面 */
    { 5, 4, 7, 6 }, /* F-E-H-G を結ぶ面 */
    { 4, 0, 3, 7 }, /* E-A-D-H を結ぶ面 */
    { 4, 5, 1, 0 }, /* E-F-B-A を結ぶ面 */
    { 3, 2, 6, 7 }  /* D-C-G-H を結ぶ面 */
};

// 稜線
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

//色
GLdouble color[][3] = {
    { 1.0, 0.0, 0.0 }, /* 赤 */
    { 0.0, 1.0, 0.0 }, /* 緑 */
    { 0.0, 0.0, 1.0 }, /* 青 */
    { 1.0, 1.0, 0.0 }, /* 黄 */
    { 1.0, 0.0, 1.0 }, /* マゼンタ */
    { 0.0, 1.0, 1.0 }  /* シアン 　*/
};


// normal map(法線マップ)
GLdouble normal[][3] = {
    { 0.0, 0.0,-1.0 },
    { 1.0, 0.0, 0.0 },
    { 0.0, 0.0, 1.0 },
    {-1.0, 0.0, 0.0 },
    { 0.0,-1.0, 0.0 },
    { 0.0, 1.0, 0.0 }
};

// 光源１の位置
GLfloat light0pos[] = { 0.0, 3.0, 5.0, 1.0 };
// 光源２の位置
GLfloat light1pos[] = { 5.0, 3.0, 0.0, 1.0 };
// 光源２の色
GLfloat green[] = { 0.0, 1.0, 0.0, 1.0 };

/* 材質の色 */
GLfloat red[] = { 0.8, 0.2, 0.2, 1.0 };
GLfloat blue[] = { 0.2, 0.2, 0.8, 1.0 };

void cube(void){
    int i;
    int j;
    glBegin(GL_QUADS);
    for(i = 0 ; i < 6 ; i++){
        glNormal3dv(normal[i]);
        for (j = 0; j < 4; j++) {
            glVertex3dv(vertex[face[i][j]]);
        }
    }
    glEnd();
}

void idle(void){
    glutPostRedisplay();
}

void display(void)
{
    static int r = 0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* 光源の位置をセット */
    glLightfv(GL_LIGHT0, GL_POSITION, light0pos);
    glLightfv(GL_LIGHT1, GL_POSITION, light1pos);
    
    /* モデルビュー変換行列の保存 */
    glPushMatrix();
    
    glRotated((double)r, 0.0, 1.0, 0.0);
    
    /* 図形の色(赤) */
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, red);
    
    /* 図形の描画 */
    cube(); /* 赤く、回転速度遅い */
    
    /* 二つ目の図形描画(階層構造になっており、Push-Pop間の内部にしか影響が出ないのに注目) */
    glPushMatrix();
    glTranslated(1.0, 1.0, 1.0);
    glRotated((double)r, 0.0, 1.0, 0.0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, blue);
    cube(); /* 青く、回転速度が速い */
    glPopMatrix();
    
    /* モデルビュー変換行列の復帰 */
    glPopMatrix();
    
    glutSwapBuffers(); // 画面入れ替え(ダブルバッファリング)
    
    if (++r >= 360) {
        r = 0;
    }
}

void resize(int w , int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0); // 透視投影
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void init(void){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    // デプスバッファを有効に
    glEnable(GL_DEPTH_TEST);
    
    // カリングを有効に
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT); // GL_BACKにすると裏側を消去
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, green);
    glLightfv(GL_LIGHT1, GL_SPECULAR, green);
}

void mouse(int button , int state , int x , int y){
    switch (button) {
            // 押している間進む
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN) {
                glutIdleFunc(idle);
            }
            else{
                glutIdleFunc(0); // stop
            }
            break;
            // 1クリックごとに進む
        case GLUT_RIGHT_BUTTON:
            if(state == GLUT_DOWN){
                glutPostRedisplay();
            }
            break;
        default:
            break;
    }
}

void keyboard(unsigned char key , int x , int y){
    switch (key) {
        case 'q':
        case 'Q':
        case '\033':
            exit(0);
            break;
        default:
            break;
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); // ダブルバッファリングをON
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
}





