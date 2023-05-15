#include "mbed.h"
#include "stm32746g_discovery_audio.h"
#include "stm32746g_discovery_sdram.h"
#include <cstdint>


typedef enum {
    BUFFER_OFFSET_NONE = 0,
    BUFFER_OFFSET_HALF = 1,
    BUFFER_OFFSET_FULL = 2,
} BUFFER_StateTypeDef;


#define AUDIO_BLOCK_SIZE   ((uint32_t)512)
#define AUDIO_BUFFER_IN     SDRAM_DEVICE_ADDR
#define AUDIO_BUFFER_OUT   (AUDIO_BUFFER_IN + (AUDIO_BLOCK_SIZE * 2))

const float frequencies[] = {440.0f, 880.0f, 1320.0f, 1760.0f};
const float amplitudes[] = {1.0f, 0.5f, 0.3f, 0.2f};
const int num_harmonics = sizeof(frequencies) / sizeof(float);


uint16_t pBuffer[AUDIO_BLOCK_SIZE]; // buffer de sortie

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


for (uint32_t i = 0; i < AUDIO_BLOCK_SIZE; i++) {
    float t = (float)i / 2;
    float value = 0.0f;
    for (int j = 0; j < num_harmonics; j++) {
        value += amplitudes[j] * sin(2.0f * 3.14f * frequencies[j] * t);
    }
    pBuffer[i] = (uint16_t)(0 * 0xFFFF);
}
    /* Start Playback */
    BSP_AUDIO_OUT_SetAudioFrameSlot(CODEC_AUDIOFRAME_SLOT_02);
    BSP_AUDIO_OUT_Play(pBuffer, AUDIO_BLOCK_SIZE);
    osDelay(500);
    BSP_AUDIO_OUT_Pause();
}




