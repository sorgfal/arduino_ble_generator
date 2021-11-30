import 'package:arduino_ble_generator/property_item.dart';
part "arduino_firmware_generator.dart";

class ArduinoCodeBuilder {
  final List<PropertyItem> properties;

  ArduinoCodeBuilder(this.properties);

  String _generateConstDefinitions() {
    String result = "\n// UUID CONST DEFINITION \n";
    for (var prop in properties) {
      result += prop.getUUIDConstantDefinition();
      result += "\n";
    }
    result += "//  END UUID CONST DEFINITION \n";
    return result;
  }

  String _generateBLECharacteristicPointerDefinitions() {
    String result = "\n// BLECharacteristic Pointer Definitions \n";
    for (var prop in properties) {
      result += prop.getBLECharacteristicPointerDefinition();
      result += "\n";
    }
    result += "//  END BLECharacteristic Pointer Definitions  \n";
    return result;
  }

  String _generateCallbackDefinitions() {
    String result = "\n// Callbacks  Definitions \n";
    for (var prop in properties) {
      result += prop.getCallbacksClassDefinition();
      result += "\n";
    }
    result += "//  END Callbacks  Definitions  \n";
    return result;
  }

  String _generateCharacteristicAssignmentDefinitions() {
    String result = "\n//Characteristic Assignment Definitions \n";
    for (var prop in properties) {
      result += prop.getCharacteristicAssignment();
    }
    result += "//  END Characteristic Assignment Definitions  \n";
    return result;
  }

  String generateAll() {
    String result = "";
    result += _generateConstDefinitions();
    result += _generateBLECharacteristicPointerDefinitions();
    result += _generateCallbackDefinitions();
    result += _generateCharacteristicAssignmentDefinitions();
    return result;
  }
}
