#include "303Gravity.h"
#include "303Smoke.h"


Gravity::Gravity( 
	ofPtr<Smoke> P,ofVec3f mousePos,float gravity):
SingleF(P)	
{
	_mousePos.set("mousePOS",mousePos);
	_Gravity.set("Gravity",gravity);
}

Gravity::~Gravity(void)
{

}

void Gravity::applyForce()
{
	ofPtr<Smoke> P = getS();
	ofVec3f Pos0=P->getPosition();
	ofVec3f Pos1=_mousePos;

	ofVec3f dir =(Pos1-Pos0).normalize();
	
	float M = P->getMass();

	ofVec3f ForceGravity = M * _Gravity * _Gravity  * _Gravity * dir;
	P->applyForce(ForceGravity);
}

void Gravity::draw()
{

}

void Gravity::update(ofVec3f mousePos,float gravity)
{
	_Gravity= gravity;
	_mousePos=mousePos;
}
