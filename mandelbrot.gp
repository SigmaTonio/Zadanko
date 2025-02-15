set terminal pdfcairo size 8cm,8cm font "Arial,8"
set output 'mandelbrot.pdf'
set view map
unset key
set size ratio -1
set samples 100, 100
set palette defined (0 "black", 1 "blue", 3 "green", 5 "red", 6 "white")
plot 'mandelbrot.dat' using 1:2:3 with dots palette
