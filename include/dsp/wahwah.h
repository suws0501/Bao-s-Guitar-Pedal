#pragma once

#include "biquad.h"
#include "codec.h"

typedef struct
{
	FloatBiquadState bqstate;
} WahwahState;

typedef struct
{
	float wah; ///< peak, 0..1
	float q; ///< resonance, 0..1
} WahwahParams;

void initWahwah(WahwahState* state);

void processWahwah(const FloatAudioBuffer* restrict in,
                   FloatAudioBuffer* restrict out, WahwahState* state,
                   const WahwahParams* params);

