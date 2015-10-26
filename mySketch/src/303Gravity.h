#pragma once
#include "ofMain.h"
#include "303SingleF.h"
class Smoke;

class Gravity:
	public SingleF
{
public:
	Gravity(ofPtr<Smoke> P, ofVec3f mousePos,float gravity= 2.0f);
	virtual ~Gravity(void);

	virtual void applyForce();
	virtual void draw();
	void update(ofVec3f mousePos,float gravity);

private:
	ofParameter<float> _Gravity;
	ofParameter<ofVec3f> _mousePos;

};
