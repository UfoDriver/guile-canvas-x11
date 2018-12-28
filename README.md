# Simple Xlib canvas to use with Guile

Compile and run with

```make && ./guile-canvas```

Connecting to guile:

```telnet localhost 37146```

Or, better, accessing from emacs with geiser:

```M-x and connect-to-guile```

## Functions supported

`(draw-point x y)` - draws point at x, y

[X11 tutorial][1].

[1]: https://tronche.com/gui/x/xlib/
