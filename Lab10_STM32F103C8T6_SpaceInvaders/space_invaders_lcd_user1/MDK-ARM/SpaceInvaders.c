#include "SpaceInvaders.h"
#include "Random.h"
#include "stdio.h"
#include "fonts.h"
#define PI 3.14159265358979323846
#define NUM_ANGLES 360
//Battleship battleship;
uint8_t clear=5;
Sprite sprite;
Sprite chicken;
Sprite Hamster;
uint8_t spacestone_x[3];
uint8_t spacestone_y[3];
uint8_t stars_vip_x[12];
uint8_t stars_vip_y[12];
uint8_t dynamic_stars_x_3=128;
uint8_t dynamic_stars_y_3=0;
uint8_t dynamic_stars_x_1;
uint8_t dynamic_stars_y_1;
//random stars
uint8_t dynamic_stars_x_2=76;
uint8_t dynamic_stars_y_2=175;
uint8_t dynamic_stars_x_4=100;
uint8_t dynamic_stars_y_4=82;
int16_t f ;
int16_t ddF_x;
int16_t ddF_y;
int32_t dynamic_hole_x=0;
int32_t dynamic_hole_y=0;
uint16_t current_fill_level=11;
uint8_t x_menu;
uint8_t y_menu=37;
int angle;
int angle1=50;
int angle2=100;
int angle3=230;
int angle4=180;
int angle5=280;
bool isFirstCall = true;
int quadrant = 0;
int32_t button1;
element fire;
element water;
element ground;
static const float precomputed_sin[NUM_ANGLES] = {
    // Paste the output from the previous program here
113, 113, 113, 113, 113, 113, 113, 113, 113, 112, 112, 112, 112, 112, 112, 111, 111, 111, 111, 110, 110, 110, 110, 109, 109, 109, 108, 108, 107, 107, 107, 106, 106, 105, 105, 104, 104, 103, 103, 102, 102, 101, 101, 100, 100, 99, 98, 98, 97, 96, 96, 95, 95, 94, 93, 93, 92, 91, 90, 90, 89, 88, 88, 87, 86, 85, 85, 84, 83, 82, 81, 81, 80, 79, 78, 77, 77, 76, 75, 74, 73, 73, 72, 71, 70, 69, 68, 68, 67, 66, 65, 64, 63, 62, 62, 61, 60, 59, 58, 57, 57, 56, 55, 54, 53, 53, 52, 51, 50, 49, 49, 48, 47, 46, 45, 45, 44, 43, 42, 42, 41, 40, 40, 39, 38, 37, 37, 36, 35, 35, 34, 34, 33, 32, 32, 31, 30, 30, 29, 29, 28, 28, 27, 27, 26, 26, 25, 25, 24, 24, 23, 23, 23, 22, 22, 21, 21, 21, 20, 20, 20, 20, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 20, 20, 20, 20, 21, 21, 21, 22, 22, 23, 23, 23, 24, 24, 25, 25, 26, 26, 27, 27, 28, 28, 29, 29, 30, 30, 31, 32, 32, 33, 34, 34, 35, 35, 36, 37, 37, 38, 39, 40, 40, 41, 42, 42, 43, 44, 45, 45, 46, 47, 48, 49, 49, 50, 51, 52, 53, 53, 54, 55, 56, 57, 57, 58, 59, 60, 61, 62, 62, 63, 64, 65, 66, 67, 68, 68, 69, 70, 71, 72, 73, 73, 74, 75, 76, 77, 77, 78, 79, 80, 81, 81, 82, 83, 84, 85, 85, 86, 87, 88, 88, 89, 90, 90, 91, 92, 93, 93, 94, 95, 95, 96, 96, 97, 98, 98, 99, 100, 100, 101, 101, 102, 102, 103, 103, 104, 104, 105, 105, 106, 106, 107, 107, 107, 108, 108, 109, 109, 109, 110, 110, 110, 110, 111, 111, 111, 111, 112, 112, 112, 112, 112, 112, 113, 113, 113, 113, 113, 113, 113, 113
};
static const float precomputed_cos[NUM_ANGLES] = {
    // Paste the output from the previous program here
	80, 81, 82, 83, 83, 84, 85, 86, 87, 88, 88, 89, 90, 91, 92, 92, 93, 94, 95, 96, 96, 97, 98, 99, 100, 100, 101, 102, 103, 103, 104, 105, 105, 106, 107, 108, 108, 109, 110, 110, 111, 111, 112, 113, 113, 114, 115, 115, 116, 116, 117, 117, 118, 118, 119, 119, 120, 120, 121, 121, 122, 122, 122, 123, 123, 124, 124, 124, 125, 125, 125, 125, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 127, 127, 127, 127, 127, 127, 126, 126, 126, 126, 125, 125, 125, 125, 124, 124, 124, 123, 123, 122, 122, 122, 121, 121, 120, 120, 119, 119, 118, 118, 117, 117, 116, 116, 115, 115, 114, 113, 113, 112, 111, 111, 110, 110, 109, 108, 108, 107, 106, 105, 105, 104, 103, 103, 102, 101, 100, 100, 99, 98, 97, 96, 96, 95, 94, 93, 92, 92, 91, 90, 89, 88, 88, 87, 86, 85, 84, 83, 83, 82, 81, 80, 79, 78, 77, 77, 76, 75, 74, 73, 72, 72, 71, 70, 69, 68, 68, 67, 66, 65, 64, 64, 63, 62, 61, 60, 60, 59, 58, 57, 57, 56, 55, 55, 54, 53, 52, 52, 51, 50, 50, 49, 49, 48, 47, 47, 46, 45, 45, 44, 44, 43, 43, 42, 42, 41, 41, 40, 40, 39, 39, 38, 38, 38, 37, 37, 36, 36, 36, 35, 35, 35, 35, 34, 34, 34, 34, 33, 33, 33, 33, 33, 33, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 33, 33, 33, 33, 33, 33, 34, 34, 34, 34, 35, 35, 35, 35, 36, 36, 36, 37, 37, 38, 38, 38, 39, 39, 40, 40, 41, 41, 42, 42, 43, 43, 44, 44, 45, 45, 46, 47, 47, 48, 49, 49, 50, 50, 51, 52, 52, 53, 54, 55, 55, 56, 57, 57, 58, 59, 60, 60, 61, 62, 63, 64, 64, 65, 66, 67, 68, 68, 69, 70, 71, 72, 72, 73, 74, 75, 76, 77, 77, 78, 79
};
static const float precomputed_sin_1[NUM_ANGLES] = {
    // Paste the output from the previous program here
105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 104, 104, 104, 104, 104, 104, 103, 103, 103, 103, 103, 102, 102, 102, 102, 101, 101, 101, 100, 100, 100, 99, 99, 99, 98, 98, 97, 97, 97, 96, 96, 95, 95, 94, 94, 93, 93, 92, 92, 91, 91, 90, 90, 89, 89, 88, 87, 87, 86, 86, 85, 84, 84, 83, 83, 82, 81, 81, 80, 79, 79, 78, 77, 77, 76, 75, 75, 74, 73, 73, 72, 71, 71, 70, 69, 68, 68, 67, 66, 66, 65, 64, 64, 63, 62, 62, 61, 60, 59, 59, 58, 57, 57, 56, 55, 55, 54, 53, 53, 52, 51, 51, 50, 49, 49, 48, 47, 47, 46, 46, 45, 44, 44, 43, 43, 42, 41, 41, 40, 40, 39, 39, 38, 38, 37, 37, 36, 36, 35, 35, 34, 34, 33, 33, 33, 32, 32, 31, 31, 31, 30, 30, 30, 29, 29, 29, 28, 28, 28, 28, 27, 27, 27, 27, 27, 26, 26, 26, 26, 26, 26, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 26, 26, 26, 26, 26, 26, 27, 27, 27, 27, 27, 28, 28, 28, 28, 29, 29, 29, 30, 30, 30, 31, 31, 31, 32, 32, 33, 33, 33, 34, 34, 35, 35, 36, 36, 37, 37, 38, 38, 39, 39, 40, 40, 41, 41, 42, 43, 43, 44, 44, 45, 46, 46, 47, 47, 48, 49, 49, 50, 51, 51, 52, 53, 53, 54, 55, 55, 56, 57, 57, 58, 59, 59, 60, 61, 62, 62, 63, 64, 64, 65, 66, 66, 67, 68, 68, 69, 70, 71, 71, 72, 73, 73, 74, 75, 75, 76, 77, 77, 78, 79, 79, 80, 81, 81, 82, 83, 83, 84, 84, 85, 86, 86, 87, 87, 88, 89, 89, 90, 90, 91, 91, 92, 92, 93, 93, 94, 94, 95, 95, 96, 96, 97, 97, 97, 98, 98, 99, 99, 99, 100, 100, 100, 101, 101, 101, 102, 102, 102, 102, 103, 103, 103, 103, 103, 104, 104, 104, 104, 104, 104, 105, 105, 105, 105, 105, 105, 105, 105, 105
};

static const float precomputed_cos_1[NUM_ANGLES] = {
    // Paste the output from the previous program here
	80, 81, 81, 82, 83, 83, 84, 85, 86, 86, 87, 88, 88, 89, 90, 90, 91, 92, 92, 93, 94, 94, 95, 96, 96, 97, 98, 98, 99, 99, 100, 101, 101, 102, 102, 103, 104, 104, 105, 105, 106, 106, 107, 107, 108, 108, 109, 109, 110, 110, 111, 111, 112, 112, 112, 113, 113, 114, 114, 114, 115, 115, 115, 116, 116, 116, 117, 117, 117, 117, 118, 118, 118, 118, 118, 119, 119, 119, 119, 119, 119, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 119, 119, 119, 119, 119, 119, 118, 118, 118, 118, 118, 117, 117, 117, 117, 116, 116, 116, 115, 115, 115, 114, 114, 114, 113, 113, 112, 112, 112, 111, 111, 110, 110, 109, 109, 108, 108, 107, 107, 106, 106, 105, 105, 104, 104, 103, 102, 102, 101, 101, 100, 99, 99, 98, 98, 97, 96, 96, 95, 94, 94, 93, 92, 92, 91, 90, 90, 89, 88, 88, 87, 86, 86, 85, 84, 83, 83, 82, 81, 81, 80, 79, 79, 78, 77, 77, 76, 75, 74, 74, 73, 72, 72, 71, 70, 70, 69, 68, 68, 67, 66, 66, 65, 64, 64, 63, 62, 62, 61, 61, 60, 59, 59, 58, 58, 57, 56, 56, 55, 55, 54, 54, 53, 53, 52, 52, 51, 51, 50, 50, 49, 49, 48, 48, 48, 47, 47, 46, 46, 46, 45, 45, 45, 44, 44, 44, 43, 43, 43, 43, 42, 42, 42, 42, 42, 41, 41, 41, 41, 41, 41, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 41, 41, 41, 41, 41, 41, 42, 42, 42, 42, 42, 43, 43, 43, 43, 44, 44, 44, 45, 45, 45, 46, 46, 46, 47, 47, 48, 48, 48, 49, 49, 50, 50, 51, 51, 52, 52, 53, 53, 54, 54, 55, 55, 56, 56, 57, 58, 58, 59, 59, 60, 61, 61, 62, 62, 63, 64, 64, 65, 66, 66, 67, 68, 68, 69, 70, 70, 71, 72, 72, 73, 74, 74, 75, 76, 77, 77, 78, 79, 79
};
static const float precomputed_sin_2[NUM_ANGLES] = {
    // Paste the output from the previous program here
97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 96, 96, 96, 96, 96, 96, 96, 95, 95, 95, 95, 95, 94, 94, 94, 94, 94, 93, 93, 93, 92, 92, 92, 92, 91, 91, 91, 90, 90, 90, 89, 89, 88, 88, 88, 87, 87, 86, 86, 86, 85, 85, 84, 84, 83, 83, 82, 82, 81, 81, 81, 80, 80, 79, 79, 78, 78, 77, 76, 76, 75, 75, 74, 74, 73, 73, 72, 72, 71, 71, 70, 69, 69, 68, 68, 67, 67, 66, 66, 65, 64, 64, 63, 63, 62, 62, 61, 61, 60, 59, 59, 58, 58, 57, 57, 56, 56, 55, 55, 54, 54, 53, 52, 52, 51, 51, 50, 50, 49, 49, 49, 48, 48, 47, 47, 46, 46, 45, 45, 44, 44, 44, 43, 43, 42, 42, 42, 41, 41, 40, 40, 40, 39, 39, 39, 38, 38, 38, 38, 37, 37, 37, 36, 36, 36, 36, 36, 35, 35, 35, 35, 35, 34, 34, 34, 34, 34, 34, 34, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 34, 34, 34, 34, 34, 34, 34, 35, 35, 35, 35, 35, 36, 36, 36, 36, 36, 37, 37, 37, 38, 38, 38, 38, 39, 39, 39, 40, 40, 40, 41, 41, 42, 42, 42, 43, 43, 44, 44, 44, 45, 45, 46, 46, 47, 47, 48, 48, 49, 49, 49, 50, 50, 51, 51, 52, 52, 53, 54, 54, 55, 55, 56, 56, 57, 57, 58, 58, 59, 59, 60, 61, 61, 62, 62, 63, 63, 64, 64, 65, 66, 66, 67, 67, 68, 68, 69, 69, 70, 71, 71, 72, 72, 73, 73, 74, 74, 75, 75, 76, 76, 77, 78, 78, 79, 79, 80, 80, 81, 81, 81, 82, 82, 83, 83, 84, 84, 85, 85, 86, 86, 86, 87, 87, 88, 88, 88, 89, 89, 90, 90, 90, 91, 91, 91, 92, 92, 92, 92, 93, 93, 93, 94, 94, 94, 94, 94, 95, 95, 95, 95, 95, 96, 96, 96, 96, 96, 96, 96, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97
};

static const float precomputed_cos_2[NUM_ANGLES] = {
    // Paste the output from the previous program here
	80, 81, 81, 82, 82, 83, 83, 84, 84, 85, 86, 86, 87, 87, 88, 88, 89, 89, 90, 90, 91, 91, 92, 93, 93, 94, 94, 95, 95, 96, 96, 96, 97, 97, 98, 98, 99, 99, 100, 100, 101, 101, 101, 102, 102, 103, 103, 103, 104, 104, 105, 105, 105, 106, 106, 106, 107, 107, 107, 107, 108, 108, 108, 109, 109, 109, 109, 109, 110, 110, 110, 110, 110, 111, 111, 111, 111, 111, 111, 111, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 111, 111, 111, 111, 111, 111, 111, 110, 110, 110, 110, 110, 109, 109, 109, 109, 109, 108, 108, 108, 107, 107, 107, 107, 106, 106, 106, 105, 105, 105, 104, 104, 103, 103, 103, 102, 102, 101, 101, 101, 100, 100, 99, 99, 98, 98, 97, 97, 96, 96, 96, 95, 95, 94, 94, 93, 93, 92, 91, 91, 90, 90, 89, 89, 88, 88, 87, 87, 86, 86, 85, 84, 84, 83, 83, 82, 82, 81, 81, 80, 79, 79, 78, 78, 77, 77, 76, 76, 75, 74, 74, 73, 73, 72, 72, 71, 71, 70, 70, 69, 69, 68, 67, 67, 66, 66, 65, 65, 64, 64, 64, 63, 63, 62, 62, 61, 61, 60, 60, 59, 59, 59, 58, 58, 57, 57, 57, 56, 56, 55, 55, 55, 54, 54, 54, 53, 53, 53, 53, 52, 52, 52, 51, 51, 51, 51, 51, 50, 50, 50, 50, 50, 49, 49, 49, 49, 49, 49, 49, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 49, 49, 49, 49, 49, 49, 49, 50, 50, 50, 50, 50, 51, 51, 51, 51, 51, 52, 52, 52, 53, 53, 53, 53, 54, 54, 54, 55, 55, 55, 56, 56, 57, 57, 57, 58, 58, 59, 59, 59, 60, 60, 61, 61, 62, 62, 63, 63, 64, 64, 64, 65, 65, 66, 66, 67, 67, 68, 69, 69, 70, 70, 71, 71, 72, 72, 73, 73, 74, 74, 75, 76, 76, 77, 77, 78, 78, 79, 79
};
bool is_within_rectangle(uint32_t x1, uint32_t y1, uint32_t width1, uint32_t height1,
                          uint32_t x2, uint32_t y2, uint32_t width2, uint32_t height2) {
    if (x1 >= x2 + width2 || x2 >= x1 + width1 || 
        y1 >= y2 + height2 || y2 >= y1 + height1) {
        return false;
    }
    return true;
}
void dynamic_hole(uint32_t centerX, uint32_t centerY, uint32_t radius) {
    // C?p nh?t góc
    
		ST7735_FillRectangle(precomputed_sin_1[angle1], precomputed_cos_1[angle1],7,6,ST7735_PURPOSE);
		angle1 = (angle1 + 10) % NUM_ANGLES;
    // In hình ?nh t?i v? trí m?i
    ST7735_DrawImage(precomputed_sin_1[angle1], precomputed_cos_1[angle1],7,6,gImage_stars_vip);
}
void dynamic_hole_3(uint32_t centerX, uint32_t centerY, uint32_t radius) {
    // C?p nh?t góc
    
		ST7735_FillRectangle(precomputed_sin_1[angle3], precomputed_cos_1[angle3],7,6,ST7735_PURPOSE);
		angle3 = (angle3 + 10) % NUM_ANGLES;
    // In hình ?nh t?i v? trí m?i
    ST7735_DrawImage(precomputed_sin_1[angle3], precomputed_cos_1[angle3],7,6,gImage_stars_vip);
}
void dynamic_hole_1(uint32_t centerX, uint32_t centerY, uint32_t radius) {
//    // C?p nh?t góc
//    
		ST7735_FillRectangle(precomputed_sin[angle], precomputed_cos[angle],7,6,ST7735_PURPOSE);
		angle = (angle + 10) % NUM_ANGLES;
   // In hình ?nh t?i v? trí m?i
    ST7735_DrawImage(precomputed_sin[angle], precomputed_cos[angle],7,6,gImage_stars_vip);
}
void dynamic_hole_4(uint32_t centerX, uint32_t centerY, uint32_t radius) {
//    // C?p nh?t góc
//    
		ST7735_FillRectangle(precomputed_sin[angle4], precomputed_cos[angle4],7,6,ST7735_PURPOSE);
		angle4 = (angle4 + 10) % NUM_ANGLES;
   // In hình ?nh t?i v? trí m?i
    ST7735_DrawImage(precomputed_sin[angle4], precomputed_cos[angle4],7,6,gImage_stars_vip);
}
void dynamic_hole_2(uint32_t centerX, uint32_t centerY, uint32_t radius) {
//    // C?p nh?t góc
//    
		ST7735_FillRectangle(precomputed_sin_2[angle2], precomputed_cos_2[angle2],7,6,ST7735_PURPOSE);
		angle2 = (angle2 + 10) % NUM_ANGLES;
   // In hình ?nh t?i v? trí m?i
    ST7735_DrawImage(precomputed_sin_2[angle2], precomputed_cos_2[angle2],7,6,gImage_stars_vip);
}
void dynamic_hole_5(uint32_t centerX, uint32_t centerY, uint32_t radius) {
//    // C?p nh?t góc
//    
		ST7735_FillRectangle(precomputed_sin_2[angle5], precomputed_cos_2[angle5],7,6,ST7735_PURPOSE);
		angle5 = (angle5 + 10) % NUM_ANGLES;
   // In hình ?nh t?i v? trí m?i
    ST7735_DrawImage(precomputed_sin_2[angle5], precomputed_cos_2[angle5],7,6,gImage_stars_vip);
}
void animateFillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t radius, uint16_t color) {
    // fillScreen(BLACK);  // Clear display with background color
    ST7735_DrawRoundRect(x, y, w, h, radius, ST7735_WHITE);  // Draw outline of the rectangle
    
    // C?p nh?t m?c d? fill m?i l?n g?i hàm
    current_fill_level += 1;  // Tang 2 pixel m?i l?n g?i, b?n có th? thay d?i giá tr? này
    
    // Ð?m b?o m?c d? fill không vu?t quá chi?u r?ng c?a hình ch? nh?t
    // Fill t? trái sang ph?i
    ST7735_FillRoundRect(x, y + 2, current_fill_level, h - 4, radius, color);
    //HAL_Delay(100);  // Delay to slow down the animation
}
void battleshipInit_1(Battleship* battleship){
	battleship->x = 83; 
	battleship->y = 128;
	battleship->image = battleship_img_1;
	battleship->w = 40;
	battleship->h = 28;
}
bool isCollision(int x1, int y1, int width1, int height1, 
                 int x2, int y2, int width2, int height2) {
    // Ki?m tra di?u ki?n không va ch?m
    if (x1 + width1 < x2 || // rect1 n?m bên trái rect2
        x1 > x2 + width2 || // rect1 n?m bên ph?i rect2
        y1 + height1 < y2 || // rect1 n?m trên rect2
        y1 > y2 + height2) { // rect1 n?m du?i rect2
        return false;
    }

    // N?u không có di?u ki?n nào ? trên th?a mãn, thì có va ch?m
    return true;
}
void background_init(){
	int i;
		for(i=0;i<3;i++){
		spacestone_x[i]=(Random()%128+1);
		spacestone_y[i]=(Random()%168+1);
		bool a;
		a=is_within_rectangle(spacestone_x[i],spacestone_y[i],23,30,40,20,49,50)||is_within_rectangle(spacestone_x[i],spacestone_y[i],23,30,5,90,39,40)||is_within_rectangle(spacestone_x[i],spacestone_y[i],23,30,5,0,40,38);
		if(a){
			i--;
		}
	}
		for(i=0;i<16;i++){
		stars_vip_x[i]=(Random()%128+1);
		stars_vip_y[i]=(Random()%168+1);
		bool a;
		a=is_within_rectangle(stars_vip_x[i],stars_vip_y[i],7,6,40,20,49,50) || is_within_rectangle(stars_vip_x[i],stars_vip_y[i],7,6,5,90,39,40)||is_within_rectangle(stars_vip_x[i],stars_vip_y[i],7,6,5,0,40,38) ;
		if(a){
			i--;
		}
	}
}
void stars_walk_1(){
	ST7735_FillRectangle(dynamic_stars_x_1,dynamic_stars_y_1,7, 6, ST7735_PURPOSE);
	dynamic_stars_x_1++;
	dynamic_stars_y_1++;
	ST7735_DrawImage(dynamic_stars_x_1,dynamic_stars_y_1,7,6,gImage_stars_vip);
	if(dynamic_stars_x_1==128 || dynamic_stars_y_1==145){
		dynamic_stars_x_1=0;
		dynamic_stars_y_1=0;
	}
}
void stars_walk_4(){
	ST7735_FillRectangle(dynamic_stars_x_4,dynamic_stars_y_4,7, 6, ST7735_PURPOSE);
	dynamic_stars_x_4--;
	dynamic_stars_y_4-=3;
	ST7735_DrawImage(dynamic_stars_x_4,dynamic_stars_y_4,7,6,gImage_stars_vip);
	if(dynamic_stars_x_4==0 || dynamic_stars_y_4==0){
		dynamic_stars_x_4=(Random()%128+1);
		dynamic_stars_y_4=(Random()%128+1);
	}
}
void stars_walk_2(){
	ST7735_FillRectangle(dynamic_stars_x_2,dynamic_stars_y_2,7, 6, ST7735_PURPOSE);
	dynamic_stars_x_2++;
	dynamic_stars_y_2+=4;
	ST7735_DrawImage(dynamic_stars_x_2,dynamic_stars_y_2,7,6,gImage_stars_vip);
	if(dynamic_stars_x_2==128 || dynamic_stars_y_2==145){
		dynamic_stars_x_2=(Random()%128+1);
		dynamic_stars_y_2=(Random()%128+1);
	}
}
void stars_walk_3(){
	ST7735_FillRectangle(dynamic_stars_x_3,dynamic_stars_y_3,7, 6, ST7735_PURPOSE);
	dynamic_stars_x_3-=2;
	dynamic_stars_y_3++;
	ST7735_DrawImage(dynamic_stars_x_3,dynamic_stars_y_3,7,6,gImage_stars_vip);
	if(dynamic_stars_x_3==0 || dynamic_stars_y_3==145){
		dynamic_stars_x_3=128;
		dynamic_stars_y_3=0;
	}
}
void planet_1(){
	ST7735_DrawImage(40,40,49,50,gImage_planet_1);
};
void planet_2(){
	ST7735_DrawImage(5,90,39,40,gImage_planet_2);
};
void planet_3(){
	ST7735_DrawImage(0,0,39,40,gImage_planet_2);
};
void stars_1(){
	ST7735_DrawImage(20,100,18,20,gImage_stars);
}
void stars_2(){
	ST7735_DrawImage(70,85,18,20,gImage_stars);
}
void stars_3(){
	ST7735_DrawImage(110,60,18,20,gImage_stars);
}
void stars_4(){
	ST7735_DrawImage(0,40,18,20,gImage_stars);
}
void saobang(){
	ST7735_DrawImage(100,10,25,23,gImage_saobang);
}
void hole(){
	ST7735_DrawImage(90,82,30,30,gImage_hole);
}
void spacestones(){
	int i;
	for(i=0;i<3;i++){
	ST7735_DrawImage(spacestone_x[i],spacestone_y[i],23,30,gImage_spacestones);
	}
}
void stars_vip(){
	int i;
	for(i=0;i<16;i++){
		ST7735_DrawImage(stars_vip_x[i],stars_vip_y[i],7,6,gImage_stars_vip);
	}
}
void background(){
	//ST7735_FillScreen(ST7735_PURPOSE);
	stars_1();
	stars_2();
	stars_3();
	stars_4();
	stars_vip();
	spacestones();
	planet_1();
	planet_2();
	planet_3();
	hole();
	saobang();
}
void menu_loading(){
	dynamic_hole(60,60,40);
	ST7735_DrawCircle(65,80,40,ST7735_WHITE);
	ST7735_DrawCircle(65,80,48,ST7735_WHITE);
	ST7735_DrawCircle(65,80,32,ST7735_WHITE);
	dynamic_hole_1(60,60,45);
	dynamic_hole_2(60,60,45);
	dynamic_hole_3(60,60,45);
	dynamic_hole_4(60,60,45);
	dynamic_hole_5(60,60,45);
	ST7735_DrawImage(40,55,50,50,gImage_EDABK_logo);
	animateFillRoundRect(0,0,128,30,4,ST7735_WHITE);
	ST7735_DrawString(20,10,"Space_Invader",Font_7x10,ST7735_PURPOSE,ST7735_WHITE);
}
void menu(){
		ST7735_DrawRoundRect(0,0,128,30,4,ST7735_WHITE);
	  ST7735_FillRoundRect(0,2, 128, 26, 4, ST7735_WHITE);
		ST7735_DrawString(20,10,"Space_Invader",Font_7x10,ST7735_PURPOSE,ST7735_WHITE);
	  ST7735_DrawImage(78,110,50,50,gImage_EDABK_logo);
		ST7735_DrawString(38,40,"Start 2P",Font_7x10,ST7735_WHITE,ST7735_PURPOSE);
		ST7735_DrawString(38,60,"Start 1P",Font_7x10,ST7735_WHITE,ST7735_PURPOSE);
		ST7735_DrawString(45,80,"Scores",Font_7x10,ST7735_WHITE,ST7735_PURPOSE);
		ST7735_DrawString(50,100,"Exit",Font_7x10,ST7735_WHITE,ST7735_PURPOSE);
		ST7735_FillRoundRect(0,124, 77, 30, 4, ST7735_WHITE);
	  ST7735_DrawString(5,125,"1 san pham",Font_7x10,ST7735_PURPOSE,ST7735_WHITE);
	  ST7735_DrawString(25,140,"cua",Font_7x10,ST7735_PURPOSE,ST7735_WHITE);
		ST7735_DrawRoundRect(35,y_menu,60,15,4,ST7735_WHITE);
}
void init_fire(){
	 fire.x=10;
	fire.y=0;
	fire.w=25;
	fire.h=33;
	fire.vx=1;
	fire.vy=3;
	fire.life=alive;
	fire.image=gImage_Fire;
}
void recover_fire(){
	 fire.x=10;
	fire.y=0;
	fire.life=alive;
	
}
void change_element_water(Battleship* battleship){
	battleship->bullet.image=gImage_water_bullet;
	battleship->bullet.w=17;
	battleship->bullet.y=17;
}
void init_water(){
	 water.x=100;
	water.y=0;
	water.w=20;
	water.h=30;
	water.vx=1;
	water.vy=2;
	water.life=alive;
	water.image=gImage_water;
	water.clear=1;
}
void recover_water(){
	 water.x=100;
	water.y=0;
	water.life=alive;
	water.clear=1;
}
void move_water(Battleship* battleship1,Battleship* battleship2){
	if(water.life){
	ST7735_FillRectangle(water.x,water.y,water.w,water.h,ST7735_PURPOSE);
	water.x-=water.vx;
	water.y+=water.vy;
	ST7735_DrawImage(water.x,water.y,water.w,water.h,water.image);
	if(water.y>175,water.y>128){
		water.life=dead;
	}
	if(isCollision(water.x,water.y,water.w,water.h,battleship1->x,battleship1->y,battleship1->w,battleship1->h)){
		water.life=dead;
		change_element_water(battleship1);
	}
	if(isCollision(water.x,water.y,water.w,water.h,battleship2->x,battleship2->y,battleship2->w,battleship2->h)){
		water.life=dead;
		change_element_water(battleship2);
	}
}
	else{
	if(clear) ST7735_FillRectangle(water.x,water.y,water.w,water.h,ST7735_PURPOSE);
	clear=0;
	}
}
void change_element_fire(Battleship* battleship){
	battleship->bullet.image=gImage_fire_bullet;
	battleship->bullet.w=10;
	battleship->bullet.y=17;
}
void move_fire(Battleship* battleship1,Battleship* battleship2){
	if(fire.life){
	ST7735_FillRectangle(fire.x,fire.y,fire.w,fire.h,ST7735_PURPOSE);
	fire.x+=fire.vx;
	fire.y+=fire.vy;
	ST7735_DrawImage(fire.x,fire.y,fire.w,fire.h,fire.image);
	if(fire.y>175,fire.y>128){
		fire.life=dead;
	}
	if(isCollision(fire.x,fire.y,fire.w,fire.h,battleship1->x,battleship1->y,battleship1->w,battleship1->h)){
		fire.life=dead;
		change_element_fire(battleship1);
	}
	if(isCollision(fire.x,fire.y,fire.w,fire.h,battleship2->x,battleship2->y,battleship2->w,battleship2->h)){
		fire.life=dead;
		change_element_fire(battleship2);
	}
	
}
	else{
	if(clear) ST7735_FillRectangle(fire.x,fire.y,fire.w,fire.h,ST7735_PURPOSE);
	clear=0;
	}
}
void changestate(){
	if(y_menu>80){
		y_menu=37;
	}
	else {
		ST7735_DrawRoundRect(35,y_menu,60,15,4,ST7735_PURPOSE);
		y_menu+=20;
	}
}
// Initialize battelship
uint32_t Convert(uint32_t adc_data){
	if(adc_data>4096) return 50;
	return (uint32_t)(adc_data * 83 / 4096.0);
}

// Battleship 1 move
void battleshipMove(Battleship* battleship){
	int32_t temp = battleship->x;
	battleship->x = Convert(ADCData); 
	if (temp != battleship->x){
  ST7735_FillRectangle(temp, battleship->y, battleship->w, battleship->h, ST7735_PURPOSE);		
	}
	ST7735_DrawImage(battleship->x, battleship->y, battleship->w, battleship->h, (uint16_t*)battleship->image);
}

// Battleship 2 move
void battleshipMove_2(Battleship* battleship){
	int32_t temp = battleship->x;
		if(Convert(ADCData_2)>83){
	return;
	}
	battleship->x = Convert(ADCData_2); 
	if (temp != battleship->x){
	ST7735_FillRectangle(temp, battleship->y, battleship->w, battleship->h, ST7735_PURPOSE);		
	}
	ST7735_DrawImage(battleship->x, battleship->y, battleship->w, battleship->h, (uint16_t*)battleship->image);
}
void Initbullet(Battleship* battleship1,Battleship* battleship2){
	battleship1->bullet.image=bullet;
	battleship2->bullet.image=bullet;
	battleship1->bullet.w = 4;
	battleship1->bullet.h = 7;
	battleship2->bullet.w = 4;
	battleship2->bullet.h = 7;
}
// Initialize bullet 1
void battleshipBulletInit(Battleship* battleship){
	battleship->bullet.number_bullet++;
	if(battleship->bullet.number_bullet==1||battleship->bullet.number_bullet==4){
	battleship->bullet.x = battleship->x + 22;
	battleship->bullet.y = battleship->y - 32;
	battleship->bullet.number_bullet=1;
	battleship->bullet.leftGameArea = 0;
	}
	if(battleship->bullet.number_bullet==2){
	battleship->bullet.leftGameArea1 = 0;
	battleship->bullet.x1 = battleship->x + 22;
	battleship->bullet.y1 = battleship->y - 32;
	}
	if(battleship->bullet.number_bullet==3){
	battleship->bullet.x2 = battleship->x + 22;
	battleship->bullet.y2 = battleship->y - 32;
	battleship->bullet.leftGameArea2 = 0;
	}
	//battleship->bullet.image = bullet;
//battleship->bullet.black = bullet_black;

	battleship->bullet.collisionDetected = 0;
	
}

// Initialize bullet 2
void battleshipBulletInit_2(Battleship* battleship){
	battleship->bullet.x = battleship->x + 22;
	battleship->bullet.y = battleship->y + 32;
	//battleship->bullet.image = bullet;
	//battleship->bullet.black = bullet_black;
	battleship->bullet.w = 4;
	battleship->bullet.h = 7;
	battleship->bullet.collisionDetected = 0;
	battleship->bullet.leftGameArea = 0;
}

// Bullet 1 move
void battleshipBulletMove(Battleship* battleship){
	if (!(battleship->bullet.leftGameArea || battleship->bullet.collisionDetected)){
		ST7735_FillRectangle(battleship->bullet.x, battleship->bullet.y, battleship->bullet.w, battleship->bullet.h, ST7735_PURPOSE);
		battleship->bullet.y -= battleship->bullet.h;
		ST7735_DrawImage(battleship->bullet.x, battleship->bullet.y, battleship->bullet.w, battleship->bullet.h, battleship->bullet.image);		
	}
	else {
		ST7735_FillRectangle(battleship->bullet.x, battleship->bullet.y, battleship->bullet.w, battleship->bullet.h, ST7735_PURPOSE);
	}
	if (battleship->bullet.y <= 0){
		battleship->bullet.leftGameArea = 1;
	}
}
void battleshipBulletMove_1(Battleship* battleship){
	if (!(battleship->bullet.leftGameArea1 || battleship->bullet.collisionDetected)){
		ST7735_FillRectangle(battleship->bullet.x1, battleship->bullet.y1, battleship->bullet.w, battleship->bullet.h, ST7735_PURPOSE);
		battleship->bullet.y1 -= battleship->bullet.h;
		ST7735_DrawImage(battleship->bullet.x1, battleship->bullet.y1, battleship->bullet.w, battleship->bullet.h, battleship->bullet.image);		
	}
	else {
		ST7735_FillRectangle(battleship->bullet.x1, battleship->bullet.y1, battleship->bullet.w, battleship->bullet.h, ST7735_PURPOSE);
	}
	if (battleship->bullet.y1 <= 0){
		battleship->bullet.leftGameArea1 = 1;
	}
}
void battleshipBulletMove_2(Battleship* battleship){
	if (!(battleship->bullet.leftGameArea2 || battleship->bullet.collisionDetected)){
		ST7735_FillRectangle(battleship->bullet.x2, battleship->bullet.y2, battleship->bullet.w, battleship->bullet.h, ST7735_PURPOSE);
		battleship->bullet.y2 -= battleship->bullet.h;
		ST7735_DrawImage(battleship->bullet.x2, battleship->bullet.y2, battleship->bullet.w, battleship->bullet.h, battleship->bullet.image);		
	}
	else {
		ST7735_FillRectangle(battleship->bullet.x2, battleship->bullet.y2, battleship->bullet.w, battleship->bullet.h, ST7735_PURPOSE);
	}
	if (battleship->bullet.y2 <= 0){
		battleship->bullet.leftGameArea2 = 1;
	}
}
// Bullet 2 move
void battleshipBulletMove_21(Battleship* battleship){
	if (!(battleship->bullet.leftGameArea || battleship->bullet.collisionDetected)){
		ST7735_DrawImage(battleship->bullet.x, battleship->bullet.y, battleship->bullet.w, battleship->bullet.h, battleship->bullet.black);
		battleship->bullet.y += battleship->bullet.h;
		ST7735_DrawImage(battleship->bullet.x, battleship->bullet.y, battleship->bullet.w, battleship->bullet.h, battleship->bullet.image);		
	}
	else {
		ST7735_DrawImage(battleship->bullet.x, battleship->bullet.y, battleship->bullet.w, battleship->bullet.h, battleship->bullet.black);
	}
	if (battleship->bullet.y >= 160){
		battleship->bullet.leftGameArea = 1;
	}
}

uint8_t endGame = 0;
// Handle collision
//void handleCollision(Battleship* battleship){
//	if (!((sprite.x >= (battleship->bullet.x + battleship->bullet.w)) || (battleship->bullet.x >= (sprite.x + sprite.w)) || ((sprite.y - sprite.h) >= (battleship->bullet.y)) || ((battleship->bullet.y - battleship->bullet.h) >= (sprite.y)))){
//		battleship->bullet.collisionDetected = 1;
//		sprite.life = dead;
//		endGame = 1;
//	}
//}

// Handle collision
void handleCollision(Battleship* battleship_1, Battleship* battleship_2){
	if (!((battleship_2->x >= (battleship_1->bullet.x + battleship_1->bullet.w)) || (battleship_1->bullet.x >= (battleship_2->x + battleship_2->w)) || ((battleship_2->y - battleship_2->h) >= (battleship_1->bullet.y)) || ((battleship_1->bullet.y - battleship_1->bullet.h) >= (battleship_2->y)))){
		battleship_1->bullet.collisionDetected = 1;
		battleship_2->life = dead;
		battleship_1->life = alive;	
		endGame = 1;
	}
	if (!((battleship_1->x >= (battleship_2->bullet.x + battleship_2->bullet.w)) || (battleship_2->bullet.x >= (battleship_1->x + battleship_1->w)) || ((battleship_1->y + battleship_1->h / 2) >= (battleship_2->bullet.y)) || ((battleship_2->bullet.y + battleship_2->bullet.h) <= (battleship_1->y)))){
		battleship_2->bullet.collisionDetected = 1;
		battleship_1->life = dead;
		battleship_2->life = alive;
		endGame = 1;
	}
}

// Initialize spritespriteInit
void spriteInit(void){
	sprite.x = 30;
	sprite.y = 0;
	sprite.vx = 0;
	sprite.vy = 0;
	sprite.image = gImage_dino;
	//sprite.black = sprite_black;
	sprite.life = alive;
	sprite.w = 25;
	sprite.h = 18;
	//chickenInit
	chicken.x = 60;
	chicken.y = 0;
	chicken.vx = 0;
	chicken.vy = 0;
	chicken.image = gImage_chicken;
	//chicken.black = chicken_black;
	chicken.life = alive;
	chicken.w = 25;
	chicken.h = 27;
		//HamsterInit
	Hamster.x = 0;
	Hamster.y = 30;
	Hamster.vx = 0;
	Hamster.vy = 0;
	Hamster.image = gImage_Hamster;
	//Hamster.black = Hamster_black;
	Hamster.life = alive;
	Hamster.w = 20;
	Hamster.h = 19;
}
// Sprite move
	
uint8_t count = 0;
uint8_t flag = 0;
uint8_t count_chicken = 0;
uint8_t flag_chicken = 0;
uint8_t count_Hamster = 0;
uint8_t flag_Hamster = 0;
// Sprite move
void spriteMove(Battleship* battleship,Battleship* battleship1){
	if(isCollision(sprite.x,sprite.y,sprite.w,sprite.h,battleship->bullet.x,battleship->bullet.y,battleship->bullet.w,battleship->bullet.h)){
		sprite.life=dead;
	clear+=5;
	}
	if(isCollision(chicken.x,chicken.y,chicken.w,chicken.h,battleship->bullet.x,battleship->bullet.y,battleship->bullet.w,battleship->bullet.h)){
	  chicken.life=dead;
	clear+=5;
	}
	if(isCollision(Hamster.x,Hamster.y,Hamster.w,Hamster.h,battleship->bullet.x,battleship->bullet.y,battleship->bullet.w,battleship->bullet.h)){
		Hamster.life=dead;
	clear+=5;
	}
	if(isCollision(sprite.x,sprite.y,sprite.w,sprite.h,battleship->bullet.x1,battleship->bullet.y1,battleship->bullet.w,battleship->bullet.h)){
		sprite.life=dead;
	clear+=5;
	}
	if(isCollision(chicken.x,chicken.y,chicken.w,chicken.h,battleship->bullet.x1,battleship->bullet.y1,battleship->bullet.w,battleship->bullet.h)){
		chicken.life=dead;
	clear+=5;
	}
	if(isCollision(Hamster.x,Hamster.y,Hamster.w,Hamster.h,battleship->bullet.x1,battleship->bullet.y1,battleship->bullet.w,battleship->bullet.h)){
		Hamster.life=dead;
	clear+=5;
	}
	if(isCollision(sprite.x,sprite.y,sprite.w,sprite.h,battleship->bullet.x2,battleship->bullet.y2,battleship->bullet.w,battleship->bullet.h)){
		sprite.life=dead;
	clear+=5;
	}
	if(isCollision(chicken.x,chicken.y,chicken.w,chicken.h,battleship->bullet.x2,battleship->bullet.y2,battleship->bullet.w,battleship->bullet.h)){
		chicken.life=dead;
	clear+=5;
	}
	if(isCollision(Hamster.x,Hamster.y,Hamster.w,Hamster.h,battleship->bullet.x2,battleship->bullet.y2,battleship->bullet.w,battleship->bullet.h)){
		Hamster.life=dead;
	clear+=5;
	}
	if(isCollision(sprite.x,sprite.y,sprite.w,sprite.h,battleship1->bullet.x,battleship1->bullet.y,battleship1->bullet.w,battleship1->bullet.h)){
		sprite.life=dead;
	clear+=5;
	}
	if(isCollision(chicken.x,chicken.y,chicken.w,chicken.h,battleship1->bullet.x,battleship1->bullet.y,battleship1->bullet.w,battleship1->bullet.h)){
		chicken.life=dead;
	clear+=5;
	}
	if(isCollision(Hamster.x,Hamster.y,Hamster.w,Hamster.h,battleship1->bullet.x,battleship1->bullet.y,battleship1->bullet.w,battleship1->bullet.h)){
		Hamster.life=dead;
	clear+=5;
	}
	if(isCollision(sprite.x,sprite.y,sprite.w,sprite.h,battleship1->bullet.x1,battleship1->bullet.y1,battleship1->bullet.w,battleship1->bullet.h)){
		sprite.life=dead;
	clear+=5;
	}
	if(isCollision(chicken.x,chicken.y,chicken.w,chicken.h,battleship1->bullet.x1,battleship1->bullet.y1,battleship1->bullet.w,battleship1->bullet.h)){
		chicken.life=dead;
	clear+=5;
	}
	if(isCollision(Hamster.x,Hamster.y,Hamster.w,Hamster.h,battleship1->bullet.x1,battleship1->bullet.y1,battleship1->bullet.w,battleship1->bullet.h)){
		Hamster.life=dead;
	clear+=5;
	}
	if(isCollision(sprite.x,sprite.y,sprite.w,sprite.h,battleship1->bullet.x2,battleship1->bullet.y2,battleship1->bullet.w,battleship1->bullet.h)){
		sprite.life=dead;
	clear+=5;
	}
	if(isCollision(chicken.x,chicken.y,chicken.w,chicken.h,battleship1->bullet.x2,battleship1->bullet.y2,battleship1->bullet.w,battleship1->bullet.h)){
		chicken.life=dead;
	clear+=5;
	}
	if(isCollision(Hamster.x,Hamster.y,Hamster.w,Hamster.h,battleship1->bullet.x2,battleship1->bullet.y2,battleship1->bullet.w,battleship1->bullet.h)){
		Hamster.life=dead;
	clear+=5;
	}
	if(sprite.life == alive){
		count++;
		ST7735_FillRectangle(sprite.x, sprite.y, sprite.w, sprite.h, ST7735_PURPOSE);
		//Random_UpdateSeed(sprite.vx);
		sprite.vx = Random() % 4 + 1;
		sprite.vy = Random() & 4 + 1; 
		if(count == 10){
		flag++;
		if(flag < 30 || sprite.x <= 0 || sprite.y <= 9){	
			sprite.x += sprite.vx;
			sprite.y += sprite.vy;
		}	
		if ((flag >= 20 && flag < 40) || sprite.x >= 83 || sprite.y >= 120){
			sprite.x -= sprite.vx;
			sprite.y -= sprite.vy;
		}
		if (flag == 40) flag = 0;
		count = 0;
		}
		ST7735_DrawImage(sprite.x, sprite.y, sprite.w, sprite.h, sprite.image);
	}
	else {
		if(clear){
		ST7735_FillRectangle(sprite.x, sprite.y, sprite.w, sprite.h, ST7735_PURPOSE);	
		clear--;
	}
}
	if(chicken.life == alive){
		count_chicken++;
		ST7735_FillRectangle(chicken.x, chicken.y, chicken.w, chicken.h, ST7735_PURPOSE);
		Random_UpdateSeed(chicken.vx);
		chicken.vx = Random() % 4 + 1;
		chicken.vy = Random() & 4 + 1; 
		if(count_chicken == 10){
		flag_chicken++;
		if(flag_chicken < 20 || chicken.x <= 3 || chicken.y <= 9){	
			chicken.x += chicken.vx;
			chicken.y += chicken.vy;
		}	
		if ((flag_chicken >= 20 && flag_chicken < 40) || chicken.x >= 83 || chicken.y >= 100){
			chicken.x -= chicken.vx;
			chicken.y -= chicken.vy;
		}
		if (flag_chicken == 40) flag_chicken = 0;
		count_chicken = 0;
		}
		ST7735_DrawImage(chicken.x, chicken.y, chicken.w, chicken.h, chicken.image);
	}
	else {
			if(clear){
		ST7735_FillRectangle(chicken.x, chicken.y, chicken.w, chicken.h, ST7735_PURPOSE);
     clear--;
		}		
	}
		if(Hamster.life == alive){
		count_Hamster++;
		ST7735_FillRectangle(Hamster.x, Hamster.y, Hamster.w, Hamster.h, ST7735_PURPOSE);
		Random_UpdateSeed(Hamster.vx);
		Hamster.vx = Random() % 4 + 1;
		Hamster.vy = Random() & 4 + 1; 
		if(count_Hamster == 10){
		flag_Hamster++;
		if(flag_Hamster < 20 || Hamster.x <= 0 || Hamster.y <= 9){	
			Hamster.x += Hamster.vx;
			Hamster.y += Hamster.vy;
		}	
		if ((flag_Hamster >= 20 && flag_Hamster < 40) || Hamster.x >= 83 || Hamster.y >= 120){
			Hamster.x -= Hamster.vx;
			Hamster.y -= Hamster.vy;
		}
		if (flag_Hamster == 40) flag_Hamster = 0;
		count_Hamster = 0;
		}
		ST7735_DrawImage(Hamster.x, Hamster.y, Hamster.w, Hamster.h, Hamster.image);
	}
	else {
		if(clear){
		ST7735_FillRectangle(Hamster.x, Hamster.y, Hamster.w, Hamster.h, ST7735_PURPOSE);	
		clear--; 
		}
	}
}
bool Endgame(){
	return (!chicken.life)&&(!Hamster.life)&&(!sprite.life);
}