#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    gui.setup();
    gui.add(sendSliderColor.setup("Color Slider", false));
    gui.add(color.setup("color",ofColor(100,100,140),ofColor(0,0),ofColor(255,255)));
    
    sender.setup(HOST, PORT);
    
    ofSetColor(255,255,255);
    ofBackground(0,0,0);
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofColor readSlider = color;
    int red     = readSlider.r;
    int green   = readSlider.g;
    int blue    = readSlider.b;
    
    if (red != prevR ||
        green != prevG ||
        blue != prevB){
        
        ofxOscMessage m;
        
        m.setAddress("/led");
        m.addIntArg(255);
        m.addIntArg(red);
        m.addIntArg(green);
        m.addIntArg(blue);
        
        sendMessage(m);
        
        prevR = red;
        prevG = green;
        prevB = blue;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(color);
    gui.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::sendMessage(ofxOscMessage msg) {
    //    ofLog() << "sending message" << endl;
    sender.sendMessage(msg);
}
