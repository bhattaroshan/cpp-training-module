# Day 12: Drawing a Green Line from Red Box to Blue Box

## Learning Objectives

### Advanced Image Processing:
- Learn how to detect and fill a path with a specific color (green) starting from the red box and continuing through black pixels.
- Apply algorithmic thinking to trace a path in a maze by following black pixels.
- Understand how to fill an area on an image with color based on pixel detection.

### Testing and Debugging:
- Ensure the green line is correctly drawn starting from the red box and continues to the next black pixels.
- Debug any issues with detecting and filling the path between the red and blue boxes.
- Verify that the green line does not overlap white walls and fills the path correctly.

---

## Tasks

### 1. **Draw a Green Line from Red Box to Blue Box**
- Find the red box in the maze image (which has a specific color value).
- Start right after the red box and fill color with green along the path where black pixels are found.
- Continue filling green along the black pixels until you reach the blue box (or the path is blocked by white walls).
- Ensure that the green line is visible and clean, clearly contrasting against the black background of the maze.

### 2. **Handle Maze with Black Background and White Walls**
- The maze has a black background and white walls. The goal is to follow black pixels (the path) from the red box to the blue box and fill them with green.
- Make sure the green line avoids white walls, only filling the black areas.
