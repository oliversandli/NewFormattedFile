# NewFormattedFile

nff (NewFormattedFile) creates a new file with the format specified by its matching config file. Thus a file ending in `.py` will be created with the contents of `nff`'s `py.conf`. The `.conf` files are simply plain text. Five `.conf` files are included as examples.

## Installation

Clone using git:
```bash
git clone https://github.com/oliversandli/NewFormattedFile.git
```
Run install script:
```bash
cd NewFormattedFile/release/
./install.sh
```
Config files are stored in `~/.config/nff/templates/` or in `$XDG_CONFIG_HOME/nff/templates/` if the target system is using [XDG Base Directory Specification](https://specifications.freedesktop.org/basedir-spec/basedir-spec-latest.html).

See `install.sh` for installation details. It uses `g++` by default; change that command to preferred `C++` compiler before installing.

## Usage

```bash
nff my_new_file.py
```
```bash
cat my_new_file.py

#!/usr/bin/env python3
"""file docstring"""

# imports


def func_one(arg_one, arg_two):
    """function docstring"""
    pass


if __name__ == "__main__":
    func_one(1, 2)
```

## Special Thanks

* [@RobertZenz](https://github.com/RobertZenz) for suggesting `XDG` support.
