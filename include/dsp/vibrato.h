#pragma once

#include "codec.h"
#include <stdlib.h>

#define VIBRATO_MAX_DEPTH 50
#define VIBRATO_LINELEN (VIBRATO_MAX_DEPTH * 2)

typedef struct
{
	float delayline_l[VIBRATO_LINELEN];
	float delayline_r[VIBRATO_LINELEN];
	size_t writepos;
	float phase;
} VibratoState;

typedef struct
{
	float speed;
	float depth;
	float phasediff;
} VibratoParams;

void initVibrato(VibratoState* state);

void processVibrato(const FloatAudioBuffer *__restrict__ in,
                    FloatAudioBuffer* __restrict__ out, VibratoState* state,
                    const VibratoParams* params);