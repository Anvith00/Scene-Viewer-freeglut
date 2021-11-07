# Scene-Viewer-freeglut
Scene Viewer made using freeglut and C++, can be used on any modern C++ development software(s) (IDEs/ text editors + compilers), all you need is freeglut libraries installed in your OS.
Source code contained in one single file, i.e., main.cpp

Components used in this project:
1. Three Primitives of geometries namely, Cube, Icosahedron and the Pyramid. 
2. Reshape function to maintain the shape of the geometry drawn on any window width and height.
3. Lighting to imitate ambient, diffuse and specular lighting.
4. Stars: Generated using point primitives kept inside a for loop with the location for the points kept random using srand() and rand().
5. Mouse and keyboard callbacks to be able to perform actions on each mouse or keyboard event, to traverse around the three-dimensional world created in the code using two transform functions : Translation and Rotation.


**NOTICE: xxf86vm is required. If you are running Linux, you can easily install libXxf86vm/libxxf86vm/xxf86vm (depending on the distro you have, package names vary oftentimes in different package families of distros) in the terminal with your package manager.**

Example, for installing in Fedora ,type in:
`sudo dnf install libXxf86vm*`

Do not forget to use these three linkers: `glut`, `GL` and `GLU`.

If you're running this C++ code on a terminal, all you'll need to do is `g++ <filename_you_saved_code_as>.cpp -lglut -lGL -lGLU`
