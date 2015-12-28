//
//  Step1.cpp
//  OpenGL
//
//  Created by Jake on 2015/12/28.
//  Copyright © 2015年 Jake. All rights reserved.
//

#include "Step1.h"
#include <iostream>
#include <GLUT/glut.h>

void Step1::renderSceneCallBack(void){
    // フレームバッファを開放する。
    glClear(GL_COLOR_BUFFER_BIT);
    // バックバッファとフロントバッファを交換する。
    // つまり書き溜めておいたものを表示する
    glutSwapBuffers();
}

void Step1::initializeGlutCallbacks(){
    /*
     ウィンドウシステムで作業しているため、
     実行中のプログラムとの相互詐称の大部分はコールバック関数を介して起こります。そのメインコールバックを設定します。
     ここで設定した関数は継続的にGLUTループにより呼びだされます。
    */
    glutDisplayFunc(renderSceneCallBack);
}

int Step1::exec(int argc, char * argv[]){
    
    // GLUT OpenGLのユーティリティを初期化します。
    glutInit(&argc, argv);
    
    // GLUTのオプションを設定します。ダブルバッファリングとカラーバッファを指定。
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    
    // 以下の3つはウィンドウのパラメータを指定して、作成します。
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Step1");
    

    initializeGlutCallbacks();
    
    // フレームバッファをクリアする時に使用される色を指定
    glClearColor(0.0f, 0.0f , 0.0f, 0.0f);
    
    /*
     GLUTのループを開始します。具体的には
     ウィンドウシステムからのイベントをリッスンし、
     設定された関数を継続的に呼び出します。
     つまりDisplayFuncで設定された関数を呼び出し続けます。
    */
    glutMainLoop();
    
    return 0;
}
