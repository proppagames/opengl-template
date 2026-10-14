Project template for OpenGL which renders a texture and plays a sound.

Extra steps I do after cloning (in vscode environment)
1. CMake Quickstart and select compiler to create preset
2. Edit CMakePresets.json "binaryDir" to be "${sourceDir}/build" (this is my preference over the default)
3. Make sure to run project from project root directory (not the build directory) because paths (assets, shaders, etc.)
are relative to root

Note:
May not work with msvs C++ compiler due to minor syntactical difference such as using "not" instead of "!". 
This project is intended for g++ compilers but can work with others after a little modification.
