# Day 9: Modularizing Image Processing and Shape Drawing

## Learning Objectives

### Modularization:
- Separate functionalities into distinct classes for better organization and maintainability.
- Create a `Filter` class for image processing tasks.
- Create a `Shape` class for drawing shapes on images.

### Implementing New Features:
- Extend the `Filter` class with a median filter for noise reduction.
- Enhance the `Shape` class with the ability to draw polygons.

### Testing and Debugging:
- Validate the functionality of each class independently.
- Debug and ensure that new features integrate seamlessly with existing code.

---

## Tasks

### 1. **Refactor Code into Classes**
- Create a `Filter` class to encapsulate all image processing functionalities, including grayscale conversion, Sobel edge detection, and the new median filter.
- Create a `Shape` class to handle shape-drawing functionalities, such as drawing rectangles and polygons.

### 2. **Implement a Median Filter**
- Add a method to the `Filter` class that applies a median filter to an image for noise reduction.
- Ensure the filter handles edge cases effectively.

### 3. **Enhance Shape Drawing**
- Implement a `drawPoly` method in the `Shape` class to allow the drawing of polygons based on a list of coordinates.
- Ensure the polygon can be filled with a specified color and outlined with a stroke color.

### 4. **Test Modularized Code**
- Test the `Filter` class by:
  - Applying grayscale conversion.
  - Performing Sobel edge detection.
  - Testing the median filter on a noisy image.
- Test the `Shape` class by:
  - Drawing rectangles on an image.
  - Drawing polygons with various configurations.

---

## Example Usage

### Modularized Classes
```cpp
#include "Filter.h"
#include "Shape.h"

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
    filter.convertToGrayscale(image, width, height);
    filter.sobelEdgeDetection(image, width, height);
    filter.applyMedianFilter(image, width, height); // New median filter

    // Save the processed image
    filter.saveToPNG(image, width, height, "processed_image.png");

    // Create Shape object and draw shapes
    Shape shape;
    shape.drawRect(image, 50, 50, 200, 100, {255, 0, 0}, {0, 255, 0});
    shape.drawPoly(image, width, height, {{100, 100}, {150, 200}, {200, 150}}, {0, 0, 255}, {255, 255, 0});

    // Save the image with shapes
    filter.saveToPNG(image, width, height, "shapes_image.png");

    stbi_image_free(imageData);
    return 0;
}
```

---

### Testing Median Filter
- Load a noisy image and apply the median filter.
- Compare the output with the original image to validate noise reduction.

### Testing Polygon Drawing
- Use the `drawPoly` method with various sets of coordinates.
- Verify the polygons are rendered correctly with both stroke and fill colors.

---

By the end of this session, participants will have:
- Modularized the codebase into distinct classes.
- Added advanced image processing and shape drawing capabilities.
- Tested and validated the new features effectively.

