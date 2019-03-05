@echo off

call "C:\Program Files\Microsoft Visual Studio .NET 2003\Vc7\bin\vcvars32.bat"
devenv /build Release .\VIkit\VIkit.sln

