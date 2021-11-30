import 'package:uuid/uuid.dart';

class PropertyItem {
  /// Семантичное название свойства
  final String name;

  /// [type] Тип может быть bool, int, String
  final Type type;

  /// [writable] Можно ли внешним устройствам записывать значение характеристики
  final bool writable;

  /// [notifiable] Можно ли подписываться на изменение значения характеристики
  final bool notifiable;
  late String uuid;
  PropertyItem(this.name, this.type,
      {this.writable = false, this.notifiable = false}) {
    uuid = Uuid().v4();
  }

  String get _uuidConstName => name.toUpperCase() + "_UUID";
  String get _propertyPointerName => "${name}Prop";

  String get _propertyCallbackClassName => "C${_propertyPointerName}Callbacks";

  String getUUIDConstantDefinition() {
    return '#define $_uuidConstName "$uuid"';
  }

  String getBLECharacteristicPointerDefinition() {
    return "BLECharacteristic *$_propertyPointerName;";
  }

  bool get hasCallback => writable;

  String getCallbacksClassDefinition() {
    if (!hasCallback) {
      return "";
    }
    return '''class $_propertyCallbackClassName : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rawValue = pCharacteristic->getValue();
    ${type == int ? 'int value = atoi(rawValue.c_str());' : ""}${type == String ? 'const char* value = rawValue.c_str();' : ""}${type == bool ? 'bool value = atoi(rawValue.c_str())==1;' : ""}
    /// Здесь обработка изменения свойств

    /// Здесь обработка изменения свойств кончается 
    ${notifiable ? 'pCharacteristic->notify()' : null};
  }
};''';
  }

  String getCharacteristicAssignment() {
    return '''$_propertyPointerName = pService->createCharacteristic($_uuidConstName,BLECharacteristic::PROPERTY_READ${writable ? "| BLECharacteristic::PROPERTY_WRITE" : ""} ${notifiable ? "|BLECharacteristic::PROPERTY_NOTIFY" : ""});
    ${hasCallback ? "$_propertyPointerName->setCallbacks(new $_propertyCallbackClassName());" : ""}
    ''';
  }
}
