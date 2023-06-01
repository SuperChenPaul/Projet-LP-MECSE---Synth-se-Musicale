#include "mbed.h"
#include "stm32746g_discovery_audio.h"
#include "stm32746g_discovery_sdram.h"



typedef enum {
    BUFFER_OFFSET_NONE = 0,
    BUFFER_OFFSET_HALF = 1,
    BUFFER_OFFSET_FULL = 2,
} BUFFER_StateTypeDef;


#define AUDIO_BLOCK_SIZE   ((uint32_t)8)
#define AUDIO_BUFFER_IN     SDRAM_DEVICE_ADDR
#define AUDIO_BUFFER_OUT   (AUDIO_BUFFER_IN + (AUDIO_BLOCK_SIZE * 2))

const float frequencies[] = {220.0f, 440.0f ,880.0f, 1320.0f};
const float amplitudes[] = {1.0f, 0.5f, 0.3f, 0.2f};
const int num_harmonics = sizeof(frequencies) / sizeof(float);


uint16_t pBuffer[AUDIO_BLOCK_SIZE]; // buffer de sortie
uint32_t i = 0;

DigitalIn allo(USER_BUTTON);

volatile uint32_t  audio_rec_buffer_state = BUFFER_OFFSET_NONE;


int main()
{
    printf("\n\nAUDIO LOOPBACK EXAMPLE START:\n");

    BSP_AUDIO_IN_OUT_Init(INPUT_DEVICE_DIGITAL_MICROPHONE_2, OUTPUT_DEVICE_HEADPHONE, DEFAULT_AUDIO_IN_FREQ, DEFAULT_AUDIO_IN_BIT_RESOLUTION, DEFAULT_AUDIO_IN_CHANNEL_NBR);
    printf("AUDIO loop from digital micro (U20 & U21 components on board) to headphone (CN10 jack connector)\n");


    /* Initialize SDRAM buffers */
    BSP_SDRAM_Init();
    memset((uint16_t *)AUDIO_BUFFER_IN, 0, AUDIO_BLOCK_SIZE * 2);
    memset((uint16_t *)AUDIO_BUFFER_OUT, 0, AUDIO_BLOCK_SIZE * 2);
    printf("SDRAM init done\n");
    

    audio_rec_buffer_state = BUFFER_OFFSET_NONE;



    /* Start Playback */
    printf("Etape 1\n");
    BSP_AUDIO_OUT_SetAudioFrameSlot(CODEC_AUDIOFRAME_SLOT_02);
    BSP_AUDIO_OUT_Play(pBuffer, AUDIO_BLOCK_SIZE);


  
    printf("Etape 2\n");
        for (i=0; i < AUDIO_BLOCK_SIZE; i++) {
            float value = 0.0f;
            value = 2.0f * sin(2.0f * 3.14f * 440.0f*i);
            pBuffer[2*i] = (uint16_t)(value * 0xFFFF);
      }

        

}
