# Day 10: Advanced Image Processing and Integration

## Learning Objectives

### Advanced Image Processing:
- Convert grayscale images to color using hit-and-trial techniques.
- Merge two images together using normalization techniques.
- Implement median filtering for noise reduction.
- Apply thresholding to images for binary segmentation.

### Testing and Debugging:
- Validate the accuracy and efficiency of new methods.
- Compare results of different approaches to determine the best techniques.

---

## Tasks

### 1. **Convert Grayscale Image to Color**
- Use trial-and-error methods to map grayscale intensity values to color values.
- Experiment with different color mapping algorithms to achieve realistic results.

### 2. **Merge Two Images**
- Implement a method to merge two images together by normalizing their pixel values.
- Ensure that the output image combines features from both input images effectively.

### 3. **Implement a Median Filter**
- Add a function to apply a median filter to an image to reduce noise.
- Test the filter on noisy images and compare the results before and after filtering.

### 4. **Thresholding**
- Apply thresholding to an image to segment it into binary regions based on intensity values.
- Experiment with different threshold values to observe their impact on segmentation.

---

## Example Workflow

### Using Day 9 Codebase
```cpp
#include "Filter.h"

int main() {
    int width, height, channels;
    unsigned char* imageData = stbi_load("./images/sample.jpg", &width, &height, &channels, 3);
    if (imageData == nullptr) {
        std::cout << "Failed to load image!" << std::endl;
        return -1;
    }

    // Create Filter object and process the image
    Filter filter;
    auto image = filter.convertTo2D(imageData, width, height);

    // Convert grayscale to color
    filter.convertGrayscaleToColor(image, width, height);

    // Load a second image for merging
    unsigned char* secondImageData = stbi_load("./images/second_sample.jpg", &width, &height, &channels, 3);
    if (secondImageData == nullptr) {
        std::cout << "Failed to load second image!" << std::endl;
        return -1;
    }
    auto secondImage = filter.convertTo2D(secondImageData, width, height);

    // Merge two images
    filter.mergeImages(image, secondImage, width, height);

    // Apply median filter
    filter.applyMedianFilter(image, width, height);

    // Apply thresholding
    filter.threshold(image, width, height, 128);

    // Save the processed image
    filter.saveToPNG(image, width, height, "processed_image_day10.png");

    stbi_image_free(imageData);
    stbi_image_free(secondImageData);
    return 0;
}
```

---

### Testing Grayscale to Color Conversion
- Experiment with mapping grayscale values to different color schemes.
- Compare the visual appearance of the output images.

### Testing Image Merging
- Test the merging function with different pairs of images.
- Ensure that features from both images are clearly visible in the output.

### Testing Median Filter
- Load a noisy image and apply the median filter.
- Compare the filtered image with the original to validate noise reduction.

### Testing Thresholding
- Apply thresholding with different threshold values (e.g., 50, 128, 200).
- Observe the impact on image segmentation and choose the optimal value.

---

By the end of this session, participants will have:
- Enhanced their understanding of advanced image processing techniques.
- Implemented and tested new functionalities using the Day 9 codebase.
- Developed insights into the challenges and solutions for image manipulation tasks.

