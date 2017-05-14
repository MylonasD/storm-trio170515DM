#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	
	
	
	//mesh.setMode(OF_PRIMITIVE_POINTS);
	//ofColor c = ofRandom(0, 100000);
	
	//if new xyz from OSC =pos
	//ofVec3f pos (oscX,  oscY, oscZ);
	//mesh.addVertex(pos);
	//mesh.addColor(c);
	
	receiver.setup(PORT);
	cout << "listening for osc messages on port " << PORT << "\n";
	/*
	//////////////////////////////  1
	mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	mesh.enableColors();
	mesh.enableIndices();

	ofVec3f top(100.0, 50.0, 0.0);
	ofVec3f left(50.0, 150.0, 0.0);
	ofVec3f right(150.0, 150.0, 0.0);

	mesh.addVertex(top);
	mesh.addColor(ofFloatColor(1.0, 0.0, 0.0));

	mesh.addVertex(left);
	mesh.addColor(ofFloatColor(0.0, 1.0, 0.0));

	mesh.addVertex(right);
	mesh.addColor(ofFloatColor(1.0, 1.0, 0.0));

	*/
	////////////////////////// 2
	
	mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	mesh.enableColors();

	
	
	
}

//--------------------------------------------------------------
void ofApp::update() {

	ofVec3f  v0(-100, -100, -100);
	ofVec3f v1(100, -100, -100);
	ofVec3f v2(100, 100, -100);
	ofVec3f v3(-100, 100, -100);
	ofVec3f v4(-100, -100, 100);
	ofVec3f v5(100, -100, 100);
	ofVec3f v6(100, 100, 100);
	ofVec3f v7(-100, 100, 100);
	ofVec3f v8(-150, 140, 300);
	ofVec3f v9(-190, 130, 320);
	ofVec3f v10(-200, 135, 360);
	ofVec3f v11(-230, 100, 380);
	ofVec3f v12(-250, 80, 390);
	ofVec3f v13(-300, 70, 410);
	//
    mesh.addVertex(v0);
	mesh.addColor(ofFloatColor(0.0, 0.0, 0.0));

	mesh.addVertex(v1);
	mesh.addColor(ofFloatColor(1.0, 0.0, 0.0));

	mesh.addVertex(v2);
	mesh.addColor(ofFloatColor(1.0, 1.0, 0.0));

	mesh.addVertex(v3);
	mesh.addColor(ofFloatColor(0.0, 1.0, 1.0));

	mesh.addVertex(v4);
	mesh.addColor(ofFloatColor(0.0, 0.0, 1.0));

	mesh.addVertex(v5);
	mesh.addColor(ofFloatColor(1.0, 0.0, 1.0));

	mesh.addVertex(v6);
	mesh.addColor(ofFloatColor(1.0, 1.0, 1.0));

	mesh.addVertex(v7);
	mesh.addColor(ofFloatColor(0.4, 0.8, 0.9));
	mesh.addVertex(v8);
	mesh.addColor(ofFloatColor(0.7, 1.0, 0.2));
	mesh.addVertex(v9);
	mesh.addColor(ofFloatColor(0.0, 1.0, 1.0));
	mesh.addVertex(v10);
	mesh.addColor(ofFloatColor(0.0, 1.0, 1.0));
	mesh.addVertex(v11);
	mesh.addColor(ofFloatColor(0.0, 1.0, 1.0));
	mesh.addVertex(v12);
	mesh.addColor(ofFloatColor(0.0, 1.0, 1.0));
	mesh.addVertex(v13);
	mesh.addColor(ofFloatColor(0.0, 1.0, 1.0));

	
	// osc receive from SuperCollider
	while (receiver.hasWaitingMessages()) {

        // get the next message
            ofxOscMessage m;
            receiver.getNextMessage(m);

            // check for mouse moved message
            if(m.getAddress() == "/data"){
                mouseX=100;
                // both the arguments are int32's
                //mouseX = m.getArgAsInt32(0);
                //mouseY = m.getArgAsInt32(1);
            }


            //ofxOscMessage m;
		// string msg_string;
        //m.setAddress("/data");
        //int x, y, z;
		//m.addFloatArg(x);
		//m.addFloatArg(y);
		//m.getArgAsFloat(x);
		//m.getArgAsFloat(y);
		//m.getArgAsFloat(z);
		// m.addInt32Arg(x);
		//m.addInt64Arg(x);
		//m.addIntArg(x);
        //m.getArgAsInt(x);
        //m.getArgAsInt(y);
        //m.getArgAsInt(z);

		// m.getArgAsBlob(x);
		//m.getArgAsBlob(y);


		//ofVec2f eventPos = ofVec2f(x, y);
		//ofVec2f mouseNorm = ofVec2f(eventPos) / ofGetWindowSize();
		//ofVec2f mouseVel = ofVec2f(eventPos - pMouse) / ofGetWindowSize();
		//addToFlui(mouseNorm, mouseVel, true, true);
		//pMouse = eventPos;
        //receiver.getNextMessage(m);



	}
}
//--------------------------------------------------------------
void ofApp::draw(){





         ofColor centerColor = ofColor(85, 78, 68);
	ofColor edgeColor(0, 0, 0);
	ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
	cam.begin();
	
	ofPushMatrix();
	ofTranslate(-ofGetWidth() / 2, -ofGetHeight() / 2); 
	mesh.draw();
	ofPopMatrix();
	cam.end();
	//ofLine(30, 40, 1, 300, 400, 1);
	glLineWidth(4);

    string buf;
        buf = "listening for osc messages on port" + ofToString(PORT);
        ofDrawBitmapString(buf, 10, 20);
        if (mouseX ==0){
            ofDrawBitmapString("nothin so far", 30, 40);
        }else

        {
            ofDrawBitmapString("got a massage", 50, 60);
        }
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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
