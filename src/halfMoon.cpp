#include "halfMoon.h"

//--------------------------------------------------------------
void halfMoon::draw(ofRectangle frame_, float time_, float side_) {
    
    ofPushMatrix();
    ofTranslate(frame_.getCenter());
    
    for (int v = -10; v <= 10; v++) {
        for (int h = -10; h <= 10; h++) {
            float motion = ofWrap((time_ - h * .25) / 4., 0, 1);
            motion = ofxTskokmtMath::cubicBezierByX(ofPoint(.85, 0), ofPoint(.15, 1), motion);
            
            ofColor color;
            if (h % 2 == 0) {
                if (ofWrap(v + 1 + h * 2, 0, 4) < 2) color.setHex(0x67d502);
                else color.setHex(0xf343ce);
            }
            else {
                if (ofWrap(v + 1 + h * 2, 0, 4) < 2) color.setHex(0xd9ea04);
                else color.setHex(0x0086d9);
            }
            ofSetColor(color);
            
            //ofDrawCircle(h * side_ * 2, v * side_ * 2, side_);
            ofPushMatrix();
            ofTranslate(h * side_ * sqrt(3) / 2., (v + .5) * side_ + (h % 2) * side_ / 2.);
            //ofRotateRad(ofNoise(v * PI * 100, h * 100) * 10000);
            //ofRotateRad(ofGetElapsedTimef() * (v % 2 ? -1 : 1));
            ofRotateRad(motion * TWO_PI);
            ofRotateRad((v % 2) * PI);
            ofRotateRad(-HALF_PI);
            ofBeginShape();
            for (int i = 0; i <= 180; i++) {
                float angle = ofMap(i, 0, 180, 0, PI);
                ofVertex(ofPoint(cos(angle), sin(angle)) * side_ / 2. * .99);
            }
            for (int i = 180; i >= 0; i--) {
                float angle = ofMap(i, 0, 180, 0, PI);
                ofVertex(ofPoint(cos(angle), sin(angle)) * side_ / 2. * .1);
            }
            ofEndShape(true);
            ofPopMatrix();
        }
    }
    
    ofPopMatrix();
}
