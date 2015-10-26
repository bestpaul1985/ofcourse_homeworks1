#pragma once
#include "ofMain.h"
class Smoke;

class SingleF
{
public:
	SingleF(ofPtr<Smoke> P);
	virtual ~SingleF(void);

	virtual void applyForce()=0;
	virtual void draw()=0;
//	virtual void update()=0;

protected:
	ofPtr<Smoke> getS();	

private:
	ofPtr<Smoke> s;

};

