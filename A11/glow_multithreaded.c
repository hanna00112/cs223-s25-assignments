/*----------------------------------------------
 * Author: Hanna Abrahem 
 * Date: April 11th, 2025
 * Description: creating a program to apply a glow effect on the image "earth-small.ppm" with threads  
 ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>
#include <pthread.h>
#include "read_ppm.h"
#include "write_ppm.h"

typedef struct {
	int thread_id;
	int num_threads;
	int width;
	int height;
	int threshold;
	int blur_size;
	int start_row;
	int end_row;
	struct ppm_pixels** input_pixels;
	struct ppm_pixels** bright_pixels;
	struct ppm_pixels** blurred_pixels;
} threadargs;

void* brighting_blurring_image(void arg*) {
	threadargs* args = (threadargs*)arg;

	for (int h = args->start_row; h < args->end_row; h++) {
	     for (int w = 0; w < args->width; w++) {
		     //struct ppm_pixel px = pixels[h][w];
		     int brightness = (args->input_pixels[h][w].red + args->input_pixels[h][w].blue + args->input_pixels[h][w].green) / 3;

		     if (brightness > args->threshold) {
			     args->bright_pixels[h][w] = args->input_pixels[h][w]; //keeping the bright pixels
			      } else {
			     // setting non-bright pixels to black
			     args->bright_pixels[h][w].red = 0;
			     args->bright_pixels[h][w].blue = 0;
			     args->bright_pixels[h][w].green = 0;
		     }
		     int count = 0;
		     int red_sum = 0;
	             int green_sum = 0;
		     int blue_sum = 0;
		     int radius = args->blur_size / 2;

		     for (int j = -radius; j < radius; j++) {
			     for (int k = -radius; k < radius; k++) {
				     int new_height = h + j;
			             int new_width = w + k;

				     //checking the bounds
				     if (new_height >= 0 && new_height < height && new_width >= 0 && new_width < width) {
					     red_sum += args->bright_pixels[new_height][new_width].red;
					     green_sum += args->bright_pixels[new_height][new_width].green;
					     blue_sum += args->bright_pixels[new_height][new_width].blue;
					     count++;
				     }
			     }
		     }
		     args->blurred_pixels[h][w].red = red_sum/count;
		     args->blurred_pixels[h][w].green = green_sum/count;
		     args->blurred_pixels[h][w].blue = blue_sum/count;

		      if (args->bright_pixels[h][w].red != 0 ||args-> bright_pixels[h][w].green != 0 || args->bright_pixels[h][w].blue != 0) { //all pixels that are not currently black
			     args->input_pixels[h][w].red = args->input_pixels[h][w].red + args->blurred_pixels[h][w].red;
			     args->input_pixels[h][w].green = args->input_pixels[h][w].green + args->blurred_pixels[h][w].green;
		   	     args->input_pixels[h][w].blue = args->input_pixels[h][w].blue + args->blurred_pixels[h][w].blue;
	     }
	     }
	}
}

int main(int argc, char* argv[]) 
{
  int N = 4;
  int threshold = 200;
  int blursize = 24;
  const char* filename = "earth-small.ppm";

  int opt;
  while ((opt = getopt(argc, argv, ":N:t:b:f:")) != -1) {
    switch (opt) {
      case 'N': N = atoi(optarg); break;
      case 't': threshold = atof(optarg); break;
      case 'b': blursize = atof(optarg); break;
      case 'f': filename = optarg; break;
      case '?': printf("usage: %s -N <NumThreads> -t <brightness threshold> -b <box blur size> -f <ppmfile>\n", argv[0]); break;
    }
  }
  // todo: your code here
  // compute image
  /**reading ppm file **/
  int width, height;
  struct ppm_pixel** pixels = read_ppm_2d(filename,&width,&height);

   //if could not read pixels
     if (!pixels) {
	  fprintf(stderr, "Error unable to read pixels from file %s \n", argv[1]);
	return 1;
  }

     //allocating space for the new image
     struct ppm_pixel** bright_pixels = malloc(height * sizeof(struct ppm_pixel*));
     for (int i = 0; i < height; i++){
	     bright_pixels[i] = malloc(width * sizeof(struct ppm_pixel*));
     }
     struct ppm_pixel** blurred_pixels = malloc(height * sizeof(struct ppm_pixel*));
     for (int i = 0; i < height; i++){
             blurred_pixels[i] = malloc(width * sizeof(struct ppm_pixel*));
     }
     pthread_t* threads = malloc(sizeof(pthread_t) * N);
     threadargs* args = malloc(sizeof(thread_data ) * N) ;
     int rows_per_thread = height / N;
     for (int i = 0; i < N; i++) {
	     args[i].thread_id = i;
	     //args[i].num_threads = N;
	     args[i].start_row = i * rows_per_thread;
	     args[i].end_row = (i + 1) * rows_per_thread;
	     args[i].width = width;
	     args[i].height = height;
	     args[i].threshold = threshold;
	     args[i].blur_size = blursize;
	     args[i].input_pixels = ppm_pixels;
	     args[i].bright_pixels = bright_pixels;
	     args[i].blurred_pixels = blurred_pixels;

	     pthread_create(&threads[i], NULL, brighting_blurring_image, &args[i]);

     }
     for (int i = 0; i < N; i++) {
    pthread_join(threads[i], NULL);
}
   write_ppm_2d("glow.ppm", pixels, width, height);


}
