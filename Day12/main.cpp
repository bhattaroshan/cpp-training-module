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
            imageFlat.emplace_back(color.r);  
            imageFlat.emplace_back(color.g); 
            imageFlat.emplace_back(color.b);  
        }
    }

    if (stbi_write_png(filename, width, height, 3, imageFlat.data(), width * 3)) {
        std::cout << "Image saved successfully to " << filename << std::endl;
    } else {
        std::cout << "Failed to save image!" << std::endl;
    }
}

bool isRed(const RGB color){
    return (color.r-color.g >=50 && color.r-color.b>=50);
}

bool isBlue(const RGB color){
    return (color.b-color.g >=50 && color.b-color.r>=50);
}

bool isBlack(const RGB color){
    return (color.b<50 && color.r<50 && color.g<50);
}

bool isWhite(const RGB color){
    return (color.b==255 && color.r==255 && color.g==255);
}

bool isGreen(const RGB color){
    return (color.g-color.b >=50 && color.g-color.r>=50);
}

coordinate getStartingPostion(std::vector<std::vector<RGB>>& mat, int width, int height){
    coordinate coor {-1,-1};

    for(int row=0;row<height;++row){
        for(int col=0;col<width;++col){
            if(isRed(mat[row][col]) && col+1<width && isBlack(mat[row][col+1])){
                coor.x = row;
                coor.y = col+1;
                return coor;
            }
        }
    }
    return coor;
}

void drawDotsUtils(std::vector<std::vector<RGB>>& mat, int width, int height,int i,int j){
    if(i<0 || j<0 || i>=height || j>=width) return;
    // if(isWhite(mat[i][j])) 
    // {
    //     std::cout<<"White detectected at "<<i<<","<<j<<std::endl;
    //     return;
    // }
    if(isGreen(mat[i][j])) {
        std::cout<<"Green detected"<<std::endl;
        return;
    }
    // if(isRed(mat[i][j])) {
    //     std::cout<<"Red detected"<<std::endl;
    //     return;
    // }
    // if(isBlack(mat[i][j])){
    //     // std::cout<<"Black detected"<<std::endl;
    //     mat[i][j] = {0x00,0xff,0x00};
    // }

    mat[i][j] = {0x00,0xff,0x00};
    std::cout<<i<<","<<j<<std::endl;
    drawDotsUtils(mat,width,height,i-1,j); //top
    drawDotsUtils(mat,width,height,i+1,j); //bottom
    drawDotsUtils(mat,width,height,i,j-1); //left
    drawDotsUtils(mat,width,height,i,j+1); //right
}

void drawDots(std::vector<std::vector<RGB>>& mat, int width, int height){
    coordinate coor = getStartingPostion(mat,width,height);
    coor.x = 70; //height
    coor.y = 112; //width
    drawDotsUtils(mat,width,height,coor.x,coor.y);
}

int main(){
    int width,height,channels;
    unsigned char* imageData = stbi_load("./maze.jpg",&width,&height,&channels,3);

    auto mat = convertTo2D(imageData,width,height); 
    std::cout<<mat.size()<<","<<mat[0].size()<<std::endl;
    drawDots(mat,width,height);
    // mat[70][112]={0,0xff,0};
    saveToPNG(mat,width,height,"test.png");
    // std::cout<<coor.x<<","<<coor.y<<std::endl;

    return 0;
}