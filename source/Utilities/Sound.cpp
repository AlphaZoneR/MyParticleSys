#include "Sound.h"

#include <cstdio>

#include <AL/al.h>
#include <AL/alc.h>

namespace util {
	Sound::Sound(const char * name) {
		FILE * file = fopen(name, "rb");

		int format;
		fread(&format, 4, 1, file);

		int sample;
		fread(&sample, 4, 1, file);

		int length;
		fread(&length, 4, 1, file);

		char * data = new char[length];
		fread(data, length, 1, file);
		fclose(file);

		alGenBuffers(1, &buffer);
		alBufferData(buffer, format, data, length, sample);
		delete[] data;

		alGenSources(1, &source);
		alSourcei(source, AL_BUFFER, buffer);
		alSourcei(source, AL_LOOPING, false);

		alSourcef(source, AL_GAIN, 1.0f);
		alSourcef(source, AL_PITCH, 1.0f);

		float SourcePos[] = {0.0, 0.0, 0.0};
		float SourceVel[] = {0.0, 0.0, 0.0};
		alSourcefv(source, AL_POSITION, SourcePos);
		alSourcefv(source, AL_VELOCITY, SourceVel);
	}

	Sound::~Sound() {
		Stop();
		alDeleteBuffers(1, &buffer);
		alDeleteSources(1, &source);
	}

	const void Sound::Play() const {
		alSourcePlay(source);
	}

	const void Sound::Stop() const {
		alSourceStop(source);
	}

	const unsigned Sound::GetBuffer() const {
		return(buffer);
	}

	const unsigned Sound::GetSource() const {
		return(source);
	}

	SoundData::SoundData(const char * name) {
		FILE * file = fopen(name, "rb");

		int format;
		fread(&format, 4, 1, file);
		fread(&sample, 4, 1, file);

		int length;
		fread(&length, 4, 1, file);

		char * data = new char[size];
		fread(data, length, 1, file);
		fclose(file);

		if (format == AL_FORMAT_MONO8) {
			size = length;
			height = new float[size];
			char * ptr = (char *)data;
			for (int i = 0; i < size; ++i) {
				height[i] = (float)ptr[i] / 0x7F;
			}
		}

		if (format == AL_FORMAT_STEREO8) {
			size = length / 2;
			height = new float[size];
			char * ptr = (char *)data;
			for (int i = 0; i < size; ++i) {
				height[i] = (float)(ptr[i * 2] + ptr[i * 2 + 1]) / 2 / 0x7F;
			}
		}

		if (format == AL_FORMAT_MONO16) {
			size = length / 2;
			height = new float[size];
			short * ptr = (short *)data;
			for (int i = 0; i < size; ++i) {
				height[i] = (float)ptr[i] / 0x7FFF;
			}
		}

		if (format == AL_FORMAT_STEREO16) {
			size = length / 4;
			height = new float[size];
			short * ptr = (short *)data;
			for (int i = 0; i < size; ++i) {
				height[i] = (float)(ptr[i * 2] + ptr[i * 2 + 1]) / 2 / 0x7FFF;
			}
		}
		delete[] data;
	}

	SoundData::~SoundData() {
		delete[] height;
	}

	const int SoundData::GetSize() const {
		return(size);
	}

	const int SoundData::GetSample() const {
		return(sample);
	}

	const float SoundData::GetHeight(const int i) const {
		return(height[i]);
	}
};
