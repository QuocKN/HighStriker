#include <gui/screen1_screen/Screen1View.hpp>
#include "stm32f4xx_hal.h"

extern UART_HandleTypeDef huart1;
Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::updateCurrentScore(int32_t value) // nhận dữ liệu từ Presenter
{
//	HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_13);
//  HAL_UART_Transmit(&huart1, (uint8_t*)currentScoreBuffer, CURRENTSCORE_SIZE, HAL_MAX_DELAY);
	if (value < 0)  // -1là ẩn
	{
	    Unicode::snprintf(currentScoreBuffer, sizeof(currentScoreBuffer), "");
	}
	else
	{
	    Unicode::snprintf(currentScoreBuffer, sizeof(currentScoreBuffer), "%d", value);
	}
	currentScore.invalidate();
}


void Screen1View::updateHighScore(int32_t value)
{
	if (value < 0)  // -1 là ẩn
	{
	    Unicode::snprintf(highScoreBuffer, sizeof(highScoreBuffer), "");
	}else{
		Unicode::snprintf(highScoreBuffer, sizeof(highScoreBuffer), "%d", value);
	}
	highScore.invalidate();
}
