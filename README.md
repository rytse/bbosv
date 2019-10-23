# Black Box OSV Code
Code for ENEE100 Black Box Acquisition Group's OSV

## Build Setup

Because of the slightly more complex code structure and included libraries, the Arduino sketch is built and uploaded
using the [`ino`](http://inotool.org) CLI tool rather than the Arduino IDE. `ino` and its dependencies may be
installed natively on Linux and MacOS, and on Windows through the Windows Subsystem for Linux.

`ino` depends on the `avr` toolchain (`avr-gcc`, `avr-g++`, `avr-ar`, `avr-objcopy`), the Arduino library and
metadata files (`boards.txt`) provided by the `arduino` package on `apt` and its equivalent on `brew`, and the
serial comm library `picocom`.

`ino` may be installed using `pip` on Python 2.7. The `enviornment.yml` file provided may be used to set up a conda
environment containing the `ino` tool. On a Linux system with conda, installed, the setup may look something like
this:

```
$ sudo apt install arduino picocom
$ conda create env -f environment.yml
$ conda activate ino
```
