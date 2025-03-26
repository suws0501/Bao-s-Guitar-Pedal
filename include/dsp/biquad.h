#pragma once
#include "codec.h"


typedef struct
{
	float gain;
	float a1, a2; // poles
	float b0, b1, b2; // zeros
} FloatBiquadCoeffs;


typedef struct
{
	float X[2][2];
	float Y[2][2];
} FloatBiquadState;


void bqMakeLowpass(FloatBiquadCoeffs* c, float w0, float q);

void bqMakeBandpass(FloatBiquadCoeffs* c, float w0, float q);

void bqProcess(const FloatAudioBuffer* restrict in, FloatAudioBuffer* restrict out,
               const FloatBiquadCoeffs* c, FloatBiquadState* state);