set terminal pdf size 800,800
set output 'mandelbrot.pdf'
set view map
unset key
set size ratio -1
set palette defined (0 "black", 1 "blue", 2 "cyan", 3 "green", 4 "yellow", 5 "red", 6 "white")
plot 'mandelbrot.dat' using 1:2:3 with points palette
