#include "hbglfw.ch"

FUNCTION Main()

   LOCAL window

   IF ! glfwInit()
      OutStd( e"\nError" )
      RETURN -1
   ENDIF

   glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 )
   glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 )
   glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE )

   window := glfwCreateWindow( 800, 600, "Learn OpenGL, GLFW and Harbour", NIL, NIL )

   IF window == NIL
      OutStd( e"\nFailed to create GLFW window" )
      glfwTerminate()
      RETURN -1
   ENDIF

   glfwMakeContextCurrent( window )
   glfwSwapInterval( 1 )
   glViewport( 0, 0, 800, 600 )

   DO WHILE ! glfwWindowShouldClose( window )

      IF ( glfwGetKey( window, GLFW_KEY_ESCAPE ) == GLFW_PRESS )
         glfwSetWindowShouldClose( window, GLFW_TRUE )
      ENDIF

      glfwSwapBuffers( window )
      glfwPollEvents()

   ENDDO

   glfwTerminate()

   RETURN 0
