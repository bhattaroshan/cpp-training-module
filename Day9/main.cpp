

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include<iostream>
#include<vector>
#include "./stb/stb_image.h"
#include "./stb/stb_image_write.h"

struct RGB{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct coordinate{
    int x;
    int y;
};

std::vector<std::vector<RGB>> convertTo2D(const unsigned char* imageData,int width, int height){
    std::vector<std::vector<RGB>> output;
    int length = width*height*3;
    RGB color;

    for(int i=0;i<height;++i){
        std::vector<RGB> row;
        for(int j=0; j<width*3;j+=3){
            color.r = imageData[i*width*3+j+0];
            color.g = imageData[i*width*3+j+1];
            color.b = imageData[i*width*3+j+2];
            row.emplace_back(color);
        }
        output.emplace_back(row);
    }

    return output;
}

void saveToPNG(const std::vector<std::vector<RGB>>& imageData, int width, int height, const char* filename) {
    std::vector<unsigned char> imageFlat;
    imageFlat.reserve(width * height * 3); 

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            const RGB& color = imageData[i][j];
            imageFlat.push_back(color.r);  
            imageFlat.push_back(color.g); 
            imageFlat.push_back(color.b);  
        }
    }

    if (stbi_write_png(filename, width, height, 3, imageFlat.data(), width * 3)) {
        std::cout << "Image saved successfully to " << filename << std::endl;
    } else {
        std::cout << "Failed to save image!" << std::endl;
    }
}

void convertToGrayscale(std::vector<std::vector<RGB>>& imageData,int width, int height){
     for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            RGB& color = imageData[i][j];
            float gray = color.r * 0.2989f+color.r * 0.5870f+color.r * 0.1140f;
            color.r = gray;
            color.g = gray;
            color.b = gray;
        }
    }
}

void sobelEdgeDetection(std::vector<std::vector<RGB>>& imageData, int width, int height) {
    const int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    const int Gy[3][3] = {
        {-1, -2, -1},
        { 0,  0,  0},
        { 1,  2,  1}
    };

    std::vector<std::vector<RGB>> originalImage = imageData;

    for (int i = 1; i < height - 1; ++i) {
        for (int j = 1; j < width - 1; ++j) {
            float gx = 0.0f;
            float gy = 0.0f;

            for (int k = -1; k <= 1; ++k) {
                for (int l = -1; l <= 1; ++l) {
                    float intensity = originalImage[i + k][j + l].r; 
                    gx += Gx[k + 1][l + 1] * intensity;
                    gy += Gy[k + 1][l + 1] * intensity;
                }
            }

            float gradientMagnitude = std::sqrt(gx * gx + gy * gy);

            gradientMagnitude = std::min(std::max(gradientMagnitude, 0.0f), 255.0f);

            imageData[i][j].r = gradientMagnitude;
            imageData[i][j].g = gradientMagnitude;
            imageData[i][j].b = gradientMagnitude;
        }
    }
}

void drawRect(std::vector<std::vector<RGB>>& input, int x, int y, int width, int height, RGB stroke={0,0,0}, RGB fill={0xff,0xff,0xff}){
    for(int i=x;i<x+width;++i){
        input[y][i]= stroke;
        input[y+height][i]= stroke;
    }
    for(int i=y;i<y+height;++i){
        input[i][x] = stroke;
        input[i][x+width] = stroke;
    }
    for(int i=x+1; i<x+width;++i){
        for(int j=y+1;j<y+height;++j){
            input[j][i] = fill;
        }
    }
}

void drawPloy(std::vector<std::vector<RGB>>& input, int width, int height, const std::vector<coordinate>& coor, RGB stroke, RGB fill){

}

int main(){
    int width,height,channels;
    unsigned char* imageData = stbi_load("./images/traffic.jpg",&width,&height,&channels,3);
    if(imageData==nullptr){
        std::cout<<"Image loading failed\n";
    }

    auto image = convertTo2D(imageData,width,height);


    convertToGrayscale(image,width,height);
    sobelEdgeDetection(image,width,height);
    saveToPNG(image,width,height,"test.png");
    stbi_image_free(imageData);
    return 0;
}

// int height = 400;
// int width = 500;
// std::vector<std::vector<RGB>> image(height,std::vector<RGB>(width,{0xff,0xff,0xff}));
// drawRect(image,100,100,200,50,{0,0,0},{0xff,0,0});