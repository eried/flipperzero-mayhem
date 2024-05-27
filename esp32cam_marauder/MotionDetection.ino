// Using EloquentEsp32cam library
#include <eloquent_esp32cam.h>
#include <eloquent_esp32cam/motion/detection.h>

using eloq::camera;
using eloq::motion::detection;

void motion_detection_setup() {
  camera.pinout.aithinker();
  camera.brownout.disable();
  camera.resolution.vga();
  camera.quality.high();

  // configure motion detection
  // the higher the stride, the faster the detection
  // the higher the stride, the lesser granularity
  detection.stride(1);
  // the higher the threshold, the lesser sensitivity
  // (at pixel level)
  detection.threshold(5);
  // the higher the threshold, the lesser sensitivity
  // (at image level, from 0 to 1)
  detection.ratio(0.2);
  // optionally, you can enable rate limiting (aka debounce)
  // motion won't trigger more often than the specified frequency
  detection.rate.atMostOnceEvery(5).seconds();

  // init camera
  while (!camera.begin().isOk())
      Serial.println(camera.exception.toString());

  Serial.println("Camera OK");
  Serial.println("Awaiting for motion...");
}

unsigned long nextMotionAlert = 0;

void motion_detection_loop() {
  // capture picture
  if (!camera.capture().isOk()) {
      Serial.println(camera.exception.toString());
      return;
  }

  // run motion detection
  if (!detection.run().isOk()) {
      Serial.println(detection.exception.toString());
      return;
  }

  // on motion, perform action
  if (detection.triggered() && millis()>nextMotionAlert) {
  
      Serial.println("Motion!");
      nextMotionAlert = millis()+1000;
  }
}
