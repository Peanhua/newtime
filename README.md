This program converts 24 hour time into new time format, which is 6 hour time.

The AM/PM time system has a problem, without the postfix (AM/PM) one never knows if "10" is AM or PM. This program fixes 50% of that problem by dividing time into EAM (Early AM), LAM (Late AM), EPM (Early PM), and LPM (Late PM) times.


## License
Copyright (C) 2022  Steve Joni Yrjänä <joniyrjana@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Complete license can be found in the LICENSE file.


## Build and install using a release
Autotools build system is used, so the procedure to build from a release is:
```
$ ./configure && make
```
And then installing:
```
# make install
```
### Uninstall
```
# make uninstall
```


## Example usage
```
$ newtime 10
4 LAM
$ 
```
