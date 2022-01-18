#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup() {
    ofEnableDepthTest();
    baseNode.setPosition(0, 0, 0);
    childNode.setParent(baseNode);
    childNode.setPosition(0, 0, 200);
    grandChildNode.setParent(childNode);
    grandChildNode.setPosition(0, 10, 0);
    //cam.setParent(grandChildNode);
    //cam.setAutoDistance(false);
    cam.setFarClip(100000);
    cam.setPosition(100, 100, 0);
    reverseDolly = true;
    color = ofColor(255, 0, 0);

}

//--------------------------------------------------------------
void ofApp::update() {
    //cam.setFarClip(sin(ofGetElapsedTimeMillis())/ 1000);
    int tempCounter = 0;
    // 
    //if ((int)ofGetElapsedTimef() % 2 == 1) {
    //    tempCounter++;
    //    cam.rotateAroundDeg(tempCounter, glm::vec3(0, 1, 0), baseNode.getGlobalPosition());
    //    cam.lookAt(baseNode);
    //    if (reverseDolly == true) {
    //        cam.dolly(tempCounter * 5);
    //    }
    //    if (reverseDolly == false) {
    //        cam.dolly(tempCounter * 5 * -1);
    //    }
    //}

    //if (reverseDolly == true) {
    //    cam.dolly();
    //}
    //if (reverseDolly == false) {
    //    cam.dolly( * -1);
    //}
    
    if ((int)ofGetElapsedTimef() % 3 == 1) {
        reverseDolly = !reverseDolly;
    }

    //baseNode.pan(.3f);
    baseNode.pan(1);
    baseNode.rotateDeg(20, glm::vec3(0, 1, 0));
    cam.lookAt(baseNode);
    cam.rotateAroundDeg(0.3, glm::vec3(0, 1, 0), baseNode.getGlobalPosition());
    //cam.rotateAroundDeg(0.2, glm::vec3(1, 0, 0), baseNode.getGlobalPosition());
    //baseNode.tilt(-1);
    //childNode.tilt(1);
    //childNode.pan(sin(ofGetElapsedTimef()));
    childNode.move(6 * sin(ofGetElapsedTimef()) + 20, 0, 0);
    childNode.move(0,  sin(ofGetElapsedTimef()) * 50, 0);
    //childNode.pan(1); 
    //childNode.rollDeg(1);

    line.addVertex(childNode.getGlobalPosition());

    if (line.size() > 10000) {
        line.getVertices().erase(
            line.getVertices().begin()
        );
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(255);
    ofSetColor(color);
    cam.begin();

    for (float i = 0; i < line.getVertices().size(); i++) {
        color.setHueAngle((i / line.getVertices().size()) * 360);
        //ofSetColor(color + ofGetElapsedTimef());
        ofSetColor(255 * (i / line.getVertices().size()));
        if (i == 0) {

        }

        line.getVertices()[i];
        ofDrawSphere(line.getVertices()[i], 30 * log(i));

    }
    ofSetColor(0);
    //line.draw();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 0) {
        std::cout << cam.getGlobalTransformMatrix() << std::endl;
    }
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
