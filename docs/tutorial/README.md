# Getting started

### Compilation using Visual Studio 2017

In this tutorial, steps of generating the dll lib of GLFW library are shown. I compile them from the source file with Visual Studio 2017.

Run the x64 Native Tools command prompt for VS 2017

```
c:\>git clone --depth=10 https://github.com/glfw/glfw.git glfw
c:\>cd glfw
c:\glfw>mkdir glfw-build
c:\glfw>cd glfw-build
c:\glfw\glfw-build>cmake -G"NMake Makefiles" -DBUILD_SHARED_LIBS=ON -DGLFW_BUILD_TESTS=ON -DGLFW_BUILD_EXAMPLES=ON -DGLFW_BUILD_DOCS=ON ..
c:\glfw\glfw-build>nmake
c:\glfw\glfw-build>cd c:\
```

### MinGW (Minimalist GNU for Windows)
```
c:\>git clone --depth=10 https://github.com/glfw/glfw.git glfw
c:\>cd glfw
c:\glfw>mkdir glfw-build
c:\glfw>cd glfw-build
c:\glfw\glfw-build>cmake -G"MinGW Makefiles" -DBUILD_SHARED_LIBS=ON -DGLFW_BUILD_TESTS=ON -DGLFW_BUILD_EXAMPLES=ON -DGLFW_BUILD_DOCS=ON ..
c:\glfw\glfw-build>mingw32-make
c:\glfw\glfw-build>cd c:\
```

### You can set these environment variables before starting the build
```
c:\>set HB_WITH_GLFW=c:\glfw\include
c:\>set PATH=c:\glfw\glfw-build\src
```

### Compilation hb-glfw
```
c:\>git clone --depth=10 https://github.com/rjopek/hb-glfw.git hbglfw
c:\>cd hbglfw
c:\hbglfw>hbmk2 hbglfw.hbp
c:\hbglfw>cd tests
c:\hbglfw\tests>hbmk2 sharing.prg -run
```

![Windows](http://harbour.pl/img/sharing.png "Windows 10 desktop")

### Windows pre-compiled binaries
These packages contain complete GLFW header file, documentation and release mode DLL and static library binaries for Visual C++ 2010 (32-bit only), Visual C++ 2012, Visual C++ 2013, Visual C++ 2015, MinGW (32-bit only) and MinGW-w64.

- [32-bit Windows binaries](https://github.com/glfw/glfw/releases/download/3.2.1/glfw-3.2.1.bin.WIN32.zip)

- [64-bit Windows binaries](https://github.com/glfw/glfw/releases/download/3.2.1/glfw-3.2.1.bin.WIN64.zip)

---
[Request create tutorial](https://github.com/rjopek/harbour-gl/issues/new)
