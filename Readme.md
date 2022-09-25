# GLFW-GLAD-Example

Simple program written in C using the extension loader libary glad and glfw as graphics libary

## Setup
  * Create folder external
  * Clone glfw into external/glfw - https://github.com/glfw/glfw
  * Add generated glad files into external/glad - https://gen.glad.sh/
  * Add CMakeLists.txt in external/glad: <br/>
 ```
  add_library(
        glad
        src/gl.c
        include/glad/gl.h
        include/KHR/khrplatform.h
)

target_include_directories(glad PUBLIC include)
```
  * Build project