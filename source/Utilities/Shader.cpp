#include "Shader.h"

#include <Window/OpenGL.h>
#include <cstdio>

namespace util {
	ShaderSource::ShaderSource(const string name, const int type) {
		FILE * file = fopen(name.c_str(), "rb");

		if (!file) {
		}

		fseek(file, 0, SEEK_END);
		int size = ftell(file);
		fseek(file, 0, SEEK_SET);

		char * source = new char[size + 1];
		fread(source, size, 1, file);
		source[size] = 0;
		fclose(file);

		shader = glCreateShader(type);
		glShaderSource(shader, 1, (const char **)&source, 0);
		glCompileShader(shader);
	}

	ShaderSource::~ShaderSource() {
		glDeleteShader(shader);
	}

	const bool ShaderSource::Compiled() const {
		int compiled = 0;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
		return(compiled);
	}

	const int ShaderSource::GetShader() const {
		return(shader);
	}

	const string ShaderSource::GetCompileInfo() const {
		char message[1024];
		glGetShaderInfoLog(shader, 1024, 0, message);
		return(message);
	}

	Shader::Shader(ShaderSource * vert, ShaderSource * frag) {
		if (!vert || !vert->Compiled()) {
		}
		if (!frag || !frag->Compiled()) {
		}

		program = glCreateProgram();
		glAttachShader(program, vert->GetShader());
		glAttachShader(program, frag->GetShader());
		glLinkProgram(program);
	}

	Shader::~Shader() {
		glDeleteProgram(program);
	}

	const void Shader::Use() const {
		glUseProgram(program);
	}

	const bool Shader::Linked() const {
		int linked;
		glGetProgramiv(program, GL_LINK_STATUS, &linked);
		return(linked);
	}
};
