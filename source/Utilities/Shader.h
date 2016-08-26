#pragma once

#include <string>

using std::string;

namespace util {
	class ShaderSource {
		int shader;

	public:
		ShaderSource(const string name, const int type);
		~ShaderSource();

		const bool Compiled() const;
		const int GetShader() const;

		const string GetCompileInfo() const;
	};

	class Shader {
		int program;

	public:
		Shader(ShaderSource * vert, ShaderSource * frag);
		~Shader();

		const void Use() const;
		const bool Linked() const;
	};
};
