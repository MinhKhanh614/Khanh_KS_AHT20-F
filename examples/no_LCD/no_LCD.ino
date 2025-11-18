/*
  17/11/2025:
    
        Arduino Library sử dụng: https://github.com/dvarrel/AHT20/releases/tag/1.0.2
        
        Điểm cần lưu ý:
        - Hoạt động tốt trong khoảng 0–80 %RH. Nếu >80 %RH lâu dài, cảm biến có thể bị trôi tín hiệu nhưng sẽ tự hồi phục khi trở lại điều kiện bình thường.
        - Không nên để trong môi trường có hơi dung môi, keo, băng dính dễ bay hơi vì sẽ làm sai lệch kết quả.
        - Có cơ chế phục hồi bằng sấy khô hoặc tái hydrat hóa nếu cảm biến bị trôi.

        Kết quả sau khi nạp code (tại vị trí anh Ngọc):
          15:44:28.418 -> T: 28.66 C	 H: 52.11% RH
          15:44:30.497 -> T: 28.65 C	 H: 52.11% RH
          15:44:32.601 -> T: 28.66 C	 H: 52.15% RH
          15:44:34.730 -> T: 28.65 C	 H: 52.44% RH
          15:44:36.744 -> T: 28.63 C	 H: 52.16% RH
          15:44:38.826 -> T: 28.63 C	 H: 52.20% RH
          15:44:40.909 -> T: 28.63 C	 H: 52.26% RH

          

*/
#include <Wire.h>
#include <AHT20.h>
AHT20 aht20;

void setup()
{
  Serial.begin(115200);
  Serial.println("AHT20 example");

  Wire.begin();
  if (aht20.begin() == false)
  {
    Serial.println("AHT20 not detected. Please check wiring. Freezing.");
    while(true);
  }
}

void loop()
{
  float temperature = aht20.getTemperature();
  float humidity = aht20.getHumidity();

  Serial.print("T: ");
  Serial.print(temperature, 2);
  Serial.print(" C\t H: ");
  Serial.print(humidity, 2);
  Serial.println("% RH");

  delay(2000);
}
