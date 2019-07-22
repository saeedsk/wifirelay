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

#include "log.h"
#include "controller.h"
#include "gpio.h"
#include "mqtt.h"
#include "filesystem.h"
#include "log.h"



void app_main()
{
    log_init();

    ESP_LOGE(TAG, "[APP] Startup..");

    show_system_stats();
    filesystem_init();
    wifi_init();
    mqtt_init();
    mqtt_app_start();
    
}