#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxGui.h"

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void sendMessage(ofxOscMessage msg);
    
        ofXml XML;
        
        // xml vars
        string HOST;
        string HOST2;
        int PORT;
        int PORT2;
    
        // gui vars
        ofxPanel gui;
        ofxToggle sendSliderColor;
        ofxColorSlider color;
        
        // OSC Sender
        ofxOscSender sender;
        ofxOscSender sender2;
		
        // other vars
        bool _debug;
        int prevR;
        int prevG;
        int prevB;
};
