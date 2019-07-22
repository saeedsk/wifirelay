
const static int CONNECTED_BIT = BIT0;


bool value1 = 0;
bool value2 = 0;
bool value3 = 0;
bool value4 = 0;


int show_system_stats()
{
    ESP_LOGI(TAG, "[APP] Free memory: %d bytes", esp_get_free_heap_size());
    ESP_LOGI(TAG, "[APP] IDF version: %s", esp_get_idf_version());
    return 0;    
}
