#include "303Smoke.h"

Smoke::Smoke( 
	ofPoint Pos /*= ofPoint(0,0,0)*/, 
	float Mass /*= 1.0*/, 
	ofVec3f angle/* = ofVec3f(0,0,0)*/,
	ofVec3f Vel /*= ofVec3f(0,0,0)*/, 
	ofVec3f Acc /*= ofVec3f(0,0,0)*/ ):
	position(Pos),
	mass(Mass),
	velocity(Vel),//速度
	acceleration(Acc),
	Force(ofVec3f(0,0,0))
{
	initalPos=Pos;
	velocity=Vel;
	I.loadImage("123.png");
	I.setImageType(OF_IMAGE_COLOR_ALPHA);

}

Smoke::~Smoke(void)
{

}

void Smoke::update(float Pmass)
{
	computeAcceleration();

	float DeltaTime = ofGetLastFrameTime();
	accelerate(DeltaTime);
	move(DeltaTime);
	
//	bounceInWindow();
	
	if(position.distance(initalPos)>300.0f)
	{
		position=initalPos;
	}
	

	mass=Pmass;

}

void Smoke::draw()
{
	ofPushStyle();	
	
	ofPixels P;
	
	I.getTextureReference();
	ofSetColor(255);
	I.draw(position);
/*	for (int i=0;i<5;i++)
	{
		ofColor C=ofColor(255,255,255,255-15*i);
		ofSetColor(C);
		ofCircle(position,i);
	}*/

/*	ofFill();
	ofColor C1,C2;
	C1 =ofColor(255,255,255,200);
	C2 =ofColor(255,255,255,125);
	ofSetColor(C1);	
	ofCircle(position,10);*/
//	ofSetColor(C2);
//	ofCircle(position,6);
	ofPopStyle();
}

void Smoke::bounceInWindow()//小球触壁后反弹
{
	if(position.x>ofGetWidth()||position.x<0.0f)
	{
		velocity.x = -velocity.x;
	}
	if(position.y>ofGetHeight()||position.y<0.0f)
	{
		velocity.y = -velocity.y;
	}

	position.x = ofClamp(position.x, 0, ofGetWidth());
	position.y = ofClamp(position.y, 0, ofGetHeight());
}

void Smoke::move( float DeltaTime )
{
	ofVec3f DeltaPostion = DeltaTime * velocity * 1;
	position += DeltaPostion;
}

void Smoke::accelerate( float DeltaTime )
{
	ofVec3f DeltaVelocity = DeltaTime * acceleration;
	velocity += DeltaVelocity;
}

void Smoke::computeAcceleration()
{
	
	acceleration =  Force/mass;//acceleration加速度 a=F/m
	Force = ofVec3f(0,0,0);
}

void Smoke::applyForce( ofVec3f F )
{
	Force += F;
	Force.limit(10000.0f);
}


