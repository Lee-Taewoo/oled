/*
 * app.c
 *
 *  Created on: Jan 16, 2025
 *      Author: user
 */

#include "app.h"

// 외부 장치 선언
extern UART_HandleTypeDef huart2;
extern I2C_HandleTypeDef hi2c1;

void app() {
	// uart 초기화
	initUart(&huart2);
	// ssd1306 초기화
	ssd1306_Init();
	ssd1306_Fill(0);
	ssd1306_SetCursor(0, 0);
	ssd1306_WriteString("Hello World", Font_7x10, 1);
	ssd1306_SetCursor(0, 10);
	ssd1306_WriteString("1234567890", Font_7x10, 1);
	ssd1306_UpdateScreen();
	ssd1306_SetContrast(255);
	while(1) {
		ssd1306_Fill(0);
		static int x = 0;
		ssd1306_Line(x, 0, x, 63, 1);
		x++;
		x %= 128;
		ssd1306_UpdateScreen();
		HAL_Delay(100);
	}
}
