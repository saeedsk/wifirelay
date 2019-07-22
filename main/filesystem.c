

#include "esp_spiffs.h"



#if 0	
    const char* partition_label;
    esp_err_t frmt = esp_spiffs_format(&partition_label);

    ESP_LOGI(TAG, "Initializing SPIFFS");
    esp_vfs_spiffs_conf_t conf = {
      .base_path = "/spiffs",
      .partition_label = NULL,
      .max_files = 5,
      .format_if_mount_failed = true
    };

    
    esp_err_t ret = esp_vfs_spiffs_register(&conf);

    if (ret != ESP_OK) {
        if (ret == ESP_FAIL) {
            ESP_LOGE(TAG, "Failed to mount or format filesystem");
        } else if (ret == ESP_ERR_NOT_FOUND) {
            ESP_LOGE(TAG, "Failed to find SPIFFS partition");
            ESP_LOGI(TAG, "Opening file");
            FILE* f = fopen("/spiffs/laststate.txt", "w");
            if (f == NULL) {
                ESP_LOGE(TAG, "Failed to open file for writing");
                return;
            }
            fprintf(f, "[{\"relay1\":\"1\"},{\"relay2\":\"1\"},{\"relay3\":\"1\"},{\"relay4\":\"1\"}]\n");
            fclose(f);
            ESP_LOGI(TAG, "File written");
        } else {
            ESP_LOGE(TAG, "Failed to initialize SPIFFS (%s)", esp_err_to_name(ret));
        }
        return;
    }

    struct stat st;
    if (stat("/spiffs/laststate.txt", &st) == 0) {
        ESP_LOGI(TAG, "Reading file");
        FILE* f = fopen("/spiffs/laststate.txt", "r");
        if (f == NULL) {
            ESP_LOGE(TAG, "Failed to open file for reading");
            return;
        }
        char line[80];
        fgets(line, sizeof(line), f);
        fclose(f);
        ESP_LOGI(TAG, "Read from file: '%s'", line);
    }
    

    esp_vfs_spiffs_unregister(NULL);
    ESP_LOGI(TAG, "SPIFFS unmounted");
#endif    



int filesystem_init()
{
    nvs_flash_init();
    return 0;
}