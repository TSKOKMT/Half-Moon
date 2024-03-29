#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"

class halfMoon {

public:
    halfMoon();
    void draw(ofRectangle frame_, float time_);
        
    vector<ofColor> colors;
};
