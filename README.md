in progress ...
## Fractol
Create a basic computer graphics project using the MiniLibX library.

#### How to get started
Download the library either from the project page in your intra or from the
source files at https://github.com/42Paris/minilibx-linux

Follow the instructions to install the library. You may have to install any
dependencies.

Once installed, you can put the minilibx library at the root of your project
directory.

Navigate to the man directory and start reading the man pages. Start with man1.
Once inside the man1 directory you can access the the man for mlx.1 by typing

`man ./mlx.1`

This will give you the instructions on how to establish a connection between
the software (your code) and the X-server, which manages the display and the
keyboard and mouse.  It will tell you the necessary flags for compilation.

I recommend setting up your Makefile so that you're ready to start testing the
functions.  If you're curious about how the functions work, you can open up
the corresponding files inside the minilibx directory.

#### Requirement checklist
```
RENDERING
▢ Offer Julia and Mandelbrot sets.
▢ Mouse wheel allows zooming in and out almost infinitely (within the
    computer's limits
▢ Create different Julia sets
▢ A parameter is passed on the comand line to define what time of fractal
    will be displayed
    ▢ Handle more parameters to use them as rendering options
    ▢ If no parameter is provided, or if the parameter is invalid, the 
        program displays a list of available parameters and exits.
    ▢ Use a few colors to reveal the depth of each fractal.

GRAPHICS MANAGEMENT
▢ Display image in the window
▢ Window management must remain smooth
▢ Pressing `Esc` must close the window and exit the program
▢ Clicking on the `x` on the window's fram must close the window
    and exit the program.
▢ Use images of the minilibx library
```

