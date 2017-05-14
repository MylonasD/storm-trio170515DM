#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define HOST "localhost"
//#define PORT 12345
#define PORT 57130

#define NUM_MSG_STRINGS 20

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		ofVboMesh mesh;
		ofEasyCam cam;

		ofxOscReceiver          receiver;

		float oscX = 0.0;
		float oscY = 0.0;
		float oscZ = 0.0;

        int mouseX =0;
          // mouseY;

		int current_msg_strings;
		string msg_strings[NUM_MSG_STRINGS];
		float timers[NUM_MSG_STRINGS];

};
