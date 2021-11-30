#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#define SERVICE_UUID  "9a8ca9ef-e43f-4157-9fee-c37a3d7dc12d" // ID сервиса

#define DEVICE_MANUFACTURER "HOOKAH INC" // Имя "Производителя"
#define DEVICE_NAME         "HOOKAH 1" // Имя устройства

// UUID CONST DEFINITION 
#define NAME_UUID "5956f04f-b600-45b8-aad8-8cd11839297f"
#define BATTERY_UUID "c2fabe1b-1923-4e90-bd9c-6f33b33f3d22"
#define LBOWLSTATE_UUID "4b39731f-7359-4133-b120-18496160e764"
#define LBOWLPROCESS_UUID "c8b6bd70-319b-4d57-af1a-bad1db1388c8"
#define LBOWLSPEED_UUID "dd6f9ef6-57a3-462e-8934-bb8928070b83"
#define LBOWLTHERM_UUID "605d2519-9b8f-4cfe-a2a1-fd32b28be0c0"
#define LBOWLAMODE_UUID "04a3d6a0-9011-41b4-bbf1-5585ea37a74f"
#define LBOWLTIMER_UUID "82a7a57a-ce51-40f2-8c58-3b38f137bf0e"
#define RBOWLSTATE_UUID "87515f86-7584-4474-9f29-9d316eae308b"
#define RBOWLPROCESS_UUID "082be236-bfa3-4eab-bd9a-ae2a596dc9c1"
#define RBOWLSPEED_UUID "3d53ed6d-435e-4d78-b4c9-a65364b532cf"
#define RBOWLTHERM_UUID "40136388-9ad9-4e47-bf68-55cd421f9e8d"
#define RBOWLAMODE_UUID "2509a828-e663-45c6-a58c-0ddca8d23cbd"
#define RBOWLTIMER_UUID "892e7d50-ba2e-4fa1-9b17-6420c23b2c17"
#define FTUBESTATE_UUID "acc148ec-0a82-4731-ad1b-2b2aecf83f4b"
#define FTUBEBATTERY_UUID "ad7fe95d-69ee-427d-9a32-6eaa413be56c"
#define STUBESTATE_UUID "0cf2cf42-e514-4b4c-91e1-aceedc9aa1b2"
#define STUBEBATTERY_UUID "4597768d-03f0-407c-adc9-376848d425f0"
#define TTUBESTATE_UUID "68933e8d-2ee5-4bf2-8693-dc633afe8878"
#define TTUBEBATTERY_UUID "ca062470-689e-4b77-8ea0-a587916c3436"
//  END UUID CONST DEFINITION 


// BLECharacteristic Pointer Definitions 
BLECharacteristic *nameProp;
BLECharacteristic *batteryProp;
BLECharacteristic *lbowlstateProp;
BLECharacteristic *lbowlprocessProp;
BLECharacteristic *lbowlspeedProp;
BLECharacteristic *lbowlthermProp;
BLECharacteristic *lbowlamodeProp;
BLECharacteristic *lbowltimerProp;
BLECharacteristic *rbowlstateProp;
BLECharacteristic *rbowlprocessProp;
BLECharacteristic *rbowlspeedProp;
BLECharacteristic *rbowlthermProp;
BLECharacteristic *rbowlamodeProp;
BLECharacteristic *rbowltimerProp;
BLECharacteristic *ftubestateProp;
BLECharacteristic *ftubebatteryProp;
BLECharacteristic *stubestateProp;
BLECharacteristic *stubebatteryProp;
BLECharacteristic *ttubestateProp;
BLECharacteristic *ttubebatteryProp;
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
class ClbowlstatePropCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rawValue = pCharacteristic->getValue();
    int value = atoi(rawValue.c_str());
    /// Здесь обработка изменения свойств

    /// Здесь обработка изменения свойств кончается 
    pCharacteristic->notify();
  }
};
class ClbowlprocessPropCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rawValue = pCharacteristic->getValue();
    const char* value = rawValue.c_str();
    /// Здесь обработка изменения свойств

    /// Здесь обработка изменения свойств кончается 
    pCharacteristic->notify();
  }
};
class ClbowlspeedPropCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rawValue = pCharacteristic->getValue();
    int value = atoi(rawValue.c_str());
    /// Здесь обработка изменения свойств

    /// Здесь обработка изменения свойств кончается 
    pCharacteristic->notify();
  }
};
class ClbowlthermPropCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rawValue = pCharacteristic->getValue();
    int value = atoi(rawValue.c_str());
    /// Здесь обработка изменения свойств

    /// Здесь обработка изменения свойств кончается 
    pCharacteristic->notify();
  }
};
class ClbowlamodePropCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rawValue = pCharacteristic->getValue();
    int value = atoi(rawValue.c_str());
    /// Здесь обработка изменения свойств

    /// Здесь обработка изменения свойств кончается 
    pCharacteristic->notify();
  }
};
class ClbowltimerPropCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rawValue = pCharacteristic->getValue();
    const char* value = rawValue.c_str();
    /// Здесь обработка изменения свойств

    /// Здесь обработка изменения свойств кончается 
    pCharacteristic->notify();
  }
};
class CrbowlstatePropCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rawValue = pCharacteristic->getValue();
    int value = atoi(rawValue.c_str());
    /// Здесь обработка изменения свойств

    /// Здесь обработка изменения свойств кончается 
    pCharacteristic->notify();
  }
};
class CrbowlprocessPropCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rawValue = pCharacteristic->getValue();
    const char* value = rawValue.c_str();
    /// Здесь обработка изменения свойств

    /// Здесь обработка изменения свойств кончается 
    pCharacteristic->notify();
  }
};
class CrbowlspeedPropCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rawValue = pCharacteristic->getValue();
    int value = atoi(rawValue.c_str());
    /// Здесь обработка изменения свойств

    /// Здесь обработка изменения свойств кончается 
    pCharacteristic->notify();
  }
};
class CrbowlthermPropCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rawValue = pCharacteristic->getValue();
    int value = atoi(rawValue.c_str());
    /// Здесь обработка изменения свойств

    /// Здесь обработка изменения свойств кончается 
    pCharacteristic->notify();
  }
};
class CrbowlamodePropCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rawValue = pCharacteristic->getValue();
    int value = atoi(rawValue.c_str());
    /// Здесь обработка изменения свойств

    /// Здесь обработка изменения свойств кончается 
    pCharacteristic->notify();
  }
};
class CrbowltimerPropCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rawValue = pCharacteristic->getValue();
    const char* value = rawValue.c_str();
    /// Здесь обработка изменения свойств

    /// Здесь обработка изменения свойств кончается 
    pCharacteristic->notify();
  }
};
class CftubestatePropCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rawValue = pCharacteristic->getValue();
    int value = atoi(rawValue.c_str());
    /// Здесь обработка изменения свойств

    /// Здесь обработка изменения свойств кончается 
    pCharacteristic->notify();
  }
};
class CftubebatteryPropCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rawValue = pCharacteristic->getValue();
    int value = atoi(rawValue.c_str());
    /// Здесь обработка изменения свойств

    /// Здесь обработка изменения свойств кончается 
    pCharacteristic->notify();
  }
};
class CstubestatePropCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rawValue = pCharacteristic->getValue();
    int value = atoi(rawValue.c_str());
    /// Здесь обработка изменения свойств

    /// Здесь обработка изменения свойств кончается 
    pCharacteristic->notify();
  }
};
class CstubebatteryPropCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rawValue = pCharacteristic->getValue();
    int value = atoi(rawValue.c_str());
    /// Здесь обработка изменения свойств

    /// Здесь обработка изменения свойств кончается 
    pCharacteristic->notify();
  }
};
class CttubestatePropCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rawValue = pCharacteristic->getValue();
    int value = atoi(rawValue.c_str());
    /// Здесь обработка изменения свойств

    /// Здесь обработка изменения свойств кончается 
    pCharacteristic->notify();
  }
};
class CttubebatteryPropCallbacks : public BLECharacteristicCallbacks {
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
    lbowlstateProp = pService->createCharacteristic(LBOWLSTATE_UUID,BLECharacteristic::PROPERTY_READ| BLECharacteristic::PROPERTY_WRITE |BLECharacteristic::PROPERTY_NOTIFY);
    lbowlstateProp->setCallbacks(new ClbowlstatePropCallbacks());
    lbowlprocessProp = pService->createCharacteristic(LBOWLPROCESS_UUID,BLECharacteristic::PROPERTY_READ| BLECharacteristic::PROPERTY_WRITE |BLECharacteristic::PROPERTY_NOTIFY);
    lbowlprocessProp->setCallbacks(new ClbowlprocessPropCallbacks());
    lbowlspeedProp = pService->createCharacteristic(LBOWLSPEED_UUID,BLECharacteristic::PROPERTY_READ| BLECharacteristic::PROPERTY_WRITE |BLECharacteristic::PROPERTY_NOTIFY);
    lbowlspeedProp->setCallbacks(new ClbowlspeedPropCallbacks());
    lbowlthermProp = pService->createCharacteristic(LBOWLTHERM_UUID,BLECharacteristic::PROPERTY_READ| BLECharacteristic::PROPERTY_WRITE |BLECharacteristic::PROPERTY_NOTIFY);
    lbowlthermProp->setCallbacks(new ClbowlthermPropCallbacks());
    lbowlamodeProp = pService->createCharacteristic(LBOWLAMODE_UUID,BLECharacteristic::PROPERTY_READ| BLECharacteristic::PROPERTY_WRITE |BLECharacteristic::PROPERTY_NOTIFY);
    lbowlamodeProp->setCallbacks(new ClbowlamodePropCallbacks());
    lbowltimerProp = pService->createCharacteristic(LBOWLTIMER_UUID,BLECharacteristic::PROPERTY_READ| BLECharacteristic::PROPERTY_WRITE |BLECharacteristic::PROPERTY_NOTIFY);
    lbowltimerProp->setCallbacks(new ClbowltimerPropCallbacks());
    rbowlstateProp = pService->createCharacteristic(RBOWLSTATE_UUID,BLECharacteristic::PROPERTY_READ| BLECharacteristic::PROPERTY_WRITE |BLECharacteristic::PROPERTY_NOTIFY);
    rbowlstateProp->setCallbacks(new CrbowlstatePropCallbacks());
    rbowlprocessProp = pService->createCharacteristic(RBOWLPROCESS_UUID,BLECharacteristic::PROPERTY_READ| BLECharacteristic::PROPERTY_WRITE |BLECharacteristic::PROPERTY_NOTIFY);
    rbowlprocessProp->setCallbacks(new CrbowlprocessPropCallbacks());
    rbowlspeedProp = pService->createCharacteristic(RBOWLSPEED_UUID,BLECharacteristic::PROPERTY_READ| BLECharacteristic::PROPERTY_WRITE |BLECharacteristic::PROPERTY_NOTIFY);
    rbowlspeedProp->setCallbacks(new CrbowlspeedPropCallbacks());
    rbowlthermProp = pService->createCharacteristic(RBOWLTHERM_UUID,BLECharacteristic::PROPERTY_READ| BLECharacteristic::PROPERTY_WRITE |BLECharacteristic::PROPERTY_NOTIFY);
    rbowlthermProp->setCallbacks(new CrbowlthermPropCallbacks());
    rbowlamodeProp = pService->createCharacteristic(RBOWLAMODE_UUID,BLECharacteristic::PROPERTY_READ| BLECharacteristic::PROPERTY_WRITE |BLECharacteristic::PROPERTY_NOTIFY);
    rbowlamodeProp->setCallbacks(new CrbowlamodePropCallbacks());
    rbowltimerProp = pService->createCharacteristic(RBOWLTIMER_UUID,BLECharacteristic::PROPERTY_READ| BLECharacteristic::PROPERTY_WRITE |BLECharacteristic::PROPERTY_NOTIFY);
    rbowltimerProp->setCallbacks(new CrbowltimerPropCallbacks());
    ftubestateProp = pService->createCharacteristic(FTUBESTATE_UUID,BLECharacteristic::PROPERTY_READ| BLECharacteristic::PROPERTY_WRITE |BLECharacteristic::PROPERTY_NOTIFY);
    ftubestateProp->setCallbacks(new CftubestatePropCallbacks());
    ftubebatteryProp = pService->createCharacteristic(FTUBEBATTERY_UUID,BLECharacteristic::PROPERTY_READ| BLECharacteristic::PROPERTY_WRITE |BLECharacteristic::PROPERTY_NOTIFY);
    ftubebatteryProp->setCallbacks(new CftubebatteryPropCallbacks());
    stubestateProp = pService->createCharacteristic(STUBESTATE_UUID,BLECharacteristic::PROPERTY_READ| BLECharacteristic::PROPERTY_WRITE |BLECharacteristic::PROPERTY_NOTIFY);
    stubestateProp->setCallbacks(new CstubestatePropCallbacks());
    stubebatteryProp = pService->createCharacteristic(STUBEBATTERY_UUID,BLECharacteristic::PROPERTY_READ| BLECharacteristic::PROPERTY_WRITE |BLECharacteristic::PROPERTY_NOTIFY);
    stubebatteryProp->setCallbacks(new CstubebatteryPropCallbacks());
    ttubestateProp = pService->createCharacteristic(TTUBESTATE_UUID,BLECharacteristic::PROPERTY_READ| BLECharacteristic::PROPERTY_WRITE |BLECharacteristic::PROPERTY_NOTIFY);
    ttubestateProp->setCallbacks(new CttubestatePropCallbacks());
    ttubebatteryProp = pService->createCharacteristic(TTUBEBATTERY_UUID,BLECharacteristic::PROPERTY_READ| BLECharacteristic::PROPERTY_WRITE |BLECharacteristic::PROPERTY_NOTIFY);
    ttubebatteryProp->setCallbacks(new CttubebatteryPropCallbacks());
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