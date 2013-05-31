//
//  CCAnimationHelper.cpp
//  slidefun
//
//  Created by Xia Inkoo on 12-11-27.
//
//

#include "CCAnimateManager.h"
#include "cocos2d.h"

using namespace cocos2d;

CCAnimate * CCAnimateManager::getAnimate(string name)
{
    return CCAnimate::create(CCAnimationCache::sharedAnimationCache()->animationByName(name.c_str()));
}

void CCAnimateManager::animateWithFrame(string frame, int frameCount, float delay, string animateName, const char * format)
{
    CCAnimation* animation = CCAnimation::create();
    animation->setDelayPerUnit(delay);
    char str[64] = {0};
	for (int i = 0; i < frameCount; i++)
	{
        sprintf(str, format,frame.c_str(), i);
		CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
		CCSpriteFrame* frame = cache->spriteFrameByName(str);
		animation->addSpriteFrame(frame);
	}
    CCAnimationCache::sharedAnimationCache()->addAnimation(animation, animateName.c_str());
}

void CCAnimateManager::animateWithFile(string name, int frameCount, float delay, string animateName, const char * format)
{
    CCAnimation* animation = CCAnimation::create();
    animation->setDelayPerUnit(delay);
    char str[64] = {0};
	for (int i = 0; i < frameCount; i++)
	{
		sprintf(str, format,name.c_str(), i);
        CCTexture2D * texture = CCTextureCache::sharedTextureCache()->addImage(str);
        CCSize size = texture->getContentSize();
        CCRect rect = CCRectMake(0, 0, size.width, size.height);
		CCSpriteFrame * frame = CCSpriteFrame::createWithTexture(texture, rect);
        animation->addSpriteFrame(frame);
	}
	CCAnimationCache::sharedAnimationCache()->addAnimation(animation, animateName.c_str());
}
