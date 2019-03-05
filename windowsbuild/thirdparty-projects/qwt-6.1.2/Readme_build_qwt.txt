To build qwt-6.2.1 for VisIt's use:

1) Unzip/untar the package.
2) Open qwtconfig.pri (located in the qwt's root directory)
   Modify QWT_INSTALL_PREFIX for win32 to the location needed. Save.
3) Open qwtbuild.pri (also located in qwt's root directory)
   Modify win32 CONFIG to be only ' += release', delete or comment out the line 'CONFIG += build_all'.  Save.
4) Open a Visual studio command prompt.
5) CD to qwt's root directory
6) Run 'qmake qwt.pro' 
   (use qmake version corresponding to the Visual studio you are using).
7) Nmake
8) Nmake install


