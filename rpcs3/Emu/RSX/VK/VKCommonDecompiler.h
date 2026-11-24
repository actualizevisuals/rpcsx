#pragma once
#include "../Program/GLSLTypes.h"

namespace vk
{
	using namespace ::glsl;

	int get_varying_register_location(std::string_view varying_register_name);

	// Varyings used to emulate RSX user clip planes on GPUs without shaderClipDistance
	// (e.g. ARM Mali). Placed after the RSX varyings (locations 0-14).
	constexpr int emulated_clip_distance_location0 = 15; // clip planes 0-3
	constexpr int emulated_clip_distance_location1 = 16; // clip planes 4-5 in .xy

	// Whether shaders must emulate user clip planes (vertex output + fragment discard).
	bool emulate_clip_distance();
} // namespace vk
