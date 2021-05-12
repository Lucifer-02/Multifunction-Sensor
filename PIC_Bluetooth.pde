import processing.serial.*;
Serial serial;

int autoX, autoY;      // Position of square button
int openX, openY;  // Position of circle button
int closeX, closeY;      // Position of square button
int halfX, halfY;  // Position of circle button

int autoSize = 90;     // Diameter of rect
int openSize = 93;   // Diameter of circle
int closeSize = 93;
int halfSize = 93;

color baseColor;
color currentColor;

boolean autoOver = false;
boolean openOver = false;
boolean closeOver = false;
boolean halfOver = false;

boolean status_open = false;
boolean status_auto = false;
boolean status_close = false;
boolean status_half = false;

void setup() {
  size(640, 360);
  baseColor = color(102);
  currentColor = baseColor;

  autoX = 130;
  autoY = 50;
  openX = 430;
  openY = 100;
  closeX = 175;
  closeY = 250;
  halfX = 430;
  halfY = 250;

  ellipseMode(CENTER);
  serial = new Serial(this, "COM10", 9600); // tương tự lệnh serial. truyền vào COM3 là cổng giao tiếp, baudrate: 9600

}

void draw() {
  update(mouseX, mouseY);
  background(currentColor);
  surface.setTitle("CONTROL WINDOW WITH BLUETOOTH");//đặt tên cho task

  //--------------------
  if (autoOver) {
    fill(color(58,171,58));
  } else {
    fill(color(200));
  } 
  stroke(0);
  rect(autoX, autoY, autoSize, autoSize);
  textSize(20); // cấu hình kích thước chữ
  text("AUTO MODE", autoX - 10, autoY + 120); // tạo ký tự LIGHT  tại vị trí 280x130
  if(status_auto == true){
    textSize(32); // cấu hình kích thước chữ
    text("AUTO MODE ON", 190, 30); // tạo ký tự LIGHT  tại vị trí 280x130
  }

  //------------------------
  if (openOver) {
    fill(color(196,47,14));
  } else {
    fill(color(200));
  } 
  stroke(0);
  ellipse(openX, openY, openSize, openSize);
  textSize(20); // cấu hình kích thước chữ
  text("OPEN WINDOW", openX - 65, openY + 70); // tạo ký tự LIGHT  tại vị trí 280x130
  if(status_open == true){
    textSize(32); // cấu hình kích thước chữ
    text("OPEN WINDOW", 190, 30); // tạo ký tự LIGHT  tại vị trí 280x130

  }

  //--------------------
  if (closeOver) {
    fill(color(242,235,24));
  } else {
    fill(color(200));
  } 
  stroke(0);
  ellipse(closeX, closeY, closeSize, closeSize);
  textSize(20); // cấu hình kích thước chữ
  text("CLOSE WINDOW", closeX - 75, closeY + 70); // tạo ký tự LIGHT  tại vị trí 280x130
  if(status_close == true){
    textSize(32); // cấu hình kích thước chữ
    text("CLOSE WINDOW", 190, 30); // tạo ký tự LIGHT  tại vị trí 280x130
  }
  //-----------------------
  if (halfOver) {
    fill(color(24,242,235));
  } else {
    fill(color(200));
  } 
  stroke(0);
  ellipse(halfX, halfY, halfSize, halfSize);
  textSize(20); // cấu hình kích thước chữ
  text("HALF WINDOW", halfX - 65, halfY + 70); // tạo ký tự LIGHT  tại vị trí 280x130
  if(status_half == true){
    textSize(32); // cấu hình kích thước chữ
    text("OPEN HALF WINDOW", 150, 30); // tạo ký tự LIGHT  tại vị trí 280x130
  //--------------------------


  }

}

void update(int x, int y) {
  
  openOver = autoOver = false;
  
  if ( overOpen(openX, openY, openSize) ) {
    openOver = true;
    autoOver = false;
    halfOver = false;
    closeOver = false;

  } 
  if ( overAuto(autoX, autoY, autoSize, autoSize) ) {
    autoOver = true;
    openOver = false;
    halfOver = false;
    closeOver = false;


  } 
  if ( overClose(closeX, closeY, closeSize) ) {
    closeOver = true;
    autoOver = false;
    openOver = false;
    halfOver = false;
  } 
  if ( overHalf(halfX, halfY, halfSize) ) {
    halfOver= true;
    autoOver = false;
    openOver = false;
    closeOver = false;
  } 


}

void mousePressed() {
  if (autoOver) {
    status_auto = true;
    status_open = false;
    status_close = false;
    status_half = false;

    for(int i=0; i<10; i++)
    { 
      serial.write("A");

    }

  } 

  if (openOver) {
    status_auto = false;
    status_open = true;
    status_close = false;
    status_half = false;
    for(int i=0; i<50; i++)
    { 
      serial.write("O");

    }

  } 

  if (closeOver) {
    status_auto = false;
    status_open = false;
    status_close = true;
    status_half = false;
    for(int i=0; i<50; i++)
    { 
      serial.write("C");

    }

  } 
  if (halfOver) {
    status_auto = false;
    status_open = false;
    status_close = false;
    status_half = true;
    for(int i=0; i<30; i++)
    { 
      serial.write("H");

    }

  } 

}

boolean overAuto(int x, int y, int width, int height)  {
  if (mouseX >= x && mouseX <= x+width && 
      mouseY >= y && mouseY <= y+height) {
    return true;
  } else {
    return false;
  }
}

boolean overOpen(int x, int y, int diameter) {
  float disX = x - mouseX;
  float disY = y - mouseY;
  if (sqrt(sq(disX) + sq(disY)) < diameter/2 ) {
    return true;
  } else {
    return false;
  }
}

boolean overClose(int x, int y, int diameter) {
  float disX = x - mouseX;
  float disY = y - mouseY;
  if (sqrt(sq(disX) + sq(disY)) < diameter/2 ) {
    return true;
  } else {
    return false;
  }
}

boolean overHalf(int x, int y, int diameter) {
  float disX = x - mouseX;
  float disY = y - mouseY;
  if (sqrt(sq(disX) + sq(disY)) < diameter/2 ) {
    return true;
  } else {
    return false;
  }
}
