import 'dart:io';

import 'package:arduino_ble_generator/arduino_code_builder.dart';
import 'package:arduino_ble_generator/property_item.dart';

var properties = [
  PropertyItem('name', String),
  PropertyItem('battery', int, notifiable: true, writable: true),
];

void main(List<String> args) {
  File outputFile = File(args.isNotEmpty ? args.first : "./out/firmware.c");
  var generatedCode =
      ArduinoFirmwareGenerator(ArduinoCodeBuilder(properties)).build();
  if (!outputFile.existsSync()) {
    outputFile.createSync(recursive: true);
  }
  outputFile.writeAsStringSync(generatedCode);
}
