#include "303Drive.h"
#include "303Smoke.h"



Drive::Drive( 
	ofPtr<Smoke> P,ofVec3f mousePos,float drive_k,float drive):
SingleF(P)	
{
	_mousePos.set("mousePOS",mousePos);
	_Drive.set("Drive",drive);
	_Drive_k.set("Drive_k",drive_k);
}

Drive::~Drive(void)
{

}

void Drive::applyForce()
{
	ofPtr<Smoke> P = getS();
	
	ofVec3f Pos0=P->getPosition();
	ofVec3f Pos1=_mousePos;

	ofVec3f dir =(Pos0-Pos1).normalize();

	ofVec3f e=ofVec3f(-dir.y,dir.x,0);

//	float x=Pos.x-500;
//	ofVec3f e= ofVec3f(x,-abs(x*_Drive_k),0).normalize();	
	
	float M = P->getMass();
	ofVec3f ForceDrive =  M *_Drive *e *_Drive_k *_Drive_k *_Drive_k *_Drive_k  ;
	P->applyForce(ForceDrive);
}

void Drive::draw()
{

}

void Drive::update(ofVec3f mousePos , float drive ,float drive_k )
{
	_mousePos=mousePos;
	_Drive=drive;
	_Drive_k=drive_k;
}
