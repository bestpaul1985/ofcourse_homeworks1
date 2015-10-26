#pragma once
#include "ofMain.h"
#include "303SingleF.h"
class Particle;

class WindResistance:
	public SingleF
{
public:
	WindResistance(ofPtr<Smoke> P, float windForce, float windAngle);
	virtual ~WindResistance(void);

	virtual void applyForce();
	virtual void draw();
	void update(float windForce ,float windAngle);

private:
	ofParameter<float> _WindForce;
	ofParameter<float> _WindAngle;


};

