#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup() {
    ofEnableDepthTest();
    originAxis.setGlobalPosition(0, 0, 0);
    baseNode.setPosition(0, 0, 0);
    childNode.setParent(baseNode);
    childNode.setPosition(0, 0, 0);

    
    ofSetSphereResolution(64);
    cam.setFarClip(10000);
    cam.setGlobalPosition(20, 0, 0);
    color = ofColor(255, 0, 0);
    ofSetFrameRate(30);
    flip = true;

    float translationStep = 0;
    for (size_t i = 0; i < 5000; i++) {
        //circleBois.push_back(circleBoi(glm::vec2(ofGetWidth() / 2 + cos(i * 60) * 60 - translationStep, ofGetHeight() / 2 + sin(i * 60) * 60 - translationStep), ofColor(0,0,0), 20));
        //circleBois.push_back(circleBoi(glm::vec2((ofGetWidth() / 2) + 100 - translationStep, (ofGetHeight() / 2) + 100 - translationStep), ofColor(0,0,0), 20));
        circleBois.push_back(circleBoi(glm::vec2(ofGetWidth() / 2, ofGetHeight() / 2 + 200 - translationStep), ofColor(0,0,0), 20));
        translationStep += 0.08;
    }
}

//--------------------------------------------------------------
void ofApp::update() {




}

//--------------------------------------------------------------
void ofApp::draw() {
    //infinityCounter = 0;
    ofBackground(255);
    //cam.begin();
    //ofSetColor(color);
    //ofDrawSphere(baseNode.getGlobalPosition(), 8);
    //ofSetColor(0, 125, 125);
    //ofDrawSphere(baseNode.getGlobalPosition(), 6);
    //cam.end();
    //ofSetColor(255);
    //ofDrawEllipse(ofGetWidth() - ofGetElapsedTimef() * 100, ofGetHeight()/2 + sin(ofGetElapsedTimef() * 10) * 100, 40, 40);
    //ofDrawEllipse(
    //    ofGetWidth() / 2 + cos(ofGetElapsedTimef()) * 60 - ofGetElapsedTimef() * 10, 
    //    ofGetHeight()/2 + sin(ofGetElapsedTimef()) * 60 - ofGetElapsedTimef() * 10, 
    //    40, 40);
    if (flip) {
        for (int i = 0; i < circleBois.size(); i++) {
            circleBois[i].color = ofColor(((float)i / circleBois.size()) * 255);
            circleBois[i].pos = circleBois[i].pos + glm::vec2(cos(ofGetElapsedTimef() * ofNoise(ofGetElapsedTimef() / 10) + i),sin(ofGetElapsedTimef() + i));
            circleBois[i].draw();
        }    
    }
    else {
        for (int i = 0; i < circleBois.size(); i++) {
            circleBois[i].color = ofColor(((float)i / circleBois.size()) * 255);
            circleBois[i].pos = circleBois[i].pos + glm::vec2(cos(ofGetElapsedTimef() * ofNoise(ofGetElapsedTimef() / 10) + i),sin(ofGetElapsedTimef() * i));
            circleBois[i].draw();
        }
    }
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'l') {
        cam.lookAt(baseNode);
    }
    if (key == 'g') {
        cam.setGlobalPosition(baseNode.getGlobalPosition());
    }
    if (key == 'c') {
        cout << cam.getGlobalPosition() << endl;
        cout << baseNode.getGlobalPosition() << endl;
    }
    if (key = 'f') {
        flip = !flip;
    }
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

void ofApp::infiniteCaterpillar(ofNode domNode, ofNode subNode, int counter){
    while (counter < 10) {
        ofSetColor(255 * (counter / 10.0f), 125, 125);
        domNode.setGlobalPosition(domNode.getGlobalPosition() + glm::vec3(0, abs(sin(ofGetElapsedTimef())) + 30, 0));
        //subNode.setGlobalPosition(subNode.getGlobalPosition() + glm::vec3(0, 15 * abs(cos(ofGetElapsedTimef())) + 15, 0));

        ofDrawSphere(domNode.getGlobalPosition(), exp(counter/(3.0f)));
        //ofDrawSphere(domNode.getGlobalPosition(), counter);
        //ofDrawSphere(subNode.getGlobalPosition(), 5 + (counter * 2));
        counter++;
        infiniteCaterpillar(domNode, subNode, counter);
    }
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
