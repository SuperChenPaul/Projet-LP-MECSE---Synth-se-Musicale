#include "mbed.h"
#include "stm32746g_discovery_audio.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_sdram.h"
#include "stm32746g_discovery_ts.h"
#include "time.h"
#include <cstdint>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

Serial bluetooth (PF_7,PF_6);

typedef enum {
  BUFFER_OFFSET_NONE = 0,
  BUFFER_OFFSET_HALF = 1,
  BUFFER_OFFSET_FULL = 2,
} BUFFER_StateTypeDef;

#define AUDIO_BLOCK_SIZE ((uint32_t)16)
#define AUDIO_BUFFER_IN SDRAM_DEVICE_ADDR
#define AUDIO_BUFFER_OUT (AUDIO_BUFFER_IN + (AUDIO_BLOCK_SIZE))



int main() {

  uint16_t pBuffer[AUDIO_BLOCK_SIZE * 20]; // buffer de sortie
  volatile uint32_t audio_rec_buffer_state = BUFFER_OFFSET_NONE;
  uint16_t i = 0;
  float value = 0.0f;
  char mode='1';
  char BT ;

  bluetooth.baud(115200);

  /*SDRAM Init*/
  BSP_SDRAM_Init();
  memset((uint16_t *)AUDIO_BUFFER_IN, 0, AUDIO_BLOCK_SIZE * 2);
  memset((uint16_t *)AUDIO_BUFFER_OUT, 0, AUDIO_BLOCK_SIZE * 2);


  audio_rec_buffer_state = BUFFER_OFFSET_NONE;

  /*Audio output initialization*/
  BSP_AUDIO_OUT_Init(OUTPUT_DEVICE_HEADPHONE, 60, DEFAULT_AUDIO_IN_FREQ);
  BSP_AUDIO_OUT_SetAudioFrameSlot(CODEC_AUDIOFRAME_SLOT_02);


  
  while (1) {

      /* get Bluetooth information*/
    BT =  bluetooth.getc() ;

    /*Switch mode*/
    if (BT=='1') mode='1';
    else if (BT=='2') mode='2';


    /*First mode*/
    if (mode=='1'){
    switch (BT)
    {
    case('a'):
    /*Buidling signal*/
      for (i = 0; i < AUDIO_BLOCK_SIZE*10; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 440.0f * ((float)i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      /*Copying*/
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE*10 );
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE*10);
    break;
    case('b'):
      for (i = 0; i < AUDIO_BLOCK_SIZE*10; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 440000.0f * ((float)i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE*10);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE*10);
    break;
    case('c'):
      for (i = 0; i < AUDIO_BLOCK_SIZE*10; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 4400000.0f * ((float)i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE*10);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE*10);
    break;
    case('d'):
      for (i = 0; i < AUDIO_BLOCK_SIZE*11; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 440.0f * ((float)i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE*11);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE*11);
    break;
    case('e'):
      for (i = 0; i < AUDIO_BLOCK_SIZE*11; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 440000.0f * ((float)i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE*11);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE*11);
    break;
    case('f'):
      for (i = 0; i < AUDIO_BLOCK_SIZE*11; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 4400000.0f * ((float)i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE*11);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE*11);
    break;
    case('g'):
      for (i = 0; i < AUDIO_BLOCK_SIZE*12; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 440.0f * ((float)i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE*12);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE*12);
    break;
    case('h'):
      for (i = 0; i < AUDIO_BLOCK_SIZE*12; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 440000.0f * ((float)i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE*12);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE*12);
    break;
    case('i'):     
     for (i = 0; i < AUDIO_BLOCK_SIZE*12; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 4400000.0f * ((float)i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE*12);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE*12);
    break;
    case('j'):      
        for (i = 0; i < AUDIO_BLOCK_SIZE * 13 ; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 440.0f *((float) i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE * 13);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE * 13);
    break;
    case('k'):    
      for (i = 0; i < AUDIO_BLOCK_SIZE * 13 ; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 44000.0f *((float) i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE * 13);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE * 13);
    break;
    case('l'):
      for (i = 0; i < AUDIO_BLOCK_SIZE * 13 ; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 4400000.0f *((float) i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE * 13);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE * 13);
    break;
    case('m'):
      for (i = 0; i < AUDIO_BLOCK_SIZE * 14 ; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 440.0f *((float) i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE * 14);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE * 14);
    break;
    case('n'):
      for (i = 0; i < AUDIO_BLOCK_SIZE * 14 ; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 44000.0f *((float) i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE * 14);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE * 14);
    break;
    case('o'):
      for (i = 0; i < AUDIO_BLOCK_SIZE * 14 ; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 4400000.0f *((float) i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE * 14);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE * 14);
    break;
    case('p'):
      for (i = 0; i < AUDIO_BLOCK_SIZE * 15 ; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 440.0f *((float) i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE * 15);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE * 15);
    break;   
    case('q'):
      for (i = 0; i < AUDIO_BLOCK_SIZE * 15 ; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 440000.0f *((float) i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE * 15);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE * 15);
    break;
    case(' '):
      BSP_AUDIO_OUT_Stop(CODEC_PDWN_SW);
    break;
  }
  }

    /*Second mode*/
  else if (mode=='2'){
      switch (BT)
    {
    case('a'):
      for (i = 0; i < AUDIO_BLOCK_SIZE; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 440.0f * ((float)i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE );
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE);
    break;
    case('b'):
      for (i = 0; i < AUDIO_BLOCK_SIZE; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 44000.0f * ((float)i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE);
    break;
    case('c'):
      for (i = 0; i < AUDIO_BLOCK_SIZE; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 4400000.0f * ((float)i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE);
    break;
    case('d'):
      for (i = 0; i < AUDIO_BLOCK_SIZE*2; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 440.0f * ((float)i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE*2);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE*2);
    break;
    case('e'):
      for (i = 0; i < AUDIO_BLOCK_SIZE*2; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 44000.0f * ((float)i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE*2);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE*2);
    break;
    case('f'):
      for (i = 0; i < AUDIO_BLOCK_SIZE*2; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 4400000.0f * ((float)i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE*2);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE*2);
    break;
    case('g'):
      for (i = 0; i < AUDIO_BLOCK_SIZE*3; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 440.0f * ((float)i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE*3);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE*3);
    break;
    case('h'):
      for (i = 0; i < AUDIO_BLOCK_SIZE*3; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 44000.0f * ((float)i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE*3);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE*3);
    break;
    case('i'):     
     for (i = 0; i < AUDIO_BLOCK_SIZE*3; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 4400000.0f * ((float)i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE*3);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE*3);
    break;
    case('j'):      
        for (i = 0; i < AUDIO_BLOCK_SIZE * 4 ; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 440.0f *((float) i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE * 4);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE * 4);
    break;
    case('k'):    
      for (i = 0; i < AUDIO_BLOCK_SIZE * 4 ; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 44000.0f *((float) i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE * 4);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE * 4);
    break;
    case('l'):
      for (i = 0; i < AUDIO_BLOCK_SIZE * 4 ; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 4400000.0f *((float) i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE * 4);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE * 4);
    break;
    case('m'):
      for (i = 0; i < AUDIO_BLOCK_SIZE * 5 ; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 440.0f *((float) i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE * 5);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE * 5);
    break;
    case('n'):
      for (i = 0; i < AUDIO_BLOCK_SIZE * 5 ; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 440000.0f *((float) i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE * 5);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE * 5);
    break;
    case('o'):
      for (i = 0; i < AUDIO_BLOCK_SIZE * 5 ; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 4400000.0f *((float) i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE * 5);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE * 5);
    break;
    case('p'):
      for (i = 0; i < AUDIO_BLOCK_SIZE * 6 ; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 440.0f *((float) i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE * 6);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE * 6);
    break;   
    case('q'):
      for (i = 0; i < AUDIO_BLOCK_SIZE * 6 ; i++) {
        value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 440000.0f *((float) i / DEFAULT_AUDIO_IN_FREQ));
        pBuffer[i] = (uint16_t)(value * 0xFFFF);
      }
      memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE * 6);
      BSP_AUDIO_OUT_Play((uint16_t *)AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE * 6);
    break;
    case(' '):
      BSP_AUDIO_OUT_Stop(CODEC_PDWN_SW);
    break;
      
  }
  }
  }
}