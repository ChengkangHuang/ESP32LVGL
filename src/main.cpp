#include <Arduino.h>
#include <lvgl.h>
#include <AppUI/ui.h>
#include <TFT_eSPI.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 25
#define DHTTYPE DHT22
DHT_Unified dht(DHTPIN, DHTTYPE);

static const uint16_t screenWidth = 240;
static const uint16_t screenHeight = 240;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * 10];

TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

static pthread_t lvgl_mutex;

#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char *buf)
{
    Serial.printf(buf);
    Serial.flush();
}
#endif

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}

void lvgl_task(void *pvParameters)
{
    while (1)
    {
        pthread_mutex_lock(&lvgl_mutex);
        lv_task_handler();
        pthread_mutex_unlock(&lvgl_mutex);
        // Serial.println("lvgl_task core: " + String(xPortGetCoreID()));
        delay(5);
    }
}

void sensor_task(void *pvParameters)
{
    while (1)
    {
        delay(2000);
        sensors_event_t event;
        dht.temperature().getEvent(&event);
        (isnan(event.temperature)) ? Serial.println("Error reading temperature!") : Serial.print("Temperature: " + String(event.temperature) + " *C\n");
        pthread_mutex_lock(&lvgl_mutex);
        lv_arc_set_value(ui_TemperatureArc, int(round(event.temperature)));
        lv_event_send(ui_TemperatureArc, LV_EVENT_VALUE_CHANGED, NULL);
        pthread_mutex_unlock(&lvgl_mutex);

        dht.humidity().getEvent(&event);
        (isnan(event.relative_humidity)) ? Serial.println("Error reading humidity!") : Serial.print("Humidity: " + String(event.relative_humidity) + " %\n");
        pthread_mutex_lock(&lvgl_mutex);
        lv_label_set_text_fmt(ui_CurrentHumidity, "%d%%RH", int(round(event.relative_humidity)));
        pthread_mutex_unlock(&lvgl_mutex);

        // Serial.println("sensor_task core: " + String(xPortGetCoreID()));
    }
}

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);
    lv_init();
    tft.begin();
    tft.setRotation(0);
    lv_disp_draw_buf_init(&draw_buf, buf, buf, screenWidth * 10);

#if LV_USE_LOG != 0
    lv_log_register_print_cb(my_print); /* register print function for debugging */
#endif

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    ui_init();

    /*Initialize the sensor*/
    dht.begin();
    sensor_t sensor;

    /*Create tasks*/
    pthread_mutex_init(&lvgl_mutex, NULL);
    xTaskCreatePinnedToCore(lvgl_task, "lvgl_task", 4096, NULL, 1, NULL, 1);
    xTaskCreatePinnedToCore(sensor_task, "sensor_task", 4096, NULL, 1, NULL, 0);
}

void loop()
{
    // put your main code here, to run repeatedly:
}