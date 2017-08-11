project(QuartzCore)

include(darling_framework)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} \
	-include math.h \
	-include stdlib.h \
	-include CoreFoundation/CoreFoundation.h \
	-include Foundation/Foundation.h \
	-Wno-nonportable-include-path \
	-Wno-deprecated-objc-isa-usage \
	-mmacosx-version-min=10.10"
)

include_directories(
	${CMAKE_SOURCE_DIR}/src/external/foundation/include
	${CMAKE_SOURCE_DIR}/src/external/foundation/include/Foundation
	${CMAKE_SOURCE_DIR}/src/external/corefoundation
	${CMAKE_SOURCE_DIR}/src/external/objc4/runtime
	${CMAKE_SOURCE_DIR}/src/external/libclosure
	${CMAKE_SOURCE_DIR}/src/external/security/include
	${CMAKE_SOURCE_DIR}/src/external/cfnetwork/include
	${CMAKE_SOURCE_DIR}/src/external/cfnetwork/private_include
	${CMAKE_SOURCE_DIR}/src/launchd/liblaunch
	${CMAKE_SOURCE_DIR}/src/libmalloc/include
	${CMAKE_SOURCE_DIR}/src/copyfile
	${CMAKE_SOURCE_DIR}/src/libc/gen
	${CMAKE_SOURCE_DIR}/src/external/icu/icuSources/i18n
	${CMAKE_SOURCE_DIR}/src/external/icu/icuSources/common
	${CMAKE_SOURCE_DIR}/src/external/libxml2/include
	${CMAKE_BINARY_DIR}/src/external/libxml2/include

	${CMAKE_CURRENT_SOURCE_DIR}
)

set(QuartzCore_sources
	CAAnimationGroup.m
	CAAnimation.m
	CABase.m
	CABasicAnimation.m
	CALayerContext.m
	CALayer.m
	CAMediaTimingFunction.m
	CAPropertyAnimation.m
	CARenderer.m
	CATransactionGroup.m
	CATransaction.m
	CATransform3D.m
	CATransition.m
	CAValueFunction.m
	CAWindowOpenGLContext.m
	CIAffineTransform.m
	CIBloom.m
	CIBoxBlur.m
	CIColor.m
	CIContext.m
	CIFilter.m
	CIImage.m
	CILinearGradient.m
	CIVector.m
)

set_source_files_properties(${QuartzCore_sources} LANGUAGE C)

add_framework(QuartzCore
	FAT
	CURRENT_VERSION
	SOURCES
		${QuartzCore_sources}
	VERSION "A"
	DEPENDENCIES
		objc
		system
		${CoreFoundation}
		Foundation
		Onyx2D
		# native libraries
		GL
	CIRCULAR_DEPENDENCIES
		OpenGL
		CoreGraphics
)