# HB-GLFW

hb-glfw bindings to GLFW an open source, multi-platform library for creating windows with OpenGL contexts and managing input and events.

### Beginners' tutorial
Introduction to project - [first steps](docs/tutorial/README.md)

### Example code
```Harbour
FUNCTION Main()

   LOCAL window

   IF ! glfwInit()
      RETURN - 1
   ENDIF

   window := glfwCreateWindow( 640, 480, "Hello World", NIL, NIL )

   IF window == NIL
      glfwTerminate()
      RETURN - 1
   ENDIF

   glfwMakeContextCurrent( window )

   DO WHILE ! glfwWindowShouldClose( window )

      glClear( GL_COLOR_BUFFER_BIT )

      glfwSwapBuffers( window )

      glfwPollEvents()

   ENDDO

   glfwTerminate()

   RETURN 0
```
### Thanks
I am grateful to my friends who have somehow contributed to the creation of this project. You can find them in contributions. Of course, many things can be improved in this project. If you have any comments, please give them to me.

### Good to know
“there is direction but there is no destination”  ( Carl R. Rogers )

## License
[![License](http://img.shields.io/:license-mit-blue.svg?style=flat-square)](LICENSE)
