#include "hbglfw.ch"

#if defined(__PLATFORM__DARWIN)
#define MODIFIER GLFW_MOD_SUPER
#else
#define MODIFIER GLFW_MOD_CONTROL
#endif

PROCEDURE Main( argc )

   LOCAL window

   IF argc != NIL
      usage()
      RETURN
   ENDIF

   glfwSetErrorCallback( @error_callback() )

   IF !glfwInit()
      ? "Failed to initialize GLFW"
      RETURN
   ENDIF

   window := glfwCreateWindow( 200, 200, "Clipboard Test", NIL, NIL )

   IF window == NIL
      glfwTerminate()
      ? "Failed to open GLFW window"
      RETURN
   ENDIF

   glfwMakeContextCurrent( window )
   gladLoadGL_glfwGetProcAddress()
   glfwSwapInterval( 1 )

   glfwSetKeyCallback( window, @key_callback() )

   glClearColor( 0.5, 0.5, 0.5, 0 )

   DO WHILE !glfwWindowShouldClose( window )
      glClear( GL_COLOR_BUFFER_BIT )

      glfwSwapBuffers( window )
      glfwWaitEvents()

   ENDDO

   glfwTerminate()

   ? "Finishing... ;)"

   RETURN

STATIC PROCEDURE usage()

   ? "Usage: clipboard [-h]"

   RETURN

STATIC PROCEDURE error_callback( nError, cDescription )

   HB_SYMBOL_UNUSED( nError )
   ? "Error: ", cDescription

   RETURN

STATIC PROCEDURE key_callback( window, key, scancode, action, mods )

   LOCAL string

   IF action != GLFW_PRESS
      RETURN
   ENDIF

   SWITCH KEY
   CASE GLFW_KEY_ESCAPE
      ? "ESCAPE"
      glfwSetWindowShouldClose( window, GLFW_TRUE )
      EXIT
   CASE GLFW_KEY_V
      IF mods == MODIFIER
         string := glfwGetClipboardString( NIL )
         IF string != NIL
            ? e"Clipboard contains \"", string, e"\""
         ELSE
            ? "Clipboard does not contain a string"
         ENDIF
         EXIT
      ENDIF
   CASE GLFW_KEY_C
      IF mods == MODIFIER
         string := "Hello GLFW world!"
         glfwSetClipboardString( NIL, string )
         ? "Setting clipboard to ", string
         EXIT
      ENDIF
   OTHERWISE
      ? key, scancode, action, mods
   ENDSWITCH

   RETURN
