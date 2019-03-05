#!C:\A_VisIt\NewTrunk\windowsbuild\MSVC2017\python\2.7.14\python.exe
# EASY-INSTALL-ENTRY-SCRIPT: 'babel==2.6.0','console_scripts','pybabel'
__requires__ = 'babel==2.6.0'
import re
import sys
from pkg_resources import load_entry_point

if __name__ == '__main__':
    sys.argv[0] = re.sub(r'(-script\.pyw?|\.exe)?$', '', sys.argv[0])
    sys.exit(
        load_entry_point('babel==2.6.0', 'console_scripts', 'pybabel')()
    )
