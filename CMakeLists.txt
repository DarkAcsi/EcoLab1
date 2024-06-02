cmake_minimum_required(VERSION 3.27)
project(Eco.Lab1 C)

set(CMAKE_C_STANDARD 90)

include_directories(HeaderFiles)
include_directories(SharedFiles)

include_directories(Eco.CalculatorA/SharedFiles)
include_directories(Eco.CalculatorB/SharedFiles)
include_directories(Eco.CalculatorC/SharedFiles)
include_directories(Eco.CalculatorD/SharedFiles)
include_directories(Eco.CalculatorE/SharedFiles)

include_directories(
        $ENV{ECO_FRAMEWORK}/Eco.List1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.Core1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.InterfaceBus1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.System1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.MemoryManager1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.FileSystemManagement1/SharedFiles
)

set(CMAKE_STATIC_LINKER_FLAGS "/NOLOGO")
set(CMAKE_SHARED_LINKER_FLAGS "/NOLOGO /DLL /SUBSYSTEM:WINDOWS /TLBID:1 /DYNAMICBASE /NXCOMPAT /MACHINE:X86 /ERRORREPORT:QUEUE")
set(CMAKE_EXE_LINKER_FLAGS "/NOLOGO /TLBID:1 /DYNAMICBASE /NXCOMPAT /MACHINE:X86 /ERRORREPORT:QUEUE /SUBSYSTEM:CONSOLE /INCREMENTAL:NO")
set(CMAKE_C_FLAGS "/nologo /W3 /WX- /Oy- /EHsc /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gz /TC /analyze- /errorReport:queue")
set(CID "1F5DF16EE1BF43B999A434ED38FE8F3A")

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
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /DEBUG")

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
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /OPT:REF /OPT:ICF /LTCG")
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
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /DEBUG")

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
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /OPT:REF /OPT:ICF /LTCG")

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
        SourceFiles/CEcoLab1.c
        SourceFiles/CEcoLab1Factory.c
        SharedFiles/IdEcoLab1.h
        SharedFiles/IEcoLab1.h
        HeaderFiles/CEcoLab1.h
        HeaderFiles/CEcoLab1Factory.h
)

add_executable(
        Eco.Lab1
        UnitTestFiles/SourceFiles/EcoLab1.c
        SharedFiles/IdEcoLab1.h
        SharedFiles/IEcoLab1.h
        HeaderFiles/CEcoLab1.h
        HeaderFiles/CEcoLab1Factory.h
)

target_link_libraries(Eco.Lab1 ${CID})
target_link_libraries(
        Eco.Lab1
        $ENV{ECO_FRAMEWORK}/Eco.InterfaceBus1/BuildFiles/Windows/x86/StaticRelease/00000000000000000000000042757331.lib
        $ENV{ECO_FRAMEWORK}/Eco.MemoryManager1/BuildFiles/Windows/x86/StaticRelease/0000000000000000000000004D656D31.lib
        $ENV{ECO_FRAMEWORK}/Eco.FileSystemManagement1/BuildFiles/Windows/x86/StaticRelease/00000000000000000000000046534D31.lib
        $ENV{ECO_FRAMEWORK}/Eco.System1/BuildFiles/Windows/x86/StaticRelease/00000000000000000000000000000100.lib
)

#add_subdirectory(Eco.CalculatorA)
add_subdirectory(Eco.CalculatorC)
target_link_libraries(Eco.Lab1 4828F6552E4540E78121EBD220DC360E)

add_subdirectory(Eco.CalculatorB)
target_link_libraries(Eco.Lab1 AE202E543CE54550899603BD70C62565)

add_subdirectory(Eco.CalculatorD)
target_link_libraries(Eco.Lab1 3A8E44677E82475CB4A3719ED8397E61)

add_subdirectory(Eco.CalculatorE)
target_link_libraries(Eco.Lab1 872FEF1DE3314B87AD44D1E7C232C2F0)