#include "303ksSmoke.h"
#include "303Smoke.h"
#include "303SingleF.h"
#include "303Gravity.h"
#include "303Drive.h"
#include "303WindResistance.h"

//--------------------------------------------------------------
ksSmoke::ksSmoke(float Pmass,float Pgravity,float Pdrive_k,float Pdrive,
					   float PwindForce, float PwindAngle,float Presistance){
	mass=Pmass;
	gravity=Pgravity;
	drive_k=Pdrive_k;
	drive=Pdrive;
	windForce=PwindForce;
	windAngle=PwindAngle;
	resistance=Presistance;
	mousePos=ofVec3f(ofRandom(0.6,1)*ofGetWidth(),ofRandom(0.4,1)*ofGetHeight(),0);
	eggPos=mousePos;
	num=0;

	for(int i=0;i<50;i++)
	{
		ofPtr<Smoke> P;
		ofPoint Pos = ofPoint(300,300);
		ofVec3f V;
		V.x = ofRandom(-30.0f,30.0f);
		V.y = ofRandom(-30.0f,30.0f);
		ofVec3f a;
//		a.x =ofRandom(0,360.0f);
//		a.y =ofRandom(0,360.0f);
		P.reset(new Smoke(Pos,mass,a,V));
		Sts.push_back(P);
	}

	setupGravity();
	setupDrive();
	setupWindResistance();

}

ksSmoke::~ksSmoke()
{

}


//--------------------------------------------------------------
void ksSmoke::update(){

	updateParticles();

	update_singleForce();
	
	update_gravity();
	update_drive();
	update_windresistance();

}

//--------------------------------------------------------------

	
void ksSmoke::draw(){
	
//	ofColor C=ofColor(0,windAngle/360*255,windAngle/360*255);
//	ofBackground(C);

	vector<ofPtr<Smoke> >::iterator itr;
	for(itr = Sts.begin();itr<Sts.end();itr++)
	{
		ofPtr<Smoke> pt = *itr;
		pt->draw();
	}

	vector<ofPtr<SingleF> >::iterator itSF;
	for(itSF=SF.begin();itSF<SF.end();itSF++)
	{
		ofPtr<SingleF> SF = *itSF;
		SF->draw();
	}


}


void ksSmoke::setupGravity()
{
	int NumPts = Sts.size();
	for(int i=0;i<NumPts;i++)
	{
		ofPtr<Gravity> gravityForce;
		ofPtr<Smoke> Pt;
		Pt = Sts[i];
		gravityForce.reset(new Gravity(Pt,mousePos,gravity));
		Gfs.push_back(gravityForce);
		SF.push_back(gravityForce);
	}
}


void ksSmoke::setupDrive()
{
	int NumPts = Sts.size();
	for(int i=0;i<NumPts;i++)
	{
		ofPtr<Drive> DriveForce;
		ofPtr<Smoke> Pt;
		Pt = Sts[i];
		DriveForce.reset(new Drive(Pt,mousePos,drive,drive_k));
		Dfs.push_back(DriveForce);
		SF.push_back(DriveForce);
	}
}


void ksSmoke::setupWindResistance()
{
	int NumPts = Sts.size();
	for(int i=0;i<NumPts;i++)
	{
		ofPtr<WindResistance> WindResistForce;
		ofPtr<Smoke> Pt;
		Pt = Sts[i];
		WindResistForce.reset(new WindResistance(Pt,windForce,windAngle));
		Wfs.push_back(WindResistForce);
		SF.push_back(WindResistForce);
	}
}


void ksSmoke::updateParticles()
{
	vector<ofPtr<Smoke> >::iterator itr;
	for(itr = Sts.begin();itr<Sts.end();itr++)
	{
		ofPtr<Smoke> pt = *itr;				
		pt->update(mass);
		pt->setinitalPos(mousePos);	
	}
}

void ksSmoke::update_gravity()
{
	vector<ofPtr<Gravity> >::iterator itG;
	for(itG=Gfs.begin();itG<Gfs.end();itG++)
	{
		ofPtr<Gravity> G = *itG;
		G->update(mousePos,gravity);
	}
}


void ksSmoke::update_windresistance()
{
	vector<ofPtr<WindResistance> >::iterator itF;
	for(itF=Wfs.begin();itF<Wfs.end();itF++)
	{
		ofPtr<WindResistance> W = *itF;
		W->update(windForce,windAngle);
	}
}


void ksSmoke::update_drive()
{
	vector<ofPtr<Drive> >::iterator itD;
	for(itD=Dfs.begin();itD<Dfs.end();itD++)
	{
		ofPtr<Drive> D = *itD;
		D->update(mousePos,drive,drive_k);
	}
}


void ksSmoke::update_singleForce()
{
	vector<ofPtr<SingleF> >::iterator itSF;
	for(itSF=SF.begin();itSF<SF.end();itSF++)
	{
		ofPtr<SingleF> SF = *itSF;
		SF->applyForce();
	}
}

void ksSmoke::press( float x, float y )
{
	mousePos.x=x;
	mousePos.y=y;


}

void ksSmoke::updateParameter(float Pmass,float Pgravity,float Pdrive_k,float Pdrive,
								  float PwindForce, float PwindAngle,float Presistance)
{
	mass=Pmass;
	gravity=Pgravity;
	drive_k=Pdrive_k;
	drive=Pdrive;
	windForce=PwindForce;
	windAngle=PwindAngle;
	resistance=Presistance;
}


