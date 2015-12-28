//
//  Step1.hpp
//  OpenGL
//
//  Created by Jake on 2015/12/28.
//  Copyright © 2015年 Jake. All rights reserved.
//

#ifndef Step1_h
#define Step1_h

#include <stdio.h>

class Step1{
public:
    int exec(int argc ,char * argv[]);
    void initializeGlutCallbacks();
    static void renderSceneCallBack(void );
};

#endif /* Step1_sdh */
