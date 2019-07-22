#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "esp_system.h"
#include "esp_event_loop.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"
#include "freertos/event_groups.h"

#include "lwip/sockets.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"


#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_err.h"


const static int CONNECTED_BIT = BIT0;


bool value1 = 0;
bool value2 = 0;
bool value3 = 0;
bool value4 = 0;



void app_main()
{

    gpio_config_t io_conf;
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    //bit mask of the pins that you want to set,e.g.GPIO2/16
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    //disable pull-down mode
    io_conf.pull_down_en = 0;
    //disable pull-up mode
    io_conf.pull_up_en = 0;
    //configure GPIO with the given settings
    gpio_config(&io_conf);

    
     
    ESP_LOGE(TAG, "[APP] Startup..");
    ESP_LOGI(TAG, "[APP] Free memory: %d bytes", esp_get_free_heap_size());
    ESP_LOGI(TAG, "[APP] IDF version: %s", esp_get_idf_version());

    esp_log_level_set("*", ESP_LOG_ERROR);
    esp_log_level_set("MQTT_CLIENT", ESP_LOG_ERROR);
    esp_log_level_set("TRANSPORT_TCP", ESP_LOG_ERROR);
    esp_log_level_set("TRANSPORT_SSL", ESP_LOG_ERROR);
    esp_log_level_set("TRANSPORT", ESP_LOG_ERROR);
    esp_log_level_set("OUTBOX", ESP_LOG_ERROR);

    nvs_flash_init();
    wifi_init();
    mqtt_app_start();
    
}