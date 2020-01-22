#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup() {
    ofDisableArbTex();
    
    ofFboSettings settings;
    settings.internalformat = GL_RGB32F;
    settings.width = ofGetWidth();
    settings.height = ofGetHeight();
    settings.useDepth = true;
    settings.depthStencilAsTexture = true;

    fbo.allocate(settings);
    
    fbo.begin();
    ofClear(0, 0, 0);
    ofClearAlpha();
    fbo.end();

    model.loadModel("pikachu.obj");
    mesh = model.getMesh(0);
    
    ofLoadImage(texture, "pikachu.png");
    camera.setPosition(0, 0, 525);
	//Load shader
	// shader.load( "shaderVert.c", "shaderFrag.c" );
	shader.load( "base.vert", "base.frag" );
}

//--------------------------------------------------------------
float time0 = 0;
float phase = 0;
float distortAmount = 0;

void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	ofEnableDepthTest();				//Enable z-buffering

	//Set a gradient background from white to gray
	//for adding an illusion of visual depth to the scene
	ofBackgroundGradient( ofColor( 255 ), ofColor( 128 ) );

	ofPushMatrix();	//Store the coordinate system

	//Move the coordinate center to screen's center
	ofTranslate( ofGetWidth()/2, ofGetHeight()/2, 0 );

	//Calculate the rotation angle
	float time = ofGetElapsedTimef();	//Get time in seconds
	// rotate doesn't seem to work:
	float angle = time * 10;			//Compute angle. We rotate at speed 10 degrees per second
        ofRotate( angle, 0, 1, 0 );			//Rotate the coordinate system along y-axe

	//Enable the shader
        camera.begin();
	shader.begin();		
        shader.setUniform1f("u_time", time);

        //TODO: new
        shader.setUniformTexture( "tex0", texture, 0 );
    bool wireframe = false; 
    if (!wireframe) {mesh.draw();}
    else {mesh.drawWireframe();}

    shader.end();	//Disable the shader
    camera.end();
    
    ofPopMatrix();	//Restore the coordinate system
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
