#include "303WindResistance.h"
#include "303Smoke.h"


WindResistance::WindResistance( 
	ofPtr<Smoke> P,
	 float  windForce, float windAngle):
SingleF(P)	
{
	_WindForce.set("WindForce",windForce,0.0f,10.0f);
	_WindAngle.set("WindAngle",windAngle,0.0f,90.0f);
}

WindResistance::~WindResistance(void)
{

}

void WindResistance::applyForce()
{
	ofPtr<Smoke> P = getS();

	float Angle=_WindAngle/360*3.14*2;
	
	ofVec3f FoceWindResist = ofVec3f(_WindForce*_WindForce*_WindForce*cos(Angle),
									_WindForce*_WindForce*_WindForce*sin(Angle),0);

	P->applyForce(FoceWindResist);
}

void WindResistance::draw()
{

}

void WindResistance::update( float windForce ,float windAngle )
{
	_WindForce=windForce;
	_WindAngle=windAngle;
}
