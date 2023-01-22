// Aline Normoyle, 2020
//
// For documentation about this code, see the glfw3 quick start guide
//   https://www.glfw.org/docs/3.3/quick.html

#include "AGL.h"
#include "AGLM.h"
#include <cmath>
using namespace std;

GLFWvidmode return_struct;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
   if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
   {
      glfwSetWindowShouldClose(window, GLFW_TRUE);
   }
   //    if (key == GLFW_KEY_UP && action == GLFW_PRESS)
//    {

//         double time = glfwGetTime();
//         double red = (sin(time) + 1) * 0.5; // map sin value [-1,1] to color value [0,1]
//         double blue = (cos(time) + 1) * 0.5; // map cos value [-1,1] to color value [0,1]

//         // Create a vector to test glm
//         glm::vec3 color(red, 0, blue);
//         glClearColor(color.x, color.y, color.z, 1.0);

//         cout << "rgb " << red << " , " << "0 , " << blue << endl; 
//    }
}

// is this still static 
static int countPlaces(int num){
    
    int count = 0; 

    while(num > 0){
        num = num/10; 
        count += 1; 
    }

    return count; 

}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    int width = 0; 
    int height = 0; 

    glfwGetWindowPos(window, &width, &height);	

    if (width > 0 && height > 0)
    {
        double red = width/xpos; // map sin value [-1,1] to color value [0,1]
        double blue = height/ypos; // map cos value [-1,1] to color value [0,1]

        // Create a vector to test glm
        glm::vec3 color(red, 0, blue);
        glClearColor(color.x, color.y, color.z, 1.0);
    }
    else{
        double red = 0; // map sin value [-1,1] to color value [0,1]
        double blue = 0; // map cos value [-1,1] to color value [0,1]

        // Create a vector to test glm
        glm::vec3 color(red, 0, blue);
        glClearColor(color.x, color.y, color.z, 1.0);
    }

}

int main(int argc, char** argv)
{
  GLFWwindow* window;

  if ( !glfwInit() )
  {
     return -1;
  }

#ifdef __APPLE__
  // Explicitly ask for a 4.0 context on OS X 
  glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 0);
  glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow( 1280, 720, "Hello World", NULL, NULL );
  if (!window)
  {
     glfwTerminate();
     return -1;
  }

  // Make the window's context current 
  glfwMakeContextCurrent(window);

  // Tell GLFW to call our callback fun when a key is pressed
  glfwSetKeyCallback(window, key_callback);

  // checks if cursor moved 
  glfwSetCursorPosCallback(window, cursor_position_callback);

  // Loop until the user closes the window 
  while (!glfwWindowShouldClose(window))
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the buffers

    // Animate the screen color as a test
    // double time = glfwGetTime();
    // double red = (sin(time) + 1) * 0.5; // map sin value [-1,1] to color value [0,1]
    // double blue = (cos(time) + 1) * 0.5; // map cos value [-1,1] to color value [0,1]

    // // Create a vector to test glm
    // glm::vec3 color(red, 0, blue);
    // glClearColor(color.x, color.y, color.z, 1.0);

    // Swap front and back buffers
    glfwSwapBuffers(window);

    // Poll for and process events
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}

