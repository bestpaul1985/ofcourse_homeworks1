#include "ofApp.h"
#include "303ksSmoke.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofDisableArbTex();
	ofEnableDepthTest();
	ofEnableAlphaBlending();
	
	

	Pmass=12.0;
	Pgravity=15.0;
	Pdrive_k=4.0;
	Pdrive=6.0;
	PwindForce=2.0;
	PwindAngle=60;
	Presistance=1.0;

	for(int i=0;i<1;i++)
	{
		ofPtr<ksSmoke> ksS;
		ksS.reset(new ksSmoke( Pmass, Pgravity, Pdrive_k, Pdrive,
			PwindForce,  PwindAngle, Presistance));
		ksSts.push_back(ksS);

	}
}

//--------------------------------------------------------------
void ofApp::update(){

	vector<ofPtr<ksSmoke> >::iterator itr;
	for(itr = ksSts.begin();itr<ksSts.end();itr++)
	{
		ofPtr<ksSmoke> pt = *itr;
		pt->update();
	
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0,0,0);
	vector<ofPtr<ksSmoke> >::iterator itr;
	for(itr = ksSts.begin();itr<ksSts.end();itr++)
	{
		ofPtr<ksSmoke> pt = *itr;
		pt->draw();
		pt->press(mousePos.x,mousePos.y);
	}
	ofImage I;
	ofSetColor(255);
	I.loadImage("texture.png");
	I.setImageType(OF_IMAGE_COLOR_ALPHA);
	I.draw(mousePos,50,50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	mousePos=ofPoint(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
