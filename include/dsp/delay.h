#pragma once

#include "codec.h"

#define DELAY_LINELEN (CODEC_SAMPLERATE/2)

typedef struct
{
	CodecIntSample delayline_l[DELAY_LINELEN];
	CodecIntSample delayline_r[DELAY_LINELEN];
	float filteredLength;
	size_t writepos;
	size_t octaverPhase;
} DelayState;

typedef struct
{
	float input;
	float confusion;
	float feedback;
	float octaveMix;
	float length;
} DelayParams;

void initDelay(DelayState* state);

void processDelay(const FloatAudioBuffer* restrict in,
                  FloatAudioBuffer* restrict out, DelayState* state,
                  const DelayParams* params);