#include "mbed.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"
#include "stm32746g_discovery_audio.h"
#include "stm32746g_discovery_sdram.h"
#include "time.h"
#include <cstdint>
#include <stdint.h>



typedef enum {
    BUFFER_OFFSET_NONE = 0,
    BUFFER_OFFSET_HALF = 1,
    BUFFER_OFFSET_FULL = 2,
} BUFFER_StateTypeDef;


#define AUDIO_BLOCK_SIZE   ((uint32_t)64)
#define AUDIO_BUFFER_IN     SDRAM_DEVICE_ADDR
#define AUDIO_BUFFER_OUT   (AUDIO_BUFFER_IN + (AUDIO_BLOCK_SIZE * 2))






int main()
{
    TS_StateTypeDef TS_State;
    uint8_t status;
    uint16_t pBuffer[AUDIO_BLOCK_SIZE]; // buffer de sortie
    uint16_t pBufferbis[AUDIO_BLOCK_SIZE*2];
    volatile uint32_t  audio_rec_buffer_state = BUFFER_OFFSET_NONE;
    uint16_t i=0;
    float value = 0.0f;
    int lock = 0;
    

    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);

    BSP_LCD_DisplayStringAt(0, LINE(5), (uint8_t *)"TOUCHSCREEN DEMO", CENTER_MODE);
    HAL_Delay(1000);

    status = BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
    if (status != TS_OK) {
        BSP_LCD_Clear(LCD_COLOR_RED);
        BSP_LCD_SetBackColor(LCD_COLOR_RED);
        BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
        BSP_LCD_DisplayStringAt(0, LINE(5), (uint8_t *)"TOUCHSCREEN INIT FAIL", CENTER_MODE);
    } else {
        BSP_LCD_Clear(LCD_COLOR_GREEN);
        BSP_LCD_SetBackColor(LCD_COLOR_GREEN);
        BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
        BSP_LCD_DisplayStringAt(0, LINE(5), (uint8_t *)"TOUCHSCREEN INIT OK", CENTER_MODE);
    }

    HAL_Delay(1000);
    BSP_LCD_SetFont(&Font12);
    BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

     printf("\n\nAUDIO LOOPBACK EXAMPLE START:\n");

    //BSP_AUDIO_IN_OUT_Init(INPUT_DEVICE_DIGITAL_MICROPHONE_2, OUTPUT_DEVICE_HEADPHONE, DEFAULT_AUDIO_IN_FREQ, DEFAULT_AUDIO_IN_BIT_RESOLUTION, DEFAULT_AUDIO_IN_CHANNEL_NBR);
    printf("AUDIO loop from digital micro (U20 & U21 components on board) to headphone (CN10 jack connector)\n");
    /* Initialize SDRAM buffers */
    BSP_SDRAM_Init();
    memset((uint16_t *)AUDIO_BUFFER_IN, 0, AUDIO_BLOCK_SIZE * 2);
    memset((uint16_t *)AUDIO_BUFFER_OUT, 0, AUDIO_BLOCK_SIZE * 2);
    printf("SDRAM init done\n");
    

    audio_rec_buffer_state = BUFFER_OFFSET_NONE;

    /* Start Playback */
    printf("Etape 1\n");
    BSP_AUDIO_OUT_Init(OUTPUT_DEVICE_HEADPHONE, 40, DEFAULT_AUDIO_IN_FREQ);
    BSP_AUDIO_OUT_SetAudioFrameSlot(CODEC_AUDIOFRAME_SLOT_02);



    while(1) {
        

        BSP_AUDIO_OUT_Play((uint16_t*) AUDIO_BUFFER_OUT, AUDIO_BLOCK_SIZE*2);
        
        
        BSP_TS_GetState(&TS_State);
        if (TS_State.touchDetected == 2) {
            if (lock==0){
                lock =1;
                BSP_AUDIO_OUT_Init(OUTPUT_DEVICE_HEADPHONE, 40, 44100);
            }
            for (i= 0; i < AUDIO_BLOCK_SIZE;i++)
            {
            value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 440.0f*((float)i/DEFAULT_AUDIO_IN_FREQ));
            pBuffer[i] = (uint16_t)(value * 0xFFFF);
            }
            memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE);
        }
        else if (TS_State.touchDetected == 1) {
            if (lock==0){
                lock =1;
                BSP_AUDIO_OUT_Init(OUTPUT_DEVICE_HEADPHONE, 40, 22100);
            }
            for (i= 0; i < AUDIO_BLOCK_SIZE;i++)
            {
            value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 1440.0f*((float)i/2));
            pBuffer[i] = (uint16_t)(value * 0xFFFF);
            }
            memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE);
        }

        else if (TS_State.touchDetected == 3) {
            if (lock==0){
                lock =1;
                BSP_AUDIO_OUT_Init(OUTPUT_DEVICE_HEADPHONE, 40, 5000);
            }
            for (i= 0; i < AUDIO_BLOCK_SIZE;i++)
            {
            value = (uint16_t)20000.0f * sin(2.0f * 3.14f * 4000.0f*((float)i/DEFAULT_AUDIO_IN_FREQ));
            pBuffer[i] = (uint16_t)(value * 0xFFFF);
            }
            memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE);
        }

        else if (TS_State.touchDetected == 4) {
            if (lock==0){
                lock =1;
                BSP_AUDIO_OUT_Init(OUTPUT_DEVICE_HEADPHONE, 40, 50100);
            }
            for (i= 0; i < AUDIO_BLOCK_SIZE;i++)
            {
            value = (uint16_t)200000.0f * sin(2.0f * 3.14f * 12000.0f*((float)i/DEFAULT_AUDIO_IN_FREQ));
            pBuffer[i] = (uint16_t)(value * 0xFFFF);
            }
            memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE);
        }

        else if (TS_State.touchDetected < 1) { 
                        lock =0;
            memset((uint16_t *)pBuffer, 0, AUDIO_BLOCK_SIZE * 2);
            memcpy((uint16_t *)(AUDIO_BUFFER_OUT), (uint16_t *)(pBuffer), AUDIO_BLOCK_SIZE);
        }
        
        printf("[%d] = %f\n",i,pBuffer[i]);
        
        if (i>=AUDIO_BLOCK_SIZE) 
        {
            i=0;
        }
  
}
}