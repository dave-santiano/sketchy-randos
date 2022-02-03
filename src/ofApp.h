#pragma once

#include "ofMain.h"

struct circleBoi{
	glm::vec2 pos;
	ofColor color;
	int radius;
	circleBoi(glm::vec2 pos, ofColor color, int radius) :
		pos(pos),
		color(color),
		radius(radius)
	{}

	void draw() {
		ofSetColor(color);
		ofSetCircleResolution(64);
		ofDrawEllipse(pos, radius, radius);
	}
};


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

		void infiniteCaterpillar(ofNode domNode, ofNode subNode, int counter);
		int infinityCounter;
		ofPolyline mainLine;
		ofNode originAxis;
		ofNode baseNode;
		ofNode childNode;
		ofNode grandChildNode;
		ofPolyline line;
		ofEasyCam cam;
		ofBuffer camMatrix;
		bool reverseDolly;
		ofColor color;
		bool flip;
		
		vector<circleBoi> circleBois;
};
