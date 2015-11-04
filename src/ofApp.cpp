#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ofxGuiSetDefaultWidth(600);
    gui.setup();
    
    gui.add(sendSliderColor.setup("Color Slider", true));
    gui.add(color.setup("color",ofColor(100,100,140),ofColor(0,0),ofColor(255,255)));
    
    if (XML.load("settings.xml") ){
        ofLog() << "XML loaded" << endl;
    }
    
    else {
        // if nonexistent, create
        XML.addChild("SETTINGS");
        XML.setTo("SETTINGS");
    }
    
    
    if(XML.exists("//HOST")) {
        HOST = XML.getValue<string>("//HOST");
        ofLog() << "loaded HOST: " << ofToString(HOST) << endl;
    } else {
        HOST = "192.168.2.3";
    }
    
    if(XML.exists("//PORT")) {
        PORT = XML.getValue<int>("PORT");
        ofLog() << "loaded PORT: " << ofToString(PORT) << endl;
    } else {
        PORT = 9998;
    }
    
    
    if(XML.exists("//HOST2")) {
        HOST2 = XML.getValue<string>("//HOST2");
        ofLog() << "loaded HOST2: " << ofToString(HOST2) << endl;
    } else {
        HOST2 = "192.168.2.3";
    }
    
    if(XML.exists("//PORT2")) {
        PORT2 = XML.getValue<int>("PORT2");
        ofLog() << "loaded PORT2: " << ofToString(PORT2) << endl;
    } else {
        PORT2 = 9998;
    }
    
    
    sender.setup(HOST, PORT);
    sender2.setup(HOST2, PORT2);
    
    ofSetColor(255,255,255);
    ofBackground(0,0,0);
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(sendSliderColor){
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
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(color);
    gui.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch(key){
            
        case ' ':
            
            
            sendSliderColor = !sendSliderColor;
            
            break;
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
    sender2.sendMessage(msg);
}
