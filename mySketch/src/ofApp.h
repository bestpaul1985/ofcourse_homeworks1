#pragma once

#include "ofMain.h"
class MouseSmoke;
class ksSmoke;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
		ofParameter<int> Mode;
		ofParameter<int> n;
		ofParameter<float> r;
		ofParameter<float> Pmass;
		ofParameter<float> Pgravity;
		ofParameter<float> Pdrive_k;
		ofParameter<float> Pdrive;
		ofParameter<float> PwindForce;
		ofParameter<float> PwindAngle;
		ofParameter<float> Presistance;


		ofPoint mousePos;
		// ----------- MouseSmoke ---------------------//
		vector<ofPtr<MouseSmoke> > Mts;

		// ----------- Smoke -----------------//
				vector<ofPtr<ksSmoke> > ksSts;
};
