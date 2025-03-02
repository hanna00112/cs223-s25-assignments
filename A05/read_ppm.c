/*----------------------------------------------
 * Author: Hanna Abrahem  
 * Date: Feb 16th, 2025
 * Description: read PPM files stored in binary format. 
 ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_ppm.h"

// Choose *one* to implement (do not remove the other one!)

struct ppm_pixel* read_ppm(const char* filename, int* w, int* h) {
  return NULL;
}

/*return an array or arrays */
struct ppm_pixel** read_ppm_2d(const char* filename, int* w, int* h) {
	FILE* ppmData = fopen(filename, "rb"); //opening file in binary mode

	if (ppmData == NULL) {
		perror("Error opening file");
		return NULL;
	}
 // Read the magic number
    char magic[3];
    if (!fgets(magic, sizeof(magic), ppmData) || strncmp(magic, "P6", 2) != 0) {
        fprintf(stderr, "Error: Not a P6 PPM file\n");
        fclose(ppmData);
        return NULL;
    }
    // Skip comment lines
    char c = fgetc(ppmData);
    while (c == '#') {
        while (fgetc(ppmData) != '\n'); // Skip entire comment line
        c = fgetc(ppmData); // Read next character
    }
    ungetc(c, ppmData); // Put back last read character

    // Read width, height, and max color value
    int max_val;
    char line[256];
    while (fgets(line, sizeof(line), ppmData)) {
        if (line[0] == '#') continue; // Skip comments
        if (sscanf(line, "%d %d", w, h) == 2) break;
    }
    while (fgets(line, sizeof(line), ppmData)) {
        if (line[0] == '#') continue; // Skip comments
        if (sscanf(line, "%d", &max_val) == 1) break;
    }
    
    if (*w <= 0 || *h <= 0) {
        fprintf(stderr, "Error: Invalid dimensions (%d x %d)\n", *w, *h);
        fclose(ppmData);
        return NULL;
    }

    if (max_val != 255) {
        fprintf(stderr, "Error: Unsupported max color value %d\n", max_val);
        fclose(ppmData);
        return NULL;
    }
    fgetc(ppmData); // Skip any remaining whitespace
    printf("Debug: File position before reading pixels: %ld\n", ftell(ppmData));

     // Allocate memory for 2D array
    struct ppm_pixel** binary = malloc((*h) * sizeof(struct ppm_pixel*));
    if (!binary) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        fclose(ppmData);
        return NULL;
    }
    binary[0] = malloc((*h) * (*w) * sizeof(struct ppm_pixel));
    if (!binary[0]) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        fclose(ppmData);
        free(binary);
        return NULL;
    }
     for (int i = 1; i < *h; i++) {
        binary[i] = binary[0] + (i * (*w));
    }
   // Debugging: Print expected pixel data size
    printf("Debug: Width=%d, Height=%d, MaxVal=%d\n", *w, *h, max_val);
    printf("Reading %d pixels (%d bytes expected)\n", (*w) * (*h), (*w) * (*h) * 3);



    // Read all pixel data at once
     // Debugging: Print expected pixel data size
    printf("Debug: Width=%d, Height=%d, MaxVal=%d\n", *w, *h, max_val);
    printf("Reading %d pixels (%d bytes expected)\n", (*w) * (*h), (*w) * (*h) * 3);

    // Read all pixel data at once
    size_t bytes_read = fread(binary[0], sizeof(struct ppm_pixel), (*w) * (*h), ppmData);
    if (bytes_read != (*w) * (*h) * 3) {
        fprintf(stderr, "Error: Unable to read pixel data (read %zu bytes, expected %d)\n", bytes_read, (*w) * (*h));
        fclose(ppmData);
        free(binary[0]);
        free(binary);
        return NULL;
    }



fclose(ppmData);
return binary;

return NULL;

}
