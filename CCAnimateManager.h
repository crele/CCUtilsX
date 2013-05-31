//
//  CCAnimationHelper.h
//  slidefun
//
//  Created by Xia Inkoo on 12-11-27.
//
//

#ifndef __slidefun__CCAnimationManager__
#define __slidefun__CCAnimationManager__

#include <iostream>
#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class CCAnimateManager:public CCAnimation
{
public:
    static CCAnimate * getAnimate(string name);
    static void animateWithFile(string name, int frameCount, float delay, string animateName, const char * format = "%s%04d.png");
    static void animateWithFrame(string frame,int frameCount, float delay, string animateName,const char * format = "%s%04d.png");
};


#endif /* defined(__slidefun__CCAnimationHelper__) */
