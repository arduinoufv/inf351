/// Author: Raphael Nepomuceno <raphael.nepomuceno@protonmail.com>

// Tetris {{{



#define TETRIS_COLS (12)
#define TETRIS_ROWS (12)

#define MAX_AREA (2 * 3)

typedef unsigned char byte;

typedef struct {
  byte r;
  byte g;
  byte b;
} color_t;

typedef struct {
  bool points[MAX_AREA];

  byte cols;
  byte rows;
} block_shape_t;

typedef struct {
  block_shape_t shape;

  byte x;
  byte y;

  color_t color;
} block_t;

typedef struct {
  bool set;
  color_t color;
} tile_t;

typedef struct {
  tile_t tiles[TETRIS_COLS * TETRIS_ROWS];

  byte cols;
  byte rows;
} worldt;

/// Resets the state for the specified world.
void new_world(worldt *world) {
  for (byte i = 0; i < world->rows * world->cols; ++i)
    world->tiles[i].set = false;
}

/// Resets the state for the specified block.
void new_block(block_t *block, byte type) {
  block->x = 0;
  block->y = 0;

  switch (type) {
  case 0:
    block->color = (color_t){0x00, 0xFF, 0xFF};
    block->shape = (block_shape_t){
        .points = {1, 1, 1, 1},
        .cols = 4,
        .rows = 1,
    };
    break;

  case 1:
    block->color = (color_t){0x00, 0x00, 0xFF};
    block->shape = (block_shape_t){
        .points = {1, 0, 0, 1, 1, 1},
        .cols = 3,
        .rows = 2,
    };
    break;

  case 2:
    block->color = (color_t){0xFF, 0x80, 0x00};
    block->shape = (block_shape_t){
        .points = {0, 0, 1, 1, 1, 1},
        .cols = 3,
        .rows = 2,
    };
    break;

  case 3:
    block->color = (color_t){0xFF, 0xFF, 0x00};
    block->shape = (block_shape_t){
        .points = {1, 1, 1, 1},
        .cols = 2,
        .rows = 2,
    };
    break;

  case 4:
    block->color = (color_t){0x00, 0xFF, 0x00};
    block->shape = (block_shape_t){
        .points = {0, 1, 1, 1, 1, 0},
        .cols = 3,
        .rows = 2,
    };
    break;

  case 5:
    block->color = (color_t){0xFF, 0x00, 0xFF};
    block->shape = (block_shape_t){
        .points = {0, 1, 0, 1, 1, 1},
        .cols = 3,
        .rows = 2,
    };
    break;

  case 6:
    block->color = (color_t){0xFF, 0x00, 0x00};
    block->shape = (block_shape_t){
        .points = {1, 1, 0, 0, 1, 1},
        .cols = 3,
        .rows = 2,
    };
    break;
  }
}

/// Rotates a block 90 degrees counter-clockwise.
void rotate(block_shape_t *shape) {
  bool buf[MAX_AREA];

  byte rows = shape->rows;
  byte cols = shape->cols;

  for (byte y = 0; y < rows; ++y)
    for (byte x = 0; x < cols; ++x)
      // Mirror and transpose.
      buf[x * rows + y] =
          shape->points[y * cols + (cols - 1 - x)]; // (x, y) <- (y, w - 1 - x)

  for (byte i = 0; i < MAX_AREA; ++i)
    shape->points[i] = buf[i];

  shape->rows = cols;
  shape->cols = rows;
}

/// Checks if a block touches any other set tile directly below it.
bool touches(const block_t *block, const worldt *world, const byte dx,
             const byte dy) {
  for (byte y = 0; y < block->shape.rows; ++y)
    for (byte x = 0; x < block->shape.cols; ++x) {
      byte wy = block->y + y + dy;
      byte wx = block->x + x + dx;

      byte block_pos = y * block->shape.cols + x;
      byte world_pos = wy * world->cols + wx;

      // Block touches the floor.
      if (wy >= world->rows)
        return true;

      // Block touches the walls.
      if (wx >= world->cols || wx < 0)
        return true;

      if (world->tiles[world_pos].set && block->shape.points[block_pos])
        return true;
    }

  return false;
}

/// Transforms a block into a world tile.
void paste(const block_t *block, worldt *world) {
  for (byte y = 0; y < block->shape.rows; ++y) {
    for (byte x = 0; x < block->shape.cols; ++x) {
      byte wy = block->y + y;
      byte wx = block->x + x;

      byte pos = wy * world->cols + wx;

      if (block->shape.points[y * block->shape.cols + x]) {
        world->tiles[pos].set = true;
        world->tiles[pos].color = block->color;
      }
    }
  }
}

/// Checks if all tiles in the specified row are set.
bool is_dirty_row(worldt *world, byte row) {
  bool dirty = true;
  byte pos = row * world->cols;

  for (byte x = 0; x < world->cols; ++x)
    dirty &= world->tiles[pos + x].set;

  return dirty;
}

/// Shifts all rows, until floor_, down by 1. Row 0 is unset.
void shift_down(worldt *world, byte floor_) {
  for (char y = floor_ - 1; y >= 0; --y) {
    byte row = y * world->cols;
    byte below = (y + 1) * world->cols;

    for (byte x = 0; x < world->cols; ++x)
      world->tiles[below + x] = world->tiles[row + x];
  }

  // Unset all tiles in row 0.
  for (byte x = 0; x < world->cols; ++x)
    world->tiles[x].set = false;
}

/// Cleans up fully set rows.
void cleanup(worldt *world) {
  for (byte y = 0; y < world->rows;)
    if (is_dirty_row(world, y))
      shift_down(world, y);
    else
      ++y;
}
// }}}


#include <ESP8266WiFi.h>
#include <PubSubClient.h>

long randNumber;


//const char* ssid = "moto g(7) 4767";
//const char* password = "arduino351";

// ADM_DPI             professoresDp1
// dpi-mestrado     DLrVk89XYj

const char* ssid = "dpi-mestrado2";
const char* password = "vbmuGDxY1e";



//const char* ssid = "416-DPI";
//const char* password = "ag21sRJOBt";




const char* mqtt_server = "broker.mqtt-dashboard.com";  // Public Broker, pay attention in topics to avoid conflicts

#define MQTTPORT 1883
#define UP "tetris/up"
#define DOWN "tetris/down"
#define LEFT "tetris/left"
#define RIGHT "tetris/right"

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
/*****
 * Add two pushbutton subscribe. You could add more controls....
 */
      // ... and resubscribe
       client.subscribe(UP);
      client.subscribe(DOWN);
          client.subscribe(LEFT);
      client.subscribe(RIGHT);
      
/*******************************************************/      
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}




#include <Adafruit_NeoPixel.h>

#define LED_PIN (D3)

#define ROWS (12)
#define COLS (12)

#define MS_PER_TICK (300)


Adafruit_NeoPixel pixels =
    Adafruit_NeoPixel(ROWS * COLS, LED_PIN, NEO_GRB + NEO_KHZ800);

// LED helper {{{

/// Lights up a pixel.
void set_pixel(int x, int y, int r, int g, int b) {
  // Odd rows are counted backwartds.
  if (y % 2 == 1)
    x = (COLS - 1) - x;

  pixels.setPixelColor(COLS * y + x, pixels.Color(r, g, b));
}
// }}}

byte mqtt_input=66;

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  String Topic(topic);
  Serial.print(Topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

   mqtt_input = 66;

  if ( Topic.equals(UP) ) {
    mqtt_input = 65;
  }
  if ( Topic.equals(DOWN) ) {
    mqtt_input = 66;
  }
  if ( Topic.equals(LEFT) ) {
    mqtt_input = 68;
  }
  if ( Topic.equals(RIGHT) ) {
    mqtt_input = 67;
  }

  if (mqtt_input != 66) Serial.println(mqtt_input);

}




      

long lastMsg;


void setup() {
 Serial.begin(115200);
   setup_wifi();
  client.setServer(mqtt_server, MQTTPORT);
  client.setCallback(callback);
  lastMsg = 0;
  
  pixels.begin();
  randomSeed(analogRead(0));

  block_t block;
  worldt world;

  world.cols = TETRIS_COLS;
  world.rows = TETRIS_ROWS;

  new_block(&block, random(0, 7));
  new_world(&world);


  pinMode(D5,INPUT_PULLUP);
  pinMode(D6,INPUT_PULLUP);
  pinMode(D7,INPUT_PULLUP);
  pinMode(D1,INPUT_PULLUP);
   Serial.println("inicio teste botoes");
for (int i = 0; i < 1000; i++) {
  delay(50);
  if ( digitalRead(D5) == LOW) Serial.println("D5");
  if ( digitalRead(D6) == LOW) Serial.println("D6");
  if ( digitalRead(D7) == LOW) Serial.println("D7");
  if ( digitalRead(D1) == LOW) Serial.println("D1");
  
}
  Serial.println("fim teste botoes");
  byte input;

  while (true) {
    if (!client.connected()) {
    reconnect();
    }
    client.loop();


    if (block.y == 0 && touches(&block, &world, 0, 0)) {
      new_block(&block, random(0, 7));
      new_world(&world);
    }

    // Simulate random input.
    input = mqtt_input;

    move(&block, &world, input);

    if (touches(&block, &world, 0, 1)) {
      paste(&block, &world);
      new_block(&block, random(0, 7));
    }

    // Draw
    draw_world(&world);
    draw_block(&block);

    pixels.show();
    delay(MS_PER_TICK);
  }
}

void loop() {}

bool move(block_t *block, worldt *world, byte input) {
  switch (input) {
  case 65:
    rotate(&block->shape);
    if (touches(block, world, 0, 0) == false)
      return true;
    else {
      rotate(&block->shape);
      rotate(&block->shape);
      rotate(&block->shape);
    }

  case 66:
    if (touches(block, world, 0, 1) == false) {
      block->y += 1;
      return true;
    }

  case 68:
    if (touches(block, world, -1, 0) == false) {
      block->x -= 1;
      return true;
    }

  case 67:
    if (touches(block, world, 1, 0) == false) {
      block->x += 1;
      return true;
    }
  }

  return false;
}

/// Draws the game state.
void draw_world(worldt *world) {
  tile_t tile;

  for (byte y = 0; y < world->rows; ++y)
    for (byte x = 0; x < world->cols; ++x) {
      tile = world->tiles[y * world->cols + x];

      if (tile.set)
        set_pixel(x, y, tile.color.r, tile.color.g, tile.color.b);
      else
        set_pixel(x, y, 0, 0, 0);
    }
}

void draw_block(block_t *block) {
  for (byte y = 0; y < block->shape.rows; ++y)
    for (byte x = 0; x < block->shape.cols; ++x)
      if (block->shape.points[y * block->shape.cols + x])
        set_pixel(block->x + x, block->y + y, block->color.r, block->color.g,
                  block->color.b);
      else
        set_pixel(block->x + x, block->y + y, 0, 0, 0);
}
