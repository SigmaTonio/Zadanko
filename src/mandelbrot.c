#include <stdio.h>
#include <complex.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

int mandelbrot(double complex c) {
    double complex z = 0;
    int iter = 0;
    while (cabs(z) <= 2.0 && iter < MAX_ITER) {
        z = z * z + c;
        iter++;
    }
    return iter;
}

int main() {
    FILE *fp = fopen("mandelbrot.dat", "w");
    if (!fp) {
        printf("Błąd otwierania pliku!\n");
        return 1;
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            double imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
            double complex c = real + imag * I;
            int value = mandelbrot(c);
            fprintf(fp, "%d %d %d\n", x, y, value);
        }
    }
    
    fclose(fp);
    return 0;
}
