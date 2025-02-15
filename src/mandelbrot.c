#include <stdio.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

int mandelbrot(double real, double imag) {
    double zr = 0, zi = 0, zr2, zi2;
    int iter = 0;
    while ((zr2 = zr * zr) + (zi2 = zi * zi) <= 4.0 && iter < MAX_ITER) {
        zi = 2.0 * zr * zi + imag;
        zr = zr2 - zi2 + real;
        iter++;
    }
    return iter;
}

int main() {
    FILE *fp = fopen("mandelbrot.dat", "w");
    if (!fp) return 1;

    for (int y = 0; y < HEIGHT; y++) {
        double imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
        for (int x = 0; x < WIDTH; x++) {
            double real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            fprintf(fp, "%d %d %d\n", x, y, mandelbrot(real, imag));
        }
    }

    fclose(fp);
    return 0;
}
