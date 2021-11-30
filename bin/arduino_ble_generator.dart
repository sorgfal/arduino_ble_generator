import 'dart:io';

import 'package:arduino_ble_generator/arduino_code_builder.dart';
import 'package:arduino_ble_generator/property_item.dart';

var properties = [
  PropertyItem('name', String),
  PropertyItem('battery', int, notifiable: true, writable: true),
  PropertyItem('lbowlstate', int, notifiable: true, writable: true),
  PropertyItem('lbowlprocess', String, notifiable: true, writable: true),
  PropertyItem('lbowlspeed', int, notifiable: true, writable: true),
  PropertyItem('lbowltherm', int, notifiable: true, writable: true),
  PropertyItem('lbowlamode', int, notifiable: true, writable: true),
  PropertyItem('lbowltimer', String, notifiable: true, writable: true),
  PropertyItem('rbowlstate', int, notifiable: true, writable: true),
  PropertyItem('rbowlprocess', String, notifiable: true, writable: true),
  PropertyItem('rbowlspeed', int, notifiable: true, writable: true),
  PropertyItem('rbowltherm', int, notifiable: true, writable: true),
  PropertyItem('rbowlamode', int, notifiable: true, writable: true),
  PropertyItem('rbowltimer', String, notifiable: true, writable: true),
  PropertyItem('ftubestate', int, notifiable: true, writable: true),
  PropertyItem('ftubebattery', int, notifiable: true, writable: true),
  PropertyItem('stubestate', int, notifiable: true, writable: true),
  PropertyItem('stubebattery', int, notifiable: true, writable: true),
  PropertyItem('ttubestate', int, notifiable: true, writable: true),
  PropertyItem('ttubebattery', int, notifiable: true, writable: true),
];

void main() {
  var generatedCode =
      ArduinoFirmwareGenerator(ArduinoCodeBuilder(properties)).build();
  File('./ble_generated.c').writeAsStringSync(generatedCode);
}
