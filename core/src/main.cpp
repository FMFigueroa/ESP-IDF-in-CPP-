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
int count = 0;

extern "C" void app_main(void)
{
    ESP_LOGI(LOG_TAG, "Initialising NVS");
    ESP_ERROR_CHECK(nvs_flash_init());

    ESP_LOGI(LOG_TAG, "Creating default event loop");
    ESP_ERROR_CHECK(esp_event_loop_create_default());

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
    status |= led.init();
    return status;
}

void Main::loop(void)
{
    while (true)
    {
        ESP_LOGI(LOG_TAG, "LED on ");
        led.set(true);
        vTaskDelay(pdSECOND);

        switch (count)
        {
        case 2:
            ESP_LOGW(LOG_TAG, "Hello World!🚀");
            break;
        case 3:
            ESP_LOGW(LOG_TAG, "Hello World!🔥");
            break;
        case 4:
            ESP_LOGW(LOG_TAG, "Hello World!😎");
            count = 0;
            break;
        default:
            break;
        }

        ESP_LOGE(LOG_TAG, "LED off");
        led.set(false);
        vTaskDelay(pdSECOND);

        ++count;
    }
}