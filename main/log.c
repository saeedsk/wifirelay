
#include "esp_log.h"

static const char *TAG = "MQTT_EXAMPLE";


int log_init()
{


    esp_log_level_set("*", ESP_LOG_ERROR);
    esp_log_level_set("MQTT_CLIENT", ESP_LOG_ERROR);
    esp_log_level_set("TRANSPORT_TCP", ESP_LOG_ERROR);
    esp_log_level_set("TRANSPORT_SSL", ESP_LOG_ERROR);
    esp_log_level_set("TRANSPORT", ESP_LOG_ERROR);
    esp_log_level_set("OUTBOX", ESP_LOG_ERROR);
    
    return 0;
}