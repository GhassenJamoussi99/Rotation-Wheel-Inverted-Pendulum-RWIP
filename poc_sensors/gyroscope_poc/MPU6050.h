/*
 * MPU6050.h
 *
 *  Created on: Jun 1, 2023
 *      Author: brahim Abdelkafi
 */

#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_

#define MPU6050_ADDR (0b1101000 <<1) + 0
#define SMPLRT_DIV_REG 0x19
#define GYRO_CONFIG_REG 0x1B
#define ACCEL_CONFIG_REG 0x1C
#define ACCEL_XOUT_H_REG 0x3B
#define TEMP_OUT_H_REG 0x41
#define GYRO_XOUT_H_REG 0x43
#define PWR_MGMT_1_REG 0x6B
#define WHO_AM_I_REG 0x75
#define PI 3.14159265358979323846

void MPU6050_Init();
void MPU6050_Read();
void MPU6050_Offset();
void MPU6050_Angle();
float constrain_angle(float angle);

#endif /* INC_MPU6050_H_ */
