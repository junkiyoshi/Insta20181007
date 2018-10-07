#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
}
//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	int deg = 0;
	int deg_span = 10;
	for (int radius = 0; radius <= 430; radius += 2) {

		float circumference = 2 * PI * radius;
		float small_radius = circumference / 360 * deg_span * 0.5;

		ofPushMatrix();
		ofPoint point = ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
		ofTranslate(point);

		ofNoFill();
		ofDrawCircle(ofPoint(), small_radius);

		int start_deg = ofMap(ofNoise(radius * 0.05 + ofGetFrameNum() * 0.05), 0, 1, 0, 720);
		ofFill();
		ofBeginShape();
		for (int small_deg = start_deg; small_deg < start_deg + 360; small_deg += 120) {
		
			ofVertex(small_radius * cos(small_deg * DEG_TO_RAD), small_radius * sin(small_deg * DEG_TO_RAD));
		}
		ofEndShape(true);

		ofPopMatrix();
		
		deg += deg_span;
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}