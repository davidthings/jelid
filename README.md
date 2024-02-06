# JELID

Tiny utility to aid in the identification of JELOS handhelds

This will usually be either shared in binary form or cross compiled by Jelos.

Or if you have a dev environment on the device, you can use `CMake` to build it

```
mkdir build
cd build
cmake ..
./jelid
```

Or can just `gcc` it

```
gcc jelid.c -o jelid
```

