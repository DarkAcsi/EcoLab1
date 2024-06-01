cmake_minimum_required(VERSION 3.27)
project(Eco_Lab_B C)

set(CMAKE_C_STANDARD 90)

include_directories(HeaderFiles)
include_directories(SharedFiles)

include_directories(
        $ENV{ECO_FRAMEWORK}/Eco.List1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.Core1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.InterfaceBus1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.System1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.MemoryManager1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.FileSystemManagement1/SharedFiles
)

set(CMAKE_C_FLAGS "/nologo /W3 /WX- /Oy- /EHsc /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gz /TC /analyze- /errorReport:queue")
set(CMAKE_STATIC_LINKER_FLAGS "/NOLOGO")
set(CMAKE_SHARED_LINKER_FLAGS "/NOLOGO /DLL /SUBSYSTEM:WINDOWS /TLBID:1 /DYNAMICBASE /NXCOMPAT /MACHINE:X86 /ERRORREPORT:QUEUE")
set(CID "AE202E543CE54550899603BD70C62565")

add_definitions(
        -DWIN32
        -D_WINDOWS
        -DUGUID_UTILITY
        -DECO_WINDOWS
        -DECO_WIN32
        -D_UNICODE
        -DUNICODE
)

if (STATIC_DEBUG)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /ZI /Od /Gm /RTC1 /MTd")

    add_definitions(
            -D_DEBUG
            -DECO_LIB
    )

    add_library(
            ${CID}
            STATIC
    )
elseif (STATIC_RELEASE)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /Zi /O2 /Oi /Gm- /MT /Gy")
    set(CMAKE_STATIC_LINKER_FLAGS "${CMAKE_STATIC_LINKER_FLAGS} /LTCG")

    add_definitions(
            -DNDEBUG
            -DECO_LIB
    )

    add_library(
            ${CID}
            STATIC
    )
elseif (DYNAMIC_DEBUG)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /ZI /Od /Gm /RTC1 /MTd")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /DEBUG")

    add_definitions(
            -D_DEBUG
            -DECO_DLL
            -D_WINDLL
    )

    add_library(
            ${CID}
            SHARED
    )
elseif (DYNAMIC_RELEASE)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /Zi /O2 /Oi /Gm- /MT /Gy")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /OPT:REF /OPT:ICF /LTCG")

    add_definitions(
            -DNDEBUG
            -DECO_DLL
            -D_WINDLL
    )

    add_library(
            ${CID}
            SHARED
    )
endif ()

target_sources(
        ${CID}
        PRIVATE
        SourceFiles/CEcoCalculatorB.c
        SourceFiles/CEcoCalculatorBFactory.c
        SharedFiles/IdEcoCalculatorB.h
        SharedFiles/IEcoCalculatorX.h
        HeaderFiles/CEcoCalculatorB.h
        HeaderFiles/CEcoCalculatorBFactory.h
)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
