#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetBackgroundAuto(false); // Disable automatic background clearing.
	//ofEnableAlphaBlending(); // Allow alpha channel transparency.
	ofSetCircleResolution(50); // Make circles smoother than the default.
	ofSetFrameRate(120); // Set the framerate to 60 frames per second.
	xPosition = ofGetWidth() / 2;
	yPosition = ofGetHeight() / 2;

	goat.load("goat2.png"); // bin/data folder is the default

	ofTrueTypeFont::setGlobalDpi(72);
	stencilFont.load("STENCIL.TTF", 30);
	ofLogToFile("myLogFile.txt", true);
}

//--------------------------------------------------------------
void ofApp::update() {
	if (movingUp) {
		yPosition -= 5;
	}

	if (movingDown) {
		yPosition += 5;
	}

	if (movingLeft) {
		xPosition -= 5;
	}

	if (movingRight) {
		xPosition += 5;
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(200); // Set the fill color to black with a low alpha value.
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight()); // Draw a rectangle that covers the canvas.

	goat.draw(xPosition, yPosition, 100, 100);

	// ofLog() << "X: " << xPosition << " Y: " << yPosition << "\n";
	ofSetColor(0);
	ofDrawBitmapString("X: " + std::to_string(xPosition) + " Y: " + std::to_string(yPosition), 100, 200);
	stencilFont.drawString("My Goat", xPosition - 10, yPosition + 120);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'w' || key == 'W') {
		// Up
		movingUp = true;
	}

	if (key == 's' || key == 'S') {
		// Down
		movingDown = true;
	}

	if (key == 'a' || key == 'A') {
		// Left
		movingLeft = true;
	}

	if (key == 'd' || key == 'D') {
		// Right
		movingRight = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	if (key == 'w' || key == 'W') {
		// Up
		movingUp = false;
	}

	if (key == 's' || key == 'S') {
		// Down
		movingDown = false;
	}

	if (key == 'a' || key == 'A') {
		// Left
		movingLeft = false;
	}

	if (key == 'd' || key == 'D') {
		// Right
		movingRight = false;
	}

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
