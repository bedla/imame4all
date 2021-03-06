#pragma once

#ifndef __VLM5030_H__
#define __VLM5030_H__

typedef struct _vlm5030_interface vlm5030_interface;
struct _vlm5030_interface
{
	int memory_size;    /* memory size of speech rom (0=memory region length) */
};

/* set speech rom address */
void vlm5030_set_rom(const device_config *device, void *speech_rom);

/* get BSY pin level */
int vlm5030_bsy(const device_config *device);
/* latch contoll data */
WRITE8_DEVICE_HANDLER( vlm5030_data_w );
/* set RST pin level : reset / set table address A8-A15 */
void vlm5030_rst (const device_config *device, int pin );
/* set VCU pin level : ?? unknown */
void vlm5030_vcu(const device_config *device, int pin );
/* set ST pin level  : set table address A0-A7 / start speech */
void vlm5030_st(const device_config *device, int pin );

DEVICE_GET_INFO( vlm5030 );
#define SOUND_VLM5030 DEVICE_GET_INFO_NAME( vlm5030 )

#endif /* __VLM5030_H__ */
