/*
 * MPU6050.c
 *
 *  Created on: Jun 1, 2023
 *      Author: brahim Abdelkafi
 */

# include "MPU6050.h"
# include "main.h"
# include "stdio.h"
# include "math.h"

extern I2C_HandleTypeDef hi2c1;
extern TIM_HandleTypeDef htim16;
extern UART_HandleTypeDef hlpuart1;


int16_t gyroXPresent=0, gyroYPresent=0, gyroZPresent=0,
		gyroXPast=0, gyroYPast=0,gyroZPast=0,
		GyroOffsetX=0, GyroOffsetY=0, GyroOffsetZ=0, Temp=0;
uint16_t timer_val=0;


double GyroangleX = 0,GyroangleY = 0,GyroangleZ = 0,
		AccelangleX = 0,AccelangleY = 0,
		AccX = 0,AccY = 0, AccZ = 0,
		angleX = 0,angleY = 0;
float AccOffsetX, AccOffsetY;




void MPU6050_Init()
{
	uint8_t power_mgmt_1 = 0x00;
	uint8_t sample_rate_div = 0x07;
	uint8_t gyro_config = 0x00;
	uint8_t accel_config = 0x00;

	HAL_StatusTypeDef ret = HAL_I2C_IsDeviceReady(&hi2c1, MPU6050_ADDR, 1, 100);
	 if (ret == HAL_OK)
	 {
	  printf("The device is ready \n");
	 }
	 else
	 {
	  printf("The device is NOT ready \n");
	 }

	// Wake up the MPU6050 by writing 0 to PWR_MGMT_1 register
	HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, PWR_MGMT_1_REG, 1, &power_mgmt_1, 1, HAL_MAX_DELAY);

	// Set sample rate divider
	HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, SMPLRT_DIV_REG, 1, &sample_rate_div, 1, HAL_MAX_DELAY);

	// Set gyro configuration
	HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, GYRO_CONFIG_REG, 1, &gyro_config, 1, HAL_MAX_DELAY);

	// Set accelerometer configuration
	HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, ACCEL_CONFIG_REG, 1, &accel_config, 1, HAL_MAX_DELAY);

}


void MPU6050_Read(){
	 HAL_StatusTypeDef ret;
	 uint8_t Data[14];
	 uint8_t reg[1];  // Buffer to store the data to be transmitted
	 reg[0] = ACCEL_XOUT_H_REG;  // Store the register address in the buffer
	 gyroXPast = gyroXPresent;
	 gyroYPast = gyroYPresent;
	 gyroZPast = gyroZPresent;

	// Read 6 BYTES of data starting from ACCEL_XOUT_H register
	ret = HAL_I2C_Master_Transmit(&hi2c1, MPU6050_ADDR, reg, 1, HAL_MAX_DELAY);  // Start the transmission
	if (ret != HAL_OK) {
	     // handle error
	     printf("Error transmitting Accel data\n");
	     return;
	   }
	ret = HAL_I2C_Master_Receive(&hi2c1, MPU6050_ADDR, Data, 14,HAL_MAX_DELAY);  // Receive the 6 bytes of gyro data
	if (ret != HAL_OK) {
	     // handle error
	     printf("Error receiving Accel data\n");
	     return;
	   }
		AccX = (int16_t)(Data[0] << 8 | Data [1])/16384.0f;
		AccY = (int16_t)(Data[2] << 8 | Data [3])/16384.0f;
		AccZ = (int16_t)(Data[4] << 8 | Data [5])/16384.0f;
		Temp = (Data[6] << 8) | Data[7];
		gyroXPresent = (Data[8] << 8) | Data[9];
		gyroYPresent = (Data[10] << 8) | Data[11];
		gyroZPresent = (Data[12] << 8) | Data[13];
}

void MPU6050_Offset(){

		const uint16_t numSamples = 1000;
		  uint32_t totalX = 0, totalY = 0, X = 0, Y = 0, GyrototalX = 0, GyrototalY = 0, GyrototalZ = 0;
		int i;
		// Discard first few samples
		  for (uint16_t i = 0; i < 50; i++) {
			  MPU6050_Read();
		    HAL_Delay(2);
		  }
		for (i = 0; i < numSamples; i++) {

			MPU6050_Read();

			X = atan2(AccY, sqrt(pow(AccX, 2) + pow(AccZ, 2))) * 180 / PI;
			Y = atan2(-1 * AccX, sqrt(pow(AccY, 2) + pow(AccZ, 2))) * 180 / PI;
			totalX += X;
			totalY += Y;

			GyrototalX += gyroXPresent;
			GyrototalY += gyroYPresent;
			GyrototalZ += gyroZPresent;
			HAL_Delay(2);
		}
		  AccOffsetX = totalX / numSamples;
		  AccOffsetY = totalY / numSamples;

		  GyroOffsetX = GyrototalX / numSamples;
		  GyroOffsetY = GyrototalY / numSamples;
		  GyroOffsetZ = GyrototalZ / numSamples;
		  // Start the htim16 timer
		  HAL_TIM_Base_Start(&htim16);
	}

void MPU6050_Angle(){

	   timer_val = __HAL_TIM_GET_COUNTER(&htim16);
	   MPU6050_Read();

	// get the sign of Z axis
    float sgZ = AccZ < 0 ? -1 : 1;
	// calculate the angle in the X-axis
	AccelangleX = atan2(AccY, sgZ*(sqrt(pow(AccX, 2) + pow(AccZ, 2)))) * 180 / PI - AccOffsetX;
    // calculate elapsed time
	timer_val = __HAL_TIM_GET_COUNTER(&htim16) - timer_val;

	// calculate the change in angle
	GyroangleX = timer_val*(gyroXPresent + gyroXPast - 2.0f * GyroOffsetX)/ 1310000.0f;

	if (AccelangleX < -175 || AccelangleX > 175) {
	    angleX = AccelangleX;
	} else {
	    // Complementary filter - combine accelerometer and gyro angle values
	    angleX = 0.96f * (angleX + GyroangleX) + 0.04f * AccelangleX;
	}
	angleX=constrain_angle(angleX);

	printf("%.d;",(int)(AccelangleX));
	printf("%.d\r\n;",(int)(angleX));

}

float constrain_angle(float angle)
{
if (angle > 180.0f) {
    angle -= 360.0f;
}
else if (angle <= -180.0f) {
    angle += 360.0f;
}
return angle;
}

uint32_t TIM16_GetCounter() {
  return __HAL_TIM_GET_COUNTER(&htim16);
}

int _write(int file, char *ptr, int len)
{
	HAL_UART_Transmit(&hlpuart1, (uint8_t*)ptr, len, HAL_MAX_DELAY);
	return len;
}


