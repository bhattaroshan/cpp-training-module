# Day 11: Pattern Creation and Tiling

## Learning Objectives

### Advanced Image Processing:
- Create repetitive patterns by tiling smaller images.
- Apply mathematical operations to control pattern spacing and alignment.

### Testing and Debugging:
- Validate the accuracy and efficiency of tiling and transformation functions.
- Experiment with different alignment styles to understand their effects on pattern creation.
- Compare results of different tiling strategies to determine the best design techniques.

---

## Tasks

### 1. **Repeat a 200x200 Image to Fill a 1100x1100 Canvas**
- Load a small 200x200 image and repeat it in a grid to create a larger 1100x1100 canvas.
- Add an equal gap (e.g., 10 pixels) between each tile in the grid.
- Ensure that the tiles are evenly distributed across the canvas, and the gap between them is consistent.

### 2. **Add Padding Between Tiles**
- Modify the tiling function to add padding (e.g., 10 pixels) between the tiles.
- Ensure that the padding has a configurable color or transparency, allowing for different visual effects.

---

## Example Workflow

### Using Day 11 Codebase

```cpp
#include "Filter.h"

int main() {
    int width, height, channels;
    unsigned char* smallImage = stbi_load("./images/tile.jpg", &width, &height, &channels, 3);
    if (smallImage == nullptr) {
        std::cout << "Failed to load image!" << std::endl;
        return -1;
    }

    // Create a Filter object and process the image
    Filter filter;
    auto tileImage = filter.convertTo2D(smallImage, width, height);

    // Set the target canvas size (1100x1100)
    int canvasWidth = 1100;
    int canvasHeight = 1100;

    // Create a blank canvas (1100x1100)
    auto canvas = filter.createCanvas(canvasWidth, canvasHeight);

    // Define the padding size (10 pixels)
    int padding = 10;

    // Calculate the number of tiles that can fit horizontally and vertically
    int tilesPerRow = (canvasWidth + padding) / (width + padding);
    int tilesPerColumn = (canvasHeight + padding) / (height + padding);

    // Repeat the tile image to fill the canvas
    for (int row = 0; row < tilesPerColumn; ++row) {
        for (int col = 0; col < tilesPerRow; ++col) {
            // Calculate the position for each tile considering padding
            int xPos = col * (width + padding);
            int yPos = row * (height + padding);

            // Place the tile on the canvas at the calculated position
            filter.placeTileOnCanvas(canvas, tileImage, xPos, yPos, width, height);
        }
    }

    // Save the final canvas as an image
    filter.saveToPNG(canvas, canvasWidth, canvasHeight, "tiled_image_with_padding.png");

    stbi_image_free(smallImage);
    return 0;
}
