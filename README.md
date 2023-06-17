# simple-wm 

simple-wm (swm) is a X window manager heavily inspired by dwm.

It's goal is to function similarly to dwm, but with better code
(both in terms of performane and readability).


## Requirements

XLib. Xinerama for multi-monitor support.


## Installation

```sh
git clone https://github.com/miguelrcborges/simple-wm
make build
sudo make install
```

This should leave swm's binary in /usr/bin.


## Running swm

If you are using xorg-xinit, add the following line to your .xinitrc.

```sh
exec swm
```

If you use a display manager, there should be a desktop entry to swm.


## To-Dos that I'm aware (sorted by priority)

- [ ] Increase the amount of Atoms that the WM handles. Most urgent ones are the detection if a spawned window is fullscreen or a pop-up.
- [ ] A bar.
- Bug hunting & fixing

