//
//  main.cpp
//  Step1
//
//  Created by Jake on 2016/01/04.
//  Copyright © 2016年 Jake. All rights reserved.
//

// step1 create window

#include <iostream>
#include <GLUT/glut.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void init(void){
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
