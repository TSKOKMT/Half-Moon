#include "halfMoon.h"

//--------------------------------------------------------------
halfMoon::halfMoon() {
    
    colors.resize(6);
    colors[0].setHex(0xbec5c8);
    colors[1].setHex(0x00ae67);
    colors[2].setHex(0xf6a500);
    colors[3].setHex(0x168cc3);
    colors[4].setHex(0xf0616c);
    colors[5].setHex(0x9a4292);
}

//--------------------------------------------------------------
void halfMoon::draw(ofRectangle frame_, float time_) {
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    float side_ = 15 * unit;
    
    ofPushMatrix();
    ofTranslate(frame_.getCenter());
    
    int i = 0;
    for (int v = -7; v <= 7; v++) {
        for (int h = -7; h <= 7; h++) {
            float motion = ofWrap((time_ - h * .25) / 4., 0, 1);
            motion = ofxTskokmtMath::cubicBezierByX(ofPoint(.85, 0), ofPoint(.15, 1), motion);
            
            ofSetColor(colors[i % (int)colors.size()]);
            
            int res = 30;
            
            //ofDrawCircle(h * side_ * 2, v * side_ * 2, side_);
            ofPushMatrix();
            ofTranslate(h * side_ * sqrt(3) / 2., (v + .5) * side_ + (h % 2) * side_ / 2.);
            //ofRotateRad(ofNoise(v * PI * 100, h * 100) * 10000);
            //ofRotateRad(ofGetElapsedTimef() * (v % 2 ? -1 : 1));
            ofRotateRad(motion * TWO_PI);
            ofRotateRad((v % 2) * PI);
            ofRotateRad(-HALF_PI);
            ofBeginShape();
            for (int i = 0; i <= res; i++) {
                float angle = ofMap(i, 0, res, 0, PI);
                ofVertex(ofPoint(cos(angle), sin(angle)) * side_ / 2. * .99);
            }
            for (int i = res; i >= 0; i--) {
                float angle = ofMap(i, 0, res, 0, PI);
                ofVertex(ofPoint(cos(angle), sin(angle)) * side_ / 2. * .75);
            }
            ofEndShape(true);
            ofPopMatrix();
            
            i++;
        }
    }
    
    ofPopMatrix();
}
