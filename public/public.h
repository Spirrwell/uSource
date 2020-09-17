#pragma once

#ifdef PUBLIC_EXPORT
	#ifdef _WIN32
		#ifdef _MSC_VER
			#define PUBLICAPI __declspec(dllexport)
		#else
			#define PUBLICAPI __attribute__((dllexport))
		#endif
	#else
		#define PUBLICAPI __attribute__((visibility ("default")))
	#endif
#else
	#ifdef _WIN32
		#ifdef _MSC_VER
			#define PUBLICAPI __declspec(dllimport)
		#else
			#define PUBLICAPI __attribute__((dllimport))
		#endif
	#else
		#define PUBLICAPI
	#endif
#endif