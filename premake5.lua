workspace "Zebra"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Zebra"
	location "Zebra"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. ".%{prj.name}")
	objdir ("bin-int/" .. outputdir .. ".%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ZB_PLATFORM_WINDOWS",
			"ZB_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ZB_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "ZB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ZB_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. ".%{prj.name}")
	objdir ("bin-int/" .. outputdir .. ".%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"Zebra/src"
	}

	links
	{
		"Zebra"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ZB_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ZB_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "ZB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ZB_DIST"
		optimize "On"