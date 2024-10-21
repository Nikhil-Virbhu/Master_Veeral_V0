#define I2CEEPROM_H_
#include "i2cEeprom.h"
#include "i2c.h"
#include"string.h"
#include "process.h"
#include "protection.h"
#include "debug.h"

extern I2C_HandleTypeDef hi2c3;

/*
 * Function description: Generates a checksum to store structures in FRAM
 * Input : Structure pointer, size of structure
 * Output : 16-bit CRC checksum
*/
uint16_t eeprom_crc_generate(uint8_t* config_pointer, uint16_t size_of_structure)
{
	const uint16_t generator_polynomial = 0x1021;
	uint16_t crc = 0;

	for (uint16_t i=0; i<size_of_structure; i++)
	{
		crc ^= (uint16_t)((*(config_pointer + i)) << 8);

		for (int j = 0; j < 8; j++)
		{
			if((crc & 0x8000) != 0)
				crc = (uint16_t)((crc << 1) ^ generator_polynomial);
			else
				crc <<= 1;
		}
	}
	return crc;
}
/*
 * Function description: Writes the structure to FRAM
 * Input : Structure pointer, size of structure
 * Output : None
 */
void writeStructureToEeprom(uint8_t* config_pointer, uint16_t size_of_structure)
{
	if(HAL_I2C_Mem_Write(&hi2c3 , EEPROM_ADDR1, 0, I2C_MEMADD_SIZE_16BIT, (uint8_t*)config_pointer, size_of_structure,300) != HAL_OK){
		criticalFault.bits.eeprom_fault = 1;
	}
	uint16_t eeprom_crc_write = eeprom_crc_generate(config_pointer,size_of_structure);
	if(HAL_I2C_Mem_Write(&hi2c3 , EEPROM_ADDR1, 1000, I2C_MEMADD_SIZE_16BIT, (uint8_t*)&eeprom_crc_write, 2,300) != HAL_OK){
		criticalFault.bits.eeprom_fault = 1;
	}
}
/*
 * Function description: Reads the structure from FRAM
 * Input : Structure pointer, size of structure
 * Output : 1 or 0 depending upon successful read
 */
uint8_t readStructurefromEeprom(uint8_t* config_pointer, uint16_t size_of_structure)
{
	uint16_t crc_received_from_eeprom;
	if(HAL_I2C_IsDeviceReady(&hi2c3, EEPROM_ADDR1, 10, 200) == HAL_OK){
			if(HAL_I2C_Mem_Read(&hi2c3, EEPROM_ADDR1, 0, I2C_MEMADD_SIZE_16BIT, (uint8_t *)config_pointer, size_of_structure,300) != HAL_OK){
				criticalFault.bits.eeprom_fault = 1;
				 return 0;
			}
		}
	if(HAL_I2C_Mem_Read(&hi2c3, EEPROM_ADDR1, 1000, I2C_MEMADD_SIZE_16BIT, (uint8_t *)&crc_received_from_eeprom, 2,300) != HAL_OK){
		criticalFault.bits.eeprom_fault = 1;
		 return 0;
	}
	uint16_t generated_crc = eeprom_crc_generate(config_pointer,size_of_structure);
	if(generated_crc == crc_received_from_eeprom)
		return 1;
	else
		return 0;
}

/*
* Function description: Application layer function to load parameters from FRAM
* Input: None
* Output: None
*/
void para_load()
{
	if (readStructurefromEeprom((uint8_t*)&ConfigPara, sizeof(ConfigPara)) == 0)
	{
		 paraInit();
		 if(criticalFault.bits.eeprom_fault == 0)
		 {/*Action to be added*/}

		 else if (criticalFault.bits.eeprom_fault == 1)
		 {/*Action to be added*/}
	}else{
		 {/*Action to be added*/}
	  }
}

/*
* Function description: Use the factory setting parameters
* Input: None
* Output: None
*/
void default_para_load()
{
	paraInit();
}

/*
* Function description: Application layer function to save parameters to FRAM
* Input: None
* Output: None
*/
void para_save()
{
	writeStructureToEeprom((uint8_t*)&ConfigPara,sizeof(ConfigPara));
}

