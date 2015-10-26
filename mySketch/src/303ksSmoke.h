#pragma once

#include "ofMain.h"

class Smoke;


class SingleF;

class Resistance;
class Gravity;
class Drive;
class WindResistance;


class ksSmoke{

public:
	ksSmoke(float Pmass,float Pgravity,float Pdrive_k,float Pdrive,
				float PwindForce, float PwindAngle,float Presistance);
	~ksSmoke();

	void update();
	void draw();

	void press(float x, float y); 

	void updateParameter(float Pmass,float Pgravity,float Pdrive_k,float Pdrive,
							float PwindForce, float PwindAngle,float Presistance);

	void setupGravity();
	void setupDrive();
	void setupWindResistance();


	void update_singleForce();
	void update_gravity();
	void update_windresistance();
	void update_drive();
	void updateParticles();


	ofVec3f mousePos;
	ofVec3f eggPos;
	int num;

	// Smokes
	vector<ofPtr<Smoke> > Sts;

	// Single Forces
	vector<ofPtr<SingleF> > SF;		
	vector<ofPtr<Resistance> > Rfs;
	vector<ofPtr<Gravity> > Gfs;
	vector<ofPtr<Drive> > Dfs;
	vector<ofPtr<WindResistance> > Wfs;

private:
	float mass;
	float gravity;
	float drive_k;
	float drive; 
	float windForce; 
	float windAngle;
	float resistance;


};
