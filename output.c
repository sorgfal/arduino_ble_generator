#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#define SERVICE_UUID  "9a8ca9ef-e43f-4157-9fee-c37a3d7dc12d" // ID сервиса

#define DEVICE_MANUFACTURER "Manufactura" // Имя "Производителя"
#define DEVICE_NAME         "Manufactura model 1" // Имя устройства

// UUID CONST DEFINITION 
#define NAME_UUID "06c4b615-fb94-4856-9bc2-b5b1f942ed3a"
#define BATTERY_UUID "67f0a316-9a6b-4532-87c6-9696b6899844"
//  END UUID CONST DEFINITION 


// BLECharacteristic Pointer Definitions 
BLECharacteristic *nameProp;
BLECharacteristic *batteryProp;
//  END BLECharacteristic Pointer Definitions  


// Callbacks  Definitions 

class CbatteryPropCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rawValue = pCharacteristic->getValue();
    int value = atoi(rawValue.c_str());
    /// Здесь обработка изменения свойств

    /// Здесь обработка изменения свойств кончается 
    pCharacteristic->notify();
  }
};
//  END Callbacks  Definitions  




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

  
//Characteristic Assignment Definitions 
nameProp = pService->createCharacteristic(NAME_UUID,BLECharacteristic::PROPERTY_READ );
    
    batteryProp = pService->createCharacteristic(BATTERY_UUID,BLECharacteristic::PROPERTY_READ| BLECharacteristic::PROPERTY_WRITE |BLECharacteristic::PROPERTY_NOTIFY);
    batteryProp->setCallbacks(new CbatteryPropCallbacks());
    //  END Characteristic Assignment Definitions  


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
}