#pragma once

#include "ofMain.h"

class Smoke
{
public:
	Smoke(
		ofPoint Pos = ofPoint(0,0,0),
		float Mass = 1.0,
		ofVec3f angle = ofVec3f(0,0,0),
		ofVec3f Vel = ofVec3f(0,0,0),
		ofVec3f Acc = ofVec3f(0,0,0));
	virtual ~Smoke(void);

	ofPoint getPosition() const { return position; }
	void setPosition(ofPoint val) { position = val; }
	void setinitalPos(ofPoint val) { initalPos = val; }
	void setVelocity(ofPoint val) { velocity = val; }
	void setMass(float val) { mass = val; }
	ofVec3f getVelocity() const { return velocity; }
	float getMass() const { return mass; }
	


	virtual void update(float Pmass);	
	virtual void draw();	

	void applyForce(ofVec3f F);

private:	
	void accelerate( float DeltaTime );
	void move( float DeltaTime );
	void bounceInWindow();
	void computeAcceleration();
	
private:
	// properties:
	ofPoint position;
	
	ofVec3f velocity;
	
	ofVec3f acceleration;
	float   mass;
	ofVec3f initalPos;
	ofVec3f	angle;
	ofVec3f Force;
	ofTexture Tex;
	ofImage I;




};

