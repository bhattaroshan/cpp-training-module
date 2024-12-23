# Day 9: Modularization and Advanced Features in Image Processing

## Learning Objectives

### Refactoring and Modularizing Code:
- Separate image processing tasks (filters) and shape-drawing tasks into distinct classes for better maintainability and clarity.
- Understand the principles of modular design to create reusable and scalable components.

### Implementing Advanced Shape Drawing:
- Extend functionality to support polygon drawing with arbitrary coordinates.
- Learn how to handle complex geometric shapes and fill operations.

### Enhancing Filters:
- Refactor filter-related tasks like grayscale conversion and edge detection into a dedicated class.
- Implement additional filter options for future extensions.

---

## Task

### 1. **Refactor the Code**
- Separate the code into two classes:
  - `ImageFilters` for all filter-related operations, including grayscale conversion and Sobel edge detection.
  - `ShapeDrawer` for shape-drawing operations, such as rectangles and polygons.

### 2. **Implement `drawPoly`**
- Extend the `ShapeDrawer` class to include a `drawPoly` method for drawing polygons with arbitrary vertices.
- Support stroke and fill colors for polygons.

### 3. **Integrate and Test**
- Create a pipeline to load an image, apply filters, draw shapes, and save the output.
- Test each feature individually and then combine them for a comprehensive test.

---

## Example Classes and Methods

### Refactored Code Structure
```cpp
class ImageFilters {
public:
    static void convertToGrayscale(std::vector<std::vector<RGB>>& imageData, int width, int height);
    static void sobelEdgeDetection(std::vector<std::vector<RGB>>& imageData, int width, int height);
};

class ShapeDrawer {
public:
    static void drawRect(std::vector<std::vector<RGB>>& input, int x, int y, int width, int height, RGB stroke, RGB fill);
    static void drawPoly(std::vector<std::vector<RGB>>& input, int width, int height, const std::vector<coordinate>& coordinates, RGB stroke, RGB fill);
};
```

### Usage Example

```cpp
#include "ImageFilters.h"
#include "ShapeDrawer.h"
#include "stb_image.h"
#include "stb_image_write.h"

int main() {
    int width, height, channels;
    unsigned char* imageData = stbi_load("./images/input.jpg", &width, &height, &channels, 3);
    if (!imageData) {
        std::cerr << "Failed to load image!" << std::endl;
        return -1;
    }

    auto image = convertTo2D(imageData, width, height);

    // Apply grayscale filter
    ImageFilters::convertToGrayscale(image, width, height);

    // Apply Sobel edge detection
    ImageFilters::sobelEdgeDetection(image, width, height);

    // Draw a rectangle
    ShapeDrawer::drawRect(image, 50, 50, 200, 100, {0, 0, 0}, {255, 0, 0});

    // Draw a polygon
    std::vector<coordinate> polyVertices = {{100, 100}, {150, 200}, {200, 150}};
    ShapeDrawer::drawPoly(image, width, height, polyVertices, {0, 0, 255}, {0, 255, 0});

    // Save the output image
    saveToPNG(image, width, height, "output.png");

    stbi_image_free(imageData);
    return 0;
}
```

---

## Key Features

### Filters
- **Grayscale Conversion**: Converts the image to grayscale using luminance calculation.
- **Sobel Edge Detection**: Detects edges using the Sobel operator for gradient magnitude.

### Shapes
- **Rectangle**: Draws a rectangle with customizable stroke and fill colors.
- **Polygon**: Draws arbitrary polygons defined by a list of vertices, with stroke and fill colors.

---

## Suggested Exercises

1. Load an image and apply the Sobel edge detection filter to visualize edges.
2. Comment out the Sobel filter and test the `drawRect` method on a blank image.
3. Extend the code to use the `drawPoly` method and create complex shapes.
4. Refactor the provided code into the `ImageFilters` and `ShapeDrawer` classes.

---

## Advanced Challenges

1. **Dynamic Stroke Width**: Modify the shape-drawing functions to support variable stroke widths.
2. **Additional Filters**: Implement new filters, such as Gaussian blur or color inversion, in the `ImageFilters` class.
3. **Interactive Input**: Allow users to input shape parameters (e.g., vertices for a polygon) and filters interactively via a CLI or GUI.

---

By completing these tasks, participants will gain hands-on experience with modular design, advanced image processing techniques, and geometric operations.

