#ifndef _SPACEINVADERS_H_
#define _SPACEINVADERS_H_

#include "stdint.h"
#include "image.h"
#include "Timer.h"
#include "st7735.h"
#include "Random.h"
#include "UART.h"

extern uint8_t endGame;
extern bool Endgame();
typedef enum {dead, alive} status_t;
extern uint8_t spacestone_x[3];
extern uint8_t spacestone_y[3];
extern uint8_t stars_vip_x[12];
extern uint8_t stars_vip_y[12];
extern uint8_t dynamic_stars_x_3;
extern uint8_t dynamic_stars_y_3;
extern uint8_t dynamic_stars_x_1;
extern uint8_t dynamic_stars_y_1;
extern uint8_t dynamic_stars_x_2;
extern uint8_t dynamic_stars_y_2;
extern uint8_t dynamic_stars_x_4;
extern uint8_t dynamic_stars_y_4;
extern int16_t f ;
extern int16_t ddF_x;
extern int16_t ddF_y;
extern int32_t dynamic_hole_x;
extern int32_t dynamic_hole_y;
extern int32_t button1;
extern uint16_t current_fill_level;
void menu_loading();
// Sprite struct
typedef struct {
	int32_t x; // x coordinate
	int32_t y; // y coordinate
	int32_t vx,vy; // pixels/30Hz
	status_t life;
	const unsigned short *image; // ptr->image
	const unsigned short *black; 
	int32_t w; // width
	int32_t h; // height
//	uint32_t needDraw; // true if need to draw
}Sprite;
typedef struct {
	int32_t x; // x coordinate
	int32_t y; // y coordinate
	int32_t vx,vy; // pixels/30Hz
	status_t life;
	const unsigned short *image; // ptr->image
	const unsigned short *black; 
	int32_t w; // width
	int32_t h; // height
	bool clear;
//	uint32_t needDraw; // true if need to draw
}element;
// Bullet struct 
typedef struct{
	int32_t x; // x coordinate
	int32_t y; // y coordinate
	int32_t x1; // x coordinate
	int32_t y1; // y coordinate
	int32_t x2; // x coordinate
	int32_t y2; // y coordinate
	const unsigned short * image;
	const unsigned short * black;
	int32_t w; // width
	int32_t h; // height
	uint8_t collisionDetected; // collision detection
	uint8_t leftGameArea; // pass out of the game area
	uint8_t leftGameArea1; // pass out of the game area
	uint8_t leftGameArea2; // pass out of the game area
	uint8_t number_bullet;
}Bullet;

// Battleship struct
typedef struct {
	int32_t x; // x coordinate
	int32_t y; // y coordinate
	const unsigned short * image;
	const unsigned short * black;
	int32_t w; // width
	int32_t h; // height
	status_t life;
	Bullet bullet; // bullet
}Battleship;

// Initialize battelship 1
void battleshipInit_1(Battleship* battleship);
//
void background_init();
// Initialize battelship 2
void battleshipInit_2(Battleship* battleship);

// Battleship 1 move
void battleshipMove(Battleship* battleship);

// Battleship 2 move
void battleshipMove_2(Battleship* battleship);

// Initialize bullet 1
void battleshipBulletInit(Battleship* battleship);

// Initialize bullet 2
void battleshipBulletInit_2(Battleship* battleship);

// Bullet 1 move
void battleshipBulletMove(Battleship* battleship);
void battleshipBulletMove_1(Battleship* battleship);
void battleshipBulletMove_2(Battleship* battleship);
// Bullet 2 move
//void battleshipBulletMove_2(Battleship* battleship);

// Handle collision
void handleCollision(Battleship* battleship_1, Battleship* battleship_2);

// Initialize sprite
void spriteInit(void);
void recover_fire();
void recover_water();
// Sprite move
void spriteMove(Battleship* battleship,Battleship* battleship1);
//
void init_fire();
void move_fire(Battleship* battleship1,Battleship* battleship2);
void init_water();
void move_water(Battleship* battleship1,Battleship* battleship2);
void Initbullet(Battleship* battleship1,Battleship* battleship2);
//
void planet_1();
void planet_2();
void planet_3();
void changestate();
//
void stars_1();
void stars_2();
void stars_3();
void stars_4();
void saobang();
void stars_vip();
//
void stars_walk_1();
void stars_walk_2();
void stars_walk_3();
void stars_walk_4();
//
void background();
void menu();
//
void hole();
//
void spacestones();
#endif /*_SPACEINVADERS_H_*/