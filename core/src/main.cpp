/**
 * @file main.cpp
 * @author FMFigueroa (felixmanuelfigueroa@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-08-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "main.h"
// Deficion de un nivel de registro local antes de usar "esp_log.h"
#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "MAIN"

static Main my_main;
u_int count = 0;

extern "C" void app_main(void)
{

    ESP_ERROR_CHECK(my_main.setup());

    while (true)
    {
        my_main.loop();
    }
}

esp_err_t Main::setup(void)
{
    esp_err_t status{ESP_OK};
    ESP_LOGW(LOG_TAG, "Setup function oK 👌");
    return status;
}

void Main::loop(void)
{
    while (true)
    {
        vTaskDelay(pdSECOND);

        if (count > 30)
        {
            count = 0;
        }
        if (count < 10)
        {
            ESP_LOGI(LOG_TAG, "Hello World!🚀");
        }
        if (count >= 10 && count < 20)
        {
            ESP_LOGW(LOG_TAG, "Hello World!🚀");
        }
        if (count >= 20)
        {
            ESP_LOGE(LOG_TAG, "Hello World!🚀");
        }

        ++count;
    }
}