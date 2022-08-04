#include <pebble.h>

static Window *s_main_window;
static TextLayer *s_time_layer;
static TextLayer *s_today_layer;
static TextLayer *s_month_layer;
static TextLayer *s_weather_layer;
static TextLayer *s_humidity_layer;
static TextLayer *s_conditions_layer;

static RotBitmapLayer *s_wind_layer;
static BitmapLayer *s_background_layer;

static GBitmap *s_wind_direction;
static GBitmap *s_background_bitmap;

static void inbox_received_callback(DictionaryIterator *iter, void *context) {
  static char temperature_buffer[8];
  static char humidity_buffer[8];
  static char conditions_buffer[32];
  static char wind_direction_buffer[8];

  Tuple *temp_tuple = dict_find(iter, MESSAGE_KEY_TEMPERATURE);
  Tuple *humidity_tuple = dict_find(iter, MESSAGE_KEY_HUMIDITY);
  Tuple *conditions_tuple = dict_find(iter, MESSAGE_KEY_CONDITIONS);
  Tuple *direction_tuple = dict_find(iter, MESSAGE_KEY_WIND_DIRECTION);

  snprintf(temperature_buffer, sizeof(temperature_buffer), "%d°", (int)temp_tuple->value->int32);
  text_layer_set_text(s_weather_layer, temperature_buffer);
  snprintf(humidity_buffer, sizeof(humidity_buffer), "%d%%", (int)humidity_tuple->value->int32);
  text_layer_set_text(s_humidity_layer, humidity_buffer);
  snprintf(conditions_buffer, sizeof(conditions_buffer), "%s", conditions_tuple->value->cstring);
  text_layer_set_text(s_conditions_layer, conditions_buffer);
  snprintf(wind_direction_buffer, sizeof(wind_direction_buffer), "%d", (int)direction_tuple->value->int32);
  // rot_bitmap_layer_set_angle(s_wind_layer, wind_direction_buffer);
}

static void inbox_dropped_callback(AppMessageResult reason, void *context) {
  APP_LOG(APP_LOG_LEVEL_ERROR, "Message dropped!");
}

static void outbox_failed_callback(DictionaryIterator *iter, AppMessageResult reason, void *context) {
  APP_LOG(APP_LOG_LEVEL_ERROR, "Outbox send failed!");
}

static void outbox_sent_callback(DictionaryIterator *iter, void *context) {
  APP_LOG(APP_LOG_LEVEL_INFO, "Outbox send success!");
}

static void update_time() {
  time_t temp = time(NULL);
  struct tm *tick_time = localtime(&temp);

  static char time_buffer[8];
  static char date_buffer[8];
  static char month_buffer[8];
  strftime(time_buffer, sizeof(time_buffer), clock_is_24h_style() ? "%H:%M" : "%I:%M", tick_time);
  strftime(date_buffer, sizeof(date_buffer), "%e", tick_time);
  strftime(month_buffer, sizeof(month_buffer), "%b", tick_time);

  text_layer_set_text(s_time_layer, time_buffer);
  text_layer_set_text(s_today_layer, date_buffer);
  text_layer_set_text(s_month_layer, month_buffer);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time();
}


static void main_window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);


  s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BACKGROUND);
  s_background_layer = bitmap_layer_create(bounds);
  bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_background_layer));

  // s_wind_direction = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_WIND_DIRECTION);
  // s_wind_layer = rot_bitmap_layer_create(s_wind_direction);
  // layer_add_child(window_layer, bitmap_layer_get_layer(s_wind_layer));

  s_time_layer = text_layer_create(GRect(108, 76, 28, 14));
  text_layer_set_background_color(s_time_layer, GColorClear);
  text_layer_set_text_color(s_time_layer, GColorGreen);
  text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_GOTHIC_14));
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(s_time_layer));

  s_today_layer = text_layer_create(GRect(56, 150, 24, 14));
  text_layer_set_background_color(s_today_layer, GColorClear);
  text_layer_set_text_color(s_today_layer, GColorWhite);
  text_layer_set_font(s_today_layer, fonts_get_system_font(FONT_KEY_GOTHIC_14));
  text_layer_set_text_alignment(s_today_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(s_today_layer));

  s_month_layer = text_layer_create(GRect(-4, 76, 24, 14));
  text_layer_set_background_color(s_month_layer, GColorClear);
  text_layer_set_text_color(s_month_layer, GColorWhite);
  text_layer_set_font(s_month_layer, fonts_get_system_font(FONT_KEY_GOTHIC_14));
  text_layer_set_text_alignment(s_month_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(s_month_layer));
  

  s_weather_layer = text_layer_create(GRect(-8, 135, 48, 28));
  text_layer_set_background_color(s_weather_layer, GColorClear);
  text_layer_set_text_color(s_weather_layer, GColorMagenta);
  text_layer_set_font(s_weather_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24));
  text_layer_set_text_alignment(s_weather_layer, GTextAlignmentCenter);
  text_layer_set_text(s_weather_layer, "--");
  layer_add_child(window_layer, text_layer_get_layer(s_weather_layer));

  s_humidity_layer = text_layer_create(GRect(102, 135, 48, 28));
  text_layer_set_background_color(s_humidity_layer, GColorClear);
  text_layer_set_text_color(s_humidity_layer, GColorCyan);
  text_layer_set_font(s_humidity_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24));
  text_layer_set_text_alignment(s_humidity_layer, GTextAlignmentCenter);
  text_layer_set_text(s_humidity_layer, "--%");
  layer_add_child(window_layer, text_layer_get_layer(s_humidity_layer));

  s_conditions_layer = text_layer_create(GRect(-14, 0, 76, 32));
  text_layer_set_background_color(s_conditions_layer, GColorClear);
  text_layer_set_text_color(s_conditions_layer, GColorGreen);
  text_layer_set_font(s_conditions_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18));
  text_layer_set_text_alignment(s_conditions_layer, GTextAlignmentCenter);
  text_layer_set_text(s_conditions_layer, "COND");
  layer_add_child(window_layer, text_layer_get_layer(s_conditions_layer));

}

static void main_window_unload(Window *window) {
  text_layer_destroy(s_time_layer);
  text_layer_destroy(s_today_layer);
  text_layer_destroy(s_month_layer);
  text_layer_destroy(s_weather_layer);
  text_layer_destroy(s_humidity_layer);
  text_layer_destroy(s_conditions_layer);
  bitmap_layer_destroy(s_background_layer);
  rot_bitmap_layer_destroy(s_wind_layer);
  gbitmap_destroy(s_wind_direction);
  gbitmap_destroy(s_background_bitmap);
}

static void init() {
  s_main_window = window_create();

  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
  window_set_window_handlers (s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  app_message_register_inbox_received(inbox_received_callback);
  app_message_register_inbox_dropped(inbox_dropped_callback);
  app_message_register_outbox_failed(outbox_failed_callback);
  app_message_register_outbox_sent(outbox_sent_callback);

  const int inbox_size = 128;
  const int outbox_size = 128;
  app_message_open(inbox_size, outbox_size);

  window_stack_push(s_main_window, true);
  update_time();
}

static void deinit() {
  window_destroy(s_main_window);
}

int main (void) {
  init();
  app_event_loop();
  deinit();
}