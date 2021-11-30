part of 'arduino_code_builder.dart';

class ArduinoFirmwareGenerator {
  static String serviceUUID = "9a8ca9ef-e43f-4157-9fee-c37a3d7dc12d";
  static String manufacturer = "Manufactura";
  static String deviceName = "Manufactura";

  static final String _template = '''
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#define SERVICE_UUID  "$serviceUUID" // ID сервиса

#define DEVICE_MANUFACTURER "$manufacturer" // Имя "Производителя"
#define DEVICE_NAME         "$deviceName" // Имя устройства
%constDefinition
%BLECharacteristic
%callbacksDefenition



class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      // Обработка подключения телефона к устройству
      Serial.println("Client Connected");
    };

    void onDisconnect(BLEServer* pServer) {
      // Обработка отключения
      Serial.println("Client Disconnected");
    }
};


void setup() {
  Serial.begin(115200);
  // Генерация имени
  String devName = DEVICE_NAME; 
  String chipId = String((uint32_t)(ESP.getEfuseMac() >> 24), HEX);
  devName += '_';
  devName += chipId;
 
   // Инициализация девайса  c уникальным именем
  BLEDevice::init(devName.c_str()); 

  // Создаем сервер
  BLEServer *pServer = BLEDevice::createServer();
  
  // Подключаем обработчики подключения и отключения
  pServer->setCallbacks(new MyServerCallbacks()); 

  // Создаем сервис 
  BLEService *pService = pServer->createService(SERVICE_UUID); 

  %characteristicAssignment

  // Стартуем сервис
  pService->start();


  // Настройка вещания
  BLEAdvertising *pAdvertising = pServer->getAdvertising();

  BLEAdvertisementData adv;
  adv.setName(devName.c_str());
  pAdvertising->setAdvertisementData(adv);

  BLEAdvertisementData adv2;
  adv2.setCompleteServices(BLEUUID(SERVICE_UUID));
  pAdvertising->setScanResponseData(adv2);
  
  // Начало вещания
  pAdvertising->start();

}

void loop() {
  delay(1000);
}''';
  final ArduinoCodeBuilder _builder;

  ArduinoFirmwareGenerator(this._builder);
  String build() {
    return _template
        .replaceAll('%constDefinition', _builder._generateConstDefinitions())
        .replaceAll('%BLECharacteristic',
            _builder._generateBLECharacteristicPointerDefinitions())
        .replaceAll(
            '%callbacksDefenition', _builder._generateCallbackDefinitions())
        .replaceAll('%characteristicAssignment',
            _builder._generateCharacteristicAssignmentDefinitions());
  }
}
