#pragma once

namespace util {
	class Sound {
		unsigned buffer;
		unsigned source;

	public:
		Sound(const char * name);
		~Sound();

		const void Play() const;
		const void Stop() const;

		const unsigned GetBuffer() const;
		const unsigned GetSource() const;
	};

	class SoundData {
		int size;
		int sample;
		float * height;

	public:
		SoundData(const char * name);
		~SoundData();

		const int GetSize() const;
		const int GetSample() const;
		const float GetHeight(const int i) const;
	};
};
