workspace "Roob"
	architecture "x64"
	startproject "Sandbox"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Roob/vendor/GLFW/include"
IncludeDir["glad"] = "Roob/vendor/glad/include"
IncludeDir["ImGui"] = "Roob/vendor/ImGui"
IncludeDir["glm"] = "Roob/vendor/glm"

group "Dependencies"
	include "Roob/vendor/GLFW"
	include "Roob/vendor/glad"
	include "Roob/vendor/ImGui"

group ""

project "Roob"
	location "Roob"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "roobpch.h"
	pchsource "Roob/src/roobpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines {
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links {
		"GLFW",
		"glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"ROOB_PLATFORM_WINDOWS",
			"ROOB_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "ROOB_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ROOB_RELEASE"
		runtime "Release"
		optimize "on"
		
	filter "configurations:Dist"
		defines "ROOB_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Roob/vendor/spdlog/include",
		"Roob/src",
		"Roob/vendor",
		"%{IncludeDir.glm}"
	}

	links {
		"Roob"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"ROOB_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ROOB_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ROOB_RELEASE"
		runtime "Release"
		optimize "on"
		
	filter "configurations:Dist"
		defines "ROOB_DIST"
		runtime "Release"
		optimize "on"

