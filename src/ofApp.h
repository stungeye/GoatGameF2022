#pragma once

#include "ofMain.h"

struct Coordinate {
	float x, y;
};

class Actor {
	ofColor color;

public:
	ofRectangle collision;

	Actor(Coordinate coordinate, float width, float height, ofColor color):
		color{color}, collision{coordinate.x, coordinate.y, width, height} {
	}

	void draw() {
		ofSetColor(color);
		ofDrawRectangle(collision);
	}

	bool topBottomHit(const ofRectangle rect, const ofRectangle intersection) {
		return rect.getTop() <= collision.getBottom() && rect.getBottom() >= collision.getTop()
			&& (rect.getTop() > collision.getTop() + collision.height / 2 || rect.getBottom() < collision.getTop() +
				collision.height / 2)
			&& intersection.getWidth() > intersection.getHeight();
	}

	bool sideHit(const ofRectangle rect, const ofRectangle intersection) {
		return rect.getRight() >= collision.getLeft() && rect.getLeft() <= collision.getRight()
			&& (rect.getLeft() < collision.getLeft() || rect.getRight() > collision.getRight())
			&& intersection.getWidth() < intersection.getHeight();
	}


	void draw(Actor other) {
		draw();

		if (collision.intersects(other.collision)) {
			ofRectangle intersection = collision.getIntersection(other.collision);
			ofSetColor(ofColor::white);
			ofDrawRectangle(intersection);

			if (topBottomHit(other.collision, intersection)) {
				ofDrawBitmapString("Top / Bottom", 200, 180);
			} else if (sideHit(other.collision, intersection)) {
				ofDrawBitmapString("Side", 200, 180);
			}
		}
	}

	void update(Coordinate newCoordinate) {
		collision.setX(newCoordinate.x);
		collision.setY(newCoordinate.y);
	}
};

class ofApp : public ofBaseApp {

public:
	void setup() override;
	void update() override;
	void draw() override;

	void keyPressed(int key) override;
	void keyReleased(int key) override;
	void mouseMoved(int x, int y) override;
	void mouseDragged(int x, int y, int button) override;
	void mousePressed(int x, int y, int button) override;
	void mouseReleased(int x, int y, int button) override;
	void mouseEntered(int x, int y) override;
	void mouseExited(int x, int y) override;
	void windowResized(int w, int h) override;
	void dragEvent(ofDragInfo dragInfo) override;
	void gotMessage(ofMessage msg) override;

private:
	Actor a1{{200, 200}, 200, 100, ofColor::blue};
	Actor a2{{400, 400}, 50, 50, ofColor::red};
};
