Directions for building Mesa3D, summary of the instructions found on
the MesaLlvmpipe - Qt Wiki in this directory.

Get the Prerequisites:

1) Download Python for windows and install (I used python 2.7.17)
2) Update setup tools
        pip install -U setuptools
3) Update/ install wheel
        pip install -U wheel
4) Install scons
        pip install -U scons
5) Install mako
        pip install -U mako
6) Download and extract Win flex-bison from
        https://sourceforge.net/projects/winflexbison/
        Add the location to your PATH environment variable
7) Get the LLVM source tarball 
        http://llvm.org/releases/5.0.0/llvm-5.0.0.src.tar.xz
8) Get the Mesa3D source tarball
        ftp://ftp.freedesktop.org/pub/mesa/older-versions/17.x/mesa-17.3.0.tar.gz

My GIT install was missing something that one of the builds wanted, but wasn't really needed, so I temporarily removed it from my PATH environment variable to prevent a problem with this build process.


Build LLVM
1) Extract source
2) Open VS 2017 x64 command prompt, and cd to the llvm source dir
3) Configure it  (substitute paths for appropriate)
        \path\to\cmake.exe -G "Visual Studio 15 2017 Win64" -t "host=x64" -DLLVM_USE_CRT_RELEASE=MT -DCMAKE_INSTALL_PREFIX=C:\path\to\llvm\install .
4) build it
        msbuild /p:Configuration=Release INSTALL.vcxproj

Build mesa
1) Extract source
2) from the VS command prompt opened earlier, cd to the mesa source dir
3) build it:
        set LLVM=c:\path\to\llvm\install
        path\to\python\Scripts\scons build=release platform=windows machine=x86_64 libgl-gdi

The result is an opengl32.dll in build\windows-x86_64\gallium\targets\libgl-gdi
Copy it to a 'mesa' dir in the same location you store other visit TP libs.




