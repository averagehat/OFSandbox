#include "testApp.h"
#include "ofAppGlutWindow.h"

//--------------------------------------------------------------
int main(){
  // ofAppGlutWindow window; // create a window
	// set width, height, mode (OF_WINDOW or OF_FULLSCREEN)
  // 	ofSetupOpenGL(1024, 768, OF_WINDOW);
  // 	  ofGLFWWindowSettings settings;
	  ofGLFWWindowSettings settings;
          settings.setGLVersion(3, 2);
      settings.setSize(1024, 768);
      ofCreateWindow(settings);
	ofRunApp(new testApp()); // start the app
}
