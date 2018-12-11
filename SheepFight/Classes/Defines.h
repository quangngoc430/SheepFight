#pragma once

// Const
#define FPS 40
#define SCREEN_W 800
#define SCREEN_H 480

// Class
#define _MENU SceneMenu
#define _NEW_GAME SceneNewGame
#define _ABOUT SceneAbout
#define _OPTIONS SceneOptions

// Global Image
#define IMG_GO "Go-button.png"
#define IMG_PLAY_BACKGROUND "Play-ground.png"
#define IMG_MENU "Menu.png"

// Image Sheep
#define IMG_SHEEP_TYPE_1 "whitesheep_1.1.png"
#define IMG_SHEEP_TYPE_1_ANI "whitesheep_1.2.png"
#define IMG_SHEEP_TYPE_2 "whitesheep_2.1.png"
#define IMG_SHEEP_TYPE_2_ANI "whitesheep_2.2.png"
#define IMG_SHEEP_TYPE_3 "whitesheep_3.1.png"
#define IMG_SHEEP_TYPE_3_ANI "whitesheep_3.2.png"

// Image Enemy
#define IMG_ENEMY_TYPE_1 "blacksheep_1.1.png"
#define IMG_ENEMY_TYPE_1_ANI "blacksheep_1.2.png"
#define IMG_ENEMY_TYPE_2 "blacksheep_2.1.png"
#define IMG_ENEMY_TYPE_2_ANI "blacksheep_2.2.png"
#define IMG_ENEMY_TYPE_3 "blacksheep_3.1.png"
#define IMG_ENEMY_TYPE_3_ANI "blacksheep_3.2.png"

// Map
#define LANE_0 0
#define LANE_1 1
#define LANE_2 2
#define LANE_3 3
#define LANE_4 4

#define BTN_SHEEP_LANE_0 Vec2(50, 65)
#define BTN_SHEEP_LANE_1 Vec2(50, 135)
#define BTN_SHEEP_LANE_2 Vec2(50, 205)
#define BTN_SHEEP_LANE_3 Vec2(50, 275)
#define BTN_SHEEP_LANE_4 Vec2(50, 345)

#define SHEEP_LANE_0 Vec2(50, 65)
#define SHEEP_LANE_1 Vec2(50, 135)
#define SHEEP_LANE_2 Vec2(50, 205)
#define SHEEP_LANE_3 Vec2(50, 275)
#define SHEEP_LANE_4 Vec2(50, 345)

#define BTN_ENEMY_LANE_0 Vec2(600, 65)
#define BTN_ENEMY_LANE_1 Vec2(600, 135)
#define BTN_ENEMY_LANE_2 Vec2(600, 205)
#define BTN_ENEMY_LANE_3 Vec2(600, 275)
#define BTN_ENEMY_LANE_4 Vec2(600, 345)

#define ENEMY_LANE_0 Vec2(600, 65)
#define ENEMY_LANE_1 Vec2(600, 135)
#define ENEMY_LANE_2 Vec2(600, 205)
#define ENEMY_LANE_3 Vec2(600, 275)
#define ENEMY_LANE_4 Vec2(600, 345)

#define mStart 50
#define mEnd 750
#define mMiddle 400

#define MAX_SHEEP 5
#define MAX_LANES 5

#define SHEEP_DIRECTION 1
#define ENEMY_DIRECTION -1

#define BIG_SHEEP_TYPE 3
#define BIG_SIZE 3
#define BIG_SIZE_HEIGHT 48
#define BIG_SIZE_WIDTH 48

#define MEDIUM_SHEEP_TYPE 2
#define MEDIUM_SIZE 2
#define MEDIUM_SIZE_HEIGHT 48
#define MEDIUM_SIZE_WIDTH 48

#define SMALL_SHEEP_TYPE 1
#define SMALL_SIZE 1
#define SMALL_SIZE_HEIGHT 48
#define SMALL_SIZE_WIDTH 48

#define SCORE_SHEEP Vec2(330, 435)
#define SCORE_ENEMY Vec2(470, 435)

#define PREDICT_SHEEP Vec2(150, 435)
#define PREDICT_ENEMY Vec2(600, 435)