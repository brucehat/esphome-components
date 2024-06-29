#include "template_binary_sensor.h"
#include "esphome/core/log.h"

namespace esphome {
namespace template_alarm_ {

static const char *const TAG = "template_alarm.binary_sensor";

void TemplateBinarySensor::setup() {

  
  if (!this->publish_initial_state_)
    return;

  if (this->f_ != nullptr) {
    this->publish_initial_state(this->f_().value_or(false));
  } else {
    this->publish_initial_state(false);
  }

}

void TemplateBinarySensor::loop() {
  if (this->f_ == nullptr)
    return;

  auto s = this->f_();
  if (s.has_value()) {
    this->publish_state(*s);
  }
}
void TemplateBinarySensor::dump_config() { LOG_BINARY_SENSOR("", "Template Alarm Binary Sensor", this); }

}  // namespace template_alarm_
}  // namespace esphome
