Windows Build Notes for Pillow-7.2.1

First, setup.py needs to be modified to point to
locations of zlib, jpeg, and tiff.

Second, I experienced problems using setup.py (order of imports)

The setup.py file in this directory fixes the order of imports,
and sets up zlib, jpeg and tiff locations
(which may need to be modified for your system.

Copy this setup.py to the root of Pillow-7.2.1.


