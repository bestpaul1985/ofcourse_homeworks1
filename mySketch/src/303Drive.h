#pragma once
#include "ofMain.h"
#include "303SingleF.h"
class Smoke;

class Drive:
	public SingleF
{
public:
	Drive(ofPtr<Smoke> P,ofVec3f mousePos , float drive_k= 1.0f, float drive= 2.0f);
	virtual ~Drive(void);

	virtual void applyForce();
	virtual void draw();
	void update(ofVec3f mousePos , float drive ,float drive_k);

private:
	ofParameter<float> _Drive;
	ofParameter<float> _Drive_k;
	ofParameter<ofVec3f> _mousePos;

};
