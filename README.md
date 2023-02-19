# Scene-Viewer-freeglut
Concept 3D Scene Viewer made using freeglut and C++, all you need is the freeglut development library and a few packages installed in your OS ([check here](https://github.com/Anvith00/Scene-Viewer-freeglut/edit/main/README.md#setting-up)). The source code is one single file, i.e., main.cpp.

![image](https://user-images.githubusercontent.com/24383877/219960025-576abeb3-d592-4746-9f9c-167bd2ccc7b0.png)


Components used in this project:
1. Three Primitives of geometries namely, Cube, Icosahedron and the Pyramid. 
2. Reshape function to maintain the shape of the geometry drawn on any window width and height.
3. Lighting to imitate ambient, diffuse and specular lighting.
4. Stars: Generated using point primitives kept inside a for loop with the location for the points kept random using srand() and rand().
5. Mouse and keyboard callbacks to be able to perform actions on each mouse or keyboard event, to traverse around the three-dimensional world created in the code using two transform functions : Translation and Rotation.


## Setting up
* **Linux:** `xxf86vm` and `g++` are required for Linux users. You can easily install libXxf86vm/libxxf86vm/xxf86vm (depending on the distro you have, package names vary oftentimes in different package families of distros) in the terminal with your package manager. Example:
``` bash
# Fedora Workstation
sudo dnf install g++ libXxf86vm
```
``` bash
# Ubuntu 22.04 and Pop!_OS
sudo apt install g++ libxxf86vm
```
``` bash
# Arch Linux
sudo pacman -S gcc libxxf86vm
```

* **Windows:** Windows users will be required to install g++ via the [MinGW C/C++ tool](https://sourceforge.net/projects/mingw/) (**not MYSYS2!**). You can also use MinGW-w64 to run this code.
* **MacOS:** Code hasn't been tested on MacOS yet.

## Running the code (Terminal)
To get this running, the command you'll need to have the code compiled and run from the source root is:
```bash
g++ main.cpp -lglut -lGL -lGLU
./a.out
```
 
 **OR**

```bash
g++ main.cpp -lglut -lGL -lGLU && ./a.out
```

(Do not forget to use these three linkers: `glut`, `GL` and `GLU`.)
