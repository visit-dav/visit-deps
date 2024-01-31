#!C:\A_Visit\ForRegression\visit-deps\windowsbuild\MSVC2022\python\3.9.18\python.exe
# EASY-INSTALL-ENTRY-SCRIPT: 'sphinx==7.0.1','console_scripts','sphinx-build'
__requires__ = 'sphinx==7.0.1'
import re
import sys
from pkg_resources import load_entry_point

if __name__ == '__main__':
    sys.argv[0] = re.sub(r'(-script\.pyw?|\.exe)?$', '', sys.argv[0])
    sys.exit(
        load_entry_point('sphinx==7.0.1', 'console_scripts', 'sphinx-build')()
    )
