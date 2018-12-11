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
#define IMG_GO "GoNormal.png"
#define IMG_PLAY_BACKGROUND "Play-ground.png"
#define IMG_MENU "Menu.png"

// Image Sheep
#define IMG_SMALL_SHEEP_1 "whitesheep_1_1.png"
#define IMG_SMALL_SHEEP_2 "whitesheep_1_2.png"
#define IMG_SMALL_SHEEP_3 "whitesheep_1_3.png"
#define IMG_SMALL_SHEEP_4 "whitesheep_1_4.png"
#define IMG_MEDIUM_SHEEP_1 "whitesheep_2_1.png"
#define IMG_MEDIUM_SHEEP_2 "whitesheep_2_2.png"
#define IMG_MEDIUM_SHEEP_3 "whitesheep_2_3.png"
#define IMG_MEDIUM_SHEEP_4 "whitesheep_2_4.png"
#define IMG_BIG_SHEEP_1 "whitesheep_3_1.png"
#define IMG_BIG_SHEEP_2 "whitesheep_3_2.png"
#define IMG_BIG_SHEEP_3 "whitesheep_3_3.png"
#define IMG_BIG_SHEEP_4 "whitesheep_3_4.png"

// Image Enemy
#define IMG_SMALL_ENEMY_1 "blacksheep_1_1.png"
#define IMG_SMALL_ENEMY_2 "blacksheep_1_2.png"
#define IMG_SMALL_ENEMY_3 "blacksheep_1_3.png"
#define IMG_SMALL_ENEMY_4 "blacksheep_1_4.png"
#define IMG_MEDIUM_ENEMY_1 "blacksheep_2_1.png"
#define IMG_MEDIUM_ENEMY_2 "blacksheep_2_2.png"
#define IMG_MEDIUM_ENEMY_3 "blacksheep_2_3.png"
#define IMG_MEDIUM_ENEMY_4 "blacksheep_2_4.png"
#define IMG_BIG_ENEMY_1 "blacksheep_3_1.png"
#define IMG_BIG_ENEMY_2 "blacksheep_3_2.png"
#define IMG_BIG_ENEMY_3 "blacksheep_3_3.png"
#define IMG_BIG_ENEMY_4 "blacksheep_3_4.png"

// Map
#define LANE_0 0
#define LANE_1 1
#define LANE_2 2
#define LANE_3 3
#define LANE_4 4

#define BTN_SHEEP_LANE_0 Vec2(40, 45)
#define BTN_SHEEP_LANE_1 Vec2(40, 123)
#define BTN_SHEEP_LANE_2 Vec2(40, 198)
#define BTN_SHEEP_LANE_3 Vec2(40, 275)
#define BTN_SHEEP_LANE_4 Vec2(40, 355)

#define SHEEP_LANE_0 Vec2(M_START, 45)
#define SHEEP_LANE_1 Vec2(50, 123)
#define SHEEP_LANE_2 Vec2(50, 198)
#define SHEEP_LANE_3 Vec2(50, 275)
#define SHEEP_LANE_4 Vec2(50, 355)

#define BTN_ENEMY_LANE_0 Vec2(600, 45)
#define BTN_ENEMY_LANE_1 Vec2(600, 123)
#define BTN_ENEMY_LANE_2 Vec2(600, 198)
#define BTN_ENEMY_LANE_3 Vec2(600, 275)
#define BTN_ENEMY_LANE_4 Vec2(600, 355)

#define ENEMY_LANE_0 Vec2(750, 45)
#define ENEMY_LANE_1 Vec2(750, 123)
#define ENEMY_LANE_2 Vec2(750, 198)
#define ENEMY_LANE_3 Vec2(750, 275)
#define ENEMY_LANE_4 Vec2(750, 355)

#define M_START 50
#define M_END 760

#define DEFAULT_SCORE 0;
#define MAX_SCORE 100;

#define MAX_SHEEP 5
#define MAX_LANES 5

#define SHEEP_DIRECTION 1
#define ENEMY_DIRECTION -1

#define BIG_SHEEP_TYPE 3
#define BIG_SIZE 3
#define BIG_SIZE_HEIGHT 49
#define BIG_SIZE_WIDTH 65

#define MEDIUM_SHEEP_TYPE 2
#define MEDIUM_SIZE 2
#define MEDIUM_SIZE_HEIGHT 43
#define MEDIUM_SIZE_WIDTH 57

#define SMALL_SHEEP_TYPE 1
#define SMALL_SIZE 1
#define SMALL_SIZE_HEIGHT 43
#define SMALL_SIZE_WIDTH 57

#define SCORE_SHEEP Vec2(330, 435)
#define SCORE_ENEMY Vec2(470, 435)

#define PREDICT_SHEEP Vec2(150, 435)
#define PREDICT_ENEMY Vec2(600, 435)